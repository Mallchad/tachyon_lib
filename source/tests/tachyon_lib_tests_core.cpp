
#include "../include_tachyon_lib_core.h"
// #include "../build_control/tachyon_lib_unity_core.cpp"
#include <numeric>
#include <random>

using namespace tyon;

extern array<typed_procedure<void()>> g_tests_list;
array<typed_procedure<void()>> g_tests_list {};

// #include "ai_generated/iterator_requirements.cpp"

i32 tests_passed = 0;
i32 tests_failed = 0;

PROC test( bool condition, fstring description = "" ) -> void
{
    if (condition)
    {   TYON_BASE_LOGF( "Tachyon Test", "Passed! | {}", description );
        ++tests_passed;
    }
    else
    {   TYON_BASE_LOGF( "Tachyon Test",  "Failed! | {}", description );
        ++tests_failed;
    }
}

#include "test_linked_list.cpp"

PROC test_allocators() -> void
{
    raw_pointer foo = (void*)0xDEADBEEF;
    ERROR_GUARD( foo == (void*)0xDEADBEEF, "Comparison isn't working " );
    test( foo == (void*)0xDEADBEEF, "'raw_pointer' comparison to 'void*'" );
    memory_heap_allocator allocator;
    raw_pointer article_1 = allocator.allocate_raw( 100, 4 );
    raw_pointer good_ptr = allocator.allocate_relocate( article_1, 800 );

    // Breaks as it should?
    // raw_pointer bad_ptr = allocator.allocate_relocate( (void*)0x1234124, 400 );
    TYON_LOGF( "good_ptr: ", good_ptr != nullptr );
    TYON_LOGF( "bad_ptr: ", good_ptr != nullptr );

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
    test( node_2->value == 4, "undocumented" );

    auto step = list.indexer_full();
    auto iter = step; // copy
    ERROR_GUARD( step.do_iteration, "Failed indexer range check" );
    test( step.do_iteration, "linked_list<> indexer range check" );
    for (; step.do_iteration; step.forward() )
    {
        TYON_LOGF( "Node index: {} value: {}", step.index, step.value->value );
    }
    do
    {
        TYON_LOGF( "Node index: {} value: {}", iter.index, iter.value->value );
    } while( iter.forward() );

    std::random_device hardware_rng;
    std::default_random_engine rand_engine(hardware_rng());
    std::uniform_int_distribution<> rand( 0, 40000);
    std::uniform_int_distribution<> rand_alignment( 0, 40000);
    tyon::array<i32> random_list;
    random_list.resize( 10'000 );
    random_list.map_procedure( [&](i32& arg){
        arg = rand( rand_engine ); });

    memory_heap_allocator heap1;
    array<void*> allocate_raw_1;
    array<void*> deallocate_1;
    random_list.map_procedure( [&](i32& arg){
        if (arg > 20000)
        {
            allocate_raw_1.push_tail( heap1.allocate_raw( arg, rand_alignment( rand_engine ))
            );
        }
        else
        {
            deallocate_1.push_tail( allocate_raw_1.pop_tail( ) );
        }

    });


}

int
main( int argc, char** argv )
{
    tyon::library_context _library = {}; tyon::library_context_init( &_library );
    g_tests_list.push_tail( {} ) =  &test_linked_list;
    tyon::library_process_cmdline_args( argc, argv );

    for (i32 i=0; i < g_tests_list.size(); ++i)
    {
        g_tests_list[i].invoke();
    }
    // test_template_requirements();

    array<int> foo = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    i64 accumulated = std::accumulate( foo.begin(), foo.end(), 0 );
    test( accumulated == 55, "Sum tyon::array using STL iterator" );
    TYON_LOG( "Accumulated value", accumulated );

    // Should not work properly
    // TYON_LOGF( "UUID from literal {}", uid("wutwut"_uuid) );
    // constexpr u128 bad_uuid = "wutwut"_uuid;
    // TYON_LOGF( "UUID from literal constexpr {}", uid(bad_uuid) );

    u128 create_uuid_1 = "012345678-9ABC-DEFa-bcde-f6f9610e78b"_uuid;
    u128 create_uuid_2 = "41adfacc-0b27-4960-a052-6f9610e78b88"_uuid;
    TYON_LOGF( "UUID from literal {}", uid(create_uuid_1) );
    TYON_LOGF( "UUID from literal {}", uid(create_uuid_2) );
    u128 ref_uuid_1 = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF,
                        0xab, 0xcd, 0xef, 0x6f, 0x96, 0x10, 0xe7, 0x8b  };
    test( memory_same( ref_uuid_1, create_uuid_1), "UUID creation matches reference bytes" );

    // SECTION: Entity testing
    {
        entity_type_definition<file> _;
        // TODO: Need to rework, already registered by entity, need to test custom type
        // entity_type_register<file>();
        test( g_entity_type<file>, "Type-Specific Entity Cotnext is initialized" );
        file* test_file = entity_allocate<file>();

        *test_file = file_load_binary( "latest.log" );
        test( test_file, "File entity loaded real file" );
        if (test_file)
        {   test( test_file->memory.size, "File entity loaded file with some decent size" );
            fstring file_read = { test_file->memory.data, 50 };
            TYON_LOGF( "Random file read string: '{}' File Memory Size:{}", file_read, test_file->memory.size );
            test( file_read.size(), "String copy from file entity loaded memory" );
        }
    }
    {
        entity_type_definition<file> _;
        file* test_file = entity_allocate<file>();
        fstring test_file_name = "random_name";
        test_file->name = test_file_name;
        entity_init( test_file );         test( true, "entity_init() compilation" );
        entity_tick( test_file );         test( true, "entity_tick() compilation" );
        entity_destroy( test_file );      test( true, "entity_destroy() compilation" );

        file* test_file2 = entity_search<file>( test_file->id ).copy_default(nullptr);
        bool test_file_id_match = false;
        if (test_file2)
        {   test_file_id_match = (test_file2->id == test_file->id);
        }
        file* test_file3 = entity_search_name<file>( test_file_name ).copy_default(nullptr);
        bool test_file_id_match_2 = false;
        if (test_file3)
        {   test_file_id_match_2 = (test_file3->id == test_file->id);
        }
        test( test_file2, "Entity search returns match");
        test( test_file_id_match, "Search entity result matches original ID" );
        test( test_file3, "Search entity by name" );
        test( test_file_id_match_2, "Search entity by name result matches original ID" );
    }

    test_allocators();

    test( memory_padding( 4,  (void*)0xDEAD ) == 3,  "memory_padding" );
    test( memory_padding( 16, (void*)0xF003 ) == 13, "memory_padding" );
    test( memory_padding( 2,  (void*)0x0ad3 ) == 1,  "memory_padding" );
    test( memory_padding( 25, (void*)0x2afd ) == 20, "memory_padding" );
    test( memory_padding( 4,  (void*)0x0021 ) == 3,  "memory_padding" );

    test( memory_padding( 4,    0xDEAD ) == 3,  "memory_padding" );
    test( memory_padding( 16,   0xF003 ) == 13, "memory_padding" );
    test( memory_padding( 2,    0x0ad3 ) == 1,  "memory_padding" );
    test( memory_padding( 25,   0x2afd ) == 20, "memory_padding" );
    test( memory_padding( 4,    0x0021 ) == 3,  "memory_padding" );

    test( memory_align( 0xDEAD,  4 ) == 0xDEB0,  "memory_align" );
    test( memory_align( 0xF003, 16 ) == 0xF010,  "memory_align" );
    test( memory_align( 0x0ad3,  2 ) == 0x00ad4, "memory_align" );
    test( memory_align( 0x2afd, 25 ) == 0x2b11,  "memory_align" );
    test( memory_align( 0x0021,  4 ) == 0x0024,  "memory_align" );
    test( memory_align( 0x0021,  64 ) == 0x0040,  "memory_align" );

    test( memory_align_typed<i32>( 1, 64) == 64, "memory_align_typed" );

    TYON_LOG( "Program ended" );
    TYON_LOGF( "Tests Passed: {}", tests_passed );
    TYON_LOGF( "Tests Failed: {}", tests_failed );
    return (tests_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
