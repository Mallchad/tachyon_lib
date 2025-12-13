
// Base files
#include "../include_tachyon_lib_core.h"
#include "../build_control/tachyon_lib_unity_core.cpp"

#include "../tests/linked_list.cpp"

extern array<typed_procedure<void()>> g_tests_list;
array<typed_procedure<void()>> g_tests_list {};

int
main()
{
    tyon::library_context _library = {}; tyon::library_context_init( &_library );
    g_tests_list.push_tail( {} ) =  &test_linked_list;

    for (i32 i=0; i < g_tests_list.size(); ++i)
    {
        g_tests_list[i].invoke();
    }
    // TYON_BREAK();
}
