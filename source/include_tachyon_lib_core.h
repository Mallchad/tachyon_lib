
#pragma once

/* Pre-Compiled Header
 * Keeps all includes in the same place and makes the include order easier and straightforward
 * This is also typically *much* faser for the compilers/linkers to deal with */

// -- Platform Specific --
// These have to be included before stblib or naughty macros will be bypassed by stdlib including
// platform specific headers...

// Linux
#if defined(__gnu_linux) || defined(__linux__)
    #include <fcntl.h>
    #include <sys/mman.h>
    #include <sys/stat.h>
    #include <unistd.h>

// Windows
#elif defined(_WIN32)
    // Set version for GetLogicalProcessorInformationEx
    #define _WIN32_WINNT 0x0601
    #define WIN32_LEAN_AND_MEAN 1
    #define NOMINNMAX
    #include <windows.h>

    #include <fcntl.h>
    #include <io.h>
    #include <rpc.h>
    #include <sysinfoapi.h>
    #include <winnt.h>

    // Seriously why. Quit it with the dang macros.
    #undef DrawText
    #undef min
    #undef max
    #undef MIN
    #undef MAX
#endif // REFLECTION_PLATFORM_LINUX


// -- stdlib / STL --
#include <algorithm>
#include <atomic>
#include <chrono>
#include <csignal>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <ctime>
#include <filesystem>
// Disabled iostreams in favour of fmt (which redirects to 'vprint' but uses type safe operations
// #include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

/** -- Vendored Dependencies
 */
// fmtlib
// Causing exceptions on formatting code is just bad. don't do it.
#define FMT_HEADER_ONLY 1
#define FMT_USE_CONSTEXPR 1
// #define FMT_USE_CONSTEVAL 0
// #define FMT_ENFORCE_COMPILE_STRING 1
#define FMT_USE_EXCEPTIONS 0
#define FMT_DISABLE_CONSTEVAL 1

#include "../external/fmt/include/fmt/format.h"
#include "../external/fmt/include/fmt/color.h"
#include "../external/fmt/include/fmt/std.h"

#include "Tracy.hpp"

/** -- Project Local --
 * We put all defines here in a namespace not to stop namespace resolution,
 * but rather to allow name conflict resolution.
 * ie, even with `using namespace ray` and `using namespace tyon` you have 2 varients of `Vector3`
 * You can trivially resolve it by doing with `ray::Vector3` or `tyon::Vector3`
 *
 * The other 'tyon' files haven't been updated correctly to work this way so it's being left for now
 */
#include "tachyon_code_helpers.h"
#include "tachyon_reflection.h"
#include "tachyon_library.h"

#if (REFLECTION_PLATFORM_LINUX)
    #include "tachyon_platform_linux.h"
#elif (REFLECTION_PLATFORM_WINDOWS)
    #include "tachyon_platform_windows.h"
#endif // REFLECTION_PLATFORM
