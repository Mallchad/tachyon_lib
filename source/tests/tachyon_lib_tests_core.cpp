
#include "../include_tachyon_lib_core.h"
// #include "../build_control/tachyon_lib_unity_core.cpp"
#include <numeric>

using namespace tyon;

extern array<typed_procedure<void()>> g_tests_list;
array<typed_procedure<void()>> g_tests_list {};

#include "test_linked_list.cpp"
// #include "ai_generated/iterator_requirements.cpp"

PROC test( bool condition ) -> void
{
    if (condition)
    {   TYON_LOG( "Passed!" );
    }
    else
    {   TYON_LOG( "Failed!" );
    }
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
    test_linked_list();
    // test_template_requirements();

    array<int> foo = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    i64 accumulated = std::accumulate( foo.begin(), foo.end(), 0 );
    TYON_LOG( "Accumulated value", accumulated );

    // Should not work properly
    // TYON_LOGF( "UUID from literal {}", uid("wutwut"_uuid) );
    u128 create_uuid_1 = "012345678-9ABC-DEFa-bcde-f6f9610e78b"_uuid;
    u128 create_uuid_2 = "41adfacc-0b27-4960-a052-6f9610e78b88a"_uuid;
    TYON_LOGF( "UUID from literal {}", uid(create_uuid_1) );
    TYON_LOGF( "UUID from literal {}", uid(create_uuid_2) );
    u128 ref_uuid_1 = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF,
                        0xab, 0xcd, 0xef, 0x6f, 0x96, 0x10, 0xe7, 0x8b  };
    test( memory_same( ref_uuid_1, create_uuid_1) );

    TYON_LOG( "Program ended" );
}
