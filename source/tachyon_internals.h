
#pragma once

namespace tyon
{
// Default allocator for logger
template <typename T, usize align = 0>
struct log_allocator
{
    using value_type = char;
    using pointer_type = char*;
    using size_type = usize;
    using difference_type = std::ptrdiff_t;
    // using propagate_on_container_move_assignment = std::false_type;
    // using is_always_equal = std::true_type;
    // using rebind = void;

    template <typename t_allocator>
    struct rebind
    { using other = log_allocator<t_allocator, align>; };

    CONSTRUCTOR log_allocator() = default;

    PROC allocate( usize bytes, const void* hint = 0 )  -> T*
    {
        return memory_allocate_raw( bytes );
    }

    PROC deallocate( T* address, usize bytes )
    {
        return;
    }

};
template<typename A, typename B>
bool operator== ( log_allocator<A>& lhs, log_allocator<B>& rhs)
{ return true; }

template<typename A, typename B>
bool operator!= ( log_allocator<A>& lhs, log_allocator<B>& rhs)
{ return false; }

struct log_entry
{
    // using log_string = std::basic_string< char, std::char_traits<char>, log_allocator<char, 0> >;
    using log_string = fstring;

    e_log_entry type;
    log_string category;
    log_string message;
    time_date timestamp;
    source_location call_point;
};

FORWARD template <class> struct array;
// FORWARD template <class T = typename tyon::log_entry> struct array;
struct logger
{
    i32 flushed_messages = 0;
    tyon::string messages;
    array<log_entry> entries;
    bool console_output_enabled = true;
    bool string_output_enabled = true;

    std::mutex write_lock;
    fstring log_filename = "latest.log";
    FILE* log_file = nullptr;

    void
    write_error_simple( fstring message );

    PROC write_message(
        fstring category,
        fstring message,
        e_log_entry type,
        tyon::source_location call_point
    ) -> void;
};

    enum class e_primitive : u8
    {
        none       = 0,
        any        = 1,
        integer_   = 2,
        float_     = 3,
        boolean_   = 4,
        character_ = 5,
        byte_      = 6,
        pointer_   = 7,
        string_    = 8
    };

    PROC string_cast( e_primitive arg ) -> fstring;

    struct dynamic_primitive
    {   union
        {   i64 integer_;
            f64 float_;
            bool boolean_;
            char character_;
            byte byte_;
            raw_pointer pointer_;
            fstring string_;
        };
        e_primitive type;

        PROC get_string() -> monad<fstring>;

        CONSTRUCTOR dynamic_primitive();

        CONSTRUCTOR dynamic_primitive( const dynamic_primitive& arg );

        PROC operator= ( const dynamic_primitive& rhs ) -> dynamic_primitive&;

        PROC operator= ( const fstring& rhs ) -> dynamic_primitive&;

        PROC operator= ( int rhs ) -> dynamic_primitive&;

        /** Internal deduplication helper */
        PROC copy_from( const dynamic_primitive& rhs ) -> dynamic_primitive&;

        /** Internal container reset */
        PROC clean_old() -> void;

        DESTRUCTOR ~dynamic_primitive();

    };

    /** Copy and swap helper */
    void swap( dynamic_primitive& a, dynamic_primitive& b );

    struct cmdline_argument
    {
        fstring original;
        fstring original_value;
        fstring name;
        dynamic_primitive value;
        bool requires_value = false;
        bool is_value = false;
    };

    PROC string_to_i64( fstring arg ) -> monad<i64>;
    PROC string_to_f64( fstring arg ) -> monad<f64>;
    PROC string_cmdline_parse( fstring arg ) -> cmdline_argument;

    // Needs to be the very last thing because it contains everything
    struct library_context
    {
        bool initialized = false;
        /** I swear to god I have to quite an operating system just to kill the
            ginormous penalty of asking for a large amount of memory nicely */
        memory_stack_allocator global_allocator = memory_stack_allocator( 400_MiB );
        std::mutex global_allocator_lock;
        // Temporary. Needs to be removed when we have a proper global allocator
        std::mutex taint_allocator_lock;
        logger default_logger;
        logger switch_logger;
        raw_pointer null_read;
        raw_pointer null_write;
        array<cmdline_argument> cmdline_arguments;
    };

    void
    library_context_init( library_context* arg );

    PROC library_process_cmdline_args( int argc, char** argv ) -> void;

}
