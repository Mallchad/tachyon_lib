
/** This file provides project agnostic types and utility functions, in theory
 * this can ripped out and relocated to another project by only changing a line or
 * two. Or none. */

#include "include_tachyon_lib_core.h"

namespace fs = std::filesystem;

namespace tyon
{
    time_monotonic g_program_epoch = time_now();
    bool g_little_endian = true;
    i32 g_log_largest_category = 0;
    memory_stack_allocator* g_allocator = nullptr;
    memory_stack_allocator* g_taint_allocator;
    std::mutex* g_allocator_lock = nullptr;
    std::mutex g_taint_allocator_lock = {};

    raw_pointer g_null_read;
    raw_pointer g_null_write;

    library_context* g_library = nullptr;
    logger* g_logger = nullptr;
    logger* g_switch_logger = nullptr;
    asset g_asset_stub = {};
    asset_machine* g_asset = nullptr;

    null_type null;

    // -- Memory Management Library --

    isize
    memory_padding( isize padding, isize size )
    { return (padding - (size % padding) % padding); }

    isize
    memory_padding( isize padding, void* target )
    { return (padding - (u64(target) % padding) % padding); }

    raw_pointer
    memory_allocate_raw( usize size )
    {
        std::scoped_lock lock( *g_allocator_lock );
        return g_allocator->allocate<byte>( size );
    }

    bool
    memory_zero_raw( void* target, i64 bytes )
    {
        std::memset( target, 0, bytes );
        return true;
    }

    void
    FUNCTION memory_copy_raw( void* dest, const void* src, u64 bytes)
    {
        memcpy( dest, src, bytes );
    }

	bool
    FUNCTION memory_same_raw( void* a, void* b, i64 bytes )
    {
        return std::memcmp( a, b, bytes ) == 0;
    }

    void
    memory_poison( void* address, isize size )
    {
        (void)address; (void)size;
#if (defined(__SANITIZE_ADDRESS__))
        __asan_poison_memory_region( address, size );
#else
        memset( address, 0XFF, size );
#endif // address sanitizer
    }

    void
    memory_unpoison( void* address, isize size )
    {
        (void)address; (void)size;
#if (defined(__SANITIZE_ADDRESS__))
        __asan_unpoison_memory_region( address, size );
#endif // address sanitizer
    }

    CONSTRUCTOR memory_stack_allocator::memory_stack_allocator( isize _block_size )
    {
        this->os_page_size = 4096;
        i32 pages = i32(ceill(f32(_block_size) / os_page_size));
        isize min_allocation = (os_page_size * pages);
        buffer first_block;
        first_block.data = reinterpret_cast<byte*>(std::malloc( min_allocation ));
        first_block.size = min_allocation;
        first_block.head = 0;
        first_block.head_size = 0;
        this->block_size = min_allocation;
        // Force pages into memory
        std::memset( first_block.data, 0x0, first_block.size );
        memory_poison( first_block.data, first_block.size );

        blocks.reserve( 4 );
        blocks.push_back( first_block );

        this->churn = 0;
        this->churn_bytes = 0;
        this->allocations = 0;
        this->deallocations = 0;
        this->blanked_blocks = 0;
        memory_zero( &this->info, 1 );
    }

    // COPY_CONSTRUCTOR memory_stack_allocator::memory_stack_allocator( const memory_stack_allocator& )
    // {}

    void
    memory_stack_allocator::blank_all()
    {
        buffer* x_block;
        for (int i=0; i < i32(blocks.size()); ++i)
        {
            x_block = (blocks.data() + i);

            memory_poison( x_block->data, x_block->size );
            memory_zero( x_block->data, x_block->head_size );
            churn += 1;
            churn_bytes += x_block->head_size;
            ++blanked_blocks;
            x_block->head_size = 0;
        }
        entries.clear();
    }

    void memory_stack_allocator::operator= ( const memory_stack_allocator& )
    {}

