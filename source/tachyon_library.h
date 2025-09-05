
#pragma once

/// Internal dependencies
// #include <atomic>
// #include <vector>
// #include <cstdlib>
// #include <cstring>
// #include <thread>
// #include <mutex>

namespace tyon
{
    // Alias namespace
    namespace chrono = std::chrono;
    using namespace std::chrono_literals;

    /// Has no time period adjustments, is most accurate for time measurements
    using monotonic_time = chrono::time_point< chrono::steady_clock >;
    /// Calender time from system_clock
    using date_time = chrono::time_point< chrono::system_clock >;

    // Pointless, has very close to no consistent implementation
    // using time_utc = chrono::time_point< chrono::utc_clock >;
    /// Atomic Time
    // using time_tai = chrono::time_point< chrono::tai_clock >;
    // using time_gps = chrono::time_point< chrono::gps_clock >;

    /// Has no time period adjustments, is most accurate for time measurements
    using time_monotonic = chrono::time_point< chrono::steady_clock >;
    /// Calender time from system_clock
    using time_date = chrono::time_point< chrono::system_clock >;

    // Error reporting type
    using fresult = bool;

    FORWARD struct memory_stack_allocator;
    FORWARD struct null_type;
    FORWARD struct raw_pointer;
    FORWARD struct uid;
    FORWARD struct u128;
    FORWARD struct asset;
    FORWARD struct asset_type_data;
    FORWARD struct asset_machine;
    FORWARD template<typename t_signature> struct generic_procedure;
    FORWARD template <typename T> struct array;

    // -- Globals Variables --
    // make sure to initialize Pointer Types before using
    extern tyon::time_monotonic g_program_epoch;
    extern bool g_little_endian;
    extern i32 g_log_largest_category;
    extern memory_stack_allocator* g_allocator;
    extern memory_stack_allocator* g_taint_allocator;
    extern std::mutex* g_allocator_lock;
    extern std::mutex g_taint_allocator_lock;
    constexpr isize memory_default_block_size = 268'435'456;

    extern asset g_asset_stub;
    extern asset_machine* g_asset;

    extern null_type null;

    struct raw_pointer
    {
        byte* data = nullptr;

        inline TYON_FORCEINLINE
        COPY_CONSTRUCTOR raw_pointer()
        {}

        inline TYON_FORCEINLINE
        COPY_CONSTRUCTOR raw_pointer( raw_pointer& rhs )
        { this->data = rhs.data; }

        inline TYON_FORCEINLINE
        CONSTRUCTOR raw_pointer( void* rhs )
        { this->data = reinterpret_cast<byte*>(rhs); }

        inline byte&
        operator [] ( i64 arg)
        { return data[arg]; }

        /** return the address as if 'arg' is added using pointer arithmatic */
        template <typename T>
        T*
        stride( i64 arg )
        {
            T* base = reinterpret_cast<T*>( data );
            return  (base + arg);
        }

        /** Index using the stride of sizeof(T)
         *
         * This means treating the adress as a pointer of type 'T' and accessing it as if
         * it were an array using 'arg' as the index. */
        template <typename T>
        T&
        stride_as( i64 arg )
        { return reinterpret_cast<T*>(data)[arg]; }

        /* 'reinterpret_cast' value pointed to by 'data' as type 'T'.
         *
         * This is a conventience function to make it easier to do
         * type-casting. Since this is a raw pointer it carries no sense of
         * typing information. So we don't, and cannot possibly do "type-safe"
         * conversions. */
        template <typename T>
        TYON_FORCEINLINE T&
        as()
        { return *reinterpret_cast<T*>(data); }

        TYON_FORCEINLINE u32&
        as_u32()
        { return *reinterpret_cast<u32*>(data); }

        TYON_FORCEINLINE u64&
        as_u64()
        { return *reinterpret_cast<u64*>(data); }

        TYON_FORCEINLINE u128&
        as_u128()
        { return *reinterpret_cast<u128*>(data); }

        /** De-reference the data as if it were a byte */
        TYON_FORCEINLINE byte&
        operator * ()
        { return (*data); }

        /** Perform pointer arithmatic, 1 unit is a byte */
        raw_pointer
        operator + ( i64 rhs )
        { return raw_pointer { data + rhs }; }

        /** Perform pointer arithmatic, 1 unit is a byte */
        void
        operator += ( i64 rhs )
        { this->data += rhs; }

        /** Perform pointer arithmatic, 1 unit is a byte */
        raw_pointer
        operator - ( i64 rhs )
        { return raw_pointer { data - rhs }; }

        /** Perform pointer arithmatic, 1 unit is a byte */
        void
        operator -= ( i64 rhs )
        { this->data -= rhs; }

        /** Perform pointer arithmatic, increment by 1, 1 unit is a byte */
        raw_pointer
        operator ++ ()
        { this->data += 1; return *this; }

        /** Post-Fix Operator pointer arithmatic, 1 unit is a byte */
        raw_pointer
        operator ++ ( i32 )
        {
            raw_pointer result = *this;
            this->data += 1;
            return result;
        }

        /* Convert to 'void*'.
         *
         * This makes this a full primitive replacement */
        inline
        operator void* ()
        { return data; }

        /* Convert to any pointer
         *
         * This provides behaviour similar to C's 'void*'. Where it is a generic
         * pointer interchangible with any other pointer. */
        template <typename T>
        inline
        operator T* ()
        { return reinterpret_cast<T*>( data ); }

        /* Allow comparison to nullptr like 'void*' */
        inline bool
        operator == ( std::nullptr_t rhs )
        { return data == nullptr; }
    };

    // -- Math Constants --
    constexpr f64 tau_ = 6.283185307;
    constexpr f64 pi_ = 3.141592653589793;

    // -- Basic Utilities --
    #define tyon_print( ... ) log(  __FILE__, __VA_ARGS__ )

    template<typename... t_formattable>
    void
    FUNCTION log( const char* category, t_formattable... messages )
    {
        u64 category_size = strlen( category );
        fstring padding;
        g_log_largest_category = u32(category_size > g_log_largest_category ? category_size :
                                          g_log_largest_category);
        padding.insert( 0, (g_log_largest_category - category_size) + 4, ' ');

        fstring partial;
        partial.reserve( 100 );
        FOLD((partial += fmt::format( "{} ", messages ) ), ...);
        fstring full = fmt::format( "[{}]{}{}\n", category, padding, partial );
        bool output_enabled = 1;
        if (output_enabled)
        {
            // std::cout << "[" << category << "]" << padding;
            // ((std::cout << messages  << " "), ...) << "\n";
            fmt::print( "{}", full );
            // fmt::print(  );
        }
    }

    template<typename... t_formattable>
    void
    FUNCTION log_format_impl( const char* category, fstring message )
    {
        u64 category_size = strlen( category );
        fstring padding;
        g_log_largest_category = u32(category_size > g_log_largest_category ?
                                           category_size :
                                           g_log_largest_category);
        padding.insert( 0, (g_log_largest_category - category_size) + 4, ' ');

        fstring full = fmt::format( "[{}]{}{} \n", category, padding, message );
        bool output_enabled = 1;
        if (output_enabled)
        {
            fmt::print( "{}", full );
        }
    }
    #define log_format( CATEGORY_, FORMAT_, ...)                      \
        log_format_impl( (CATEGORY_), fmt::format( (FORMAT_), __VA_ARGS__ ) );

    template<typename... t_formattable>
    void
    FUNCTION log_error_format_impl( const char* category, fstring message )
    {
        u64 category_size = strlen( category );
        fstring padding;
        g_log_largest_category = u32(category_size > g_log_largest_category ?
                                     category_size :
                                     g_log_largest_category);
        padding.insert( 0, (g_log_largest_category - category_size) + 4, ' ');

        fstring full = fmt::format( "[{}]{}{} \n", category, padding, message );
        bool output_enabled = 1;
        if (output_enabled)
        {
            fmt::print( fmt::emphasis::bold | fmt::fg(fmt::color::red), "{}", full );
        }
    }
    /** We setup as a macro so that fmtlib can statically compile the string
     * then pass it along to the actual implimentation that is runtime. */
    #define log_error_format( CATEGORY_, FORMAT_, ...) \
        log_error_format_impl( (CATEGORY_), fmt::format( (FORMAT_), __VA_ARGS__ ) );

