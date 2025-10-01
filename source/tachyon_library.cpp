
/** This file provides project agnostic types and utility functions, in theory
 * this can ripped out and relocated to another project by only changing a line or
 * two. Or none. */

#include "include_core.h"

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
    asset g_asset_stub = {};
    asset_machine* g_asset = nullptr;

    null_type null;

    // -- Memory Management Library --

    constexpr isize
    binary_padding( isize padding, isize size )
    { return (padding - (size % padding) % padding); }

    isize
    binary_alignment( isize padding, void* target )
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

    void
    memory_poison( void* address, isize size )
    {
        (void)address; (void)size;
#if (defined(__SANITIZE_ADDRESS__))
        __asan_poison_memory_region( address, size );
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
    }

    void memory_stack_allocator::operator= ( const memory_stack_allocator& )
    {}

    raw_pointer memory_stack_allocator::allocate_raw( isize bytes )
    {
        isize size = (bytes);
        isize type_size = 1;
        buffer* block = &(blocks.back());
        isize alignment = binary_alignment( 1, block->data + block->head_size );
        void* head_data = (block->data + block->head_size + alignment);
        void* result = nullptr;

        bool size_exceeded = ((alignment + block->head_size + size) > block->size);
        if (size_exceeded)
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
            alignment = binary_alignment( 1, head_data );
            head_data = (block->data + block->head_size + alignment);

            if (new_block.data == nullptr) { return nullptr; }
        }

        // Allocate the new memory
        memory_unpoison( head_data, size );
        result = reinterpret_cast<void*>( head_data );
        block->head_size += (alignment + size);
        churn_bytes += size;
        ++churn;
        ++allocations;

        return result;
    }

    PROC memory_stack_allocator::allocate_raw_fast( i64 bytes ) -> raw_pointer
    {
        buffer* block = &(blocks.back());
        return (block->data + block->head_size);
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

    PROC resource_arena::push_cleanup( cleanup_delegate arg ) -> void
    {
        destroy_stack.push_tail( arg );
    }

    // Resource Library
    DESTRUCTOR resource_arena::~resource_arena()
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
    }

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
        profiler_log( buffer, "[" + name + "]", description );
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
            profiler_log( buffer, "[" + name + "]", description );
        }
    }

    // -- Threading Library --

    // -- Type Support Library --
    constexpr CONSTRUCTOR uid::uid( i64 _id, u128 _uuid ) : id( _id ), uuid( _uuid ) {}
    uid::operator i64() { return id; }

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
        new_file = fopen( file_string.c_str(), "r" );
        if (new_file == nullptr)
        {
            log( "File", "Failed to open file: ", target );
            return result;
        }

        fseek( new_file, 0, SEEK_END );
        filesize = ftell( new_file );
        if (filesize <= 0)
        {
            log( "File", "WARNING, opened file is zero length" );
            fclose( new_file );
            return result;
        }

        // Return to beginning
        fseek( new_file, 0, SEEK_SET );

        result.memory.data = allocator->allocate_raw( filesize );
        if (result.memory.data == nullptr)
        { log ( "File", "Failed to allocate memory for read operation", target ); }
        result.memory.size = filesize;

        isize read_size = fread( result.memory.data, sizeof(byte), result.memory.size, new_file );
        ERROR_GUARD( read_size == result.memory.size,
                     "Something is amiss if we read a different amount than we sized for." );
        log( "File", "Loaded whole file at path: ", target );
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
        FILE* file_ = fopen( filename.c_str(), "w" );
        ERROR_GUARD( file_, "Failed to open file" );
        u64 bytes_written = fwrite( arg->memory.data, 1, arg->memory.size, file_ );
        bool write_ok = (i64(bytes_written) >= arg->memory.size);

        // Cleanup
        fclose( file_ );
        if (write_ok)
        { tyon_log( fmt::format( "Wrote binary file '{}'", arg->filename ) ); }
        else
        { log_error_format( "Tachyon", "Failed to write binary file '{}'", arg->filename  ); }
        ERROR_GUARD( write_ok, "File wrote less than full data or failed" );

        return write_ok;
    }

    // -- Asset Library --

    void
    asset_machinery_init()
    {
        i32 iteration_limit = 1000;
        fpath self_directory = file_self_directory();
        g_asset->search_paths.change_allocation( 20 );
        g_asset->assets.change_allocation( 100 );

        g_asset->search_paths.push_tail( self_directory );

        fpath x_path;
        fpath x_filename;
        fs::directory_entry x_entry;
        for (i32 i_search=0; i_search < g_asset->search_paths.head_size; ++i_search)
        {
            x_path = g_asset->search_paths[i_search];
            if (fs::is_directory( x_path ) == false) { continue; }
            auto iterator = fs::recursive_directory_iterator( x_path );
            for (i32 i_file=0; i_file < iteration_limit; i_file++)
            {
                if (iterator == fs::end( iterator)) { break; }
                x_entry = *iterator;
                x_filename = x_entry;
                if (x_entry.is_regular_file())
                {
                    asset new_asset;
                    new_asset.file.filename = x_filename;
                    new_asset.name = x_filename.filename().string();
                    g_asset->assets.push_tail( new_asset );
                }
                iterator++;
            }
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
        ERROR_GUARD( result, "Failed to load asset" );
        bool new_asset = (result == nullptr);
        if (new_asset)
        {
            g_asset->assets.push_back( asset{} );
            result = g_asset->assets.get_tail_address();
            result->file.filename = filename;
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
        if (arg->loaded == false)
        {
            result = arg->loader( arg );
        }
        if (result)
        {
            log_format( "TYON Asset", "Successfully loaded file {} at path '{}' using loader '{}'",
                        arg->name, arg->file.filename, arg->loader_name );
        }
        else
        {
            log_error_format( "TYON Asset", "Failed to load file {} at path '{}' using loader '{}'",
                              arg->name, arg->file.filename, arg->loader_name );
        }
        return result;
    }

    // -- Logging --

    void
    logger::write_error_simple( fstring message )
    {
        this->messages.append( message );

        // Write to log file if possible
        if (log_file == nullptr)
        { log_file = fopen( "latest.log", "w" ); }
        if (log_file)
        { fwrite( message.data(), 1, message.size(), log_file ); }

        // Ensure file has synchronized messages before proceeding
        fflush( log_file );
        if (console_output_enabled)
        {
            fmt::print( fmt::emphasis::bold | fmt::fg(fmt::color::red), "{}", message );
        }
    }

    PROC logger::write_message( fstring category, fstring message, e_log_entry type ) -> void
    {
        PROFILE_SCOPE_FUNCTION();
        std::scoped_lock _lock( write_lock );

        log_entry& entry = entries.push_tail( {} );
        entry.type = type;
        entry.category = category;
        entry.message = message,
        entry.timestamp = time_now_utc();

        // Write to log file if possible
        if (log_file == nullptr)
        { log_file = fopen( "latest.log", "w" ); }
        if (log_file)
        { fwrite( message.data(), 1, message.size(), log_file ); }

        fflush( log_file );
        if (console_output_enabled)
        {
            i64 nanoseconds = time_to_epoch_nanoseconds( entry.timestamp );
            u64 category_size = category.size();
            fstring padding;

            g_log_largest_category = u32(category_size > g_log_largest_category ?
                                         category_size :
                                         g_log_largest_category);
            padding.insert( 0, (g_log_largest_category - category_size) + 4, ' ');
            fmt::print( "[{}][{}] {} \n", nanoseconds, entry.category, entry.message );
        }
    }

    void
    library_context_init( library_context* arg )
    {
        if (arg->initialized)
        {
            printf( "library has already been initialized but 'library_context_init'"
                    "was called again" );
            TYON_BREAK();
        }
        g_program_epoch = time_now();
        g_allocator = &arg->global_allocator;
        g_allocator_lock = &arg->global_allocator_lock;
        // g_taint_allocator_lock = &arg->taint_allocator_lock;
        g_logger = &arg->default_logger;

        // Using logging, needs to run after logging setup
        g_little_endian = test_little_endian();
        // Use malloc on purpose to take advantage of virtual memory
        g_null_read = reinterpret_cast<byte*>( malloc( 1'000'000'000 ) );
        g_null_write = reinterpret_cast<byte*>( malloc( 1'000'000'000 ) );

        // Finished!
        arg->initialized = true;
    }

    // -- Platform Library --

    fresult
    FUNCTION test_little_endian()
    {
        fuint16 full_bits = 1;
        fuint8 first_bits = *reinterpret_cast<fuint8*>( &full_bits );
        bool little_endian = static_cast<bool>( first_bits );

        log(
            "Platform",
            (little_endian ? "Platform tested for endianess, came back as little endian" :
             "Platform tested for endianess, came back as big endian")
            );
        return little_endian;
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
