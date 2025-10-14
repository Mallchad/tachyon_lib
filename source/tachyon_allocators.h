
#pragma once

namespace tyon
{

struct heap_entry
{
    raw_pointer data;
    i64 position;
    i64 size;
    i64 alignment;
};

struct memory_heap_allocator final : i_allocator
{
    // using entry
    linked_list<heap_entry> used;
    linked_list<heap_entry> free;
    array<buffer> blocks;

    CONSTRUCTOR memory_heap_allocator();

    PROC allocate_raw( isize bytes, isize alignment = 1 ) -> raw_pointer override;
    PROC allocate_raw_fast( i64 bytes, isize alignment = 1 ) -> raw_pointer override;
    // realloc compat function
    PROC allocate_relocate( void* reference, i64 bytes ) -> raw_pointer override;
    PROC deallocate( void* address ) -> void override;
    /** Clear all stored allocations and zero memory */
    PROC blank_all() -> void override;
    PROC get_memory_statistics() -> allocator_info override;
};

PROC test_allocators() -> void;

};
