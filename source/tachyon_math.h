
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



        // Vectors 
        struct v2_f32
        {
            f32 x;
            f32 y;
            
            TYON_CUDA_SHARED
            CONSTRUCTOR v2_f32();
            TYON_CUDA_SHARED
            CONSTRUCTOR v2_f32( f32 arg );
            TYON_CUDA_SHARED
            CONSTRUCTOR v2_f32( f32 x, f32 y);
            TYON_CUDA_SHARED
            explicit CONSTRUCTOR v2_f32( f64 arg );
        };

        struct v2_f64
        {
            f64 x;
            f64 y; 
        
            TYON_CUDA_SHARED
            CONSTRUCTOR v2_f64();
            TYON_CUDA_SHARED
            CONSTRUCTOR v2_f64( f64 arg );
            TYON_CUDA_SHARED
            CONSTRUCTOR v2_f64( f64 x, f64 y);
            TYON_CUDA_SHARED
            explicit CONSTRUCTOR v2_f64( f32 arg );
        };

        struct v3_f32
        {
            f32 x;
            f32 y;
            f32 z; 
        
            TYON_CUDA_SHARED
            CONSTRUCTOR v3_f32();
            TYON_CUDA_SHARED
            CONSTRUCTOR v3_f32( f32 arg );
            TYON_CUDA_SHARED
            CONSTRUCTOR v3_f32( f32 x, f32 y, f32 z);
            TYON_CUDA_SHARED
            explicit CONSTRUCTOR v3_f32( f64 arg );
        };

        struct v3_f64
        {
            f64 x;
            f64 y; 
            f64 z;
        
            TYON_CUDA_SHARED
            CONSTRUCTOR v3_f64();
            TYON_CUDA_SHARED
            CONSTRUCTOR v3_f64( f64 arg );
            TYON_CUDA_SHARED
            CONSTRUCTOR v3_f64( f64 x, f64 y, f64 z);
            TYON_CUDA_SHARED
            explicit CONSTRUCTOR v3_f64( f32 arg );
        };

        struct v4_f32
        {
            f32 x;
            f32 y;
            f32 z; 
            f32 w;
        
            TYON_CUDA_SHARED
            CONSTRUCTOR v4_f32();
            TYON_CUDA_SHARED
            CONSTRUCTOR v4_f32( f32 arg );
            TYON_CUDA_SHARED
            CONSTRUCTOR v4_f32( f32 x, f32 y, f32 z, f32 w);
            TYON_CUDA_SHARED
            explicit CONSTRUCTOR v4_f32( f64 arg );
        };

        struct v4_f64
        {
            f64 x;
            f64 y;
            f64 z; 
            f64 w;
        
            TYON_CUDA_SHARED
            CONSTRUCTOR v4_f64();
            TYON_CUDA_SHARED
            CONSTRUCTOR v4_f64( f64 arg );
            TYON_CUDA_SHARED
            CONSTRUCTOR v4_f64( f64 x, f64 y, f64 z, f64 w);
            TYON_CUDA_SHARED
            explicit CONSTRUCTOR v4_f64( f32 arg );
        };



        // Matrices
        struct matrix2_f32
        {
            f32 m11; f32 m12;
            f32 m21; f32 m22;

            TYON_CUDA_SHARED
            CONSTRUCTOR matrix2_f32();
            TYON_CUDA_SHARED
            CONSTRUCTOR matrix2_f32( f32 arg );
            TYON_CUDA_SHARED
            CONSTRUCTOR matrix2_f32( f32 m11, f32 m12, f32 m21, f32 m22);
            TYON_CUDA_SHARED
            explicit CONSTRUCTOR matrix2_f32( f64 arg );
        };

        struct matrix2_f64
        {
            f64 m11; f64 m12;
            f64 m21; f64 m22;

            TYON_CUDA_SHARED
            CONSTRUCTOR matrix2_f64();
            TYON_CUDA_SHARED
            CONSTRUCTOR matrix2_f64( f64 arg );
            TYON_CUDA_SHARED
            CONSTRUCTOR matrix2_f64( f64 m11, f64 m12, f64 m21, f64 m22);
            TYON_CUDA_SHARED
            explicit CONSTRUCTOR matrix2_f64( f32 arg );
        };

        struct matrix3_f32
        {
            f32 m11; f32 m12; f32 m13;
            f32 m21; f32 m22; f32 m23;
            f32 m31; f32 m32; f32 m33;

            TYON_CUDA_SHARED
            CONSTRUCTOR matrix3_f32();
            TYON_CUDA_SHARED
            CONSTRUCTOR matrix3_f32( f32 arg );
            TYON_CUDA_SHARED
            CONSTRUCTOR matrix3_f32( f32 m11, f32 m12, f32 m13, f32 m21, f32 m22, f32 m23, f32 m31, f32 m32, f32 m33);
            TYON_CUDA_SHARED
            explicit CONSTRUCTOR matrix3_f32( f64 arg );
        };

        struct matrix3_f64
        {
            f64 m11; f64 m12; f64 m13;
            f64 m21; f64 m22; f64 m23;
            f64 m31; f64 m32; f64 m33;

            TYON_CUDA_SHARED
            CONSTRUCTOR matrix3_f64();
            TYON_CUDA_SHARED
            CONSTRUCTOR matrix3_f64( f32 arg );
            TYON_CUDA_SHARED
            CONSTRUCTOR matrix3_f64( f32 m11, f32 m12, f32 m13, f32 m21, f32 m22, f32 m23, f32 m31, f32 m32, f32 m33);
            TYON_CUDA_SHARED
            explicit CONSTRUCTOR matrix3_f64( f64 arg );
        };

        struct matrix4_f32
        {
            f32 m11; f32 m12; f32 m13; f32 m14;
            f32 m21; f32 m22; f32 m23; f32 m24;
            f32 m31; f32 m32; f32 m33; f32 m34;
            f32 m41; f32 m42; f32 m43; f32 m44;

            TYON_CUDA_SHARED
            CONSTRUCTOR matrix4_f32();
            TYON_CUDA_SHARED
            CONSTRUCTOR matrix4_f32( f32 arg );
            TYON_CUDA_SHARED
            CONSTRUCTOR matrix4_f32( f32 m11, f32 m12, f32 m13, f32 m14, f32 m21, f32 m22, f32 m23, f32 m24, f32 m31, f32 m32, f32 m33, f32 m34, f32 m41, f32 m42, f32 m43, f32 m44);
            TYON_CUDA_SHARED
            explicit CONSTRUCTOR matrix4_f32( f64 arg );
        };

        struct matrix4_f64
        {
            f64 m11; f64 m12; f64 m13; f64 m14;
            f64 m21; f64 m22; f64 m23; f64 m24;
            f64 m31; f64 m32; f64 m33; f64 m34;
            f64 m41; f64 m42; f64 m43; f64 m44;

            TYON_CUDA_SHARED
            CONSTRUCTOR matrix4_f64();
            TYON_CUDA_SHARED
            CONSTRUCTOR matrix4_f64( f64 arg );
            TYON_CUDA_SHARED
            CONSTRUCTOR matrix4_f64( f64 m11, f64 m12, f64 m13, f64 m14, f64 m21, f64 m22, f64 m23, f64 m24, f64 m31, f64 m32, f64 m33, f64 m34, f64 m41, f64 m42, f64 m43, f64 m44);
            TYON_CUDA_SHARED
            explicit CONSTRUCTOR matrix4_f64( f32 arg );
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



        // Vector-Vector
            // Addition
            TYON_CUDA_SHARED
            PROC operator+(const v2_f32& v0, const v2_f32& v1) -> v2_f32;

            TYON_CUDA_SHARED
            PROC operator+(const v2_f64& v0, const v2_f64& v1) -> v2_f64;

            TYON_CUDA_SHARED
            PROC operator+(const v3_f32& v0, const v3_f32& v1) -> v3_f32;

            TYON_CUDA_SHARED
            PROC operator+(const v3_f64& v0, const v3_f64& v1) -> v3_f64;

            TYON_CUDA_SHARED
            PROC operator+(const v4_f32& v0, const v4_f32& v1) -> v4_f32;

            TYON_CUDA_SHARED
            PROC operator+(const v4_f64& v0, const v4_f64& v1) -> v4_f64;

            // Subtraction
            TYON_CUDA_SHARED
            PROC operator-(const v2_f32& v0, const v2_f32& v1) -> v2_f32;

            TYON_CUDA_SHARED
            PROC operator-(const v2_f64& v0, const v2_f64& v1) -> v2_f64;

            TYON_CUDA_SHARED
            PROC operator-(const v3_f32& v0, const v3_f32& v1) -> v3_f32;

            TYON_CUDA_SHARED
            PROC operator-(const v3_f64& v0, const v3_f64& v1) -> v3_f64;

            TYON_CUDA_SHARED
            PROC operator-(const v4_f32& v0, const v4_f32& v1) -> v4_f32;

            TYON_CUDA_SHARED
            PROC operator-(const v4_f64& v0, const v4_f64& v1) -> v4_f64;

            // Multiplication
            TYON_CUDA_SHARED
            PROC operator*(const v2_f32& v0, const v2_f32& v1) -> v2_f32;

            TYON_CUDA_SHARED
            PROC operator*(const v2_f64& v0, const v2_f64& v1) -> v2_f64;

            TYON_CUDA_SHARED
            PROC operator*(const v3_f32& v0, const v3_f32& v1) -> v3_f32;

            TYON_CUDA_SHARED
            PROC operator*(const v3_f64& v0, const v3_f64& v1) -> v3_f64;

            TYON_CUDA_SHARED
            PROC operator*(const v4_f32& v0, const v4_f32& v1) -> v4_f32;

            TYON_CUDA_SHARED
            PROC operator*(const v4_f64& v0, const v4_f64& v1) -> v4_f64;

            // Division
            TYON_CUDA_SHARED
            PROC operator/(const v2_f32& v0, const v2_f32& v1) -> v2_f32;

            TYON_CUDA_SHARED
            PROC operator/(const v2_f64& v0, const v2_f64& v1) -> v2_f64;

            TYON_CUDA_SHARED
            PROC operator/(const v3_f32& v0, const v3_f32& v1) -> v3_f32;

            TYON_CUDA_SHARED
            PROC operator/(const v3_f64& v0, const v3_f64& v1) -> v3_f64;

            TYON_CUDA_SHARED
            PROC operator/(const v4_f32& v0, const v4_f32& v1) -> v4_f32;

            TYON_CUDA_SHARED
            PROC operator/(const v4_f64& v0, const v4_f64& v1) -> v4_f64;

            // Inverse
            TYON_CUDA_SHARED
            PROC operator-(const v2_f32& v) -> v2_f32;

            TYON_CUDA_SHARED
            PROC operator-(const v2_f64& v) -> v2_f64;

            TYON_CUDA_SHARED
            PROC operator-(const v3_f32& v) -> v3_f32;

            TYON_CUDA_SHARED
            PROC operator-(const v3_f64& v) -> v3_f64;

            TYON_CUDA_SHARED
            PROC operator-(const v4_f32& v) -> v4_f32;

            TYON_CUDA_SHARED
            PROC operator-(const v4_f64& v) -> v4_f64;



        // Vector-scalar
            // Multiplication
            TYON_CUDA_SHARED
            PROC operator*(const v2_f32& v0, const f32 s0) -> v2_f32;

            TYON_CUDA_SHARED
            PROC operator*(const v2_f64& v0, const f64 s0) -> v2_f64;

            TYON_CUDA_SHARED
            PROC operator*(const f32 s0, const v2_f32& v0) -> v2_f32;

            TYON_CUDA_SHARED
            PROC operator*(const f64 s0, const v2_f64& v0) -> v2_f64;

            TYON_CUDA_SHARED
            PROC operator*(const v3_f32& v0, const f32 s0) -> v3_f32;

            TYON_CUDA_SHARED
            PROC operator*(const v3_f64& v0, const f64 s0) -> v3_f64;

            TYON_CUDA_SHARED
            PROC operator*(const f32 s0, const v3_f32& v0) -> v3_f32;

            TYON_CUDA_SHARED
            PROC operator*(const f64 s0, const v3_f64& v0) -> v3_f64;

            TYON_CUDA_SHARED
            PROC operator*(const v4_f32& v0, const f32 s0) -> v4_f32;

            TYON_CUDA_SHARED
            PROC operator*(const v4_f64& v0, const f64 s0) -> v4_f64;

            TYON_CUDA_SHARED
            PROC operator*(const f32 s0, const v4_f32& v0) -> v4_f32;

            TYON_CUDA_SHARED
            PROC operator*(const f64 s0, const v4_f64& v0) -> v4_f64;

            // Division
            TYON_CUDA_SHARED
            PROC operator/(const v2_f32& v0, const f32 s0) -> v2_f32;

            TYON_CUDA_SHARED
            PROC operator/(const v2_f64& v0, const f64 s0) -> v2_f64;

            TYON_CUDA_SHARED
            PROC operator/(const f32 s0, const v2_f32& v0) -> v2_f32;

            TYON_CUDA_SHARED
            PROC operator/(const f64 s0, const v2_f64& v0) -> v2_f64;

            TYON_CUDA_SHARED
            PROC operator/(const v3_f32& v0, const f32 s0) -> v3_f32;

            TYON_CUDA_SHARED
            PROC operator/(const v3_f64& v0, const f64 s0) -> v3_f64;

            TYON_CUDA_SHARED
            PROC operator/(const f32 s0, const v3_f32& v0) -> v3_f32;

            TYON_CUDA_SHARED
            PROC operator/(const f64 s0, const v3_f64& v0) -> v3_f64;

            TYON_CUDA_SHARED
            PROC operator/(const v4_f32& v0, const f32 s0) -> v4_f32;

            TYON_CUDA_SHARED
            PROC operator/(const v4_f64& v0, const f64 s0) -> v4_f64;

            TYON_CUDA_SHARED
            PROC operator/(const f32 s0, const v4_f32& v0) -> v4_f32;

            TYON_CUDA_SHARED
            PROC operator/(const f64 s0, const v4_f64& v0) -> v4_f64;



        // Vector-Matrix
            TYON_CUDA_SHARED
            PROC operator*(const v2_f32& v0, const matrix2_f32& m0) -> v2_f32;

            TYON_CUDA_SHARED
            PROC operator*(const matrix2_f32& m0, const v2_f32& v0) -> v2_f32;

            TYON_CUDA_SHARED
            PROC operator*(const v2_f64& v0, const matrix2_f64& m0) -> v2_f64;

            TYON_CUDA_SHARED
            PROC operator*(const matrix2_f64& m0, const v2_f64& v0) -> v2_f64;

            TYON_CUDA_SHARED
            PROC operator*(const v3_f32& v0, const matrix3_f32& m0) -> v3_f32;

            TYON_CUDA_SHARED
            PROC operator*(const matrix3_f32& m0, const v3_f32& v0) -> v3_f32;

            TYON_CUDA_SHARED
            PROC operator*(const v3_f64& v0, const matrix3_f64& m0) -> v3_f64;

            TYON_CUDA_SHARED
            PROC operator*(const matrix3_f64& m0, const v3_f64& v0) -> v3_f64;

            TYON_CUDA_SHARED
            PROC operator*(const v4_f32& v0, const matrix4_f32& m0) -> v4_f32;

            TYON_CUDA_SHARED
            PROC operator*(const matrix4_f32& m0, const v4_f32& v0) -> v4_f32;

            TYON_CUDA_SHARED
            PROC operator*(const v4_f64& v0, const matrix4_f64& m0) -> v4_f64;

            TYON_CUDA_SHARED
            PROC operator*(const matrix4_f64& m0, const v4_f64& v0) -> v4_f64;



        // Matrices
            // Matrix Addition
            TYON_CUDA_SHARED
            PROC operator+(const matrix2_f32& m0, const matrix2_f32& m1) -> matrix2_f32;

            TYON_CUDA_SHARED
            PROC operator+(const matrix2_f64& m0, const matrix2_f64& m1) -> matrix2_f64;

            TYON_CUDA_SHARED
            PROC operator+(const matrix3_f32& m0, const matrix3_f32& m1) -> matrix3_f32;

            TYON_CUDA_SHARED
            PROC operator+(const matrix3_f64& m0, const matrix3_f64& m1) -> matrix3_f64;

            TYON_CUDA_SHARED
            PROC operator+(const matrix4_f32& m0, const matrix4_f32& m1) -> matrix4_f32;

            TYON_CUDA_SHARED
            PROC operator+(const matrix4_f64& m0, const matrix4_f64& m1) -> matrix4_f64;

            // Scalar Addition
            TYON_CUDA_SHARED
            PROC operator+(const matrix2_f32& m0, const f32& s0) -> matrix2_f32;

            TYON_CUDA_SHARED
            PROC operator+(const f32& s0, const matrix2_f32& m0) -> matrix2_f32;

            TYON_CUDA_SHARED
            PROC operator+(const matrix2_f64& m0, const f64& s0) -> matrix2_f64;

            TYON_CUDA_SHARED
            PROC operator+(const f64& s0, const matrix2_f64& m0) -> matrix2_f64;

            TYON_CUDA_SHARED
            PROC operator+(const matrix3_f32& m0, const f32& s0) -> matrix3_f32;

            TYON_CUDA_SHARED
            PROC operator+(const f32& s0, const matrix3_f32& m0) -> matrix3_f32;

            TYON_CUDA_SHARED
            PROC operator+(const matrix3_f64& m0, const f64& s0) -> matrix3_f64;

            TYON_CUDA_SHARED
            PROC operator+(const f32& s0, const matrix3_f64& m0) -> matrix3_f64;

            TYON_CUDA_SHARED
            PROC operator+(const matrix4_f32& m0, const f32& s0) -> matrix4_f32;

            TYON_CUDA_SHARED
            PROC operator+(const f32& s0, const matrix4_f32& m0) -> matrix4_f32;

            TYON_CUDA_SHARED
            PROC operator+(const matrix4_f64& m0, const f64& s0) -> matrix4_f64;

            TYON_CUDA_SHARED
            PROC operator+(const f32& s0, const matrix4_f64& m0) -> matrix4_f64;

            // Matrix Subtraction
            TYON_CUDA_SHARED
            PROC operator-(const matrix2_f32& m0, const matrix2_f32& m1) -> matrix2_f32;

            TYON_CUDA_SHARED
            PROC operator-(const matrix2_f64& m0, const matrix2_f64& m1) -> matrix2_f64;

            TYON_CUDA_SHARED
            PROC operator-(const matrix3_f32& m0, const matrix3_f32& m1) -> matrix3_f32;

            TYON_CUDA_SHARED
            PROC operator-(const matrix3_f64& m0, const matrix3_f64& m1) -> matrix3_f64;

            TYON_CUDA_SHARED
            PROC operator-(const matrix4_f32& m0, const matrix4_f32& m1) -> matrix4_f32;

            TYON_CUDA_SHARED
            PROC operator-(const matrix4_f64& m0, const matrix4_f64& m1) -> matrix4_f64;

            // Scalar Subtraction 
            TYON_CUDA_SHARED
            PROC operator-(const matrix2_f32& m0, const f32& s0) -> matrix2_f32;

            TYON_CUDA_SHARED
            PROC operator-(const f32& s0, const matrix2_f32& m0) -> matrix2_f32;

            TYON_CUDA_SHARED
            PROC operator-(const matrix2_f64& m0, const f64& s0) -> matrix2_f64;

            TYON_CUDA_SHARED
            PROC operator-(const f64& s0, const matrix2_f64& m0) -> matrix2_f64;

            TYON_CUDA_SHARED
            PROC operator-(const matrix3_f32& m0, const f32& s0) -> matrix3_f32;

            TYON_CUDA_SHARED
            PROC operator-(const f32& s0, const matrix3_f32& m0) -> matrix3_f32;

            TYON_CUDA_SHARED
            PROC operator-(const matrix3_f64& m0, const f64& s0) -> matrix3_f64;

            TYON_CUDA_SHARED
            PROC operator-(const f32& s0, const matrix3_f64& m0) -> matrix3_f64;

            TYON_CUDA_SHARED
            PROC operator-(const matrix4_f32& m0, const f32& s0) -> matrix4_f32;

            TYON_CUDA_SHARED
            PROC operator-(const f32& s0, const matrix4_f32& m0) -> matrix4_f32;

            TYON_CUDA_SHARED
            PROC operator-(const matrix4_f64& m0, const f64& s0) -> matrix4_f64;

            TYON_CUDA_SHARED
            PROC operator-(const f32& s0, const matrix4_f64& m0) -> matrix4_f64;

            // Matrix Multiplication
            TYON_CUDA_SHARED
            PROC operator*(const matrix2_f32& m0, const matrix2_f32& m1) -> matrix2_f32;

            TYON_CUDA_SHARED
            PROC operator*(const matrix2_f64& m0, const matrix2_f64& m1) -> matrix2_f64;

            TYON_CUDA_SHARED
            PROC operator*(const matrix3_f32& m0, const matrix3_f32& m1) -> matrix3_f32;

            TYON_CUDA_SHARED
            PROC operator*(const matrix3_f64& m0, const matrix3_f64& m1) -> matrix3_f64;

            TYON_CUDA_SHARED
            PROC operator*(const matrix4_f32& m0, const matrix4_f32& m1) -> matrix4_f32;

            TYON_CUDA_SHARED
            PROC operator*(const matrix4_f64& m0, const matrix4_f64& m1) -> matrix4_f64;

            // Scalar Multiplication
            TYON_CUDA_SHARED
            PROC operator*(const matrix2_f32& m0, const f32& s0) -> matrix2_f32;

            TYON_CUDA_SHARED
            PROC operator*(const f32& s0, const matrix2_f32& m0) -> matrix2_f32;

            TYON_CUDA_SHARED
            PROC operator*(const matrix2_f64& m0, const f64& s0) -> matrix2_f64;

            TYON_CUDA_SHARED
            PROC operator*(const f64& s0, const matrix2_f64& m0) -> matrix2_f64;

            TYON_CUDA_SHARED
            PROC operator*(const matrix3_f32& m0, const f32& s0) -> matrix3_f32;

            TYON_CUDA_SHARED
            PROC operator*(const f32& s0, const matrix3_f32& m0) -> matrix3_f32;

            TYON_CUDA_SHARED
            PROC operator*(const matrix3_f64& m0, const f64& s0) -> matrix3_f64;

            TYON_CUDA_SHARED
            PROC operator*(const f32& s0, const matrix3_f64& m0) -> matrix3_f64;

            TYON_CUDA_SHARED
            PROC operator*(const matrix4_f32& m0, const f32& s0) -> matrix4_f32;

            TYON_CUDA_SHARED
            PROC operator*(const f32& s0, const matrix4_f32& m0) -> matrix4_f32;

            TYON_CUDA_SHARED
            PROC operator*(const matrix4_f64& m0, const f64& s0) -> matrix4_f64;

            TYON_CUDA_SHARED
            PROC operator*(const f32& s0, const matrix4_f64& m0) -> matrix4_f64; 



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



        // Vector
            // Dot Product
            TYON_CUDA_SHARED
            PROC vector_dot_product(const v2_f32& v0, const v2_f32& v1) -> f32;

            TYON_CUDA_SHARED
            PROC vector_dot_product(const v2_f64& v0, const v2_f64& v1) -> f64;

            TYON_CUDA_SHARED
            PROC vector_dot_product(const v3_f32& v0, const v3_f32& v1) -> f32;

            TYON_CUDA_SHARED
            PROC vector_dot_product(const v3_f64& v0, const v3_f64& v1) -> f64;

            TYON_CUDA_SHARED
            PROC vector_dot_product(const v4_f32& v0, const v4_f32& v1) -> f32;

            TYON_CUDA_SHARED
            PROC vector_dot_product(const v4_f64& v0, const v4_f64& v1) -> f64;



            // Cross Product
            TYON_CUDA_SHARED
            PROC vector_cross_product(const v3_f32& v0, const v3_f32& v1) -> v3_f32;

            TYON_CUDA_SHARED
            PROC vector_cross_product(const v3_f64& v0, const v3_f64& v1) -> v3_f64;



            // Angle of two normalized vectors
            TYON_CUDA_SHARED
            PROC angle_radians(const v2_f32& v0, const v2_f32& v1) -> f32;

            TYON_CUDA_SHARED
            PROC angle_radians(const v2_f64& v0, const v2_f64& v1) -> f64;

            TYON_CUDA_SHARED
            PROC angle_radians(const v3_f32& v0, const v3_f32& v1) -> f32;

            TYON_CUDA_SHARED
            PROC angle_radians(const v3_f64& v0, const v3_f64& v1) -> f64;

            TYON_CUDA_SHARED
            PROC angle_radians(const v4_f32& v0, const v4_f32& v1) -> f32;

            TYON_CUDA_SHARED
            PROC angle_radians(const v4_f64& v0, const v4_f64& v1) -> f64;



            // Normalize
            TYON_CUDA_SHARED
            PROC vector_normalize(const v2_f32& v0) -> v2_f32;

            TYON_CUDA_SHARED
            PROC vector_normalize(const v2_f64& v0) -> v2_f64;

            TYON_CUDA_SHARED
            PROC vector_normalize(const v3_f32& v0) -> v3_f32;

            TYON_CUDA_SHARED
            PROC vector_normalize(const v3_f64& v0) -> v3_f64;

            TYON_CUDA_SHARED
            PROC vector_normalize(const v4_f32& v0) -> v4_f32;

            TYON_CUDA_SHARED
            PROC vector_normalize(const v4_f64& v0) -> v4_f64;



            // Reflect
            TYON_CUDA_SHARED
            PROC vector_reflect(const v2_f32& d, const v2_f32& n) -> v2_f32;

            TYON_CUDA_SHARED
            PROC vector_reflect(const v2_f64& d, const v2_f64& n) -> v2_f64;

            TYON_CUDA_SHARED
            PROC vector_reflect(const v3_f32& d, const v3_f32& n) -> v3_f32;

            TYON_CUDA_SHARED
            PROC vector_reflect(const v3_f64& d, const v3_f64& n) -> v3_f64;

            TYON_CUDA_SHARED
            PROC vector_reflect(const v4_f32& d, const v4_f32& n) -> v4_f32;

            TYON_CUDA_SHARED
            PROC vector_reflect(const v4_f64& d, const v4_f64& n) -> v4_f64;



            // Refract
            TYON_CUDA_SHARED
            PROC vector_refract(const v2_f32& d, const v2_f32& n, const f32& eta_0, const f32& eta_1) -> v2_f32;

            TYON_CUDA_SHARED
            PROC vector_refract(const v2_f64& d, const v2_f64& n, const f64& eta_0, const f64& eta_1) -> v2_f64;

            TYON_CUDA_SHARED
            PROC vector_refract(const v3_f32& d, const v3_f32& n, const f32& eta_0, const f32& eta_1) -> v3_f32;

            TYON_CUDA_SHARED
            PROC vector_refract(const v3_f64& d, const v3_f64& n, const f64& eta_0, const f64& eta_1) -> v3_f64;

            TYON_CUDA_SHARED
            PROC vector_refract(const v4_f32& d, const v4_f32& n, const f32& eta_0, const f32& eta_1) -> v4_f32;

            TYON_CUDA_SHARED
            PROC vector_refract(const v4_f64& d, const v4_f64& n, const f64& eta_0, const f64& eta_1) -> v4_f64;




            // Project
            TYON_CUDA_SHARED
            PROC vector_project(const v2_f32& v0, const v2_f32& v1) -> v2_f32;

            TYON_CUDA_SHARED
            PROC vector_project(const v2_f64& v0, const v2_f64& v1) -> v2_f64;

            TYON_CUDA_SHARED
            PROC vector_project(const v3_f32& v0, const v3_f32& v1) -> v3_f32;

            TYON_CUDA_SHARED
            PROC vector_project(const v3_f64& v0, const v3_f64& v1) -> v3_f64;

            TYON_CUDA_SHARED
            PROC vector_project(const v4_f32& v0, const v4_f32& v1) -> v4_f32; 

            TYON_CUDA_SHARED
            PROC vector_project(const v4_f64& v0, const v4_f64& v1) -> v4_f64;



            // Barycentric
            TYON_CUDA_SHARED
            PROC v_barycentric(const v2_f32& p0, const v2_f32& p1, const v2_f32& p2, const v2_f32& barycentric_coordinates) -> v2_f32;

            TYON_CUDA_SHARED
            PROC v_barycentric(const v2_f64& p0, const v2_f64& p1, const v2_f64& p2, const v2_f64& barycentric_coordinates) -> v2_f64;

            TYON_CUDA_SHARED
            PROC v_barycentric(const v3_f32& p0, const v3_f32& p1, const v3_f32& p2, const v2_f32& barycentric_coordinates) -> v3_f32;

            TYON_CUDA_SHARED
            PROC v_barycentric(const v3_f64& p0, const v3_f64& p1, const v3_f64& p2, const v2_f64& barycentric_coordinates) -> v3_f64;

            TYON_CUDA_SHARED
            PROC v_barycentric(const v4_f32& p0, const v4_f32& p1, const v4_f32& p2, const v2_f32& barycentric_coordinates) -> v4_f32;

            TYON_CUDA_SHARED
            PROC v_barycentric(const v4_f64& p0, const v4_f64& p1, const v4_f64& p2, const v2_f64& barycentric_coordinates) -> v4_f64;



            // Length & Lenght2
            TYON_CUDA_SHARED
            PROC vector_length(const v2_f32& v0) -> f32;

            TYON_CUDA_SHARED
            PROC vector_length(const v2_f64& v0) -> f64;

            TYON_CUDA_SHARED
            PROC vector_length(const v3_f32& v0) -> f32;

            TYON_CUDA_SHARED
            PROC vector_length(const v3_f64& v0) -> f64;

            TYON_CUDA_SHARED
            PROC vector_length(const v4_f32& v0) -> f32;

            TYON_CUDA_SHARED
            PROC vector_length(const v4_f64& v0) -> f64;

            TYON_CUDA_SHARED
            PROC vector_length2(const v2_f32& v0) -> f32;

            TYON_CUDA_SHARED
            PROC vector_length2(const v2_f64& v0) -> f64;

            TYON_CUDA_SHARED
            PROC vector_length2(const v3_f32& v0) -> f32;

            TYON_CUDA_SHARED
            PROC vector_length2(const v3_f64& v0) -> f64;

            TYON_CUDA_SHARED
            PROC vector_length2(const v4_f32& v0) -> f32;

            TYON_CUDA_SHARED
            PROC vector_length2(const v4_f64& v0) -> f64;



            // Distance & Distance2
            TYON_CUDA_SHARED
            PROC vector_distance(const v2_f32& v0, const v2_f32& v1) -> f32;

            TYON_CUDA_SHARED
            PROC vector_distance(const v2_f64& v0, const v2_f64& v1) -> f64;

            TYON_CUDA_SHARED
            PROC vector_distance(const v3_f32& v0, const v3_f32& v1) -> f32;

            TYON_CUDA_SHARED
            PROC vector_distance(const v3_f64& v0, const v3_f64& v1) -> f64;

            TYON_CUDA_SHARED
            PROC vector_distance(const v4_f32& v0, const v4_f32& v1) -> f32;

            TYON_CUDA_SHARED
            PROC vector_distance(const v4_f64& v0, const v4_f64& v1) -> f64;

            TYON_CUDA_SHARED
            PROC vector_distance2(const v2_f32& v0, const v2_f32& v1) -> f32;

            TYON_CUDA_SHARED
            PROC vector_distance2(const v2_f64& v0, const v2_f64& v1) -> f64;

            TYON_CUDA_SHARED
            PROC vector_distance2(const v3_f32& v0, const v3_f32& v1) -> f32;

            TYON_CUDA_SHARED
            PROC vector_distance2(const v3_f64& v0, const v3_f64& v1) -> f64;

            TYON_CUDA_SHARED
            PROC vector_distance2(const v4_f32& v0, const v4_f32& v1) -> f32;

            TYON_CUDA_SHARED
            PROC vector_distance2(const v4_f64& v0, const v4_f64& v1) -> f32;



            // Orthonormal basis
            TYON_CUDA_SHARED
            PROC construct_orthonormal_basis(const v3_f32& basis_vector_z, const v3_f32& omega, v3_f32& basis_vector_x, v3_f32& basis_vector_y) -> void;

            TYON_CUDA_SHARED
            PROC construct_orthonormal_basis(const v3_f64& basis_vector_z, const v3_f64& omega, v3_f64& basis_vector_x, v3_f64& basis_vector_y) -> void;



            // z-aligned normal
            TYON_CUDA_SHARED
            PROC transform_to_z_aligned_normal(const v3_f32& omega_i, const v3_f32& normal, v3_f32& basis_vector_x, v3_f32& basis_vector_y, v3_f32& basis_vector_z) -> v3_f32;

            TYON_CUDA_SHARED
            PROC transform_to_z_aligned_normal(const v3_f64& omega_i, const v3_f64& normal, v3_f64& basis_vector_x, v3_f64& basis_vector_y, v3_f64& basis_vector_z) -> v3_f64;



            // z to world space
            TYON_CUDA_SHARED
            PROC local_direction_to_world_space(const v3_f32& reference_dir, const f32& cos_theta, const f32& phi) -> v3_f32;

            TYON_CUDA_SHARED
            PROC local_direction_to_world_space(const v3_f64& reference_dir, const f64& cos_theta, const f64& phi) -> v3_f64;




        // Matrix
            // Rotation
            TYON_CUDA_SHARED
            PROC general_2d_rotation_matrix(const f32& theta) -> matrix2_f32;

            TYON_CUDA_SHARED
            PROC general_2d_rotation_matrix(const f64& theta) -> matrix2_f64;

            TYON_CUDA_SHARED
            PROC general_3d_rotation_matrix(const f32& r_x, const f32& r_y, const f32& r_z) -> matrix3_f32;

            TYON_CUDA_SHARED
            PROC general_3d_rotation_matrix(const f64& r_x, const f64& r_y, const f64& r_z) -> matrix3_f64;

            TYON_CUDA_SHARED
            PROC euler_rotation_matrix(const f32& theta, const v3_f32& u) -> matrix3_f32;

            TYON_CUDA_SHARED
            PROC euler_rotation_matrix(const f64& theta, const v3_f64& u) -> matrix3_f64;



            // Transpose
            TYON_CUDA_SHARED
            PROC transpose_matrix(const matrix2_f32& m) -> matrix2_f32;

            TYON_CUDA_SHARED
            PROC transpose_matrix(const matrix2_f64& m) -> matrix2_f64;

            TYON_CUDA_SHARED
            PROC transpose_matrix(const matrix3_f32& m) -> matrix3_f32;

            TYON_CUDA_SHARED
            PROC transpose_matrix(const matrix3_f64& m) -> matrix3_f64;

            TYON_CUDA_SHARED
            PROC transpose_matrix(const matrix4_f32& m) -> matrix4_f32;

            TYON_CUDA_SHARED
            PROC transpose_matrix(const matrix4_f64& m) -> matrix4_f64;



        // Conversion
            // To radians
            TYON_CUDA_SHARED
            PROC to_radians(const f32& degrees) -> f32;

            TYON_CUDA_SHARED
            PROC to_radians(const f64& degrees) -> f64;



            // To degrees
            TYON_CUDA_SHARED
            PROC to_degrees(const f32& radians) -> f32;

            TYON_CUDA_SHARED
            PROC to_degrees(const f64& radians) -> f64;



            // Spherical coordinates
            TYON_CUDA_SHARED
            PROC cartesian_to_spherical(const v3_f32& cartesian) -> v3_f32;

            TYON_CUDA_SHARED
            PROC cartesian_to_spherical(const v3_f64& cartesian) -> v3_f64;

            TYON_CUDA_SHARED
            PROC spherical_to_cartesian(const v3_f32& spherical) -> v3_f32;

            TYON_CUDA_SHARED
            PROC spherical_to_cartesian(const v3_f64& spherical) -> v3_f64;



        // Utility
            // Lerp
            TYON_CUDA_SHARED
            PROC lerp(const f32& a, const f32& b, const f32& t) -> f32;

            TYON_CUDA_SHARED
            PROC lerp(const f64& a, const f64& b, const f64& t) -> f64;

            TYON_CUDA_SHARED
            PROC lerp(const v2_f32& va, const v2_f32& vb, const f32& t) -> v2_f32;

            TYON_CUDA_SHARED
            PROC lerp(const v2_f64& va, const v2_f64& vb, const f64& t) -> v2_f64;

            TYON_CUDA_SHARED
            PROC lerp(const v3_f32& va, const v3_f32& vb, const f32& t) -> v3_f32;

            TYON_CUDA_SHARED
            PROC lerp(const v3_f64& va, const v3_f64& vb, const f64& t) -> v3_f64;

            TYON_CUDA_SHARED
            PROC lerp(const v4_f32& va, const v4_f32& vb, const f32& t) -> v4_f32;

            TYON_CUDA_SHARED
            PROC lerp(const v4_f64& va, const v4_f64& vb, const f64& t) -> v4_f64;



            // Smooth step
            TYON_CUDA_SHARED
            PROC smooth_step(const f32& edge0, const f32& edge1, const f32& t) -> f32;

            TYON_CUDA_SHARED
            PROC smooth_step(const f64& edge0, const f64& edge1, const f64& t) -> f64;



            // Absolute
            TYON_CUDA_SHARED
            PROC absolute(const f32& a) -> f32;

            TYON_CUDA_SHARED
            PROC absolute(const f64& a) -> f64;



            // Clamp
            TYON_CUDA_SHARED
            PROC clamp_range(const f32& edge0, const f32& edge1, const f32& a) -> f32;

            TYON_CUDA_SHARED
            PROC clamp_range(const f64& edge0, const f64& edge1, const f64& a) -> f64;



            // Min
            TYON_CUDA_SHARED
            PROC minimum(const f32& a, const f32& b) -> f32;

            TYON_CUDA_SHARED
            PROC minimum(const f64& a, const f64& b) -> f64;



            // Max
            TYON_CUDA_SHARED
            PROC maximum(const f32& a, const f32& b) -> f32;

            TYON_CUDA_SHARED
            PROC maximum(const f64& a, const f64& b) -> f64;



            // Round down
            TYON_CUDA_SHARED
            PROC round_down(const f32& a) -> f32;

            TYON_CUDA_SHARED
            PROC round_down(const f64& a) -> f64;



            // Round up
            TYON_CUDA_SHARED
            PROC round_up(const f32& a) -> f32;

            TYON_CUDA_SHARED
            PROC round_up(const f64& a) -> f64;



            // Round normal
            TYON_CUDA_SHARED
            PROC round_normal(const f32& a) -> f32;

            TYON_CUDA_SHARED
            PROC round_normal(const f64& a) -> f64;



            // Fraction
            TYON_CUDA_SHARED
            PROC fraction(const f32& a) -> f32;

            TYON_CUDA_SHARED
            PROC fraction(const f64& a) -> f64;



            // Remap
            TYON_CUDA_SHARED
            PROC remap(const f32& start0, const f32& end0, const f32& start1, const f32& end1, const f32& value) -> f32;

            TYON_CUDA_SHARED
            PROC remap(const f64& start0, const f64& end0, const f64& start1, const f64& end1, const f64& value) -> f64;



            // Swap
            TYON_CUDA_SHARED
            PROC swap_pair(f32& a, f32& b) -> void;

            TYON_CUDA_SHARED
            PROC swap_pair(f64& a, f64& b) -> void;

            TYON_CUDA_SHARED
            PROC swap_pair(c32& a, c32& b) -> void;

            TYON_CUDA_SHARED
            PROC swap_pair(c64& a, c64& b) -> void;

            TYON_CUDA_SHARED
            PROC swap_pair(v2_f32& a, v2_f32& b) -> void;

            TYON_CUDA_SHARED
            PROC swap_pair(v2_f64& a, v2_f64& b) -> void;

            TYON_CUDA_SHARED
            PROC swap_pair(v3_f32& a, v3_f32& b) -> void;

            TYON_CUDA_SHARED
            PROC swap_pair(v3_f64& a, v3_f64& b) -> void;

            TYON_CUDA_SHARED
            PROC swap_pair(v4_f32& a, v4_f32& b) -> void;

            TYON_CUDA_SHARED
            PROC swap_pair(v4_f64& a, v4_f64& b) -> void;
}
