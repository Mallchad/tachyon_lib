
// Not including on purpose because we're testing tachyon lib as a shared library
// #include "../build_control/tachyon_lib_unity_core.cpp"

#include "../include_tachyon_lib_core.h"

using namespace tyon;
#if REFLECTION_COMPILER_CUDA
    #pragma message "Compiling for CUDA"
#endif

extern array<typed_procedure<void()>> g_tests_list;
array<typed_procedure<void()>> g_tests_list {};

TYON_CUDA_KERNEL void test_kernel()
{
    // tyon::v3_f32 foo;
    // foo = foo * foo;
    f32 test_float = tyon::square_root( 5.0f );
    printf( "yep yep \n" );
}

int main( int argc, char** argv )
{
    tyon::library_context _library = {}; tyon::library_context_init( &_library );
    // g_tests_list.push_tail( {} ) =  &test_linked_list;
    tyon::library_process_cmdline_args( argc, argv );

    for (i32 i=0; i < g_tests_list.size(); ++i)
    {
        g_tests_list[i].invoke();
    }

    auto* foo = tyon::memory_allocate<v3_f32>( 10000 );
    // test_kernel <<< 1, 100 >>> ();

    TYON_LOG( "Program ended" );
}
