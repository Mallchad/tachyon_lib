
#include "../build_control/tachyon_lib_unity_core.cpp"
#include <numeric>

using namespace tyon;

extern array<typed_procedure<void()>> g_tests_list;
array<typed_procedure<void()>> g_tests_list {};

#include "test_linked_list.cpp"
// #include "ai_generated/iterator_requirements.cpp"

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

    TYON_LOG( "Program ended" );
}
