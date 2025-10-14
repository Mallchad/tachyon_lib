
namespace tyon
{


CONSTRUCTOR memory_heap_allocator::memory_heap_allocator()
{
        tyon_log( "New heap block" );
        buffer* block = &blocks.push_tail( {} );
        block->data = malloc( 400_MiB );
        block->size = 400_MiB;
}

PROC memory_heap_allocator::allocate_raw( isize bytes, isize alignment ) -> raw_pointer
{
    buffer* block = blocks.tail_address();
    bool add_block = (block->head_size + bytes + alignment > block->size);
    if (add_block)
    {
        tyon_log( "New heap block" );
        block = &blocks.push_tail( {} );
        block->data = malloc( 400_MiB );
        block->size = 400_MiB;
    }
    block  = blocks.tail_address();
    heap_entry* entry = &used.push_tail( {} )->value;
    isize alignment_bytes = binary_alignment( alignment, block->data + block->head_size );
    isize used_bytes = (alignment_bytes + bytes);
    raw_pointer result = (block->data + block->head_size + alignment_bytes);

    *entry = heap_entry {
        .data = result,
        .position = block->head_size,
        .size = used_bytes,
        .alignment = alignment
    };

    // Just unpoison the past after alignment
    memory_unpoison( result, bytes );
    block->head_size += used_bytes + 100
;
    tyon_logf( "bytes alignment block head size {} {} {} {}",
               bytes, alignment, block->size, block->head_size );
    if (result == nullptr)
    {
        tyon_log( "is nullptr");
    }
    tyon_logf( "Saved heap pointer {}", (void*)entry->data );
    ERROR_GUARD( result != nullptr, "What happened???" );
    ERROR_GUARD( entry->data == (void*)result, "Should be equal" );

    return result;
}

    PROC memory_heap_allocator::allocate_raw_fast( i64 bytes, isize alignment ) -> raw_pointer
    {
        return nullptr;
    }

    PROC memory_heap_allocator::allocate_relocate( void* reference, i64 bytes ) -> raw_pointer
    {
        auto iter = used.indexer_ranged( 0, used.nodes.size() );

        ERROR_GUARD( iter.do_iteration, "Christ what has gone wrong" );
        heap_entry* x_entry = nullptr;
        bool match = false;
        for (; iter.do_iteration; iter.forward())
        {
            x_entry = &iter.value->value;
            if (iter.value->value.data == reference)
            { match = true; break; }
        }
        if (match == false) {
            tyon_error( "Serious allocation failiure reallocating memory" );
            tyon_errorf( "Could not find entry associated with addres: {} bytes: {}",
                         reference, bytes );
            return nullptr;
        }

        // Allocate new storage
        raw_pointer result = this->allocate_raw( bytes );
        // // Move data to new memory
        memory_copy_raw( result, x_entry->data, x_entry->size - x_entry->alignment );
        this->deallocate( x_entry->data );

        // Move entry to free list
        free.push_tail( *x_entry );
        used.remove_node( iter.value );

        return result;
    }


    PROC memory_heap_allocator::deallocate( void* address ) -> void
    {
        tyon_logf( "Deleted heap pointer {}", (void*)address );
        auto iter = used.indexer_ranged( 0, used.nodes.size() );

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
        {   tyon_errorf( "Could not find entry associated with addres: {}", address );
            return;
        }

        // Move entry to free list
        free.push_tail( *x_entry );
        used.remove_node( iter.value );

    }
/** Clear all stored allocations and zero memory */
    PROC memory_heap_allocator::blank_all() -> void
    {}
    allocator_info memory_heap_allocator::get_memory_statistics()
    {
        return {};
    }


    PROC test_allocators() -> void
    {
        raw_pointer foo = (void*)0xDEADBEEF;
        ERROR_GUARD( foo == (void*)0xDEADBEEF, "Comparison isn't working " );
        memory_heap_allocator allocator;
        raw_pointer article_1 = allocator.allocate_raw( 100, 4 );
        raw_pointer good_ptr = allocator.allocate_relocate( article_1, 800 );
        raw_pointer bad_ptr = allocator.allocate_relocate( (void*)0x1234124, 400 );
        tyon_logf( "good_ptr: ", good_ptr != nullptr );
        tyon_logf( "bad_ptr: ", good_ptr != nullptr );

        linked_list<int> list;
        list.push_tail( 1 );
        list.push_tail( 2 );
        list.push_tail( 3 );
        list.push_tail( 4 );
        list.push_tail( 5 );
        list.push_tail( 6 );
        list.push_tail( 7 );
        list.push_tail( 8 );
        auto node = list.push_tail( 99 );
        // node->value = 3;
        // node_link<int> bad_node;
        // list.remove_node( &bad_node );

        node_link<int>* node_2 = list.insert_after( node, 4 );
        ERROR_GUARD( node_2->value == 4, "" );

        auto step = list.indexer_ranged( 0, list.list_size );
        auto iter = step; // copy
        ERROR_GUARD( step.do_iteration, "Failed indexer range check" );
        for (; step.do_iteration; step.forward() )
        {
            tyon_logf( "Node index: {} value: {}", step.index, step.value->value );
        }
        do
        {
            tyon_logf( "Node index: {} value: {}", iter.index, iter.value->value );
        } while( iter.forward() );
    }

}
