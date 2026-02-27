
/* NOTE: Not using pragma once on purpose so we can include multiple times in different files
   Allegedly GCC diagnostic pushes is compatible with GCC diagnostics*/

#pragma GCC diagnostic push

// -- Set Warnings as Errors --
// Horrible and surprising cause of bugs with single line if statements.
#pragma GCC diagnostic error "-Wmisleading-indentation"

// Missing return type is UB/crash, don't do it
#pragma GCC diagnostic error "-Wreturn-type"

#pragma clang diagnostic error "-Winconsistent-missing-override"
// TODO: Disable temporarily to avoid extra work currently [2026-02-27 Fri 10:00]
// #pragma GCC diagnostic error "-Wshadow"

// Always bad unless intentional, data loss
// #pragma GCC diagnostic error "-Wfloat-conversion"

// Always bad, can cause condition misfires.
// #pragma GCC diagnostic error "-Wsign-compare"

// Always bad, reading uninitialized corrupts data
#pragma GCC diagnostic error "-Wuninitialized"

// Missing breaks can cause really nasty bugs, try to annotate all intentional fallthroughs
#pragma GCC diagnostic error "-Wimplicit-fallthrough"

// Copy asignment in statement often is indicative of a logic error.
#pragma GCC diagnostic error "-Wparentheses"

// MSVC errors on this so we need parity and be very careful and use these 2 errors
#pragma clang diagnostic error "-Wdesignated-initializers"
#pragma clang diagnostic error "-Wreorder-init-list"


// -- Temporary Debug Errors --
// Useful for cleaning up dead code or finding accidentilly unused stuff
// #pragma GCC diagnostic error "-Wunused-parameter"

// Safe cast, but may generate indicate coherency issue or generate extra instructions
// "-Werror=double-promotion"

// Pretty useful in a pinch
// #pragma GCC diagnostic error "-Wunused-value"


// -- Enable Warnings --
#pragma clang diagnostic warning "-Weverything"
#pragma GCC diagnostic error "-Wall"
#pragma GCC diagnostic warning "-Wextra"

#if (!REFLECTION_COMPILER_CUDA)
 // For strict ISO C++ compliance, not applicable or useful for CUDA compiler
#pragma GCC diagnostic warning "-Wpedantic"
#endif


// Disable warnings

// Extremely annoying, highlights ever element access use in the whole program
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"

// Nagging, let the user program in peace
#pragma GCC diagnostic ignored "-Wunused-value"

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

#pragma GCC diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
#pragma clang diagnostic ignored "-Wunreachable-code-break"
// Doesn't warn of anything meaningful, valid code, minor performance impact.
#pragma clang diagnostic ignored "-Wglobal-constructors"
// Doesn't warn of anything meaningful, valid code, minor performance impact.
#pragma clang diagnostic ignored "-Wexit-time-destructors"

// USEFUL: , turn on if you want to debug templates
#pragma GCC diagnostic ignored "-Wctad-maybe-unsupported"

// USEFUL: This limits enum expansion in an awkward way if you use it and prevents
// ::none and ::any usage. This should be re-enabled when debugging
#pragma GCC diagnostic ignored "-Wswitch-enum"

// Literally just compiler internal warnings. Not relevant.
// Has no downside to have extra semi-colons, very big problems if you miss one
#pragma GCC diagnostic ignored "-Wextra-semi"
#pragma clang diagnostic ignored "-Wextra-semi-stmt"
// Complains about unset defines being '0' with //if conditions but it's honestly fine.
#pragma GCC diagnostic ignored "-Wundef"

// Safe cast, may cause performance penalty though
#pragma GCC diagnostic ignored "-Wdouble-promotion"

// Uncovered cases will cause a bug, its good to have a default case in 100% switch coverage
#pragma clang diagnostic ignored "-Wcovered-switch-default"

// -- Depreceated or Bugged -
// https://bugs.llvm.org/show_bug.cgi?id=21629
#pragma GCC diagnostic ignored "-Wmissing-braces"
// I have no idea. It doesn't seem to recognize fixed size data types
#pragma clang diagnostic ignored "-Wtautological-constant-out-of-range-compare"

// Newer clang error, is an issue in a 3rd party library
#pragma clang diagnostic error "-Wcharacter-conversion"
