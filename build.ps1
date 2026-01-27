#!/usr/bin/env powershell

# TODO: Check if in developer powershell prompt if user wants to build under MSVC

function build_log ($message)
{
    Write-Output "[Tachyon Build]    $message"
}

build_log "Starting up python script"
python3 build.py $args
