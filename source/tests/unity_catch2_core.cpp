// SECTION: Catch2 Includes
// Everything, but unity build
#include "external/catch2/extras/catch_amalgamated.hpp"
#include "external/catch2/extras/catch_amalgamated.cpp"

//  Everything, but library mode
// #include "../../external/catch2/src/catch2/catch_all.hpp"

// SECTION: Tachyon Library Includes
#include "../include_tachyon_lib_core.h"
// #include "../build_control/tachyon_lib_unity_core.cpp"

/* SECTION: Test Definitions */

TEST_CASE( "Memory Alignment Helpers", "memory" )
{
    using namespace tyon;

    SECTION( "memory_padding" )
    {
        // pointer version
        REQUIRE( memory_padding( 4,  (void*)0xDEAD ) == 3 );
        REQUIRE( memory_padding( 16, (void*)0xF003 ) == 13 );
        REQUIRE( memory_padding( 2,  (void*)0x0ad3 ) == 1 );
        REQUIRE( memory_padding( 25, (void*)0x2afd ) == 20);
        REQUIRE( memory_padding( 4,  (void*)0x0021 ) == 3 );

        // int pointer version
        REQUIRE( memory_padding( 4,  (int*)0xDEAD ) == 3  );
        REQUIRE( memory_padding( 16, (int*)0xF003 ) == 13 );
        REQUIRE( memory_padding( 2,  (int*)0x0ad3 ) == 1  );
        REQUIRE( memory_padding( 25, (int*)0x2afd ) == 20 );
        REQUIRE( memory_padding( 4,  (int*)0x0021 ) == 3  );

        // User defined type version
        REQUIRE( memory_padding( 4,  (uid*)0xDEAD ) == 3  );
        REQUIRE( memory_padding( 16, (uid*)0xF003 ) == 13 );
        REQUIRE( memory_padding( 2,  (uid*)0x0ad3 ) == 1  );
        REQUIRE( memory_padding( 25, (uid*)0x2afd ) == 20 );
        REQUIRE( memory_padding( 4,  (uid*)0x0021 ) == 3  );

        // Integer version
        REQUIRE( memory_padding( 4,    0xDEAD ) == 3    );
        REQUIRE( memory_padding( 16,   0xF003 ) == 13   );
        REQUIRE( memory_padding( 2,    0x0ad3 ) == 1    );
        REQUIRE( memory_padding( 25,   0x2afd ) == 20   );
        REQUIRE( memory_padding( 4,    0x0021 ) == 3    );
    }

    SECTION( "memory_align" )
    {

        REQUIRE( memory_align( 0xDEAD,  4 ) == 0xDEB0  );
        REQUIRE( memory_align( 0xF003, 16 ) == 0xF010  );
        REQUIRE( memory_align( 0x0ad3,  2 ) == 0x00ad4 );
        REQUIRE( memory_align( 0x2afd, 25 ) == 0x2b11  );
        REQUIRE( memory_align( 0x0021,  4 ) == 0x0024  );
        REQUIRE( memory_align( 0x0021,  64 ) == 0x0040 );

        REQUIRE( memory_align_typed<i32>( 1, 64) == 64 );
    }

    SECTION( "uid/uuid Unique Identifiers" )
    {
        uid valid = uuid_generate();
        REQUIRE( valid.valid() );

        uid invalid;
        REQUIRE( invalid.valid() == false );

        uid copy1 = uuid_generate();
        copy1.id = 25;
        uid copy2 = copy1;
        REQUIRE( memcmp( &copy1, &copy2, sizeof( uid) ) == 0 );

        uid equal1 = uuid_generate();
        equal1.id = 25;
        uid equal2 = equal1;
        REQUIRE( equal1 == equal2 );

        uid equal_different1 = uuid_generate();
        equal_different1.id = 25;
        uid equal_different2 = uuid_generate();
        REQUIRE( (equal_different1 == equal_different2) == false );

        // Unimplimented
        // uid inequal1 = uuid_generate();
        // inequal1.id = 25;
        // uid inequal2 = inequal1;
        // REQUIRE( inequal1 != inequal2 );

    }
}
