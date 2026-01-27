#!/usr/bin/env bash

build_log()
{
    echo -E "[Tachyon Build]    ${@}"
}

# cd to script directory
self_directory="$(dirname $(readlink -f $0))"
build_log "cd to '${self_directory}'"
cd "${self_directory}"

nice -n20 python3 build.py $@
