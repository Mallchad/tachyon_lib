

project(
    'tachyon_lib', 'cpp', 'cuda',
     default_options : ['cpp_std=c++20']
)

cmake = import( 'cmake' )

include_dirs = include_directories( 'source', 'external/fmt/include' )
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
tyon_cuda_on = true
cuda_dependency = [
  dependency(
  'cuda', version : '>=10',
  modules : ['cudart']
  # modules : ['cublas']
)
] + libraries

test1 = executable(
  'tachyon_lib_tests_core',
  'source/tests/tachyon_lib_tests_core.cpp',
  # 'external/fmt/src/format.cc',
  include_directories : include_dirs,
  dependencies: libraries

)

if tyon_cuda_on
# Broken
test2 = executable(
  'tachyon_lib_tests_cuda_meson',
  'source/tests/tachyon_lib_tests_cuda.cu',
  include_directories : cuda_includes,
  dependencies: cuda_dependency
)

# command structure used
# clear ; nvcc .\source\tests\tachyon_lib_tests_cuda.cu -std=c++20 -I .\external\fmt\include\ -lrpcrt4 -g
test2 = custom_target(
    'tachyon_lib_tests_cuda',
    build_by_default: true,
    install: true,
    install_dir: 'runtime',
    output : 'tachyon_lib_tests_cuda.exe',
    input : 'source/tests/tachyon_lib_tests_cuda.cu',
    command : [
      'nvcc',
      '@INPUT@',
      '-std=c++20',
      '-l', 'rpcrt4',
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

test( 'tachyon_lib_tests_all', test1 )
test( 'tachyon_lib_tests_all', test2 )
# test( 'tachyon_lib_tests_all', test3 )
