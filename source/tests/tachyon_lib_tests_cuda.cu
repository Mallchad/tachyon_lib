
#include "../build_control/tachyon_lib_unity_core.cpp"

using namespace tyon;

extern array<typed_procedure<void()>> g_tests_list;
array<typed_procedure<void()>> g_tests_list {};

__device__ static int test_device_func_1()
{
    return 1;
}

TYON_CUDA_KERNEL void test_kernel()
{
    tyon::v3_f32 foo = 5;
    foo = foo * foo;
    f32 test_float = tyon::square_root( foo.x );
    printf( "yep yep \n" );
    __trap();
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
    test_kernel <<< 1, 100 >>> ();
    cudaDeviceSynchronize();

    TYON_LOG( "Program ended" );
}
