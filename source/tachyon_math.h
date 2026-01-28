
#pragma once

namespace tyon
{
    /** Types */
        // Complex Numbers
        struct c32
        {
            f32 real;
            f32 imag;

            TYON_CUDA_SHARED
            CONSTRUCTOR c32();
            TYON_CUDA_SHARED
            CONSTRUCTOR c32( f32 arg );
            TYON_CUDA_SHARED
            CONSTRUCTOR c32( f32 real, f32 imag );
            TYON_CUDA_SHARED
            explicit CONSTRUCTOR c32( f64 arg );
        };

        struct c64
        {
            f64 real; 
            f64 imag; 

            TYON_CUDA_SHARED
            CONSTRUCTOR c64();
            TYON_CUDA_SHARED
            CONSTRUCTOR c64( f64 arg );
            TYON_CUDA_SHARED
            CONSTRUCTOR c64( f64 real, f64 imag );
            TYON_CUDA_SHARED
            explicit CONSTRUCTOR c64( f32 arg );
        };



    /** Operators */
        // Complex numbers
            // Addition
            TYON_CUDA_SHARED
            PROC operator+(const c32& z0, const c32& z1) -> c32;

            TYON_CUDA_SHARED
            PROC operator+(const c64& z0, const c64& z1) -> c64;

            // Subtraction
            TYON_CUDA_SHARED
            PROC operator-(const c32& z0, const c32& z1) -> c32;

            TYON_CUDA_SHARED
            PROC operator-(const c64& z0, const c64& z1) -> c64;

            // Multiplication
            TYON_CUDA_SHARED
            PROC operator*(const c32& z0, const c32& z1) -> c32;

            TYON_CUDA_SHARED
            PROC operator*(const c64& z0, const c64& z1) -> c64;

            TYON_CUDA_SHARED
            PROC operator*(const c32& z0, const f32& s0) -> c32;

            TYON_CUDA_SHARED
            PROC operator*(const c64& z0, const f64& s0) -> c64;

            // Division
            TYON_CUDA_SHARED
            PROC operator/(const c32& z0, const c32& z1) -> c32;

            TYON_CUDA_SHARED
            PROC operator/(const c64& z0, const c64& z1) -> c64;

            // Inverse
            TYON_CUDA_SHARED
            PROC operator-(const c32& z0) -> c32;

            TYON_CUDA_SHARED
            PROC operator-(const c64& z0) -> c64;



    /** Functions */
        // Complex Numbers
        TYON_CUDA_SHARED
        PROC complex_conjugate(const c32& z) -> c32;

        TYON_CUDA_SHARED
        PROC complex_conjugate(const c64& z) -> c64;

        TYON_CUDA_SHARED
        PROC complex_modulus(const c32& z) -> f32;

        TYON_CUDA_SHARED
        PROC complex_modulus(const c64& z) -> f64;

        TYON_CUDA_SHARED
        PROC complex_arg(const c32& z) -> f32;

        TYON_CUDA_SHARED
        PROC complex_arg(const c64& z) -> f64;



        // Square root
        TYON_CUDA_SHARED
        PROC square_root(const f32& a) -> f32;

        TYON_CUDA_SHARED
        PROC square_root(const f64& a) -> f64;

        TYON_CUDA_SHARED
        PROC square_root(const c32& z) -> c32;

        TYON_CUDA_SHARED
        PROC square_root(const c64& z) -> c64;



        // Exponential
        TYON_CUDA_SHARED
        PROC power(const f32& base, const f32& exponent) -> f32;

        TYON_CUDA_SHARED 
        PROC power(const f64& base, const f64& exponent) -> f64;

        TYON_CUDA_SHARED
        PROC exponential(const f32& exponent) -> f32;

        TYON_CUDA_SHARED
        PROC exponential(const f64& exponent) -> f64;
 


        // Trigonometry
        TYON_CUDA_SHARED
        PROC sinus(const f32& a) -> f32;

        TYON_CUDA_SHARED
        PROC sinus(const f64& a) -> f64;

        TYON_CUDA_SHARED
        PROC cosinus(const f32& a) -> f32;

        TYON_CUDA_SHARED
        PROC cosinus(const f64& a) -> f64;

        TYON_CUDA_SHARED
        PROC tangent(const f32& a) -> f32;

        TYON_CUDA_SHARED
        PROC tangent(const f64& a) -> f64;

        TYON_CUDA_SHARED
        PROC arcsin(const f32& a) -> f32;

        TYON_CUDA_SHARED
        PROC arcsin(const f64& a) -> f64;

        TYON_CUDA_SHARED
        PROC arccos(const f32& a) -> f32;

        TYON_CUDA_SHARED
        PROC arccos(const f64& a) -> f64;

        TYON_CUDA_SHARED
        PROC arctan(const f32& a) -> f32;

        TYON_CUDA_SHARED
        PROC arctan(const f64& a) -> f64;

        TYON_CUDA_SHARED
        PROC arctan2(const f32& x, const f32& y) -> f32;

        TYON_CUDA_SHARED
        PROC arctan2(const f64& x, const f64& y) -> f64;


        // Probability
        TYON_CUDA_SHARED
        PROC error_function(const f32& a) -> f32;

        TYON_CUDA_SHARED
        PROC error_function(const f64& a) -> f64;

        TYON_CUDA_SHARED
        PROC norm_gaussian_cdf(const f32& mean, const f32& x, const f32& standard_deviation) -> f32;

        TYON_CUDA_SHARED
        PROC norm_gaussian_cdf(const f64& mean, const f64& x, const f64& standard_deviation) -> f64;



    /** Simple fixed size vector type */
    struct v3_f32
    {
        union
        {
            struct { f32 x, y, z; };
            f32 d[3];
        };

        TYON_CUDA_SHARED
        CONSTRUCTOR v3_f32( f32 arg = 0 );
        TYON_CUDA_SHARED
        CONSTRUCTOR v3_f32( f32 x, f32 y, f32 z );
        TYON_CUDA_SHARED
        explicit CONSTRUCTOR v3_f32( f64 arg );
        /* explicit CONSTRUCTOR v3_f32( v2_f32 ); */
    };

    /** NOTE: This is a comment box style. We should try to have atleast 1 per header function/global
     * Vector cross product
     *
     * This is cross product idk why
     */

    TYON_CUDA_SHARED
    PROC operator*( v3_f32 lhs, v3_f32 rhs ) -> v3_f32;

}
