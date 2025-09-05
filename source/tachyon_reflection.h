// -- More complex Stuff --
namespace reflection
{
// GNUC means "GNU Cextensions" not "GCC"
#if (__GNUC___ && !__clang__)
    #define REFLECTION_COMPILER_GCC 1
    constexpr version gcc_version = { __GNUC__, __GNU_MINOR__, __GNU_PATCHLEVEL__};
    constexpr cstring compiler_name = "gcc";
    constexpr version compiler_version = gcc_version;
#else
    #define REFLECTION_COMPILER_GCC 0
    constexpr version gcc_version = {};
#endif // GCC
#if (__clang__)
    #define REFLECTION_COMPILER_CLANG 1
    constexpr version clang_version = { __clang_major__, __clang_minor__, __clang_patchlevel__ };
    constexpr fstring_view compiler_name = "clang";
    constexpr version compiler_version = clang_version;
#else
    #define REFLECTION_COMPILER_CLANG 0
    constexpr version clang_version = {};
#endif // clang

// Microsoft Visual C++ Compiler Collection
#if (_MSC_FULL_VER)
    #define REFLECTION_COMPILER_MSVC 1
    constexpr version msvc_version = { _MSC_FULL_VER, 0, 0 };
    constexpr fstring_view compiler_name = "msvc";
    constexpr version compiler_version = msvc_version;
#else
    #define REFLECTION_COMPILER_MSVC 0
    constexpr version msvc_version = {};
#endif // MSVC

#if (__MINGW32__)
    #define REFLECTION_COMPILER_MINGW 1
    constexpr fstring_view compiler_name = "mingw";
    constexpr version compiler_version = {};
    #else
    #define REFLECTION_COMPILER_MINGW 0
#endif // mingw

#if (!REFLECTION_COMPILER_GCC && !REFLECTION_COMPILER_CLANG && !REFLECTION_COMPILER_MSVC && !REFLECTION_COMPILER_MINGW)
    # error "Platform Compiler not supported or detected incorrectly"
#endif // All platforms

#if defined(__gnu_linux__) || defined(__linux__)
    #define REFLECTION_PLATFORM_LINUX 1
#else
    #define REFLECTION_PLATFORM_LINUX 0
#endif // linux

#if defined(_WIN32)
    #define REFLECTION_PLATFORM_WINDOWS 1
#else
    #define REFLECTION_PLATFORM_WINDOWS 0
#endif // win32

#if defined(__APPLE__) && defined(__MACH__)
    #define REFLECTION_PLATFORM_MAC 1
#else
    #define REFLECTION_PLATFORM_MAC 0
#endif // Apple/Mac

    constexpr bool compiler_gcc =  REFLECTION_COMPILER_GCC;
    constexpr bool compiler_clang = REFLECTION_COMPILER_CLANG;
    constexpr bool compiler_msvc = REFLECTION_COMPILER_MSVC;

    constexpr bool platform_linux = REFLECTION_PLATFORM_LINUX;
    constexpr bool platform_mac = REFLECTION_PLATFORM_MAC;
}

// TYON_BREAK should be valid in release builds
#define TYON_SIGTRAP 5

#if (REFLECTION_COMPILER_CLANG)
    #define FORCEINLINE __attribute__((always_inline))
    #define TYON_FORCEINLINE __attribute__((always_inline))
    #define TYON_BREAK() __builtin_debugtrap();
    #define TYON_PREFETCH_CACHELINE( address ) __builtin_prefetch( address );
#elif (REFLECTION_COMPILER_GCC)
    #define FORCEINLINE __attribute__((always_inline))
    #define TYON_FORCEINLINE __attribute__((always_inline))
    #define TYON_BREAK() raise(TYON_SIGTRAP);
    #define TYON_PREFETCH_CACHELINE( address ) __builtin_prefetch( address );

#elif (REFLECTION_COMPILER_MSVC)
    #define FORCEINLINE __forceinline
    #define TYON_FORCEINLINE __forceinline
    #define TYON_BREAK() __debugbreak();
    #define TYON_PREFETCH_CACHELINE( address ) PrefetchCacheLine( PF_TEMPORAL_LEVEL_1, (address) );
#else
    #define FORCEINLINE
    #define TYON_FORCEINLINE
    #define TYON_BREAK() raise(TYON_SIGTRAP);
    #define TYON_PREFETCH_CACHELINE( address ) ERROR_PREFETCH_NOT_DEFINED
#endif // compiler


/// Call a member function pointer, this is insane to remember, don't do it manually.
/// Use this macro or std::invoke
#define INVOKE_MEMBER(object, function, ...) ((object).*(function))(__VA_ARGS__)
