
namespace tyon
{


PROC memory_heap_allocator::allocate_raw( isize bytes, isize alignment ) -> raw_pointer
{
    buffer* block = blocks.tail_address();
    bool add_block = (blocks.size() == 0);
    if (add_block)
    {
        block = &blocks.push_tail( {} );
        block->data = malloc( 400_MiB );
        block->size = 400_MiB;
    }
    heap_entry* entry = &used.push_tail( {} )->value;
    isize alignment_bytes = binary_alignment( alignment, block->data + block->head_size );
    isize used_bytes = (block->head_size + alignment_bytes + bytes);
    raw_pointer result = (block->data + used_bytes);

    *entry = heap_entry {
        .data = result,
        .position = block->head_size,
        .size = used_bytes,
        .alignment = alignment
    };

    // Just unpoison the past after alignment
    memory_unpoison( result, bytes );
    block->head_size += used_bytes;

    return result;
}

PROC memory_heap_allocator::allocate_raw_fast( i64 bytes, isize alignment ) -> raw_pointer
{
    return nullptr;
}

PROC memory_heap_allocator::allocate_relocate( void* reference, i64 bytes ) -> raw_pointer
{
    linked_list<heap_entry>::indexer iter = used.indexer_ranged( 0, used.nodes.size() );
    heap_entry* x_entry = nullptr;
    bool match = false;
    for (; iter.do_iteration; iter.forward())
    {
        x_entry = &iter.value->value;
        if (iter.value->value.data == reference)
        { match = true; break; }
    }
    if (match == false) { return nullptr; }

    // Allocate new storage
    raw_pointer result = this->allocate_raw( bytes );
    // Move data to new memory
    memory_copy_raw( result, x_entry->data, x_entry->size );
    this->deallocate( x_entry->data );

    // Move entry to free list
    free.push_tail( *x_entry );
    used.remove_node( iter.value );

    return result;
}


PROC memory_heap_allocator::deallocate( void* address ) -> void
{}
/** Clear all stored allocations and zero memory */
PROC memory_heap_allocator::blank_all() -> void
{}
allocator_info memory_heap_allocator::get_memory_statistics()
{
    return {};
}


PROC test_allocators() -> void
{

    memory_heap_allocator allocator;
    raw_pointer article_1 = allocator.allocate_raw( 100, 4 );
    raw_pointer good_ptr = allocator.allocate_relocate( article_1, 800 );
    raw_pointer bad_ptr = allocator.allocate_relocate( (void*)0x1234124, 400 );
    tyon_logf( "good_ptr: ", good_ptr != nullptr );
    tyon_logf( "bad_ptr: ", good_ptr != nullptr );

    linked_list<int> list;
    list.push_tail( 1 );
    list.push_tail( 2 );
    auto node = list.push_tail( 99 );
    // node->value = 3;
    // node_link<int> bad_node;
    // list.remove_node( &bad_node );

    node_link<int>* node_2 = list.insert_after( node, 4 );
    ERROR_GUARD( node_2->value == 4, "" );

    auto indexer = list.indexer_ranged( 0, 3 );
    ERROR_GUARD( indexer.error == false, "Failed indexer range check" );
    for (auto step = indexer.value; step.do_iteration; step.forward() )
    {
        tyon_logf( "Node index: {} value: {}", step.index, step.value->value );
    }
    auto iter = indexer.value;
    do
    {
        tyon_logf( "Node index: {} value: {}", iter.index, iter.value->value );
    } while( iter.forward() );
}

}
