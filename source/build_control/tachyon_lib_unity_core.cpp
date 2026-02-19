
// NOTE: Its a warning to use pragma once in top level build file
#ifdef UNITY_TACHYON_LIB_CORE_
    #error "Included a unity file twice"
#endif
#define UNITY_TACHYON_LIB_CORE_

// Required for windows DLL
#define TYON_EXPORTS 1
#include "../include_tachyon_lib_core.h"

#include "../tachyon_library.cpp"
#include "../tachyon_math.cpp"
#include "../tachyon_platform_common.cpp"
#include "../tachyon_platform_linux.cpp"
#include "../tachyon_platform_windows.cpp"
#include "../tachyon_entity.cpp"
#include "../tachyon_containers.cpp"
#include "../tachyon_allocators.cpp"

#if (!TYON_FMTLIB_HEADER_ONLY)
    #include "../../external/fmt/src/format.cc"
#endif
