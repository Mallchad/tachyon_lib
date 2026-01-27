
#pragma once

namespace tyon
{

    /** Complex Numbers */
        // Types
        struct c32
        {
            f32 real;
            f32 imag;

            CONSTRUCTOR c32();
            CONSTRUCTOR c32( f32 arg );
            CONSTRUCTOR c32( f32 real, f32 imag );
            explicit CONSTRUCTOR c32( f64 arg );
        };

        struct c64
        {
            f64 real; 
            f64 imag; 

            CONSTRUCTOR c64();
            CONSTRUCTOR c64( f64 arg );
            CONSTRUCTOR c64( f64 real, f64 imag );
            explicit CONSTRUCTOR c64( f32 arg );
        };

        // Operators
        // Addition
        PROC operator+(const c32& z0, const c32& z1) -> c32;

        PROC operator+(const c64& z0, const c64& z1) -> c64;

        // Subtraction
        PROC operator-(const c32& z0, const c32& z1) -> c32;

        PROC operator-(const c64& z0, const c64& z1) -> c64;

        // Multiplication
        PROC operator*(const c32& z0, const c32& z1) -> c32;

        PROC operator*(const c64& z0, const c64& z1) -> c64;

        PROC operator*(const c32& z0, const f32& s0) -> c32;

        PROC operator*(const c64& z0, const f64& s0) -> c64;

        // Division
        PROC operator/(const c32& z0, const c32& z1) -> c32;

        PROC operator/(const c64& z0, const c64& z1) -> c64;

        // Inverse
        PROC operator-(const c32& z0) -> c32;

        PROC operator-(const c64& z0) -> c64;

        // Functions
        PROC complex_conjugate(const c32& z) -> c32;



    /** Simple fixed size vector type */
    struct v3_f32
    {
        union
        {
            struct { f32 x, y, z; };
            f32 d[3];
        };

        VMEC_CUDA_SHARED
        CONSTRUCTOR v3_f32( f32 arg = 0 );
        VMEC_CUDA_SHARED
        CONSTRUCTOR v3_f32( f32 x, f32 y, f32 z );
        VMEC_CUDA_SHARED
        explicit CONSTRUCTOR v3_f32( f64 arg );
        /* explicit CONSTRUCTOR v3_f32( v2_f32 ); */
    };

    /** NOTE: This is a comment box style. We should try to have atleast 1 per header function/global
     * Vector cross product
     *
     * This is cross product idk why
     */

    VMEC_CUDA_SHARED
    PROC operator*( v3_f32 lhs, v3_f32 rhs ) -> v3_f32;

}
