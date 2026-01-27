

import argparse
import os
import subprocess
import sys
import shutil
import stat
import time
from datetime import datetime, timezone

dry_run = False

# Self-Script Information
script_name = os.path.basename(sys.argv[0])
script_dir_relative = os.path.dirname(sys.argv[0])
script_dir_absolute = os.path.realpath(script_dir_relative)

def vmec_log(*vargs):
    # Convert to nanoseconds
    current_time = int(time.time() * 1e9)
    display_time = str( current_time )
    print( f"[{display_time}][VMEC Build Py]", *vargs)

def vmec_error(*vargs):
	print("[VMEC Build Py][ERROR]", *vargs)

def vmec_debug(*vargs):
	print("[DEBUG]", *vargs)

# Always start from project root location
os.chdir(script_dir_absolute)
os.system("")  # enables ansi escape characters in terminal
vmec_log(f"Changing directory to '{script_dir_absolute}'")
vmec_log(f"Running script {script_name}")


def execute( command ):
    global dry_run
    if dry_run:
        vmec_log( f"(dry run) executing command: \"{command}\"" )
        return 0
    else:
        vmec_log( f"executing command: \"{command}\"" )
        completed = subprocess.run( command.split() )
        if completed.returncode != 0:
            vmec_error( "Failed to execute command" )
        return completed.returncode

def execute_list( *command_list ):
    global dry_run
    commands = [*command_list]
    if dry_run:
        vmec_log( f"(dry run) executing command: \"{commands}\"" )
        return 0
    else:
        vmec_log( f"executing command: '{commands}'" )
        completed = subprocess.run( commands )
        if completed.returncode != 0:
            vmec_error( "Failed to execute command" )
        return completed.returncode

# Hack to fix rmtree failing on read only objects
def rmtree_remove_readonly( func, path, _ ):
    os.chmod( path, stat.S_IWRITE )
    func( path )

options = argparse.ArgumentParser()
options.add_argument( "--build-dir", action="store" )
options.add_argument( "--build-type", action="store" )
options.add_argument( "--build-label", action="store" )
options.add_argument( "--alt-build", action="store_true",
                      help="Move build directory to uniquely named transient/build directories" )
options.add_argument( "--dry-run" )
options.add_argument( "--clean", action="store_true")
options.add_argument( "--debug", action="store_true" )
# options.add_argument( "--ninja", action="store_true" )
# options.add_argument( "--nmake", action="store_true" )
# options.add_argument( "--no-submodule-sync", action="store_true" )
options.add_argument( "--no-build", action="store_true" )
# options.add_argument( "--no-configure", action="store_true" )
options.add_argument( "--configure", action="store_true" )
options.add_argument( "--test-no-output", action="store_true" )
# options.add_argument( "--no-package", action="store_true" )
# options.add_argument( "--package-only", action="store_true" )

args = options.parse_args()
vmec_log( "Command Line Arguments: " )
for x_name in vars( args ).items():
    vmec_log( f"    {x_name[0]}    :    {x_name[1]}" )

dry_run = args.dry_run

if args.configure:
        execute( "meson setup build" )

execute( "meson compile -C build" )

if args.test_no_output:
    execute( "meson test -C build" )
else:
    execute( "meson test -C build --verbose" )
