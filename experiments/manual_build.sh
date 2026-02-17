#!/usr/bin/env bash

# cd to script directory
self_directory="$(dirname $(readlink -f $0))"
echo "cd to '${self_directory}'"
cd "${self_directory}"
mkdir -p "../build"
cd "../build"

function build_gcc()
{
    echo "Building with gcc"
    # NOTE: Linux only.
    g++ ../source/build_control/tachyon_lib_unity_core.cpp -std=c++20 --compile -o core.o &
    g++ ../source/tests/tachyon_lib_tests_core.cpp -std=c++20 --compile -o tests_core.o  &
    wait
    g++ core.o tests_core.o -luuid

}

function build_clang()
{
    echo "Building with clang"
    # NOTE: Linux only.
    clang++ ../source/build_control/tachyon_lib_unity_core.cpp -std=c++20 --compile -o core.o &
    clang++ ../source/tests/tachyon_lib_tests_core.cpp -std=c++20 --compile -o tests_core.o  &
    wait
    clang++ core.o tests_core.o -luuid

}

time build_gcc
time build_clang
