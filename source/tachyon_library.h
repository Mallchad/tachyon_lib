
#pragma once

#define PROC auto

/// Internal dependencies
// #include <atomic>
// #include <vector>
// #include <cstdlib>
// #include <cstring>
// #include <thread>
// #include <mutex>

#define TYON_SHARED_LIBRARY 0

#ifndef TYON_EXPORTS
    #define TYON_EXPORTS 0
#endif

#if  (REFLECTION_PLATFORM_WINDOWS && TYON_SHARED_LIBRARY)
    #if (TYON_EXPORTS)
        #define TYON_API __declspec(dllexport)
    #else
        #define TYON_API __declspec(dllimport)
    #endif
#else
    #define TYON_API
#endif // REFLECTION_PLATFORM_WINDOWS && TYON_SHARED_LIBRARY

// TYON_BREAK should be valid in release builds
#define TYON_SIGTRAP 5

#if (REFLECTION_COMPILER_CLANG)
    /* #define FORCEINLINE __attribute__((always_inline)) */
    #define TYON_FORCEINLINE __attribute__((always_inline))
    #define TYON_BREAK() __builtin_debugtrap();
    #define TYON_PREFETCH_CACHELINE( address ) __builtin_prefetch( address );
#elif (REFLECTION_COMPILER_GCC)
    /* #define FORCEINLINE __attribute__((always_inline)) */
    #define TYON_FORCEINLINE __attribute__((always_inline))
    #define TYON_BREAK() raise(TYON_SIGTRAP);
    #define TYON_PREFETCH_CACHELINE( address ) __builtin_prefetch( address );

#elif (REFLECTION_COMPILER_MSVC)
    /* #define FORCEINLINE __forceinline */
    #define TYON_FORCEINLINE __forceinline
    #define TYON_BREAK() __debugbreak();
    #define TYON_PREFETCH_CACHELINE( address ) PrefetchCacheLine( PF_TEMPORAL_LEVEL_1, (address) );
#else
    /* #define FORCEINLINE */
    #define TYON_FORCEINLINE
    #define TYON_BREAK() raise(TYON_SIGTRAP);
    #define TYON_PREFETCH_CACHELINE( address ) ERROR_PREFETCH_NOT_DEFINED
#endif // compiler

/** NOTE: Constexpr is helpful for marking code as CUDA compatible.

    It also solves issues with templates and One Definition Rule ODR. It's fine
    to have constexpr on a function that is never constexpr. */
#if REFLECTION_COMPILER_CUDA
    #define TYON_CUDA_DEVICE __device__
    #define TYON_CUDA_HOST  __host__
    #define TYON_CUDA_SHARED  __device__ __host__
    #define TYON_CUDA_KERNEL __global__
#else
    #define TYON_CUDA_DEVICE
    #define TYON_CUDA_HOST
    #define TYON_CUDA_SHARED
    #define TYON_CUDA_KERNEL
#endif

namespace tyon
{
    // Alias namespace
    namespace chrono = std::chrono;
    using namespace std::chrono_literals;

    // >>> Simple Types >>>

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
    using time_date_ns = u64;

    enum class e_log_entry
    {
        none = 0,
        any = 1,
        message = 2,
        error = 3,
        binary_primitive,
        binary_custom
    };

    // <<< End of Simple Types <<<

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
    FORWARD struct logger;
    FORWARD struct string;
    FORWARD struct library_context;

    struct source_location
    {
        i64 line_n = 0;
        i64 column_n = 0;
        cstring filename;
        cstring function_signature;

        constexpr PROC line() -> i64 { return line_n; }
        constexpr PROC column() -> i64 { return column_n; }
        constexpr PROC file_name() -> cstring { return filename; }
        constexpr PROC function_name() -> cstring { return function_signature; }
    };

#ifdef __GNUC__
    #define TYON_SOURCE_LOCATION() ::tyon::source_location { __LINE__, 0, __FILE__, __PRETTY_FUNCTION__ }
#else
    #define TYON_SOURCE_LOCATION() ::tyon::source_location { __LINE__, 0, __FILE__, __func__ }
#endif // __GNUC__


