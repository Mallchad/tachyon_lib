
#pragma once

namespace tyon
{

    /* using complex = complex_t; */

    /** Simple fixed size vector type */
    struct v3_f32
    {
        union
        {
            struct { f32 x, y, z; };
            f32 d[3];
        };

        CONSTRUCTOR v3_f32( f32 arg = 0 );
        CONSTRUCTOR v3_f32( f32 x, f32 y, f32 z );
        explicit CONSTRUCTOR v3_f32( f64 arg );
        /* explicit CONSTRUCTOR v3_f32( v2_f32 ); */
    };

    /** NOTE: This is a comment box style. We should try to have atleast 1 per header function/global
     * Vector cross product
     *
     * This is cross product idk why
     */
    PROC operator*( v3_f32 lhs, v3_f32 rhs ) -> v3_f32;

}
