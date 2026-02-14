
gInterpreter->AddIncludePath("external/fmt/include");
gInterpreter->LoadMacro( "source/build_control/tachyon_lib_unity_core.cpp" );

#include "source/include_tachyon_lib_core.h"

void rootlogon() {
    tyon::library_context_init( new tyon::library_context );
}