    template<typename... t_formattable> void
    FORWARD FUNCTION log(
        cstring category,
        tyon::source_location,
        t_formattable&&... messages );

    template<typename... t_formattable> void
    FORWARD FUNCTION log_error( cstring category, tyon::source_location location,
                                t_formattable... messages );
    template <typename... t_formattable> void
    FORWARD FUNCTION log_error_format( cstring category, const fmt::format_string<t_formattable...> format,
        tyon::source_location location, t_formattable&&... data );

    // template <typename... t_formattable> void
    // FORWARD log_error_format( tyon::fstring category, fmt::format_string<t_formattable...> format,
                              // tyon::source_location call_point, t_formattable&&... vargs );

    // -- Globals Variables --
    // make sure to initialize Pointer Types before using
    TYON_API extern tyon::time_monotonic g_program_epoch;
    TYON_API extern bool g_little_endian;
    TYON_API extern i32 g_log_largest_category;
    TYON_API extern memory_stack_allocator* g_allocator;
    TYON_API extern memory_stack_allocator* g_taint_allocator;
    TYON_API extern std::mutex* g_allocator_lock;
    TYON_API extern std::mutex g_taint_allocator_lock;
    constexpr isize memory_default_block_size = 268'435'456;

    // TODO: Make these use null pages
    TYON_API extern raw_pointer g_null_read;
    TYON_API extern raw_pointer g_null_write;

    TYON_API extern library_context* g_library;
    TYON_API extern logger* g_logger;
    // Prevent deadlocking from recursive calls
    TYON_API extern logger* g_switch_logger;
    TYON_API extern asset g_asset_stub;
    TYON_API extern asset_machine* g_asset;

    TYON_API extern null_type null;

    struct raw_pointer
    {
        byte* data = nullptr;

        COPY_CONSTRUCTOR raw_pointer()
        {}

        COPY_CONSTRUCTOR raw_pointer( const raw_pointer& rhs )
        { this->data = rhs.data; }

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
        { (void)(rhs); return data == nullptr; }

        /* Allow comparison to nullptr like 'void*' */
        inline bool
        operator != ( std::nullptr_t rhs )
        { (void)(rhs); return data != nullptr; }
    };

    // -- Math Constants --
    constexpr f64 tau_ = 6.283185307;
    constexpr f64 pi_ = 3.141592653589793;

    // -- Basic Utilities --

    // NOTE: These macros need to begin from the global namesoace ::tyon
    // otherwise it becomes a resolution error when used internally

    // TODO: Log flush isn't needed anymore
    // #define log_flush() std::cout.flush()

    #define log_flush() fflush( stdout );


    #define TYON_UNSUPPORTED()
    #define TYON_NOP() void(0);
    #define TYON_UNIMPLIMENTED();
    #define TYON_TESTING( x ) x;
    #define TYON_TODO( explanation )

    // Use these macros to do logging, or use it as a base for your own macros
    // with a predefined category.

    #define TYON_BASE_LOG( CATEGORY_, ... ) \
        ::tyon::log( CATEGORY_, TYON_SOURCE_LOCATION(), __VA_ARGS__ )
    #define TYON_BASE_LOGF( CATEGORY_, FORMAT_, ... ) \
        ::tyon::log_format( CATEGORY_, FORMAT_, TYON_SOURCE_LOCATION(), __VA_ARGS__ )
    #define TYON_BASE_ERROR( CATEGORY_, ... ) \
        ::tyon::log_error( CATEGORY_, TYON_SOURCE_LOCATION(), __VA_ARGS__ )
    #define TYON_BASE_ERRORF( CATEGORY_, FORMAT_, ... ) \
        ::tyon::log_error_format( CATEGORY_, FORMAT_, TYON_SOURCE_LOCATION(), __VA_ARGS__ )

