#pragma once

#ifndef M_PI
    #define M_PI 3.14159265358979323846
    #define M_PI_2 1.57079632679489661923 // pi/2
#endif // M_PI

/**
   -- Code Helper Section --
   These are a collection of macros that provide code search hints, build system
   hints, and stub helper macros like stubs.
*/

// Markup / Sanity Functions

// States a forward declaration
#define FUNCTION
#define FORWARD
#define FORWARD_FUNCTION
#define FORWARD_CLASS class
#define FORWARD_STRUCT struct
// States a function should be pure
#define PURE  = 0
#define PURE_FUNCTION
// States a class is intended to be inheritable
// #define BASE
// #define BASE_FUNCTION
// States a constructor declaration or definition
#define CONSTRUCTOR
// States a destructor declaration or definition
#define DESTRUCTOR
// States a move constructor declaration or definition
#define MOVE_CONSTRUCTOR
// States a move constructor declaration or definition
#define COPY_CONSTRUCTOR
/// Defines a copy-assignment specific equals operator (=)
#define COPY_ASSIGNMENT
// States a conversion function, essentially typecasting
#define CONVERSION
// Member variable immediately evaluated at compile time
#define IMMEDIATE static constexpr

// States a class or structis being inherited
#define INHERIT
// States the following code containers members
#define MEMBERS

// Marks a fold expression
/// Accumulate onto variable a given template pack/varadic using an operator
#define FOLD
#define FOLD_ACCUMULATE(pack, variable, op) ((#variable #op #pack), ...)


// Will break the Unreal Header Tool if defined
// (It's parsing system is particularly basic and will misinterpret tokens)
#ifndef __UNREAL__
// #define ABSTRACT
#define ABSTRACT_CLASS class
#define DECLARE_CLASS class
#define PURE_VIRTUAL
#endif

// No Operation empty statements, can silence warnings or be used as breakpoints
#define NOP asm("nop")
// Empty macros, can pad declarations for tools
#define NODECLARE
#define NODEC

// Confusing Static Usage
#define INTERNAL static
#define GLOBAL static

namespace tyon
{

// -- Redirectable typedefs --
using fint8   = int8_t;
using fint16  = int16_t;
using fint32  = int32_t;
using fint64  = int64_t;

using fuint8  = uint8_t;
using fuint16 = uint16_t;
using fuint32 = uint32_t;
using fuint64 = uint64_t;

using i8   = int8_t;
using i16  = int16_t;
using i32  = int32_t;
using i64  = int64_t;

using u8  = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
// struct u40 { u8 d[5]; };
using u64 = uint64_t;
// struct u128 { u64 d[2]; };
// struct u256 { u64 d[4]; };
// struct u512 { u64 d[8]; };
// struct u1024 { u64 d[16]; };
// struct u2048 { u64 d[32]; };
// struct u4096 { u64 d[64]; };

// Fixed width floats only supported
using f32 = float;
using f64 = double;

using byte = u8;
using fbyte = u8;
using usize = u64;
using isize = i64;

// String types
using fstring = std::basic_string<char>;
using fstring_view = std::basic_string_view<char>;
using cstring = const char*;
using fpath = std::filesystem::path;

struct version
{
    u32 major = 0;
    u32 minor = 0;
    u32 patch = 0;
    u8 vcs_hash[40] = {};
};

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

}
// -- End of Code Helpers
// *************************