    // #define log_flush() std::cout.flush()
    #define log_flush() fflush( stdout );
    #define tyon_log( ... ) log( "TYON", __VA_ARGS__);
    #define tyon_logf( format_string, ... ) log_format( "TYON", format_string, __VA_ARGS__ );
    #define tyon_log_error( message )                                           \
            log_error_format( "TYON Error", "{} @ {}:{}: {}",                   \
                          __FUNCTION__, __FILE__, __LINE__, message );          \
        log_flush();

    // Like log_error but shorter name
    #define tyon_error( message )                                       \
        log_error_format( "TYON Error", "{} @ {}:{}: {}",               \
                          __FUNCTION__, __FILE__, __LINE__, message );  \
        log_flush();

    #define tyon_errorf( format_string, ... )                   \
        log_error_format( "TYON ERROR", format_string, __VA_ARGS__ );

    #define tyon_variable( var ) log_format( "TYON", #var" [ {} ]", var );
    #define tyon_logf_error( format_string, ... )                   \
        log_error_format( "TYON ERROR", format_string, __VA_ARGS__ );
    #define profiler_log( ... ) log( "TYON Profiler", __VA_ARGS__);

    #define TYON_UNSUPPORTED()
    #define TYON_NOP() void(0);
    #define TYON_UNIMPLIMENTED();
    #define TYON_TESTING( x ) x;
    #define TYON_TODO( explanation );

