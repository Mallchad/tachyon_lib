
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
}
