
namespace tyon
{


CONSTRUCTOR memory_heap_allocator::memory_heap_allocator()
{
        TYON_LOG( "New heap block" );
        buffer* block = &blocks.push_tail( {} );
        block->data = malloc( 400_MiB );
        block->size = 400_MiB;
}

PROC memory_heap_allocator::allocate_raw( isize bytes, isize alignment ) -> raw_pointer
{
    std::scoped_lock _lock( this->lock );
    buffer* block = blocks.tail_address();
    bool add_block = (block->head_size + bytes + alignment > block->size);
    if (add_block)
    {
        TYON_LOG( "New heap block" );
        block = &blocks.push_tail( {} );
        block->data = malloc( 400_MiB );
        block->size = 400_MiB;
    }
    block = blocks.tail_address();
    node_link<heap_entry>* new_node = used.push_tail( {} );
    heap_entry* entry = &new_node->value;
    isize alignment_bytes = memory_padding( alignment, block->data + block->head_size );
    const i64 redzone_min_size = 64;
    isize redzone_size = redzone_min_size + memory_padding(
        alignment,
        (block->data + block->head_size + alignment + redzone_min_size)
    );
    isize used_bytes = (alignment_bytes + bytes + redzone_min_size);
    raw_pointer result = (block->data + block->head_size + alignment_bytes);

    *entry = heap_entry {
        .data = result,
        .position = block->head_size,
        .size = used_bytes,
        .active_size = bytes,
        .alignment = alignment,
        .id = 0
    };

    // Just unpoison the part after alignment.
    // Leave the redzone poisioned
    memory_unpoison( result, bytes );
    block->head_size += used_bytes + 100;
    TYON_LOGF( "bytes alignment block head size {} {} {} {}",
               bytes, alignment, block->size, block->head_size );

    return result;
}

    PROC memory_heap_allocator::allocate_raw_fast( i64 bytes, isize alignment ) -> raw_pointer
    {
        std::scoped_lock _lock( this->lock );
        return nullptr;
    }

    PROC memory_heap_allocator::allocate_relocate( void* reference, i64 bytes ) -> raw_pointer
    {
        std::scoped_lock _lock( this->lock2 );

        heap_entry x_entry {};
        node_link<heap_entry>* x_node = used.head();
        bool match = false;
        const i32 node_limit = 100'000;
        i32 i = 0;
        for (; i < node_limit; ++i)
        {
            x_entry = x_node->value;
            if (x_entry.data == reference)
            { match = true; break; }

            // DEBUG: Really really slow
            // TYON_LOGF( "Checking entry with address {} bytes {}",
                       // (void*)(x_entry.data), x_entry.size );
            if (x_node->next == -1)
            {   break; }
            x_node = &used.nodes[ x_node->next ];
        }
        if (match == false) {
            TYON_ERROR( "Serious allocation failiure reallocating memory" );
            TYON_ERRORF( "Could not find entry associated with addres: {}\n"
                         "bytes: {}\n"
                         "iterations: {}",
                         reference, bytes, i );
            return nullptr;
        }

        // Move entry to free list
        // NOTE: Do this before allocating to prevent pointer invalidation
        free.push_tail( x_entry );
        used.remove_node( x_node );

        // Allocate new storage
        raw_pointer result = this->allocate_raw( bytes );
        // // Move data to new memory
        memory_copy_raw( result, x_entry.data, x_entry.active_size );

        return result;
    }

    PROC memory_heap_allocator::deallocate( void* address ) -> void
    {
        // NOTE: Passing nullptr is a valid operation, simplifies error handlig.
        if (address == nullptr) { return; }

        std::scoped_lock _lock( this->lock );
        TYON_LOGF( "Deleted heap pointer {}", (void*)address );
        auto iter = used.indexer_full();

        ERROR_GUARD( iter.do_iteration, "Christ what has gone wrong" );
        heap_entry* x_entry = nullptr;
        bool match = false;
        for (; iter.do_iteration; iter.forward())
        {
            x_entry = &iter.value->value;
            if (iter.value->value.data == address)
            { match = true; break; }
        }
        if (match == false)
        {   TYON_ERRORF( "Could not find entry associated with addres: {}", address );
            return;
        }

        // Move entry to free list
        free.push_tail( *x_entry );
        used.remove_node( iter.value );
        TYON_LOGF( "DEALLOCATE NEW LIST SIZE: {}", used.list_size );
    }
/** Clear all stored allocations and zero memory */
    PROC memory_heap_allocator::blank_all() -> void
    {
        std::scoped_lock _lock( this->lock );
    }
    allocator_info memory_heap_allocator::get_memory_statistics()
    {
        std::scoped_lock _lock( this->lock );
        return {};
    }

}