    /** Make sure condition is true or break and show message
     * It's an assert. okay. */
    #define ERROR_GUARD( condition, message )                                   \
        if ( !(condition) )                                                     \
        {                                                                       \
            log_error_format( "Error Guard", "{} @ {}:{}: Condition: ({}): {}", \
                __FUNCTION__, __FILE__, __LINE__, #condition, message );        \
            log_flush();                                                        \
            TYON_BREAK();                                                       \
        };

    // #define ERROR_GUARD( condition, message ) \
    //     if (!(condition)) \
    //     { \
    //         printf( "\e[0;31m[Error Guard]    %s @ %s:%d: Condition: (%s): %s \e[0m \n", \
    //             __FUNCTION__, __FILE__, __LINE__, #condition, message );    \
    //         log_flush(); \
    //         TYON_BREAK(); \
    //     };

    #define ERROR_GUARD_NULL( value ) \
        ERROR_GUARD( value != nullptr, "Null pointer was found where it shouldn't be." );

    // -- Memory Management Library --

    constexpr isize
    binary_padding( isize padding, isize size );

    isize
    binary_alignment( isize padding, void* target );

    void
    memory_poison( void*, isize size );

    void
    memory_unpoison( void*, isize size );

    // -- Memory Management Library | Containers --

    struct buffer
    {
        byte* data = nullptr;
        isize size = 0;
        isize head = 0;
        isize head_size = 0;
    };

    namespace protection
    {
        enum type
        {
            read      = (1 << 0),
            write     = (1 << 1),
            execute   = (1 << 2),
            poisioned = (1 << 3),
            encrypted = (1 << 4)
        };
    }
    using e_protection = protection::type;

    struct allocator_info
    {
        isize os_reserved;
        isize os_physical;
        isize user_allocated;
        i64 churn;
        isize churn_bytes;
        i64 allocations;
        i64 deallocations;
        i64 blanked_blocks;
        i64 blocks;
        isize block_size;
        isize os_page_size;
        isize os_large_page_size;
    };

    struct i_allocator
    {
        template <typename T>
        T* allocate( isize count )
        {
            T* result = nullptr;
            i64 size_bytes = (sizeof(T) * count);
            i64 alignment = binary_alignment( alignof(T), result );
            result = allocate_raw( size_bytes + alignment );

            // Default allocate storage
            new(result) T[count] {};
            return result;
        }

        virtual raw_pointer allocate_raw( isize bytes ) PURE;
        virtual void deallocate( void* address ) PURE;
        /** Clear all stored allocations and zero memory */
        virtual void blank_all() PURE;
        virtual allocator_info get_memory_statistics() PURE;
        virtual ~i_allocator() {}
    };
    using i_memory_allocator = i_allocator;

    /** Simplistic stack allocator
     *
     * This allocator is not thread safe. It is not meant for that. **/
    struct memory_stack_allocator : i_memory_allocator
    {
        std::vector<buffer> blocks;

        allocator_info info;
        /// Minimum block size
        isize block_size;
        isize os_page_size;
        /** Churn is a running total of how allocations and deallocations occur
         * combined. A high churn value is indicative of either a very active
         * program, or excessive allocations without reserving long lived
         * buffers. */
        i64 churn;
        isize churn_bytes;
        i64 allocations;
        i64 deallocations;
        i64 blanked_blocks;

        CONSTRUCTOR memory_stack_allocator( isize _block_size = memory_default_block_size );
        COPY_CONSTRUCTOR memory_stack_allocator( const memory_stack_allocator& ) = delete;

        void operator= ( const memory_stack_allocator& );

        template <typename T>
        T*
        allocate( isize count )
        {
            isize size = (count * sizeof(T));
            isize type_size = sizeof(T);
            buffer* block = &(blocks.back());
            isize alignment = binary_alignment( alignof(T), block->data + block->head_size );
            void* head_data = (block->data + block->head_size + alignment);
            T* result = nullptr;

            bool size_exceeded = ((alignment + block->head_size + size) > block->size);
            if (size_exceeded)
            {
                buffer new_block;
                isize allocation = (block_size * ceil(f32(size) / block_size));
                new_block.data = reinterpret_cast<byte*>(std::malloc( allocation ));
                new_block.size = allocation;
                new_block.head = 0;
                new_block.head_size = 0;

                // Force pages into memory
                std::memset( new_block.data, 0x0, block_size );
                blocks.push_back( new_block );
                // Fixup stale data
                block = &(blocks.back());
                alignment = binary_alignment( alignof(T), head_data );
                head_data = (block->data + block->head_size + alignment);

                if (new_block.data == nullptr) { return nullptr; }
            }

            // Allocate the new memory
            memory_unpoison( head_data, size );
            result = reinterpret_cast<T*>( head_data );
            block->head_size += (alignment + size);
            // Default construct objects in-place
            new( result ) T[count] {};
            churn_bytes += size;
            ++churn;
            ++allocations;

            // TracyAlloc( result, alignment + size );
            return result;
        }

        raw_pointer allocate_raw( isize bytes ) override;

        void
        deallocate( void* address ) override;

        /** Zero and clear all blocks allocations and fixup bookkeeping */
        void
        blank_all() override;

        allocator_info
        get_memory_statistics() override;

        DESTRUCTOR ~memory_stack_allocator() override;
    };

    fstring
    format_as( allocator_info arg );

    /** Allocate physical memory, not virtual.
        This has to be declared lower than the containers because of compilation ordering.
        This function is thread safe.

        Allocations from this don't need to be freed, but if you do want to free at
        a certain time, you should create a 'memory_stack_allocator' object in a
        scope that's convenient. It will deallocate on scope exit. */
    template <typename T>
    T*
    memory_allocate( isize count )
    {
        if (count <= 0) { return nullptr; }
        std::scoped_lock lock( *g_allocator_lock );
        return g_allocator->allocate<T>( count );
    }

    /** Allocate physical memory, not virtual.
     * This function is thread safe.
     *
     * Allocations from this don't need to be freed, but if you do want to free at
     * a certain time, you should create a 'memory_stack_allocator' object in a
     * scope that's convenient. It will deallocate on scope exit. */
    raw_pointer
    memory_allocate_raw( usize size );

    // Removes an object from scope, essentially calling it's destructor if sensible
    template <typename t_movable>
    constexpr void
    FUNCTION drop( t_movable doomed )
    {
        auto _ = std::move( doomed );
    }

    bool
    memory_zero_raw( void* target, i64 bytes );

    template <typename t_ptr>
    bool
    memory_zero( t_ptr target, i64 count)
    {
        using T = decltype(*target);
        std::memset( target, 0x0, count * sizeof(T) );
        return true;
    }

    void
    FUNCTION memory_copy_raw( void* dest, const void* src, u64 bytes);

    template <typename T>
    void
    FUNCTION memory_copy( void* dest, T* src, u64 count)
    {
        memcpy( dest, src, count* sizeof(T) );
    }

    /** Type unsafe variant of 'memory_copy' */
    template <typename T>
    void
    FUNCTION memory_copy_unsafe( void* dest, void* src, u64 count )
    {
        memcpy( dest, src, count* sizeof(T) );
    }

    template <typename T>
    bool
    FUNCTION memory_compare( T& a, T& b )
    {
        return std::memcmp( &a, &b, sizeof(T) );
    }

    template <typename T>
    bool
    FUNCTION memory_same( T& a, T& b )
    {
        return std::memcmp( &a, &b, sizeof(T) );
    }

    template <typename T>
    bool
    FUNCTION memory_different( T* a, T* b )
    {
        using t_value = decltype(*a);
        return std::memcmp( a, b, sizeof(t_value) );
    }

    template <typename T>
    isize
    memory_align_typed( isize count, i32 alignment )
    {
        isize bytes = (count * sizeof(T));
        return (bytes + (alignment - (bytes % alignment)));
    }

    TYON_FORCEINLINE isize
    memory_align( isize bytes, i32 alignment );

    // -- Container Types --

    template <typename t_any>
    struct pointer final
    {
        using t_self = pointer<t_any>;
        t_any* data = 0x0;
        /** This denotes the allocator the memory belongs to. If it belongs to
            an allocator it can arbitrarily relocate the data pointer, so don't
            copy it to a raw pointer. Pointers managed this was are trivially
            serializable 0x0. allocator means system memory */
        i_memory_allocator* allocator = 0x0;
        t_self* next = nullptr;
        /** This is the primary manager for the underlying object and will propagate
            changes correctly where required */
        bool manager = false;
        /** When true this will call the destructor of the managed resource when done */
        bool scoped_resource = false;
        /** If another pointer is copied to the current pointer it is considered
            weakly shared, and is at the mercy any reallocaitons and destruction the
            other pointer. If the pointer changed it will be reflected in weakly
            shared pointers */
        bool weakly_shared = false;
        /** If a raw pointer absolutely needs access to a smart pointer, like
            through sysaclls, it will have to be bound in-place, so it shouldn't realloc or
            be destroyed for as long as possible, such pointers are marked as borrowed */
        bool borrowed = false;

        TYON_FORCEINLINE t_any&
        operator *() { return (*data); }
        TYON_FORCEINLINE t_any&
        operator []( isize i ) { return data[i]; }

        TYON_FORCEINLINE
        CONSTRUCTOR pointer( std::nullptr_t rhs )
        {
            this->data = rhs;
            this->next = nullptr;
            this->allocator = 0x0;
            this->weakly_shared = false;

            propagate_data();
        }

        template <typename t_other>
        TYON_FORCEINLINE t_self&
        operator =( pointer<t_other>& rhs )
        {
            this->data = reinterpret_cast<t_any*>( rhs.data );
            this->allocator = reinterpret_cast<t_any*>( allocator );
            this->weakly_shared = true;
            int share_cap = 100;

            this->next = rhs.next;
            rhs.next = this;
            propagate_data();
            return *this;
        }

        TYON_FORCEINLINE t_self&
        operator =( t_any* rhs )
        {
            this->data = rhs;
            this->next = nullptr;
            this->allocator = 0x0;
            this->weakly_shared = false;

            propagate_data();
            return *this;
        }

        CONVERSION operator t_any*()
        { return data; };

        /** Destroys scoped resources if necessary
            If the pointer needs to be invalidated for any reason this should be
            done manually before the smart pointer goes out of scope. With unscoped
            resources weak pointers remain valid until the external memory manager
            cleans it up */
        DESTRUCTOR ~pointer()
        {
            if (scoped_resource) { delete data; data = nullptr; propagate_data(); }
        }

        void
        FUNCTION propagate_data()
        {
            if (manager == false) { return; }
            t_self* x_ptr = next;

            int share_cap = 100;
            for (int i=0; i<share_cap; ++i)
            {
                if (x_ptr == nullptr) { break; }
                x_ptr = x_ptr->next;
                x_ptr->data = this->data;
                x_ptr->allocator = allocator;
            }
        }
    };

    template <typename T>
    struct search_result
    {
        T* match = nullptr;
        i64 index = -1;
        bool match_found = false;
    };

    template <typename t_key, typename t_value>
    struct generic_search_result
    {
        t_value* match = nullptr;
        array<t_value*> matches = nullptr;
        t_key key = {};
        bool match_found = false;
    };

    template <typename T>
    struct array
    {
        using t_self = array<T>;
        pointer<T> data = nullptr;
        isize size_ = 0;
        isize head = 0;
        isize head_size = 0;
        bool bounded = true;
        // Enforce RAII
        bool autofree = true;
        /** Only do operations on the active array portion, ie head to
            tail. This makes memory management manual, DON'T use this if you
            have no idea how you're managing memory.

        TODO: Not implemented fully yet*/
        bool active_range = true;

        bool
        change_allocation( i_memory_allocator* allocator, isize count )
        {
            data.allocator = allocator;
            return change_allocation( count );
        }

        /** Reallocates data into new storage and default constructs objects

            it uses the storage allocator, or 'g_allocator' if none is provided
         */
        bool
        change_allocation( isize count )
        {
            i_memory_allocator* allocator = (data.allocator ? data.allocator : g_allocator);
            T* new_storage = allocator->allocate_raw( count * sizeof(T) );
            ERROR_GUARD( new_storage != nullptr, "Allocation failed" );
            new(new_storage) T[count] {};
            if (data)
            {
                for (i32 i=0; i < std::min( size_, count ); ++i )
                {
                    new_storage[i] = std::move( data[i] );
                }
                allocator->deallocate( data );
            }
            if (new_storage)
            {
                data = new_storage;
                size_ = count;
                head = std::min( head, count );
                head_size = std::min( head_size, count );
            }
            else
            { return false; }
            return true;
        }

        bool
        change_allocation_raw( isize count )
        {
            i_memory_allocator* allocator = (data.allocator ? data.allocator : g_allocator);
            T* new_storage = reinterpret_cast<T*>( allocator->allocate_raw( count * sizeof(T) ) );
            ERROR_GUARD( new_storage != nullptr, "Allocation failed" );
            if (data)
            {
                memory_copy( new_storage, data.data, std::min( size_, count ) );
                allocator->deallocate( data );
            }
            if (new_storage)
            {
                data = new_storage;
                size_ = count;
                head = std::min( head, count );
                head_size = std::min( head_size, count );
            }
            else
            { return false; }
            return true;
        }

        bool
        FUNCTION allocate( i_memory_allocator* allocator, isize count )
        {
            // BROKEN
            data = allocator->allocate_raw( count * sizeof(T) );
            size_ = count;
            head_size = std::min( head_size, count );
            return (data != nullptr);
        }

        template<typename t_allocator>
        bool
        FUNCTION deallocate( t_allocator* allocator )
        {
            allocator->deallocate( data );
            size_ = 0;
            head_size = 0;
            head = 0;

            return true;
        }

        /// Pushes an new before the 'head' index and decrements the 'head'
        bool
        FUNCTION push_head( T item )
        {
            if (bounded && (head <= 0)) { return false; }
            data[ --head ] = item;
            ++head_size;
            return true;
        }

        /// Pushes a new item at off the tail (head + head_size) and increments 'head_size'
        T&
        FUNCTION push_tail( T item )
        {
            if (bounded && (head + head_size >= size_))
            {
                bool resize_ok = change_allocation( std::max<isize>(size_, 1) * 2 );
                ERROR_GUARD( resize_ok, "Serious error has occured if a resize failed" );
            }
            i64 index = head + (head_size++);
            data[ index ] = item;
            return data[ index ];
        }

        /// Pushes a new item at off the tail (head + head_size) and increments 'head_size'
        bool
        FUNCTION push_tail_unbounded( T item )
        {
            ERROR_GUARD(head + head_size < size_, "Tried to push outside of allocated capacity" );
            if (bounded && (head + head_size >= size_))
            { return false; }
            data[ head + (head_size++) ] = item;
            return true;
        }

        T
        FUNCTION pop_head()
        {
            if (bounded && (head_size = 0)) { return false; }
            T result = data[ head++ ];
            --head_size;
            return result;
        }

        T
        FUNCTION pop_tail( T item )
        {
            if (bounded && (head_size = 0)) { return false; }
            T result = data[ head + head_size - 1 ];
            --head_size;
            return result;
        }

        T&
        FUNCTION get_tail()
        { return data[ head+head_size -1 ]; }

        T*
        get_tail_address()
        { return (data + head+head_size -1); }

        T&
        operator []( isize i )
        {
            ERROR_GUARD( (i >= 0) || (i < size_), "Tried to access index ouside of bounds" );
            return data[std::clamp<i64>( i, 0, size_ )];
        }

        t_self
        COPY_ASSIGNMENT operator =( t_self rhs )
        {
            rhs.change_allocation( this->size_ );
            rhs.head_size = this->size_;
            for (i32 i=0; i < this->size_; ++i )
            {
                rhs.data[i] = data[i];
            }
            return *this;
        }

        /// Set memory of array to read only and employ data integrity checks
        void
        FUNCTION protect()
        {
            // Crash
            *(char*)0 = 1;
        }

        /** Zero from 0 to 'head_size' memory and set head and tail to zero. */
        void
        reset()
        {
            // Default init old
            new(data) T[head_size]{};
            head_size = 0;
        }

        void
        clear()
        {
            // Default init old
            new(data) T[size_]{};
        }

        // std::vector compat
        void
        FUNCTION push_back( T item )
        {
            push_tail( item );
        }

        void
        FUNCTION reserve( usize count )
        {
             change_allocation( isize(count) );
        }

        usize
        FUNCTION size()
        {
            return head_size;
        }

        // Search from 0 to 'size'
        search_result<T>
        FUNCTION linear_search( generic_procedure<bool(T&)> comparator )
        {
            search_result<T> result;
            for (i64 i=0; i < size_; ++i)
            {
                if (comparator( data[i] ))
                {
                    result.match = &(data[i]);
                    result.index = i;
                    result.match_found = true;
                    break;
                }
            }
            return result;
        }

         // Search from 0 to 'size'
        search_result<T>
        FUNCTION linear_search_value( T comparison )
        {
            search_result<T> result;
            for (i64 i=0; i < size_; ++i)
            {
                if (comparison ==data[i])
                {
                    result.value = &(data[i]);
                    result.index = i;
                    result.match_found = true;
                    break;
                }
            }
            return result;
        }

        // Search from head to tail
        search_result<T>
        FUNCTION linear_search_head( generic_procedure<bool(T&)> comparator )
        {
            search_result<T> result;
            for (i64 i=head; i < head_size; ++i)
            {
                if (comparator( data[i] ))
                {
                    result.value = &(data[i]);
                    result.index = i;
                    result.match_found = true;
                    break;
                }
            }
            return result;
        }

        // Search from head to tail
        search_result<T>
        FUNCTION linear_search_head_value( T comparison )
        {
            search_result<T> result;
            for (i64 i=head; i < head_size; ++i)
            {
                if (comparison == data[i])
                {
                    result.value = &(data[i]);
                    result.index = i;
                    result.match_found = true;
                    break;
                }
            }
            return result;
        }

        void
        cleanup()
        {
            i64 start_i = (active_range ? head : 0);
            i64 end_i = (active_range ? size_ : (head + head_size));
            for (i64 i=start_i; i < end_i; ++i )
            { this->data[i].~T(); }
        }

        DESTRUCTOR ~array()
        {
            if (this->autofree) { this->cleanup(); }
        }

        struct stl_iterator
        {
            using iterator_category = std::bidirectional_iterator_tag;
            using difference_type   = i64;
            using value_type        = T;
            using pointer           = T*;  // or also value_type*
            using reference         = T&;  // or also value_type&

            array<value_type>* context = nullptr;
            pointer data = nullptr;
            i64 offset = 0;

            reference operator *() { return *(data +offset); }
            pointer operator->() { return (data +offset); }
            stl_iterator& operator++() { ++offset; return *this; }
            stl_iterator& operator++(int)
            {
                stl_iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            friend bool operator==( stl_iterator& rhs, stl_iterator& lhs )
            { return rhs.data == lhs.data; }

            /** True iterator if has no reached passed tail index. End iterators
             * are invalid to dereference */
            operator bool() { return (offset < context->head_size); }
        };

        stl_iterator begin() { return stl_iterator{ this, data.data, 0 }; }
        stl_iterator end() { return stl_iterator{ this, data.data, head_size }; }
    };


    template <typename T>
    struct ntree_node
    {
        // uid id;
        ntree_node* parent;
        array< ntree_node<T>*> children;
        T value;
    };

    template <typename T>
    struct n_tree
    {
        using node = ntree_node<T>;
        node* data;
        isize size;
        // The absolute parent of all, might be imaginary
        node* root_node;
        // Where this particular tree starts from, doesn't change anything, just convenience
        node* start_node;
        i32 max_depth;
        i32 max_breadth;

        DESTRUCTOR ~n_tree()
        {
            for (i32 i=0; i < this->size; ++i)
            {
                // this->data[i].children.deallocate();
            }
        }
    };

    // -- Time Library --

    /** Returns a high precision, clock update unaffected time point.

     This should usually be derived from the RDTSC or a similar high precision time soruce. */
    monotonic_time
    FUNCTION time_now();

    time_date
    FUNCTION time_now_utc();

    template <typename t_numeric = f32>
    u64
    FUNCTION time_now_utc_seconds()
    {
        using t_duration = chrono::duration<t_numeric, std::ratio<1>>;
        t_duration epoch = chrono::system_clock::now().time_since_epoch();
        t_numeric result = chrono::duration_cast< t_duration >( epoch ).count();
        return result;
    }

    template <typename t_numeric>
    u64
    FUNCTION time_now_utc_nanoseconds()
    {
        using t_duration = chrono::duration<t_numeric, std::nano>;
        t_duration epoch = chrono::system_clock::now().time_since_epoch();
        t_numeric result = chrono::duration_cast< t_duration >( epoch ).count();
        return result;
    }

    /// Returns time since program start in a given numeric type
    template<typename t_numeric = f32>
    t_numeric
    FUNCTION time_elapsed_seconds()
    {
        using t_duration = chrono::duration<t_numeric, std::ratio<1>>;
        t_duration elapsed = time_now() - g_program_epoch;
        t_numeric elapsed_conversion = chrono::duration_cast< t_duration >( elapsed ).count();

        return elapsed_conversion;
    }

    /// Returns time since a given time point in a given numeric type
    template <typename t_numeric = f32>
    t_numeric
    FUNCTION time_elapsed_seconds( monotonic_time start)
    {
        using t_duration = chrono::duration<t_numeric, std::ratio<1>>;
        t_duration elapsed = time_now() - start;
        t_numeric elapsed_conversion = chrono::duration_cast< t_duration >( elapsed ).count();

        return elapsed_conversion;
    }

    /// Returns time since a given time point in a given numeric type
    template <typename t_numeric = u64>
    t_numeric
    FUNCTION time_elapsed_nanoseconds( monotonic_time start)
    {
        using t_duration = chrono::duration<t_numeric, std::nano>;
        t_duration elapsed = time_now() - start;
        t_numeric elapsed_conversion = chrono::duration_cast< t_duration >( elapsed ).count();

        return elapsed_conversion;
    }

    /** Periodic timer that allows for triggers at regular intervals
     *
     * By default the timer will just restart when the 'triggered()' is
     * called. With 'drift_compensation = true' the timer will adjust itself to
     * run on fixed intervals since the timer was started, ie if 'update_rate'
     * is 50 ms and the time since the last update is 70 ms, the next update
     * will be 30ms away instead of 50 ms */
    struct time_periodic
    {
        time_monotonic reference_time;
        time_monotonic trigger_time;
        chrono::nanoseconds update_rate;
        /// Descrepency between check time and trigger_time
        chrono::nanoseconds drift;
        /// Inactive timers will never trigger reguardless of how much time has passed
        bool active = false;
        /** Attempt to automatically correct for unstable trigger timing, if the
         * check rate is too slow, or if the timing is off it may skip
         * reasonable triggers. Try to adjust the trigger_time to compensate for
         * this. (UNUSED) */
        bool drift_compensation = false;

        CONSTRUCTOR time_periodic( chrono::nanoseconds _update_rate );

        /// Check to see if timer triggered or not
        bool
        triggered();

        operator bool();
    };

    struct time_stopwatch
    {
        /// How many times the stopwatch was started
        u64 counter = 0;
        chrono::nanoseconds clock = {};
        fstring name;
        fstring description;
        CONSTRUCTOR time_stopwatch( fstring _name, fstring _description );
        DESTRUCTOR ~time_stopwatch();
    };

    FORWARD struct time_scope;
    void procedure_time_scope_stub( time_scope* arg );
    using procedure_time_scope = decltype( &procedure_time_scope_stub );

    /** Scoped class which times and logs a unit
     * Optionally takes a stopwatch and updates it when it exits
     * Alternatively takes a function pointer to call on destruction */
    struct time_scope
    {
        time_stopwatch* stopwatch = nullptr;
        procedure_time_scope destructor = nullptr;
        monotonic_time start;
        fstring name;
        fstring description;

        CONSTRUCTOR time_scope( fstring _name, fstring _description = "" );
        CONSTRUCTOR time_scope( time_stopwatch* _stopwatch );
        CONSTRUCTOR time_scope( procedure_time_scope _destructor );
        DESTRUCTOR ~time_scope();
    };

    #define TYON_CONCAT_IMPL( x, y ) x##y
    #define TYON_CONCAT( x, y ) TYON_CONCAT_IMPL( x, y )

    #define PROFILE_SCOPE( name ) \
        ZoneNamedN( TYON_CONCAT(__tracy, __COUNTER__), (name), true );
    #define PROFILE_SCOPE_FUNCTION()                                                \
        ZoneNamed( TYON_CONCAT(__tracy, __COUNTER__), true );

    #define TIME_SCOPED( name ) \
        auto TYON_CONCAT(_profile_block_, __LINE__) =                               \
            time_scope( (name) , "time taken to execute function");                 \
        ZoneNamedN( TYON_CONCAT(__tracy, __COUNTER__), (name), true );

    // Time the function scope this macro is in and log the result
    #define TIME_SCOPED_FUNCTION() \
        auto TYON_CONCAT(_profile_block_, __LINE__) =                               \
            time_scope( __FUNCTION__ , "time taken to execute function");           \
        ZoneNamed( TYON_CONCAT(__tracy, __COUNTER__), true );

    #define f_TIME_SCOPED_ACCUMULATED( NAME, ID ) \
        {                                                                           \
        static bool _profile_init  = true;                                          \
        if (_profile_init != false)                                                 \
        { global->stopwatches.emplace_back( fstring(NAME),                          \
            fstring("time spent executing in this block across whole runtime") ); } \
            _profile_init = false;                                                  \
        }                                                                           \
        auto _profile_init_##ID = time_scope( &global->stopwatches.back() );

    #define TIME_EXPAND_MACRO( ... ) f_TIME_SCOPED_ACCUMULATED( __VA_ARGS__ )
    #define TIME_SCOPED_ACCUMULATED( NAME ) \
        TIME_EXPAND_MACRO( NAME, __COUNTER__ )
    #define TIME_SCOPED_ACCUMULATED_FUNCTION() \
        TIME_EXPAND_MACRO( __FUNCTION__, __COUNTER__ )

    #define TIME_SCOPED(...)
    #define TIME_SCOPED_FUNCTION(...)
    #define PROFILE_SCOPE(...)
    #define PROFILE_SCOPE_FUNCTION(...)

    // -- Functional Programming Library --

    inline bool function_simple_stub() { return false; }
    using function_simple = decltype( &function_simple_stub );

    inline void function_void_stub() { };
    using function_void = decltype( &function_void_stub );

    template<typename t_signature>
    struct typed_procedure;

    template <typename t_return, typename ... t_args>
    struct typed_procedure< t_return( t_args... ) >
    {
        using t_signature = t_return( t_args... );
        using t_function =  t_return( t_args... );
        using t_function_ptr = t_function*;
        using t_self = typed_procedure<t_function>;

        t_function* data= nullptr;
        bool enabled = false;

        t_self&
        COPY_ASSIGNMENT operator= ( t_function_ptr rhs )
        { assign( rhs ); return *this; }

        void
        assign( t_function* rhs )
        {
            if (rhs != nullptr)
            {
                data = rhs;
                enabled = true;
            }
        }

        t_return
        invoke( t_args... args)
        {
            t_return result = {};
            if (enabled)
            { return data( std::forward<t_args>(args)... ); }
            return result;
        }

        t_return
        operator () ( t_args... args )
        {
            return invoke( std::forward<t_args>(args)... );
        }
    };

    template <typename ...t_args>
    struct typed_procedure< void( t_args... ) >
    {
        using t_return = void;
        using t_function =  t_return( t_args... );
        using t_function_ptr = t_function*;
        using t_self = typed_procedure<t_function>;

        t_function* data = nullptr;
        bool enabled = false;

        t_self&
        COPY_ASSIGNMENT operator= ( t_function_ptr rhs )
        { assign( rhs ); return *this; }

        void
        assign( t_function* rhs )
        {
            if (rhs != nullptr)
            {
                data = rhs;
                enabled = true;
            }
        }

        void
        invoke( t_args... args)
        {
            if (enabled)
            { data( std::forward<t_args>(args)... ); }
        }

        void
        operator () ( t_args... args )
        { invoke( std::forward<t_args>(args)... ); }
    };

    template<typename t_signature>
    struct generic_procedure;

    /** A generic type-erased wrapper that supports all function types (function
     * pointers, lambdas, function objects) AND supports closures.
     *
     * It can provide an abitrary number of arguments as well as capture 1 context
     * argument. The 'context' argument will replace the first argument when the funciton is called
     * and it is intended to provide meaningful information like 'this' pointers and state, but it may
     * provide anything really, this can be used as an alternative to a lambda. */
    template <typename t_return, typename ... t_args>
    struct generic_procedure< t_return( t_args... ) >
    {
        using t_function = t_return( t_args... );
        using t_function_ptr = t_function*;
        using t_self = generic_procedure< t_function >;
        FORWARD struct i_procedure_impl;
        FORWARD template <typename t_procedure, typename t_impl_return> struct procedure_impl;
        FORWARD template <typename t_procedure, typename t_context> struct closure;

        IMMEDIATE isize small_size = 64;
        alignas(16) byte small_storage[ small_size ];
        i_procedure_impl* impl = nullptr;
        bool enabled = false;

        /** WARNING: This is a quirk/defect in C++ that means that lambdas for some
         * reason absolutely will not pass through a constructor correctly and will
         * end in a bad state, eventually leading to a segfault. This is a
         * cautionary tale in the janky behaviour of constructors that always seems
         * to prop up, so we have a copy assignment operator, that works for the
         * lambdas, and the constructor, so we can initialize-on-decleration */

        CONSTRUCTOR generic_procedure()
        { impl = reinterpret_cast<i_procedure_impl*>( &small_storage ); }

        template <typename t_procedure>
        CONSTRUCTOR generic_procedure( t_procedure proc )
        {
            impl = reinterpret_cast<i_procedure_impl*>( &small_storage );
            assign( proc );
        }

        COPY_CONSTRUCTOR generic_procedure( const t_self& rhs )
        {
            this->impl = std::launder(reinterpret_cast<i_procedure_impl*>( this->small_storage ));
            if (rhs.enabled)
            {
                rhs.impl->clone( this->impl );
                this->enabled = true;
            }
        }

        t_self& operator= (const t_self& rhs)
        {
            this->impl = std::launder(reinterpret_cast<i_procedure_impl*>( this->small_storage ));
            if (rhs.enabled)
            {
                rhs.impl->clone( this->impl );
                this->enabled = true;
            }
            return *this;
        }

        template <typename t_procedure>
        t_self& operator= ( t_procedure rhs )
        {
            assign( rhs );
            return *this;
        }

        template <typename t_procedure>
        void assign( t_procedure proc )
        {
            constexpr i64 procedure_size = sizeof(procedure_impl<t_procedure, t_return>);
            /** You should not call 'delete' on a pacement new allocated object. You do however have to
                explicitly call the destruct if it is relevant 'foo_instance->~foo()' */
            static_assert( procedure_size < small_size,
                           "procedure object or pointer is too large to fit on the stack." );
            this->impl = reinterpret_cast<i_procedure_impl*>( this->small_storage );
            new(small_storage) procedure_impl<t_procedure, t_return> { std::forward<t_procedure>( proc ) };
            enabled = true;
        }


        template <typename t_procedure, typename t_context>
        void assign_closure( t_procedure proc, t_context context )
        {
            /** You should not call 'delete' on a pacement new allocated object. You do however have to
                explicitly call the destruct if it is relevant 'foo_instance->~foo()' */
            constexpr i64 closure_size = sizeof( closure_impl<t_procedure, t_context>);
            static_assert( closure_size < small_size,
                           "procedure object or pointer is too large to fit on the stack." );
            this->impl = reinterpret_cast<i_procedure_impl*>( this->small_storage );
            new(small_storage) closure_impl<t_procedure, t_context>
            { std::forward<t_procedure>( proc ), context };
            enabled = true;
        }

        // Accepting void returns makes writing this function annoying so we're not doing it.
        // The call operator '()' can return a normal type just fine
        template <typename... t_forward>
        bool invoke( t_forward&&... args)
        {
            if (enabled)
            { impl->invoke( std::forward<t_args>(args)... ); }
            return enabled;
        }

        template <typename... t_forward>
        t_return
        operator () ( t_forward&&... args )
        {
            t_return stub = {};
            if (enabled)
            { return impl->invoke( std::forward<t_args>(args)... ); }
            else
            { return stub; }
        }

        // NOTE: It's on the stack, doesn't need to be freed. Reconsider if it moves onto the heap.
        // DESTRUCTOR ~generic_procedure()
        // { delete this->impl; }

        // -- Magic Internal Setup --

        /** Setup a base type to enable switching between functors with vtables */
        struct i_procedure_impl
        {
            virtual t_return invoke(t_args ...args) PURE;
            virtual i_procedure_impl* clone( void* destination ) PURE;
            virtual DESTRUCTOR ~i_procedure_impl() = default;
        };

        /** Closure implimentation, passes static data back to the function */
        template <typename t_procedure, typename t_context>
        struct closure_impl final : i_procedure_impl
        {
            t_procedure proc;
            t_context context;

            CONSTRUCTOR closure_impl( t_procedure&& _proc, t_context _context )
                : proc( std::move(_proc) ),
                  context( _context ) {}

            // COPY_CONSTRUCTOR closure_impl( const closure_impl<t_procedure, t_context>& other )
            //     : proc( other.proc ),
            //       context( other.context ) {}

            t_return
            invoke( t_args ...args ) override
            { return std::invoke( proc, context, args...); }

            i_procedure_impl*
            clone( void* destination ) override
            {
                return new(destination)
                closure_impl<t_procedure, t_context>( std::move(proc), context );
            }
        };

        /** Context-less implimentation, supports most function types */
        template <class t_procedure, class t_impl_return>
        struct procedure_impl final : i_procedure_impl
        {
            t_procedure proc;

            CONSTRUCTOR procedure_impl( t_procedure&& _proc )
                : proc( _proc ) {}

            t_impl_return
            invoke( t_args ...args ) override
            {
                return std::invoke(proc, args...);
            }

            i_procedure_impl*
            clone( void* destination ) override
            {
                return new(destination) procedure_impl<t_procedure, t_return>( std::move(proc) );
            }
        };
    };

    /** Void return Specialization */
    template <typename ... t_args>
    struct generic_procedure< void( t_args... ) >
    {
        using t_return = void;
        using t_function = t_return( t_args... );
        using t_function_ptr = t_function*;
        using t_self = generic_procedure< t_function >;
        FORWARD struct i_procedure_impl;
        FORWARD template <typename t_procedure, typename t_impl_return> struct procedure_impl;
        FORWARD template <typename t_procedure, typename t_context> struct closure;

        IMMEDIATE isize small_size = 64;
        alignas(16) byte small_storage[ small_size ];
        i_procedure_impl* impl = nullptr;
        bool enabled = false;

        /** WARNING: This is a quirk/defect in C++ that means that lambdas for some
         * reason absolutely will not pass through a constructor correctly and will
         * end in a bad state, eventually leading to a segfault. This is a
         * cautionary tale in the janky behaviour of constructors that always seems
         * to prop up, so we have a copy assignment operator, that works for the
         * lambdas, and the constructor, so we can initialize-on-decleration */

        CONSTRUCTOR generic_procedure()
        { impl = reinterpret_cast<i_procedure_impl*>( &small_storage ); }

        template <typename t_procedure>
        CONSTRUCTOR generic_procedure( t_procedure proc )
        {
            impl = reinterpret_cast<i_procedure_impl*>( &small_storage );
            assign( proc );
        }

        COPY_CONSTRUCTOR generic_procedure( const t_self& rhs )
        {
            this->impl = std::launder(reinterpret_cast<i_procedure_impl*>( this->small_storage ));
            if (rhs.enabled)
            {
                rhs.impl->clone( this->impl );
                this->enabled = true;
            }
        }

        t_self& operator= (const t_self& rhs)
        {
            this->impl = std::launder(reinterpret_cast<i_procedure_impl*>( this->small_storage ));
            if (rhs.enabled)
            {
                rhs.impl->clone( this->impl );
                this->enabled = true;
            }
            return *this;
        }

        template <typename t_procedure>
        t_self& operator= ( t_procedure rhs )
        {
            assign( rhs );
            return *this;
        }

        template <typename t_procedure>
        void assign( t_procedure proc )
        {
            constexpr i64 procedure_size = sizeof(procedure_impl<t_procedure, t_return>);
            /** You should not call 'delete' on a pacement new allocated object. You do however have to
                explicitly call the destruct if it is relevant 'foo_instance->~foo()' */
            static_assert( procedure_size < small_size,
                           "procedure object or pointer is too large to fit on the stack." );
            this->impl = reinterpret_cast<i_procedure_impl*>( this->small_storage );
            new(small_storage) procedure_impl<t_procedure, t_return> { std::forward<t_procedure>( proc ) };
            enabled = true;
        }


        template <typename t_procedure, typename t_context>
        void assign_closure( t_procedure proc, t_context context )
        {
            /** You should not call 'delete' on a pacement new allocated object. You do however have to
                explicitly call the destruct if it is relevant 'foo_instance->~foo()' */
            constexpr i64 closure_size = sizeof( closure_impl<t_procedure, t_context>);
            static_assert( closure_size < small_size,
                           "procedure object or pointer is too large to fit on the stack." );
            this->impl = reinterpret_cast<i_procedure_impl*>( this->small_storage );
            new(small_storage) closure_impl<t_procedure, t_context>
            { std::forward<t_procedure>( proc ), context };
            enabled = true;
        }

        template <typename... t_forward>
        bool invoke( t_forward&&... args)
        {
            if (enabled)
            { impl->invoke( std::forward<t_args>(args)... ); }
            return enabled;
        }

        template <typename... t_forward>
        void
        operator () ( t_forward&&... args )
        {
            if (enabled)
            { impl->invoke( std::forward<t_args>(args)... ); }
        }

        // NOTE: It's on the stack, doesn't need to be freed. Reconsider if it moves onto the heap.
        // DESTRUCTOR ~generic_procedure()
        // { delete this->impl; }

        // -- Magic Internal Setup --

        /** Setup a base type to enable switching between functors with vtables */
        struct i_procedure_impl
        {
            virtual t_return invoke(t_args ...args) PURE;
            virtual i_procedure_impl* clone( void* destination ) PURE;
            virtual DESTRUCTOR ~i_procedure_impl() = default;
        };

        /** Closure implimentation, passes static data back to the function */
        template <typename t_procedure, typename t_context>
        struct closure_impl final : i_procedure_impl
        {
            t_procedure proc;
            t_context context;

            CONSTRUCTOR closure_impl( t_procedure&& _proc, t_context _context )
                : proc( std::move(_proc) ),
                  context( _context ) {}

            // COPY_CONSTRUCTOR closure_impl( const closure_impl<t_procedure, t_context>& other )
            //     : proc( other.proc ),
            //       context( other.context ) {}

            void
            invoke( t_args ...args ) override
            { std::invoke( proc, context, args...); }

            i_procedure_impl*
            clone( void* destination ) override
            {
                return new(destination)
                closure_impl<t_procedure, t_context>( std::move(proc), context );
            }
        };



        template <class t_procedure>
        struct procedure_impl<t_procedure, void> final : i_procedure_impl
        {
            t_procedure proc;

            CONSTRUCTOR procedure_impl( t_procedure&& _proc )
                : proc( _proc ) {}

            void
            invoke( t_args ...args ) override
            { std::invoke(proc, args...); }

            i_procedure_impl*
            clone( void* destination ) override
            {
                return new(destination) procedure_impl<t_procedure, t_return>( std::move(proc) ); }

        };

    };

    /** Common type that eliminates the need for inputting awkward function types,
     * ie 'bool(int, int)'. Arguments only.  It is fairly rare to require anything
     * but a void reassignable functions so bool or error type is a good default. */
    template <typename ... t_args>
    using procedure = generic_procedure<fresult( t_args... )>;

    /** Proxy function to make it possible to store typing information for
     * type-erased function pointers */
    template <typename t_procedure, typename t_context, typename t_args>
    bool procedure_closure_proxy( void (*proc)(), void* context, t_args args )
    {
        // Extract closure data from using types
        auto _proc = reinterpret_cast<t_procedure>( proc );
        auto _context = *static_cast<t_context*>( context );
        return _proc( _context, args);
    }

    /** A type erased function pointer (closure type)
     * Acts on 'context_data' provided by during assignment, which is always treated as correct.
     * Extra paremeter data is provided as 'args' during a call invocation
     * signature of the callable
     *
     * The function signature of the assigned must be in the form
     * bool <name>(context, ...t_args)
     * The context is an abitrary value that provides the non-argument data the stored function
     * needs to operator, ie the 'this' pointer. It may also be a copyable structure or container.
     *
     * This version has one one key different in that it does not use vtables, and
     * cannot store multiple function types, in fact in can only store plain
     * functions. This has no purpose currently, but it may be of interest for
     * performance in future- otherwise, use plain function pointers or a
     * type-waware wrapper for performance. */
    template <typename ...t_args>
    struct procedure_mono
    {
        using t_closure = bool (*)( void(*)(), void*, t_args... );
        using t_generic_func = void(*)();
        /// The wrapped procedure which may be called to yield the stored closure
        t_closure data = nullptr;
        /// The real assigned procedure without closures
        void (*proc_data)() = nullptr;
        /// The context the stored procedure requires
        void* context_data = nullptr;
        constexpr static i64 small_storage_size = 32;
        byte small_storage[ small_storage_size ] = {};
        void (*tmp_ptr)();

        template <typename t_procedure, typename t_copyable>
        void
        assign( t_procedure proc, t_copyable context )
        {
            static_assert( sizeof(t_copyable) < small_storage_size,
                           "context type does not fix on the stack, consider increasing small "
                           "size or allocating some memory for it before assigning." );
            data = &procedure_closure_proxy<t_procedure, t_copyable>;
            context_data = small_storage;
            t_copyable* writehead = reinterpret_cast<t_copyable*>( context_data );
            *writehead = context;
            proc_data = reinterpret_cast<t_generic_func>( proc );
        }

        bool
        operator () ( t_args... args )
        {
            if (data == nullptr)
            { return false; }
            return data( proc_data, context_data, args... );
        }
    };

    template <typename t_proc = procedure<>>
    struct delegate
    {
        vector<t_proc> procedures;

        void
        register_procedure( t_proc proc )
        {
            procedures.push_back( proc );
        }

        void
        unregister_all()
        {
            procedures.clear();
        }

        void
        invoke_all()
        {
            for (i32 i=0; i < procedures.size(); ++i)
            {
                procedures[i].invoke();
            }
        }
    };

    template <typename t_procedure>
    struct defer_procedure
    {
        generic_procedure<t_procedure> deferred;

        template <typename t_callable>
        COPY_CONSTRUCTOR defer_procedure ( const t_callable& proc )
        {
            deferred.assign( proc );
        }

        DESTRUCTOR ~defer_procedure()
        {
            deferred.invoke();
        }
    };

#define DEFER( name, ... ) defer _deferred = [&] { __VA_ARGS__ };
#define DEFER_NAMED( name, ... ) defer name = [&] { __VA_ARGS__ };

    using defer = defer_procedure<void()>;

    /** -- Type Support Library --
     *
     * Type support is for simple wrapper-like types that help enforce typing
     * issues and conversions */

    using literal_integer = unsigned long long;
    using literal_float = long double;
    using literal_string = const char*;

    struct u40 { u8 d[5]; };
    using u64 = uint64_t;
    struct u128
    {
        u64 d[2] = {};
        constexpr CONSTRUCTOR u128() = default;
        constexpr CONSTRUCTOR u128( u64 low, u64 high )
        { d[0] = low; d[1] = high; }
    };
    struct u256 { u64 d[4]; };
    struct u512 { u64 d[8]; };
    struct u1024 { u64 d[16]; };
    struct u2048 { u64 d[32]; };
    struct u4096 { u64 d[64]; };

    /** Literal that provides a number with a single zero-indexed bit position set as 1 */
    constexpr u32
    operator ""_bit( literal_integer arg )
    {
        return (1 << arg);
    }

    /** Literal that provides a number with a single zero-indexed bit position set as 1

        64-bit version */
    constexpr u64
    operator ""_bit64( literal_integer arg )
    {
        return (i64(1) << arg);
    }

    constexpr i64
    operator ""_KiB( literal_integer arg )
    { return arg * (1 << 10); }

    constexpr i64
    operator ""_MiB( literal_integer arg )
    { return arg * (1 << 20); }

    constexpr i64
    operator ""_GiB( literal_integer arg )
    { return arg * (1 << 30); }

    constexpr i64
    operator ""_TiB( literal_integer arg )
    { return arg * (1 << 20); }

    inline i64
    operator ""_KB( literal_integer arg )
    { return arg * std::pow( 10, 3 ); }

    inline i64
    operator ""_MB( literal_integer arg )
    { return arg * std::pow( 10, 6 ); }

    inline i64
    operator ""_GB( literal_integer arg )
    { return arg * std::pow( 10, 9 ); }

    inline i64
    operator ""_TB( literal_integer arg )
    { return arg * std::pow( 10, 12 ); }

    struct uid
    {
        i64 id;
        u128 uuid;

        CONSTRUCTOR uid() = default;
        constexpr CONSTRUCTOR uid( i64 _id, u128 _uuid );
        constexpr CONSTRUCTOR uid( u128 _uuid ) : id(0), uuid( _uuid ) {}
        constexpr CONSTRUCTOR uid( i64 _id )
            : id(_id), uuid() { }
        operator i64();
    };

    struct minihash
    {
        u64 value = 0;

        inline minihash&
        operator =( u64 arg )
        { value = arg; return *this; }

        bool
        operator== ( minihash& rhs );

        bool
        operator!= ( minihash& rhs );
    };


    // Define null values for various types
    template <typename T> struct null_define { T value; };
    template <> struct null_define<i64> { i64 value = 0; };
    template <> struct null_define<uid> { uid value = uid(-1); };

    template <typename T >
    T null_value()
    { null_define<T> stored; return stored.value; }


    template <typename T>
    void nullify( T& arg)
    { arg = null_value<T>(); }


    /** null is a special value that auto-casts and detects a variation of
     * invalid values, having a single value to check against instead of many is
     * much more convenient */
    struct null_type
    {
        template <typename T>
        T value () { null_define<T> stored; return stored.value; }

        template <typename T>
        explicit operator T () { null_define<T> stored; return stored.value; }

        template <typename T>
        bool operator== ( T other ) { return other == static_cast<T>(*this); }

        template <typename T>
        bool operator!= ( T other ) { return other != static_cast<T>(*this); }
    };

    template <typename T>
    struct stub {};

    // -- Substantial Types --

    struct vec2_i64
    {
        i64 x;
        i64 y;

        CONSTRUCTOR vec2_i64() : x(0), y(0) { }
        // CONSTRUCTOR vec2_i64( vec2 rhs ) : x(rhs.x), y(rhs.y) { }
        CONSTRUCTOR vec2_i64( i64 arg ) : x(arg), y(arg) {}
        CONSTRUCTOR vec2_i64( i64 _x, i64 _y ) : x(_x), y(_y) {}
    };

    struct rectangle_copy_args
    {
        void* source;
        void* dest;
        vec2_i64 copy_size;
        vec2_i64 source_pos;
        vec2_i64 dest_pos;
        vec2_i64 source_size;
        vec2_i64 dest_size;
    };

    enum class color_format : u32
    {
        none     = 0,
        mono8    = 1,
        mono_f32 = 2,
        duo8     = 3,
        duo_f32  = 4,
        rgba8    = 5,
        rgba_f32 = 6,
        rgb8     = 7,
        rgb_f32  = 8,
        rgba16   = 9
    };
    using e_color_format = color_format;

    template <typename t_pixel>
    struct image
    {
        t_pixel* data = nullptr;
        vec2_i64 size = 0;
        e_color_format format = color_format::rgba8;
        bool simd_padded = false;
        // Damaged, corrupted or otherwise problematic to treat a whole image
        bool incomplete = true;
        bool corrupted = false;

        isize stride_bytes()
        {
            return (simd_padded ? memory_align_typed<t_pixel>( size.x, 4) : size.x);
        }

        isize size_pixels()
        { return (size.x * size.y); }

        isize size_bytes()
        { return (size.x * size.y * sizeof(data)); }

        t_pixel&
        operator[] ( isize i )
        {
            static t_pixel stub_pixel;
            if (data == nullptr)
            {
                tyon_log_error( "Image has no associated storage" );
                return stub_pixel;
            }
            return data[ std::clamp<isize>( i, 0, size_pixels() -1 ) ];
        }
    };

    // -- File Library --
    struct file
    {
        fpath filename;
        buffer memory;
        /// File pointed to by 'filename' is confirmed to exist or not
        bool file_exists = false;
        /** Signifies file writes will be passed through straight to disk
         may use memory map or just flush. */
        bool direct_write = false;
        /// File is available to be written using 'buffer'
        bool file_loaded = false;
        /// File status has be ready and is ready for use
        bool status_loaded = false;

        fresult
        update_status();
    };

    auto file_load_binary( const fpath target, i_memory_allocator* allocator = g_allocator ) -> file;

    auto file_write_binary( file* arg ) -> fresult;

    auto file_write_binary_stdlib( file* arg ) -> fresult;


    // -- Asset Library --

    inline bool asset_function_stub( asset* arg ) { return false; }
    using asset_function = decltype( &asset_function_stub );

    enum class asset_type
    {
        none = 0,
        text = 1,
        svg = 2,
        svg_as_texture = 3
    };
    using e_asset = asset_type;

    struct asset_type_data
    {
        fstring name;
        e_asset type = asset_type::none;
        asset_function loader = &asset_function_stub;;
        asset_function unloader =  &asset_function_stub;;
    };

    struct asset
    {
        // File/Asset type
        e_asset type = asset_type::none;
        fstring name;
        file file;
        void* data = nullptr;
        asset_function loader = &asset_function_stub;
        asset_function unloader = &asset_function_stub;
        fstring loader_name;
        bool loaded = false;
    };

    struct asset_machine
    {
        array<fpath> search_paths;
        array<asset> assets;
        array<asset_type_data> asset_types;
        bool initialied;
    };

    void
    asset_machinery_init();

    asset*
    asset_search( fstring filename, e_asset type );

    asset*
    asset_queue_load( fstring filename, e_asset type );

    void
    asset_machinery_register_type(
        fstring name,
        e_asset type,
        asset_function loader,
        asset_function unloader
        );


    bool
    asset_execute_loader( asset* arg );

    // -- Platform Library --

    enum class processor_core : u32
    {
        none            = 0,
        any             = 1,
        cpu             = 2,
        cpu__efficiency = 3,
        gpu             = 4
    };
    using e_processor_core = processor_core;

    struct cpu_cache_info
    {
        i32 cache_level = 0;
        i32 size_byte = 0;
        i32 average_latency = 0;
        i32 alignment = 0;
    };

    struct cpu_core_info
    {
        i32 id = -1;
        i32 frequency = 0;
        i32 frequency_limit_min = 0;
        i32 frequency_limit_max = 0;
        /** Highest and lowest observed frequency taking into account
         * measurements from transients and turbo */
        i32 frequency_lowest = 0;
        i32 frequency_peak = 0;
        i32 voltage_limit_min = 0;
        i32 voltage_limit_max = 0;
        /** Highest and lowest observed stable voltage varies depending on
         * conditions and drivers */
        i32 voltage_limit_lowest = 0;
        i32 voltage_limit_peak = 0;
        i32 processor_group = 0;
        // Hyper-threading can be enabled/disabled per core
        bool hyperthreading_enabled = false;
        i32 l1_cache_count = 0;
        i32 l2_cache_count = 0;
        i32 l3_cache_count = 0;
        i32 l4_cache_count = 0;
        array<cpu_cache_info> caches;
        i32 theoretical_throughput_gflops = 0;
    };

    struct numa_node_info
    {
    };

    struct cpu_info
    {
        fstring name = "Unknown";
        fstring sku = "Unknown";
        fstring vendor = "Unknown";
        fstring architecture = "Unknown";
        array<cpu_core_info> physical_cores;
        i32 physical_core_count = 0;
        i32 virtual_core_count = 0;
        i32 package_count = 0;
        i32 numa_node_count = 0;
        i32 l1_cache_count = 0;
        i32 l2_cache_count = 0;
        i32 l3_cache_count = 0;
        i32 l4_cache_count = 0;
        i32 tdp_watts = 0;
        bool hyperthreading_enabled = false;
        bool hyperthreading_supported = false;
        // extension_flags
    };

    enum class memory_type : u32
    {
        none = 0,
        any = 1,
        ddr1,
        ddr2,
        ddr3
    };
    using e_memory = memory_type;

    struct memory_info
    {
        e_memory type = memory_type::none;
        i32 size_bytes = 0;
        i32 channels = 0;
        i32 frequency = 0;
        i32 frequency_limit_min = 0;
        i32 frequency_limit_max = 0;
        /** Highest and lowest observed frequency taking into account
         * measurements from transients and turbo */
        i32 frequency_lowest = 0;
        i32 frequency_peak = 0;
        i32 processor_group = 0;
    };

    struct system_info
    {
        fstring system_name = "Uknown";
        cpu_info cpu;
        memory_info memory;
    };

    fresult
    FUNCTION test_little_endian();

    fpath
    file_self_directory();

    fpath
    file_self_filename();

    fresult
    file_open( file* arg );

    u128
    uuid_generate();

    system_info
    system_info_fetch();

    /////////////////////////////
////// -- Threading Library -- /////////////////////////////////////////////////
    /////////////////////////////

    struct thread_options
    {
        // Override the default UID with a custom one
        uid id;
        // < 16 bytes for UNIX
        fstring short_name;
        fstring name;
        fstring description;
        i32 scheduler_priority;
        // How much memory to increase the arena size by each time
        i32 permanant_block_size;
        i32 scratch_block_size;
        // allocator_type
    };

    fresult
    thread_self_background_priority();

    fresult
    thread_self_name( fstring name );

}


// -- String Formatters --
template <>
struct fmt::formatter< tyon::vec2_i64 > : formatter<string_view>
{
    auto format( tyon::vec2_i64 arg, format_context& context ) const -> format_context::iterator
    {
        string_view data = fmt::format( "[{} {}]", arg.x, arg.y );
        return formatter<string_view>::format( data, context );
    }
};

/* void*
   ::operator new( usize bytes );

   void*
   ::operator new[]( usize bytes );
   void
   ::operator delete(void* ptr) noexcept; */