    // Tachyon log category
    #define TYON_LOG( ... ) TYON_BASE_LOG( "Tachyon", __VA_ARGS__ );
    #define TYON_LOGF( FORMAT_, ... ) TYON_BASE_LOGF( "Tachyon", FORMAT_, __VA_ARGS__ );
    #define TYON_ERROR( ... ) TYON_BASE_ERROR( "Tachyon", __VA_ARGS__ );
    #define TYON_ERRORF( FORMAT_, ... ) TYON_BASE_ERRORF( "Tachyon Error", FORMAT_, __VA_ARGS__ );

    /** Make sure condition is true or break and show message
     * It's an assert. okay. */
    #define ERROR_GUARD( condition, message )                           \
        if ( !(condition) )                                             \
        {                                                               \
            TYON_BASE_ERRORF(                                           \
            "Error Guard", "Condition: ({0}) \n\tTested Value: {1} \n\tMessage: {2}", \
            #condition, bool(condition), (message) );                   \
            TYON_BREAK();                                               \
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

    isize
    memory_padding( isize padding, isize size );

    isize
    memory_padding( isize padding, void* target );

    void
    memory_poison( void*, isize size );

    void
    memory_unpoison( void*, isize size );

    // -- Memory Management Library | Containers --

    struct buffer
    {
        raw_pointer data;
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
            i64 alignment = memory_padding( alignof(T), result );
            result = allocate_raw( size_bytes + alignment );

            // Default allocate storage
            new(result) T[count] {};
            return result;
        }

        virtual raw_pointer allocate_raw( isize bytes, isize alignment = 1 ) PURE;
        PROC virtual allocate_raw_fast( i64 bytes, isize alignment = 1 ) -> raw_pointer PURE;
        PROC virtual allocate_relocate( void* reference, i64 bytes ) -> raw_pointer PURE;
        virtual void deallocate( void* address ) PURE;
        /** Clear all stored allocations and zero memory */
        virtual void blank_all() PURE;
        virtual allocator_info get_memory_statistics() PURE;
        virtual DESTRUCTOR ~i_allocator() {}
    };
    using i_memory_allocator = i_allocator;

    struct stack_entry
    {
        raw_pointer data;
        i64 position;
        i64 size;
        i64 alignment;
    };

    /** Simplistic stack allocator
     *
     * This allocator is not thread safe. It is not meant for that. **/
    struct memory_stack_allocator : i_memory_allocator
    {
        std::vector<buffer> blocks;
        std::vector<stack_entry> entries;

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
            isize alignment = memory_padding( alignof(T), block->data + block->head_size );
            void* head_data = (block->data + block->head_size + alignment);
            T* result = nullptr;

            bool size_exceeded = ((alignment + block->head_size + size) > block->size);
            if (size_exceeded) [[unlikely]]
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
                alignment = memory_padding( alignof(T), head_data );
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

        raw_pointer allocate_raw( isize bytes, isize alignment = 1 ) override;

        PROC allocate_raw_fast( i64 bytes, isize alignment = 1 ) -> raw_pointer override;

        PROC allocate_relocate( void* reference, i64 bytes ) -> raw_pointer override;

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

    bool
    FUNCTION memory_same_raw( void* a, void* b, i64 bytes );

    template <typename T>
    bool
    FUNCTION memory_same( T& a, T& b )
    {
        // Returns zero when same so compare to zero
        return (std::memcmp( &a, &b, sizeof(T) ) == 0);
    }

    template <typename T>
    bool
    FUNCTION memory_different( T& a, T& b )
    {
        // Returns zero when same so different is non-zero
        return std::memcmp( &a, &b, sizeof(T) );
    }

    template <typename T>
    isize
    memory_align_typed( isize count, i32 alignment )
    {
        isize bytes = (count * sizeof(T));
        return (bytes + (alignment - (bytes % alignment)));
    }

    isize
    memory_align( isize bytes, i32 alignment );

    /** There were supposed to be std::unique_ptr compat functions here which
     * supposed to work with memory_allocate give them ownership of values
     * allocated elsewhere, but since arena's will deallocate these values at
     * random this doesn't make sense, which unique_ptr can neither cope with
     * things not allocated by 'new' nor values stored with a different lifetime
     * to the arena it's associated.
     *
     * Perhaps a better system is to associate entity-like things with a
     * resource arena and let it handle the resources, rather than allowing you
     * to pass around unique_ptr's randomally */

    // -- Time Library --

    /** Returns a high precision, clock update unaffected time point.

     This should usually be derived from the RDTSC or a similar high precision time soruce. */
    monotonic_time
    FUNCTION time_now();

    time_date
    FUNCTION time_now_utc();

    template <typename t_numeric = u64>
    t_numeric
    FUNCTION time_to_epoch_nanoseconds( time_date arg )
    {
        using namespace std::chrono;
        using t_duration = duration<t_numeric, std::nano >;
        t_numeric result = time_point_cast<t_duration>( arg ).time_since_epoch().count();

        return result;
    }

        template <typename t_numeric = i64>
    t_numeric
    FUNCTION time_to_epoch_nanoseconds( time_monotonic arg )
    {
        using namespace std::chrono;
        using t_duration = duration<t_numeric, std::nano >;
        t_numeric result = time_point_cast<time_monotonic, t_duration>( arg.time_since_epoch() );

        return result;
    }

    template <typename t_numeric = f32>
    t_numeric
    FUNCTION time_now_utc_seconds()
    {
        using t_duration = chrono::duration<t_numeric, std::ratio<1>>;
        time_date::duration epoch = chrono::system_clock::now().time_since_epoch();
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
    FUNCTION time_elapsed_nanoseconds( time_monotonic start)
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

    #ifdef TRACY_ENABLE
    #define PROFILE_SCOPE( name ) \
        ZoneNamedN( TYON_CONCAT(__tracy, __COUNTER__), (name), true );
    #define PROFILE_SCOPE_FUNCTION()                                                \
        ZoneNamed( TYON_CONCAT(__tracy, __COUNTER__), true );

    #define TIME_SCOPED( name ) \
        auto TYON_CONCAT(_profile_block_, __LINE__) =                               \
            ::tyon::time_scope( (name) , "time taken to execute function");         \
        ZoneNamedN( TYON_CONCAT(__tracy, __COUNTER__), (name), true );

    // Time the function scope this macro is in and log the result
    #define TIME_SCOPED_FUNCTION() \
        auto TYON_CONCAT(_profile_block_, __LINE__) =                               \
            ::tyon::time_scope( __FUNCTION__ , "time taken to execute function");   \
        ZoneNamed( TYON_CONCAT(__tracy, __COUNTER__), true );

    #else // TRACY_ENABLE

    #define PROFILE_SCOPE( name )
    #define PROFILE_SCOPE_FUNCTION()
    #define TIME_SCOPED( name )
    #define TIME_SCOPED_FUNCTION()

    #endif // TRACY_ENABLE

    #define f_TIME_SCOPED_ACCUMULATED( NAME, ID ) \
        {                                                                           \
        static bool _profile_init  = true;                                          \
        if (_profile_init != false)                                                 \
        { global->stopwatches.emplace_back( fstring(NAME),                          \
            fstring("time spent executing in this block across whole runtime") ); } \
            _profile_init = false;                                                  \
        }                                                                           \
        auto _profile_init_##ID = ::tyon::time_scope( &global->stopwatches.back() );

    #define TIME_EXPAND_MACRO( ... ) f_TIME_SCOPED_ACCUMULATED( __VA_ARGS__ )
    #define TIME_SCOPED_ACCUMULATED( NAME ) \
        TIME_EXPAND_MACRO( NAME, __COUNTER__ )
    #define TIME_SCOPED_ACCUMULATED_FUNCTION() \
        TIME_EXPAND_MACRO( __FUNCTION__, __COUNTER__ )

    // #define TIME_SCOPED(...)
    // #define TIME_SCOPED_FUNCTION(...)
    // #define PROFILE_SCOPE(...)
    // #define PROFILE_SCOPE_FUNCTION(...)

    // -- Functional Programming Library --

    template <typename T>
    struct monad
    {
        // static_assert( default_value == default_value,
                       // "Default value cannot work correctly if comparison is not valid" );
        T value;
        // Non-zero on error value
        fresult error = false;

        /* Cast to value type, auto-stubs out

           NOTE: We previously had this as non-explicit but that leads to kind
           of nonsense behaviour. What is better is if you have a user-provided
           nullish value, THEN you can safely stub out by default
        */
        explicit operator T()
        {   if (error == false)
            {   return value; }
            else
            {   return {}; }
        }

        /** Returns a copy of the the only match OR the specified default value */
        PROC copy_default( T default_value ) -> T
        {   return (error == false ? value : default_value);
        }
    };

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
        using t_function_ptr = t_return(*)( t_args... );
        // using t_function_ptr = t_function*;
        using t_self = typed_procedure<t_function>;

        t_function* data= nullptr;
        bool enabled = false;

        CONSTRUCTOR typed_procedure() = default;
        COPY_CONSTRUCTOR typed_procedure( t_function_ptr rhs )
        {   assign(rhs);
        }

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

    /** Magic type deduction guide for auto-determining type from constructor/copy expression */
    template <typename t_return, typename... t_args>
    typed_procedure( t_return(*foo)( t_args... ) ) -> typed_procedure<t_return(t_args...)>;

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

        IMMEDIATE isize small_size = 128;
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

        IMMEDIATE isize small_size = 128;
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

    // Template Deduction gudie to help split t_return and t_args into seperate types...
    template <typename t_signature>
    struct delegate;

    template <typename t_return, typename ... t_args>
    struct delegate< t_return( t_args... ) >
    {
        using t_functor = procedure< t_return( t_args... ) >;
        std::vector<t_functor> procedures;

        void
        register_procedure( t_functor proc )
        {
            procedures.push_back( {} ).assign( proc );
        }

        void
        register_closure( t_functor proc, void* context = nullptr )
        {
            procedures.push_back( {} ).assign_closure( proc, context );
        }

        void
        unregister_all()
        {
            procedures.clear();
        }

        void
        invoke_all( t_args... args )
        {
            for (i32 i=0; i < procedures.size(); ++i)
            {
                procedures[i].invoke( args... );
            }
        }
    };

    template <typename t_procedure>
    struct defer_procedure
    {
        using t_self = defer_procedure<t_procedure>;
        t_procedure deferred;

        COPY_CONSTRUCTOR defer_procedure ( t_procedure&& proc ) :
            deferred( std::move(proc) )  {}

        DESTRUCTOR ~defer_procedure()
        {
            deferred();
        }
    };

#define DEFER( name, ... ) defer _deferred = [&] { __VA_ARGS__ };
#define DEFER_NAMED( name, ... ) defer name = [&] { __VA_ARGS__ };

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
        u8 d[16] = {};
        // constexpr CONSTRUCTOR u128( const u128& arg ) {
        //     d[0]  = arg.d[0]; d[1] = arg.d[1]; d[2] = arg.d[2]; d[3] = arg.d[3];
        //     d[4]  = arg.d[4]; d[5] = arg.d[5]; d[6] = arg.d[6]; d[7] = arg.d[7];
        //     d[8]  = arg.d[8]; d[9] = arg.d[9]; d[10] = arg.d[10]; d[11] = arg.d[11];
        //     d[12] = arg.d[12]; d[13] = arg.d[13]; d[14] = arg.d[14]; d[15] = arg.d[15];
        // }
    };
    struct u256 { u64 d[4]; };
    struct u512 { u64 d[8]; };
    struct u1024 { u64 d[16]; };
    struct u2048 { u64 d[32]; };
    struct u4096 { u64 d[64]; };

    TYON_COMPILED_PROC
    PROC uuid( literal_string arg ) -> u128
    {
        // Error checking only works in non-constexpr context
        i64 size = 0;
        for (; arg[ size ] != 0x0; ++size) {}
        if (size != 36 ) { throw( "UUID must be 36 characters long" ); }
        u128 result;
        char hex_value[128] = {
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
             0, 1, 2, 3, 4, 5, 6, 7, 8, 9,-1,-1,-1,-1,-1,-1,
            -1,10,11,12,13,14,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,10,11,12,13,14,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,
            -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        };
        // 7 bits defined
        u8 std_ascii_mask = (0xFF >> 1);
        // Minimum 32 size
        char buf[40] = {};
        i32 buf_size = 0;
        // Strip out redundant - char's before beginning
        for (i32 i=0; i < size; ++i)
        {   if (arg[i] == '-') { continue; }
            buf[ buf_size ] = (arg[i] & std_ascii_mask);
            ++buf_size;
        }

        char low = 0;
        char high = 0;
        // Covnert each character into hex half-byte value and shift into the right plce
        for (i32 i=0; i < 16; ++i)
        {
            high = hex_value[ i32(buf[ i*2 +0 ]) ];
            low  = hex_value[ i32(buf[ i*2 +1 ]) ];
            result.d[i] = (high << 4) | low;
            if  ((high == -1) || ( low == -1 ))
            {   throw( "Invalid character found in UUID.\n"
                       "Valid characters are hexidecimal '0123456789ABCDE' and '-' " );
            };
            // fmt::print( "{:d} {:d} ", high, low );
            // fmt::print( "{} {}", buf[ i*2 +0 ], buf[ i*2 +1 ] );
        }
        return result;

    }

    namespace literals
    {
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

    /* Generates a u128 UUID out of a UUID string in this format 'f1e9148d-2b4f-4c57-8d30-4a5e98187489'
       NOTE: This always runs at compile time may need to be changed for C++17 or lower
       NOTE: I tried will compile error if the input argument is bad.
       NOTE: I tried to make it force compile-time evaluation with 'constexpr but
       it doesn't work. Don't be tempted to use static_assert or constexpr if tricks-
       that doesn't work either.*/
    TYON_COMPILED_PROC
    PROC operator ""_uuid ( literal_string arg, std::size_t size ) -> u128
    {   return uuid( arg ); }

    }

    // NOTE: Include literals in this namespace only
    using namespace literals;

    struct uid
    {
        i64 id;
        u128 uuid;

        CONSTRUCTOR uid() = default;
        constexpr CONSTRUCTOR uid( i64 _id, u128 _uuid ) : id( _id ), uuid( _uuid ) {}
        constexpr CONSTRUCTOR uid( u128 _uuid ) : id(0), uuid( _uuid ) {}
        constexpr CONSTRUCTOR uid( i64 _id )
            : id(_id), uuid() { }
        constexpr COPY_CONSTRUCTOR uid( const uid& arg )
            : id(arg.id), uuid(arg.uuid) { }

        constexpr TYON_CUDA_SHARED
        PROC operator ==( uid rhs ) -> bool
        {
            bool difference = (
                (uuid.d[0]   ^ rhs.uuid.d[0]) |
                (uuid.d[1]   ^ rhs.uuid.d[1]) |
                (uuid.d[2]   ^ rhs.uuid.d[2]) |
                (uuid.d[3]   ^ rhs.uuid.d[3]) |
                (uuid.d[4]   ^ rhs.uuid.d[4]) |
                (uuid.d[5]   ^ rhs.uuid.d[5]) |
                (uuid.d[6]   ^ rhs.uuid.d[6]) |
                (uuid.d[7]   ^ rhs.uuid.d[7]) |
                (uuid.d[8]   ^ rhs.uuid.d[8]) |
                (uuid.d[9]   ^ rhs.uuid.d[9]) |
                (uuid.d[10]  ^ rhs.uuid.d[10]) |
                (uuid.d[11]  ^ rhs.uuid.d[11]) |
                (uuid.d[12]  ^ rhs.uuid.d[12]) |
                (uuid.d[13]  ^ rhs.uuid.d[13]) |
                (uuid.d[14]  ^ rhs.uuid.d[14]) |
                (uuid.d[15]  ^ rhs.uuid.d[15]) |
                (uuid.d[15]  ^ rhs.uuid.d[15]));
            return (difference == 0);
        }

        constexpr PROC valid() -> bool
        {
            auto empty = u128 {};
            return (*this == empty);
        }

        explicit operator i64()
        {   return id; }
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
                TYON_ERROR( "Image has no associated storage" );
                return stub_pixel;
            }
            return data[ std::clamp<isize>( i, 0, size_pixels() -1 ) ];
        }
    };

