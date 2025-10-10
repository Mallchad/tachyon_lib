
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
    heap_entry* entry = &entries.push_tail( {} )->value;
    isize alignment_bytes = binary_alignment( alignment, block->data + block->head_size );
    isize used_bytes = (block->head_size + alignment_bytes);
    raw_pointer result = (block->data + used_bytes);

    *entry = heap_entry {
        .presented_pointer = result,
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

    linked_list<int> list;
    list.push_tail( 1 );
    list.push_tail( 2 );
    auto node = list.push_tail( 99 );
    // node->value = 3;

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
