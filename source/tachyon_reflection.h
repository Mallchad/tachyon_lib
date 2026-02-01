// -- More complex Stuff --

#pragma once

namespace reflection
{

#ifndef TYON_BUILD_GIT_HASH_STRING
        #if TYON_AGGRESSIVE_DEBUGGING
        #error "No git gash provided"
    #endif TYON_AGGRESSIVE_DEBUGGING
    #define TYON_BUILD_GIT_HASH_STRING "unknown"
#endif // TYON_BUILD_GIT_HASH_STRING

#if (__MINGW32__)
    #define REFLECTION_COMPILER_MINGW 1
    constexpr tyon::fstring_view compiler_name = "mingw_gcc";
    constexpr tyon::version compiler_version = {};
#else
    #define REFLECTION_COMPILER_MINGW 0
#endif // mingw

#if (__clang__)
    #define REFLECTION_COMPILER_CLANG 1
    constexpr tyon::version clang_version = { __clang_major__, __clang_minor__, __clang_patchlevel__ };
    constexpr tyon::fstring_view compiler_name = "clang";
    constexpr tyon::version compiler_version = clang_version;
#else
    #define REFLECTION_COMPILER_CLANG 0
    constexpr tyon::version clang_version = {};
#endif // clang

// GNUC means "GNU Cextensions" not "GCC"
#if (__GNUC__ && (!REFLECTION_COMPILER_CLANG))
    #define REFLECTION_COMPILER_GCC 1
    // It's quite tricky to detect true standard GCC but if this is defined we can assume its GCC
    #if (!__GNU_PATCHLEVEL__)
    // MinGW gcc doesn't support extra version granularity
        constexpr tyon::version gcc_version = { __GNUC__ };
    #else
        constexpr tyon::version gcc_version = { __GNUC__, __GNU_MINOR__, __GNU_PATCHLEVEL__};
        constexpr tyon::cstring compiler_name = "gcc";
        constexpr tyon::version compiler_version = gcc_version;
    #endif
#else
    #define REFLECTION_COMPILER_GCC 0
    constexpr tyon::version gcc_version = {};
#endif // GCC

// nVIDIA CUDA SDK
#if (__NVCC__)
    #define REFLECTION_COMPILER_CUDA 1
    // Relies on host compiler like clang or gcc. can't override this name
    // constexpr tyon::fstring_view compiler_name = "nvcc";
    // constexpr tyon::version compiler_version = {};
#else
    #define REFLECTION_COMPILER_CUDA 0
#endif // __NVCC__


// Microsoft Visual C++ Compiler Collection

// Quirk for Clang or CUDA running under MSVC
#if (_MSC_FULL_VER && !REFLECTION_COMPILER_CLANG  && !REFLECTION_COMPILER_CUDA)
    constexpr tyon::fstring_view compiler_name = "msvc";
    constexpr tyon::version compiler_version = { _MSC_FULL_VER, 0, 0 };;
#endif
// Safe, fine under hybrid build environments
#if (_MSC_FULL_VER && !REFLECTION_COMPILER_CLANG)
    #define REFLECTION_COMPILER_MSVC 1
    constexpr tyon::version msvc_version = { _MSC_FULL_VER, 0, 0 };
#else
#define REFLECTION_COMPILER_MSVC 0
    constexpr tyon::version msvc_version = {};
#endif // MSVC

#if (!REFLECTION_COMPILER_GCC && !REFLECTION_COMPILER_CLANG && !REFLECTION_COMPILER_MSVC && !REFLECTION_COMPILER_MINGW && !REFLECTION_COMPILER_CUDA)
    # error "Platform Compiler not supported or detected incorrectly"
#endif // All platforms

#if defined(__gnu_linux__) || defined(__linux__)
    #define REFLECTION_PLATFORM_LINUX 1
    constexpr tyon::fstring_view build_os_name = "linux";
#else
    #define REFLECTION_PLATFORM_LINUX 0
#endif // linux

#if defined(_WIN32)
    #define REFLECTION_PLATFORM_WINDOWS 1
    constexpr tyon::fstring_view build_os_name = "windows";
#else
    #define REFLECTION_PLATFORM_WINDOWS 0
#endif // win32

#if defined(__APPLE__) && defined(__MACH__)
    #define REFLECTION_PLATFORM_MAC 1
    constexpr tyon::fstring_view build_os_name = "mac_os";
#else
    #define REFLECTION_PLATFORM_MAC 0
#endif // Apple/Mac

#if (!REFLECTION_PLATFORM_LINUX && !REFLECTION_PLATFORM_WINDOWS && !REFLECTION_PLATFORM_MAC)
    #error "Platform OS not supported or detected correctly"
#endif

    constexpr bool compiler_gcc =  REFLECTION_COMPILER_GCC;
    constexpr bool compiler_clang = REFLECTION_COMPILER_CLANG;
    constexpr bool compiler_msvc = REFLECTION_COMPILER_MSVC;

    constexpr bool platform_linux = REFLECTION_PLATFORM_LINUX;
    constexpr bool platform_mac = REFLECTION_PLATFORM_MAC;

    constexpr tyon::fstring_view build_git_hash_string = TYON_BUILD_GIT_HASH_STRING;
    // TODO: Fill in hex part
    constexpr tyon::version build_version = { 0, 1, 0  };
}


/// Call a member function pointer, this is insane to remember, don't do it manually.
/// Use this macro or std::invoke
#define INVOKE_MEMBER(object, function, ...) ((object).*(function))(__VA_ARGS__)
