

project(
    'tachyon_lib', 'cpp', 'cuda',
     default_options : ['cpp_std=c++20']
)

fs = import('fs')
cmake = import( 'cmake' )

include_dirs = include_directories(
  'source',
  'external/fmt/include',
  # Not needed in unity build
  'external/catch2/src/'
)
cuda_includes = include_directories( 'source', 'external/fmt/include', 'source/cuda' )
libraries = [  ]

cpp = meson.get_compiler('cpp')
system_name = host_machine.system()
if system_name == 'linux'
  message( 'Platform: Linux' )
  libraries += dependency('uuid')
elif system_name == 'windows'
    message( 'Platform: Windows' )
    libraries += cpp.find_library('rpcrt4', required: true)
endif

cuda = import('unstable-cuda')
tyon_cuda_on = false
cuda_dependency = [
  dependency(
  'cuda', version : '>=10',
  modules : ['cudart']
  # modules : ['cublas']
)
] + libraries

compiler_args = [
    '-Werror=all',
    '-Wextra',
    '-Wpedantic',

    '-Wno-unused-parameter',
    '-Wno-unused-variable'
  ]

test_core = executable(
  'tachyon_lib_tests_core',
  'source/build_control/tachyon_lib_unity_core.cpp',
  'source/tests/tachyon_lib_tests_core.cpp',
  # 'external/fmt/src/format.cc',
  include_directories : include_dirs,
  dependencies: libraries,
  cpp_args: compiler_args
)

test_catch2_core = executable(
  'tachyon_lib_tests_catch2_core',
  'source/build_control/tachyon_lib_unity_core.cpp',
  'source/tests/unity_catch2_core.cpp',
  # 'external/fmt/src/format.cc',
  include_directories : include_dirs,
  dependencies: libraries,
  cpp_args: compiler_args

)

test('', executable(
  'tachyon_lib_tests_part_1',
  'source/build_control/tachyon_lib_unity_core.cpp',
  'source/tests/ai_generated/iterator_requirements.cpp',
  # 'external/fmt/src/format.cc',
  include_directories : include_dirs,
  dependencies: libraries

))

if tyon_cuda_on
  # command structure used
  # clear ; nvcc .\source\tests\tachyon_lib_tests_cuda.cu -std=c++20 -I .\external\fmt\include\ -lrpcrt4 -g
  uuid_flag = ''
  if  system_name == 'linux'
    uuid_flag = '-luuid'
  else
    uuid_flag = '-lrpcrt4'
  endif

  test2 = custom_target(
    'tachyon_lib_tests_cuda',
    build_by_default: true,
    install: true,
    install_dir: 'runtime',
    output : 'tachyon_lib_tests_cuda.so',
    input : 'source/tests/tachyon_lib_tests_cuda.cu',
    command : [
      'nvcc',
      '@INPUT@',
      '-std=c++20',
      # Forcefully interpret library as CUDA C++
      '-o', '@OUTPUT@',
      '-I', '../external/fmt/include',
      '-g',
      '-D', 'CCCL_ENABLE_ASSERTIONS=1',
      uuid_flag
    ]
  )
  test( 'tachyon_lib_tests_all', test2 )

# NOTE: Custom command to test VMEC setup
uuid_library = 'uuid'
tachyon_lib_cuda = custom_target(
    'tachyon_lib_cuda',
    build_by_default: true,
    install: true,
    install_dir: 'runtime',
    output : 'tachyon_lib_cuda.so',
    input : 'source/build_control/tachyon_lib_unity_core.cpp',
    command : [
      'nvcc',
      '@INPUT@',
      # Generated shared library
      '--shared',
      '--relocatable-device-code=true',
      # Need to tell Linux compiler to make code position independent too
      '--compiler-options', '-fPIC',
      '--device-link',

      # Forcefully interpret library as CUDA C++
      '-x', 'cu',
      '-std=c++20',
      '-l', uuid_library,
       # cPTX Linker Verbose help
      '--ptxas-options=--verbose',
      '-o', '@OUTPUT@',
      '-I', '../external/fmt/include',
      '-g',
      '-D', 'CCCL_ENABLE_ASSERTIONS=1'
    ]
  )
endif

# # Need to fill out
# test3 = executable(
#   'tachyon_lib_tests_linked_list',
#   'source/tests/tachyon_lib_tests_core.cpp',
#   # 'external/fmt/src/format.cc',
#   include_directories : include_dirs,
#   dependencies: libraries
# )

# test( 'tachyon_lib_tests_all', test_core )
test( 'catch2_core', test_catch2_core,
    args: [
      # Show output even on test
      '--success',
      # Show execution time of each test
      '--durations=yes',
      # Print to standard output/console
      '--reporter=console',
      # Print to files also
      '--reporter=console::out=tachyon_catch2_test_log.txt',
      '--reporter=json::out=tachyon_catch2_test_log.json',
      '--reporter=json::out=tachyon_catch2_test_log.xml',
      '--reporter compact::out=tachyon_catch2_test_log.compact.txt'
    ]
    )
# test( 'tachyon_lib_tests_all', test3 )
