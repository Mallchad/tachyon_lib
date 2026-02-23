
#pragma once

namespace tyon
{
FORWARD struct thread_subsystem;
/** Supervisor of all threads */
extern thread_subsystem* g_thread_subsystem;

    /////////////////////////////
////// -- Threading Library -- /////////////////////////////////////////////////
    /////////////////////////////

struct thread_options
{
    // < 16 bytes for UNIX
    fstring short_name;
    fstring name;
    fstring description;
    /** Unfortunately the meaning  of this is fairly arbitrary  and not portable
        across platforms.  But it is really  important this is a number, and not
        just a flag- because it  becomes extremely important when doing realtime
        scheduling  tasks  where priority  and  schedling  time becomes  a  hard
        dependency order / hard execution time slice requirement.

        TODO: We will provide enums that map to priority for general usage later */
    i32 scheduler_priority;
    // How much memory to increase the arena size by each time
    i64 permanant_block_size;
    i64 scratch_block_size;
    // allocator_type
};

struct thread_context
{
    uid id;
    i_allocator* permanant = nullptr;
    i_allocator* scratch = nullptr;
    tyon::thread_options options;
};

 struct thread_subsystem
{
    array<thread_context*> threads;
};

/* Not applicable to windows, has to be done upfront */
PROC thread_self_background_priority() -> fresult;

PROC thread_self_name( fstring name ) -> fresult;

/** Creates and initializes a thread_context for g_thread. */
PROC thread_self_init( thread_options options ) -> fresult;

PROC thread_destroy( thread_context* arg = g_thread ) -> void;

/** Performs cooperate interupt tasks on the curent thread.

    Returns true if the threading subsystem wants this thread to exit as soon as possible. */
PROC thread_self_interupt( bool throw_on_interupt = false ) -> fresult;

}
