
#include "../build_control/tachyon_lib_unity_core.cpp"

using namespace tyon;

extern array<typed_procedure<void()>> g_tests_list;
array<typed_procedure<void()>> g_tests_list {};

#include "test_linked_list.cpp"

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
    // TYON_BREAK();
}