    raw_pointer memory_stack_allocator::allocate_raw( isize bytes, isize alignment )
    {
        isize size = (bytes);
        isize type_size = 1;
        buffer* block = &(blocks.back());
        isize alignment_bytes = memory_padding( alignment, block->data + block->head_size );
        void* head_data = (block->data + block->head_size + alignment_bytes);
        void* result = nullptr;

        bool size_exceeded = ((alignment_bytes + block->head_size + size) > block->size);
        if (size_exceeded) [[unlikely]]
        {
            buffer new_block;
            i32 pages = i32(ceil(f32(size) / block_size));
            isize allocation = (block_size * pages);
            new_block.data = reinterpret_cast<byte*>(std::malloc( allocation ));
            new_block.size = allocation;
            new_block.head = 0;
            new_block.head_size = 0;

            // Force pages into memory
            std::memset( new_block.data, 0x0, block_size );
            blocks.push_back( new_block );
            // Fixup stale data
            block = &(blocks.back());
            alignment_bytes = memory_padding( 1, head_data );
            head_data = (block->data + block->head_size + alignment_bytes);

            if (new_block.data == nullptr) { return nullptr; }
        }

        // Allocate the new memory
        memory_unpoison( head_data, size );
        result = reinterpret_cast<void*>( head_data );
        block->head_size += (alignment_bytes + size);
        churn_bytes += size;
        ++churn;
        ++allocations;

        stack_entry new_entry {
            .data = result,
            // Not important right now.
            .position = 0,
            .size = bytes,
            .alignment = alignment_bytes
        };

        return result;
    }

    PROC memory_stack_allocator::allocate_raw_fast( i64 bytes, isize alignment ) -> raw_pointer
    {
        buffer* block = &(blocks.back());
        isize alignment_bytes = memory_padding( alignment, block->data + block->head_size );
        isize allocation_size = (alignment + block->head_size);
        raw_pointer result = (block->data + allocation_size);
        block->head_size += allocation_size;

        return result;
    }

    PROC memory_stack_allocator::allocate_relocate( void* reference, i64 bytes ) -> raw_pointer
    {
        raw_pointer result;
        if (reference == nullptr)
        {   return nullptr;
        }
        // reallocation doesn't make a tonne of sense on stack allocates... Leave it broken for now
        // TODO: Working on
        // auto search = entries.linear_search( [](heap_entry& arg ) {
            // return arg.data == reference; } );
        auto iter = std::find_if( entries.begin(), entries.end(),
                               [=](stack_entry& arg ) {
                                   return arg.data == reference; } );
        stack_entry _tmp = (iter != entries.end() ? *iter : stack_entry{});
        search_result<stack_entry> search = { .match = &_tmp, .match_found = (iter != entries.end()) };

        stack_entry entry = search.copy_default({});
        if (search.match_found == false)
        {   return nullptr;
        }
        result = this->allocate_raw( bytes, entry.alignment );
        if (result)
        {   memory_copy_raw( result, entry.data, entry.size );
        }
        // Blank old entry
        *search.match = {};
        return result;
    }


    void
    memory_stack_allocator::deallocate( void* address )
    {
        void(0);
    }

    fstring
    format_as( allocator_info arg )
    {
        return fmt::format(
            "\n    os_reserved: {}  \n"
            "    os_physical: {} \n"
            "    user_allocated: {} \n"
            "    churn: {} \n"
            "    churn_bytes: {} \n"
            "    allocations: {} \n"
            "    deallocations: {} \n"
            "    blanked_blocks: {} \n"
            "    blocks: {} \n"
            "    block_size: {} \n"
            "    os_page_size: {} \n"
            "    os_large_page_size: {} \n"
            ,
            arg.os_reserved, arg.os_physical, arg.user_allocated, arg.churn, arg.churn_bytes,
            arg.allocations, arg.deallocations, arg.blanked_blocks, arg.blocks, arg.block_size,
            arg.os_page_size, arg.os_large_page_size
            );
    }

    allocator_info
    memory_stack_allocator::get_memory_statistics()
    {
        allocator_info result;

        result.os_reserved = 0;
        result.os_physical = 0;
        result.user_allocated = 0;
        result.churn = churn;
        result.churn_bytes = churn_bytes;
        result.allocations = allocations;
        result.deallocations = deallocations;
        result.blanked_blocks = blanked_blocks;
        result.blocks = blocks.size();
        result.block_size = block_size;
        result.os_page_size = os_page_size;
        result.os_large_page_size = 0;

        buffer x_block;
        for (int i=0; i < i32(blocks.size()); ++i)
        {
            x_block = blocks[i];
            result.os_reserved += x_block.size;
            result.os_physical += x_block.size;
            result.user_allocated += x_block.head_size;
        }
        return result;
    }

