

project(
    'tachyon_lib', 'cpp'
)

cmake = import( 'cmake' )

include_dirs = include_directories( 'source' )
libraries = []

if host_machine.system() == 'linux'
  message( 'Platform: Linux' )
  libraries += dependency('uuid')
endif

executable(
  'tachyon_lib_tests_core',
  'source/tests/tachyon_lib_tests_core.cpp',
  include_directories : include_dirs,
  dependencies: libraries

)

# Need to fill out
executable(
  'tachyon_lib_tests_linked_list',
  'source/tests/tachyon_lib_tests_core.cpp',
  include_directories : include_dirs,
  dependencies: libraries
)
