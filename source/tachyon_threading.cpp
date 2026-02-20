
namespace tyon
{

thread_subsystem* g_thread_subystem = nullptr;
thread_local thread_context* g_thread = nullptr;

PROC thread_self_init( thread_options options ) -> fresult
{
    g_thread = memory_allocate<thread_context>( 1 );
    g_thread->options = options;
    // Initialize ID
    g_thread->id = uuid_generate();

    tyon::thread_self_name( options.short_name );
    // >0 is "less priority" == 0 means normal priority
    if (options.scheduler_priority > 0)
    { tyon::thread_self_background_priority(); }

    ERROR_GUARD( (options.permanant_block_size > 0) && (options.permanant_block_size < 10_GiB),
                 "allocator block sizes must be reasonable" );
    ERROR_GUARD( (options.scratch_block_size > 0) && (options.scratch_block_size < 10_GiB),
                 "allocator block sizes must be reasonable" );

    g_thread->permanant = memory_allocate_raw( sizeof(memory_stack_allocator) );
    new(g_thread->permanant) memory_stack_allocator( options.permanant_block_size );
    g_thread->scratch = memory_allocate_raw( sizeof(memory_stack_allocator) );
    new(g_thread->scratch) memory_stack_allocator( options.scratch_block_size );
    return true;
}

PROC thread_destroy( thread_context* arg ) -> void
{
    TYON_LOGF( "Destroying thread '{:<10}' {}", g_thread->options.name, g_thread->id );
    TYON_LOG( "Thread statistics at cleanup: " );
    TYON_LOGF( "{:<10}", g_thread->permanant->get_memory_statistics() );
    TYON_LOGF( "{:<10}", g_thread->scratch->get_memory_statistics() );
    g_thread->scratch->~i_allocator();
    g_thread->permanant->~i_allocator();
    g_thread->~thread_context();

}

PROC thread_self_interupt( bool throw_on_interupt ) -> fresult
{
    // No internal signal for thread interupts yet. Just do interupt handling tasks
    return false;
}


}
