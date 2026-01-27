

project(
    'tachyon_lib', 'cpp', 'cuda',
     default_options : ['c_std=c11', 'cpp_std=c++17']
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
dep = dependency(
  'cuda', version : '>=10',
  # modules : ['cublas']
)

test1 = executable(
  'tachyon_lib_tests_core',
  'source/tests/tachyon_lib_tests_core.cpp',
  # 'external/fmt/src/format.cc',
  include_directories : include_dirs,
  dependencies: libraries

)

if tyon_cuda_on
test2 = executable(
  'tachyon_lib_tests_cuda',
  'source/tests/tachyon_lib_tests_cuda.cu',
  include_directories : cuda_includes,
  dependencies: libraries
)
endif

# Need to fill out
test3 =executable(
  'tachyon_lib_tests_linked_list',
  'source/tests/tachyon_lib_tests_core.cpp',
  # 'external/fmt/src/format.cc',
  include_directories : include_dirs,
  dependencies: libraries
)

test( 'tachyon_lib_tests_all', test1 )
test( 'tachyon_lib_tests_all', test2 )
test( 'tachyon_lib_tests_all', test3 )