    // -- File Library --
    struct file
    {
        uid id;
        /// Entity lookup name, can be auto-initialized to the filename
        fstring name;
        fpath filename;
        buffer memory;
        i64 stream_readhead = 0;

        // TODO: flag all out of date
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

    FORWARD struct logger;
    PROC logger_write_message(
        logger* context,
        fstring category,
        fstring message,
        e_log_entry type,
        tyon::source_location call_point
    ) -> void;

    template<typename... t_formattable>
    void
    FUNCTION log( cstring category, tyon::source_location location, t_formattable&&... messages )
    {
        fstring formatted_message;
        formatted_message.reserve( 100 );
        FOLD((formatted_message += fmt::format( "{} ", messages ) ), ...);
        logger_write_message( g_logger, category, formatted_message, e_log_entry::message, location );
    }

    template <typename... t_formattable>
    PROC log_format(
        cstring category,
        fmt::format_string<t_formattable...> format,
        tyon::source_location location,
        t_formattable&&... data
    )
    {
        fstring message = fmt::format( format, std::forward<t_formattable>(data)... );
        logger_write_message( g_logger, category, message, e_log_entry::message, location );
    }

    template<typename... t_formattable>
    void
    FUNCTION log_error( cstring category, tyon::source_location location, t_formattable... messages )
    {
        fstring formatted_message;
        formatted_message.reserve( 100 );
        FOLD((formatted_message += fmt::format( "{} ", messages ) ), ...);
        logger_write_message( g_logger, category, formatted_message, e_log_entry::error, location );
    }