    DESTRUCTOR memory_stack_allocator::~memory_stack_allocator()
    {
        buffer x_block;
        for (int i=0; i < i32(blocks.size()); ++i)
        {
            x_block = blocks[i];
            memory_unpoison( x_block.data, x_block.size );
            free( x_block.data );
        }
    }

    TYON_FORCEINLINE isize
    memory_align( isize bytes, i32 alignment )
    {
        return (bytes + (alignment - (bytes % alignment)));
    }

    PROC resource_arena::run_cleanup() -> void
    {
        constexpr bool debug = true;
        for (i32 i=0; i < destroy_stack.size(); ++i)
        {
            i32 i_reverse = (destroy_stack.size() - i - 1);
            destroy_stack[i_reverse].invoke();
            if constexpr (debug)
            {

            }
        }
        destroy_stack.head_size = 0;
    }


    PROC resource_arena::push_cleanup( cleanup_delegate arg ) -> void
    {
        destroy_stack.push_tail( arg );
    }

    // Resource Library
    DESTRUCTOR resource_arena::~resource_arena()
    { this->run_cleanup(); }

    // -- Container Types --

    // -- Time Library -

    monotonic_time
    FUNCTION time_now()
    { return chrono::steady_clock::now(); }

    time_date
    FUNCTION time_now_utc()
    { return chrono::system_clock::now(); }

    CONSTRUCTOR time_periodic::time_periodic( chrono::nanoseconds _update_rate )
    {
        reference_time = time_now();
        trigger_time = time_now() + update_rate;
        update_rate = _update_rate;
        active = true;
    }

/// Check to see if timer triggered or not
    bool
    time_periodic::triggered()
    {
        time_monotonic check_time = time_now();
        if (active && check_time > trigger_time)
        {
            drift = chrono::nanoseconds(check_time - trigger_time);
            chrono::nanoseconds elapsed = check_time - reference_time;
            chrono::nanoseconds next_trigger_offset = update_rate - (elapsed % update_rate);
            trigger_time = check_time + next_trigger_offset;
            return true;
        }
        return false;
    }

    time_periodic::operator bool()
    { return this->triggered(); }


    CONSTRUCTOR time_stopwatch::time_stopwatch( fstring _name, fstring _description = "" )
    {
        name = _name;
        description = _description;
    }

