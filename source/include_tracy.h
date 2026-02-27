#pragma once

#ifdef TRACY_ENABLE

// Don't want to debug other programs unless something is broken, disable warnings
#pragma GCC diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma clang diagnostic ignored "-Wextra-semi"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wsuggest-destructor-override"
#pragma clang diagnostic ignored "-Wextra-semi-stmt"
// Used a lot because of macros
#pragma GCC diagnostic ignored "-Wreserved-identifier"

#pragma GCC diagnostic ignored "-Wall"

#include "Tracy.hpp"
#include "TracyC.h"

#pragma GCC diagnostic pop

#endif // TRACY_ENABLE