    template <typename... t_formattable> void
    FUNCTION log_error_format(
        cstring category,
        const fmt::format_string<t_formattable...> format,
        tyon::source_location location,
        t_formattable&&... data
    )
    {
        fstring message = fmt::format( format, std::forward<t_formattable>(data)... );
        logger_write_message( g_logger, category, message, e_log_entry::error, location );
    }

    template <typename T>
    struct thread_pointer
    {
        using t_self = thread_pointer<T>;
        T* value;

        explicit CONSTRUCTOR thread_pointer( T* arg = nullptr ) : value(arg) {}
        CONSTRUCTOR thread_pointer( void* arg ) : value((T*)arg) {}

        // Derference Operator
        PROC operator* ()  -> T&
        {   return (*value); }

        PROC operator-> () -> T*
        {   return (value) ;}

        /* Cast to any other pointer or pointer wrapper type, just returns the typed pointer

           Explicit to prevent auto-casts. Still pretty safe but convenient */
        template <typename t_pointer>
        explicit operator t_pointer()
        {
            return t_pointer { this->value };
        }
    };

    template <typename T>
    struct cpu_pointer
    {
        using t_self = cpu_pointer<T>;
        T* value;

        explicit CONSTRUCTOR cpu_pointer( T* arg = nullptr ) : value(arg) {}
        CONSTRUCTOR cpu_pointer( void* arg ) : value((T*)arg) {}