    DESTRUCTOR time_stopwatch::~time_stopwatch()
    {
        u64 elapsed_ns = clock.count();
        u64 _elapsed_ns = elapsed_ns;
        u64 milliseconds = (_elapsed_ns / 1'000'000); _elapsed_ns %= 1'000'000;
        u64 microseconds =  (_elapsed_ns / 1'000); _elapsed_ns %= 1'000;
        u64 nanoseconds = _elapsed_ns;

        char buffer[64];
        snprintf( buffer, 64, "[%3.0lu %3.0lu %3.0lu ns]", milliseconds, microseconds, nanoseconds );
        TYON_BASE_LOGF( "Tachyon Profiler", "{} [{}] {}",
                        buffer, name, description );
        log_flush();
    }

    CONSTRUCTOR time_scope::time_scope( fstring _name, fstring _description )
    {
        start = time_now();
        name = _name;
        description = _description;
    }

    CONSTRUCTOR time_scope::time_scope( time_stopwatch* _stopwatch )
    {
        stopwatch = _stopwatch;
        start = time_now();
    }

    CONSTRUCTOR time_scope::time_scope( procedure_time_scope _destructor )
        : destructor(_destructor),
          start(time_now()) { }

    DESTRUCTOR time_scope::~time_scope()
    {
        auto time_elapsed = chrono::duration_cast<chrono::nanoseconds>( time_now() - start );
        if (destructor != nullptr)
        {
            destructor( this );
        }
        else if (stopwatch != nullptr)
        {
            stopwatch->clock += time_elapsed;
            stopwatch->counter++;
        }
        else
        {
            u64 elapsed_ns = time_elapsed.count();
            u64 _elapsed_ns = elapsed_ns;
            u64 seconds = (_elapsed_ns / 1'000'000'000); _elapsed_ns %= 1'000'000'000;
            u64 miliseconds =  (_elapsed_ns / 1'000'000); _elapsed_ns %= 1'000'000;
            u64 microseconds = (_elapsed_ns / 1'000); _elapsed_ns %= 1'000;
            u64 nanoseconds = _elapsed_ns;

            char buffer[64];
            snprintf(
                buffer, 64, "[%lu s %3.0lu %3.0lu %3.0lu ns]",
                seconds, miliseconds, microseconds, nanoseconds );
            TYON_BASE_LOGF( "Tachyon Profiler", "{} [{}] {}",
                            buffer, name, description );
        }
    }

    // -- Threading Library --

    // -- Type Support Library --

    bool
    minihash::operator== ( minihash& rhs ) { return this->value == rhs.value; };

    bool
    minihash::operator!= ( minihash& rhs ) { return this->value != rhs.value; };

    // -- File Library

    fresult
    file::update_status()
    {
        try
        {
            file_exists = fs::exists( filename );
            status_loaded = true;
        } catch (...)
        { return false; }
        return true;
    }

    /** Load a whole file into a buffer as binary.

        Breaks on UNIX virtual files, because they have no filesize */
    file
    FUNCTION file_load_binary( const fpath target, i_memory_allocator* allocator )
    {
        using namespace std::filesystem;
        file result;
        result.filename = target.string();
        FILE* new_file = nullptr;
        fuint64 filesize = 0;

        // Cast it to a normal string to let std::filesystem convert Windows wstrings.
        fstring file_string = target.string();
        new_file = fopen( file_string.c_str(), "rb" );
        if (new_file == nullptr)
        {
            TYON_LOG( "File", "Failed to open file: ", target );
            return result;
        }

        fseek( new_file, 0, SEEK_END );
        filesize = ftell( new_file );
        if (filesize <= 0)
        {
            TYON_LOG( "File", "WARNING, opened file is zero length" );
            fclose( new_file );
            return result;
        }

        // Return to beginning
        fseek( new_file, 0, SEEK_SET );
        i64 pos = ftell( new_file );

        result.memory.data = allocator->allocate_raw( filesize );
        if (result.memory.data == nullptr)
        { TYON_LOG( "File", "Failed to allocate memory for read operation", target ); }
        result.memory.size = filesize;

        isize read_size = fread( result.memory.data, sizeof(byte), result.memory.size, new_file );
        bool end_of_file = feof( new_file );
        i32 file_error = ferror( new_file );
        ERROR_GUARD( read_size == result.memory.size,
                     "Something is amiss if we read a different amount than we sized for." );
        TYON_LOG( "File", "Loaded whole file at path: ", target );
        fclose( new_file );
        result.file_loaded = true;

        return result;
    }

    fresult
    file_write_binary_stdlib( file* arg )
    {
        TIME_SCOPED_FUNCTION();
        // Cast it to a normal string to let std::filesystem convert windows wstrings.
        fstring filename = arg->filename.string();

        // Overwrite pre-existing file completely
        FILE* file_ = fopen( filename.c_str(), "wb" );
        ERROR_GUARD( file_, "Failed to open file" );
        u64 bytes_written = fwrite( arg->memory.data, 1, arg->memory.size, file_ );
        bool write_ok = (i64(bytes_written) >= arg->memory.size);

        // Cleanup
        fclose( file_ );
        if (write_ok)
        { TYON_LOG( fmt::format( "Wrote binary file '{}'", arg->filename ) ); }
        else
        { TYON_ERRORF( "Failed to write binary file '{}'", arg->filename  ); }
        ERROR_GUARD( write_ok, "File wrote less than full data or failed" );

        return write_ok;
    }

    // -- Asset Library --

    void
    asset_machinery_init()
    {
        TIME_SCOPED_FUNCTION();
        fpath self_directory = file_self_directory();
        g_asset = memory_allocate<asset_machine>( 1 );
        g_asset->search_paths.change_allocation( 20 );
        g_asset->assets.change_allocation( 100 );

        g_asset->search_paths.push_tail( self_directory );
        asset_enumerate_files();
    }

    PROC asset_enumerate_files() -> void
    {
        fpath x_path;
        fpath x_filename;
        fs::directory_entry x_entry;
        // TODO: Should really be known max_iterations
        i32 iteration_limit = 1000;
        i32 i_search = 0;

        for (; i_search < g_asset->search_paths.head_size; ++i_search)
        {
            x_path = g_asset->search_paths[i_search];
            x_path = fs::canonical( x_path );
            if (fs::is_directory( x_path ) == false)
            {   TYON_LOGF( "Failed to find asset search path: '{}'", x_path.string() );
                continue;
            }
            TYON_LOGF( "Searching for assets in search_path: '{}'", x_path.string() );
            auto iterator = fs::recursive_directory_iterator( x_path );
            for (i32 i_file=0; i_file < iteration_limit; i_file++, iterator++)
            {
                if (iterator == fs::end( iterator)) { break; }
                x_entry = *iterator;
                x_filename = x_entry;

                // Reload or skip if pre-existing asset exists
                search_result<asset> lookup = g_asset->assets.linear_search( [=]( asset& arg )
                {   return arg.file_.filename == x_filename; }
                );
                if (lookup.match_found)
                {
                    // TODO: Do asset reloading logic
                    TYON_LOGF( "Skipping already existing asset for load '{}'",
                               lookup.match->file_.filename );
                    continue;
                }

                if (x_entry.is_regular_file())
                {
                    asset new_asset;
                    new_asset.file_.filename = x_filename;
                    new_asset.name = x_filename.filename().string();
                    g_asset->assets.push_tail( new_asset );
                }
            }
        }

        i32 asset_search_limit = 1000;
        if (i_search >= asset_search_limit)
        {   TYON_ERRORF(
                "Exceeded asset system file limit {} whilst enumerating files from search paths",
                asset_search_limit);
        }
    }

    asset*
    asset_search( fstring filename, e_asset type )
    {
        asset* result = nullptr;
        {
            asset* x_asset = nullptr;
            for (i32 i=0; i < g_asset->assets.size_; ++i)
            {
                x_asset = &g_asset->assets[i];
                if (x_asset->name == filename)
                { result = x_asset; break; }
            }
        }
        if (result == nullptr)
        {
            TYON_ERRORF( "Failed to load asset: {}", filename );
            return nullptr;
        }

        bool new_asset = (result == nullptr);
        if (new_asset)
        {
            g_asset->assets.push_back( asset{} );
            result = g_asset->assets.tail_address();
            result->file_.filename = filename;
            result->name = filename;
        }

        if (result->type == asset_type::none)
        {
            result->type = type;
        }
        ERROR_GUARD( result->type == type, "There are two assets with the same name found" );
        if (result->type != type) { return &g_asset_stub; }

        // Search for matching loader
        asset_type_data* x_type = nullptr;
        asset_type_data* match = nullptr;
        for (int i=0; i < i32(g_asset->asset_types.size()); ++i)
        {
            x_type = &g_asset->asset_types[i];
            if (x_type->type == type)
            { match = x_type; break; }
        }

        if (match)
        {
            result->loader = match->loader;
            result->unloader = match->unloader;
            result->loader_name = match->name;
        }

        return result;
    }

    asset*
    asset_queue_load( fstring filename, e_asset type  )
    {
        asset* _asset = asset_search( filename, type );
        ERROR_GUARD( 0, "Unimplimented" );
        return _asset;
    }

    void
    asset_machinery_register_type(
        fstring name,
        e_asset type,
        asset_function loader,
        asset_function unloader
        )
    {
        g_asset->asset_types.push_back( asset_type_data { name, type, loader, unloader } );
    }

    bool
    asset_execute_loader( asset* arg )
    {
        bool result = false;
        if (arg == nullptr) { return false; }
        if (arg->loaded == false)
        {
            result = arg->loader( arg );
        }
        if (result)
        {
            TYON_BASE_ERRORF( "Tachyon Assets", "Successfully loaded file {} at path '{}' using loader '{}'",
                        arg->name, arg->file_.filename.string(), arg->loader_name );
        }
        else
        {
            TYON_BASE_ERRORF( "Tachyon Assets", "Failed to load file {} at path '{}' using loader '{}'",
                              arg->name, arg->file_.filename.string(), arg->loader_name );
        }
        return result;
    }

    // -- Logging --

    PROC logger_write_message(
        logger* context,
        fstring category,
        fstring message,
        e_log_entry type,
        tyon::source_location call_point
    ) -> void
    {
        PROFILE_SCOPE_FUNCTION();
        context->write_message( category, message, type, call_point );
    }

    void
    logger::write_error_simple( fstring message )
    {
        this->messages.append( message );

        // Write to log file if possible
        if (log_file == nullptr)
        { log_file = fopen( this->log_filename.c_str(), "w" ); }
        if (log_file)
        { fwrite( message.data(), 1, message.size(), log_file ); }

        // Ensure file has synchronized messages before proceeding
        fflush( log_file );
        if (console_output_enabled)
        {
            fmt::print( fmt::emphasis::bold | fmt::fg(fmt::color::red), "{}", message );
        }
    }

    PROC logger::write_message(
        fstring category,
        fstring message,
        e_log_entry type,
        tyon::source_location call_point
    ) -> void
    {
        PROFILE_SCOPE_FUNCTION();
        std::scoped_lock _lock( write_lock );
        // Prevent deadlocking from recursive calls
        std::swap( g_logger, g_switch_logger );

        log_entry& entry = entries.push_tail( {} );
        entry.type = type;
        entry.category = category;
        entry.message = message,
        entry.timestamp = time_now_utc();
        // TODO: Add call point
        // entry.call_point = call_point

        if (console_output_enabled || string_output_enabled)
        {
            i64 nanoseconds = time_to_epoch_nanoseconds( entry.timestamp );
            u64 category_size = category.size();
            fstring padding;

            g_log_largest_category = u32(category_size > g_log_largest_category ?
                                         category_size :
                                         g_log_largest_category);
            padding.insert( 0, (g_log_largest_category - category_size) + 4, ' ');

            fstring formatted_message;
            switch (entry.type)
            {
                case e_log_entry::error:
                    formatted_message = fmt::format(
                        "[{0}][{1}] \n\tLocation: {2} @ {3}:{4}:{5} \n\t{6} \n",
                        nanoseconds, entry.category, call_point.function_name(),
                        call_point.file_name(), call_point.line(), call_point.column(),
                        entry.message );
                    fmt::print( fmt::emphasis::bold | fmt::fg(fmt::color::red), "{}", formatted_message );
                    break;

                default:
                    formatted_message = fmt::format(
                        "[{}][{}] {} \n", nanoseconds, entry.category, entry.message );
                    fmt::print( "{}", formatted_message );
            }
            fflush( stdout );

            if (string_output_enabled)
            {
                // Write to log file if possible
                if (log_file == nullptr)
                { log_file = fopen( this->log_filename.c_str(), "w" ); }
                if (log_file)
                { fwrite( formatted_message.data(), 1, formatted_message.size(), log_file ); }
                fflush( log_file );
            }
        }
        std::swap( g_logger, g_switch_logger );
    }

    void
    library_context_init( library_context* arg )
    {
        TIME_SCOPED_FUNCTION();
        if (arg->initialized)
        {
            // TODO Should append this to the defualt logger at some point for pre-init messages
            fmt::print(
                "[Tachyon Pre-Init]    library has already"
                " been initialized but 'library_context_init' was called again" );
            TYON_BREAK();
        }
        g_library = arg;
        g_program_epoch = time_now();
        g_allocator = &arg->global_allocator;
        g_allocator_lock = &arg->global_allocator_lock;
        // g_taint_allocator_lock = &arg->taint_allocator_lock;
        g_logger = &arg->default_logger;
        g_switch_logger = &arg->switch_logger;
        g_entity = &arg->entity;

        // Canonicalize and log filename so its static and never changes with working directory
        // NOTE: Throws error when file doesn't exist yet so we use directories instead
        FILE* tmp_file = fopen( arg->default_logger.log_filename.c_str(), "w" );
        if (tmp_file)
        {   fclose( tmp_file );
            fstring absolute_logfile = fs::canonical( arg->default_logger.log_filename ).string();
            TYON_LOGF( "Default log file Path '{}' \n", absolute_logfile );
        }

        // Using logging, needs to run after logging setup
        g_little_endian = test_little_endian();
        // Use malloc on purpose to take advantage of virtual memory
        g_null_read = reinterpret_cast<byte*>( malloc( 1'000'000'000 ) );
        g_null_write = reinterpret_cast<byte*>( malloc( 1'000'000'000 ) );

        // Mandatory subsystems
        platform_init();
        entity_type_register<file>();

        // Init optional sub-systems
        asset_machinery_init();

        // SECTION: Random Information Logging
        fstring home_dir = file_home_directory();
        TYON_LOGF( "Home directory path: {}", home_dir );

        // Finished!
        arg->initialized = true;
    }

    PROC string_to_i64( fstring arg ) -> monad<i64>
    {
        monad<i64> result;
        try
        {   result.value = std::stoll( arg );
        }
        catch (std::invalid_argument& e)
        {   TYON_ERROR( "std::invalid_argument, no conversion could be performed", e.what() );
            result.error = true;
        }  catch (std::out_of_range& e)
        {   TYON_ERROR( "std::out_of_range, value exceeds range of container", e.what() );
            result.error = true;
        }
        return result;
    }

    PROC string_to_f64( fstring arg ) -> monad<f64>
    {
        monad<f64> result;
        try
        {   result.value = std::stod( arg );
        }
        catch (std::invalid_argument& e)
        {   TYON_ERROR( "std::invalid_argument, no conversion could be performed", e.what() );
            result.error = true;
        }  catch (std::out_of_range& e)
        {   TYON_ERROR( "std::out_of_range, value exceeds range of container", e.what() );
            result.error = true;
        }
        return result;
    }

    PROC string_cmdline_parse( fstring arg ) -> cmdline_argument
    {
        cmdline_argument result;
        result.original = arg;
        fstring normalized;
        normalized.reserve( arg.size() );

        if (arg.empty())
        {   TYON_ERROR( "Empty string passed" );
            return result;
        }

        bool double_dash_flag = false;
        /** NOTE: I  Tried to detect strings  here but we can't  do that because
            quote or speech marks are never  actually provided to us. So we just
            have  to  take  it  verbatim  as  a  string  if  no  other  type  is
            detected. Even if it looks weird. */
        bool empty_string_arg = (arg.size() == 0);
        bool assignment_flag = false;

        if (arg.size() >= 2)
        {
            double_dash_flag = (arg[0] == '-' && arg[1] == '-');
            //NOTE: Don't try to look for speech marks in a string, the commandline remoevs them.
            assignment_flag = (arg.back() == ':' || arg.back() == '=');
        }
        result.requires_value = assignment_flag;

        i32 offset = 0;
        if (double_dash_flag)
        {   // Skip first two chars
            offset = 2;

            // Strip assignment chars if exists
            if (arg.back() == '=')
            {   arg.resize( arg.size() - 1 );
            }
            else if (arg.back() == ':')
            {   arg.resize( arg.size() - 1 );
            }
            else if (arg.back() == '=' && arg.back()-- == ':')
            {   arg.resize( arg.size() -2 );
            }
        }
        bool numeric_flag = true;
        bool float_flag = false;
        char x_char = 0;
        normalized.resize( arg.size() - offset );
        for (i32 i=0; i < arg.size() - offset; ++i)
        {
            x_char = arg[ offset + i ];
            x_char = std::tolower( x_char );

            if (double_dash_flag)
            {
                // Convert dashed arguments to underscore for uniformity
                x_char = (x_char =='-' ? '_' : x_char);
                // Skip adding whitespace
                if (x_char == ' ')
                {   continue;
                }
            }
            normalized[i] = x_char;

            bool float_char = (x_char == 'e' || x_char == 'E');
            bool sign_char = (x_char == '-' || x_char == '+');
            bool numeric_char = (std::isdigit( x_char ) || sign_char || float_char);
            if (numeric_char == false)
            {   numeric_flag = false;
            }
            if (float_char)
            {   float_flag = true;
            }
        }
        if (double_dash_flag)
        {
            result.name = normalized;
            return result;
        }
        else if (numeric_flag)
        {
            result.is_value = true;
            if (float_flag)
            {   result.value.float_ = string_to_f64( normalized ).value;
                result.value.type = e_primitive::float_;
            }
            else
            {   result.value.integer_ = string_to_i64( normalized ).value;
                result.value.type = e_primitive::integer_;
            }
        }
        else // String Value
        {   normalized = arg;
            result.value = normalized;
            result.is_value = true;
            return result;
        }

        return result;
    }

    PROC library_process_cmdline_args( int argc, char** argv ) -> void
    {
        i32 arg_limit = 100;
        if (argc > arg_limit)
        {   TYON_ERROR( "More cmdline options provided than allowed" );
        }
        else
        {   arg_limit = argc;
        }

        fstring x_arg;
        x_arg.reserve( 100 );
        TYON_LOG( "Processing command line arguments" );
        for (i32 i=0; i < arg_limit; ++i)
        {
            x_arg = argv[i];
            cmdline_argument x_argument = string_cmdline_parse( x_arg );
            TYON_LOGF( "    '{}' Internal Name: '{}'", x_argument.original, x_argument.name );
            bool next_in_range = (1+ i < arg_limit);
            if (x_argument.requires_value && next_in_range)
            {   cmdline_argument x_next = string_cmdline_parse( argv[1+ i] );

                if (x_argument.requires_value && x_next.is_value == false)
                {   TYON_ERRORF( "Expected arugment '{}' to be a value following '{}'",
                                x_next.original, x_argument.original );
                    continue;
                }
                TYON_LOGF( "    '{}' | Value Argument Type {}",
                           x_next.original, string_cast( x_next.value.type ) );
                x_argument.original_value = x_next.original;
                x_argument.value = x_next.value;
                ++i; // Skip one iteration
            }
            g_library->cmdline_arguments.push_tail( x_argument );
        }
    }

    // -- Platform Library --

    fresult
    FUNCTION test_little_endian()
    {
        fuint16 full_bits = 1;
        fuint8 first_bits = *reinterpret_cast<fuint8*>( &full_bits );
        bool little_endian = static_cast<bool>( first_bits );

        TYON_BASE_LOG(
            "Tachyon Platform",
            (little_endian ? "Memory tested for endianess, came back as little endian" :
             "Platform tested for endianess, came back as big endian")
            );
        return little_endian;
    }

    PROC string_cast( e_primitive arg ) -> fstring
    {
        switch (arg)
        {
            case e_primitive::none:       return "e_primitive::none";
            case e_primitive::any:        return "e_primitive::any";
            case e_primitive::integer_:   return "e_primitive::integer_";
            case e_primitive::float_:     return "e_primitive::float_";
            case e_primitive::boolean_:   return "e_primitive::boolean_";
            case e_primitive::character_: return "e_primitive::character_";
            case e_primitive::byte_:      return "e_primitive::byte_";
            case e_primitive::pointer_:   return "e_primitive::pointer_";
            case e_primitive::string_:    return "e_primitive::string_";
        }
        return "no_conversion_found";
    }

    PROC dynamic_primitive::get_string() -> monad<fstring>
    {   monad<fstring> result;
        if (type == e_primitive::string_)
        {   result.value = string_;
        }
        else
        {   result.error = true;
        }
        return result;
    }

    CONSTRUCTOR dynamic_primitive::dynamic_primitive()
    {   memory_zero_raw( this, sizeof(dynamic_primitive));
    }

    CONSTRUCTOR dynamic_primitive::dynamic_primitive( const dynamic_primitive& arg )
    {   memory_zero_raw( this, sizeof(dynamic_primitive));
        copy_from( arg );
    }

    PROC dynamic_primitive::operator= ( const dynamic_primitive& rhs ) -> dynamic_primitive&
    {   return copy_from( rhs );
    }

    PROC dynamic_primitive::operator= ( const fstring& rhs ) -> dynamic_primitive&
    {   clean_old();
        new(&string_) fstring { rhs };
        type = e_primitive::string_;
        return *this;
    }

    PROC dynamic_primitive::copy_from( const dynamic_primitive& rhs ) -> dynamic_primitive&
    {
        clean_old();
        if (rhs.type == e_primitive::string_)
        {   new(&string_) fstring { rhs.string_ };
            type = e_primitive::string_;
        }
        else
        {   memory_copy<const dynamic_primitive>( this, &rhs, 1 );
        }
        return *this;
    }

    DESTRUCTOR dynamic_primitive::~dynamic_primitive()
    {
        clean_old();
    }

    PROC dynamic_primitive::clean_old() -> void
    {
        if (type == e_primitive::string_)
        {   string_.~fstring();
        }
        memory_zero_raw( &this->_buffer, 32);
    }

}

// /** Overriding new makes address sanitizer complain */
#if (REFLECTION_ADDRESS_SANITIZER)
// void*
// ::operator new( usize bytes )
// {
//     using namespace tyon;
//     void* result = nullptr;
//     // g_taint_allocator_lock.lock();

//     // g_taint_allocator_lock.unlock();
//     result = malloc( bytes );
//     return result;
// }

// void*
// ::operator new[]( usize bytes )
// {
//     using namespace tyon;
//     void* result = nullptr;
//     // g_taint_allocator_lock.lock();
//     // g_taint_allocator->allocate_raw( bytes );

//     // g_taint_allocator_lock.unlock();
//     result = malloc( bytes );
//     return result;
// }

// void
// ::operator delete(void* ptr) noexcept
// {
//     using namespace tyon;
//     if (ptr == nullptr) { return; }
//     // g_taint_allocator_lock.lock();

//     // g_taint_allocator_lock.unlock();
//     free( ptr );
// }


#endif // REFLECTION_ADDRESS_SANITIZER
