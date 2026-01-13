
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
        std::source_location call_point
    ) -> void;
};

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
    };

    void
    library_context_init( library_context* arg );

}