        // Derference Operator
        PROC operator* ()  -> T&
        {   return (*value); }

        PROC operator-> () -> T*
        {   return (value) ;}

        /* Cast to any other pointer or pointer wrapper type, just returns the typed pointer

           Explicit to prevent auto-casts. Still pretty safe but convenient */
        template <typename t_pointer>
        explicit operator t_pointer()
        {
            return t_pointer { this->value };
        }
    };

    template <typename T>
    struct gpu_pointer
    {
        using t_self = gpu_pointer<T>;
        T* value;

        explicit CONSTRUCTOR gpu_pointer( T* arg = nullptr ) : value(arg) {}
        CONSTRUCTOR gpu_pointer( void* arg ) : value((T*)arg) {}

        // Derference Operator
        PROC operator* ()  -> T&
        {   return (*value); }

        PROC operator-> () -> T*
        {   return (value) ;}

        /* Cast to any other pointer or pointer wrapper type, just returns the typed pointer

           Explicit to prevent auto-casts. Still pretty safe but convenient */
        template <typename t_pointer>
        explicit operator t_pointer()
        {
            return t_pointer { this->value };
        }
    };

    template <typename T>
    struct unified_pointer
    {
        using t_self = unified_pointer<T>;
        T* value;

        explicit CONSTRUCTOR unified_pointer( T* arg = nullptr ) : value(arg) {}
        CONSTRUCTOR unified_pointer( void* arg ) : value((T*)arg) {}

        // Derference Operator
        PROC operator* ()  -> T&
        {   return (*value); }

        PROC operator-> () -> T*
        {   return (value) ;}

        /* Cast to any other pointer or pointer wrapper type, just returns the typed pointer

           Explicit to prevent auto-casts. Still pretty safe but convenient */
        template <typename t_pointer>
        explicit operator t_pointer()
        {
            return t_pointer { this->value };
        }
    };

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

template <>
struct fmt::formatter< tyon::uid > : formatter<string_view>
{
    auto format( tyon::uid arg, format_context& context ) const -> format_context::iterator
    {
        using namespace tyon;
        // TYON_BREAK();
        tyon::uid tmp = arg;
        tyon::raw_pointer data = &arg.uuid;
        char hexbytes[] = "0123456789abcdefZZZZZZ";
        char formatted[40] {};

        // 8 bytes for full binary UUID
        // 32 bytes for full formatted string
        // 16 bytes for half string
        for (int i = 0; i < 8; ++i)
        {
            // Mask off half byte to find hex code
            // Remember that hex displays are always big endian so reverse byte order if little endian
            i32 left = tyon::g_little_endian;
            i32 right = 1 - tyon::g_little_endian;
            formatted[ left + (i * 2) ] = hexbytes[ (data[ 0 + i] & 0x0F) ];
            formatted[ right+ (i * 2) ] = hexbytes[ (data[ 0 + i] & 0xF0) >> 4 ];

            formatted[ left + 16+ (i * 2) ] = hexbytes[ (data[ 8 + i] & 0x0F) ];
            formatted[ right+ 16+ (i * 2) ] = hexbytes[ (data[ 8 + i] & 0xF0) >> 4 ];
        }
        tyon::fstring_view result = formatted;
        return formatter<fmt::string_view>::format( result, context );
    }
};

/* void*
   ::operator new( usize bytes );

   void*
   ::operator new[]( usize bytes );
   void
   ::operator delete(void* ptr) noexcept; */
