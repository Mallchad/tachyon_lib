
namespace tyon
{
    /** Types */
        // Complex Numbers
        TYON_CUDA_SHARED
        CONSTRUCTOR c32::c32() : real(0.0f), imag(0.0f) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR c32::c32( f32 arg ) : real(arg), imag(0.0f) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR c32::c32( f32 real, f32 imag) : real(real), imag(imag) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR c32::c32( f64 arg) {}

        TYON_CUDA_SHARED
        CONSTRUCTOR c64::c64() : real(0.0), imag(0.0) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR c64::c64( f64 arg ) : real(arg), imag(0.0) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR c64::c64( f64 real, f64 imag) : real(real), imag(imag) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR c64::c64( f32 arg) {}



        // Vectors 
        TYON_CUDA_SHARED
        CONSTRUCTOR v2_f32::v2_f32() : x(0.0f), y(0.0f) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v2_f32::v2_f32( f32 arg ) : x(arg), y(arg) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v2_f32::v2_f32( f32 x, f32 y) : x(x), y(y) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v2_f32::v2_f32( f64 arg ) {}

        TYON_CUDA_SHARED
        CONSTRUCTOR v2_f64::v2_f64() : x(0.0), y(0.0) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v2_f64::v2_f64( f64 arg ) : x(arg), y(arg) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v2_f64::v2_f64( f64 x, f64 y) : x(x), y(y) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v2_f64::v2_f64( f32 arg ) {}

        TYON_CUDA_SHARED
        CONSTRUCTOR v3_f32::v3_f32() : x(0.0f), y(0.0f), z(0.0f) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v3_f32::v3_f32( f32 arg ) : x(arg), y(arg), z(arg) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v3_f32::v3_f32( f32 x, f32 y, f32 z) : x(x), y(y), z(z) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v3_f32::v3_f32( f64 arg ) {}

        TYON_CUDA_SHARED
        CONSTRUCTOR v3_f64::v3_f64() : x(0.0), y(0.0), z(0.0) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v3_f64::v3_f64( f64 arg ) : x(arg), y(arg), z(arg) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v3_f64::v3_f64( f64 x, f64 y, f64 z) : x(x), y(y), z(z) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v3_f64::v3_f64( f32 arg ) {}

        TYON_CUDA_SHARED
        CONSTRUCTOR v4_f32::v4_f32() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v4_f32::v4_f32( f32 arg ) : x(arg), y(arg), z(arg), w(arg) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v4_f32::v4_f32( f32 x, f32 y, f32 z, f32 w) : x(x), y(y), z(z), w(w) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v4_f32::v4_f32( f64 arg ) {}

        TYON_CUDA_SHARED
        CONSTRUCTOR v4_f64::v4_f64() : x(0.0), y(0.0), z(0.0), w(0.0) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v4_f64::v4_f64( f64 arg ) : x(arg), y(arg), z(arg), w(arg) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v4_f64::v4_f64( f64 x, f64 y, f64 z, f64 w) : x(x), y(y), z(z), w(w) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR v4_f64::v4_f64( f32 arg ) {}



        // Matrices
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix2_f32::matrix2_f32() : m11(0.0f), m12(0.0f), m21(0.0f), m22(0.0f) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix2_f32::matrix2_f32( f32 arg ) : m11(arg), m12(arg), m21(arg), m22(arg) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix2_f32::matrix2_f32( f32 m11, f32 m12, f32 m21, f32 m22) : m11(m11), m12(m12), m21(m21), m22(m22) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix2_f32::matrix2_f32( f64 arg ) {}

        TYON_CUDA_SHARED
        CONSTRUCTOR matrix2_f64::matrix2_f64() : m11(0.0), m12(0.0), m21(0.0), m22(0.0) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix2_f64::matrix2_f64( f64 arg ) : m11(arg), m12(arg), m21(arg), m22(arg) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix2_f64::matrix2_f64( f64 m11, f64 m12, f64 m21, f64 m22) : m11(m11), m12(m12), m21(m21), m22(m22) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix2_f64::matrix2_f64( f32 arg ) {}

        TYON_CUDA_SHARED
        CONSTRUCTOR matrix3_f32::matrix3_f32() : m11(0.0f), m12(0.0f), m13(0.0f), m21(0.0f), m22(0.0f), m23(0.0f), m31(0.0f), m32(0.0f), m33(0.0f) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix3_f32::matrix3_f32( f32 arg ) : m11(arg), m12(arg), m13(arg), m21(arg), m22(arg), m23(arg), m31(arg), m32(arg), m33(arg) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix3_f32::matrix3_f32( f32 m11, f32 m12, f32 m13, f32 m21, f32 m22, f32 m23, f32 m31, f32 m32, f32 m33) : m11(m11), m12(m12), m13(m13), m21(m21), m22(m22), m23(m23), m31(m31), m32(m32), m33(m33) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix3_f32::matrix3_f32( f64 arg ) {}

        TYON_CUDA_SHARED
        CONSTRUCTOR matrix3_f64::matrix3_f64() : m11(0.0), m12(0.0), m13(0.0), m21(0.0), m22(0.0), m23(0.0), m31(0.0), m32(0.0), m33(0.0) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix3_f64::matrix3_f64( f32 arg ) : m11(arg), m12(arg), m13(arg), m21(arg), m22(arg), m23(arg), m31(arg), m32(arg), m33(arg) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix3_f64::matrix3_f64( f32 m11, f32 m12, f32 m13, f32 m21, f32 m22, f32 m23, f32 m31, f32 m32, f32 m33) : m11(m11), m12(m12), m13(m13), m21(m21), m22(m22), m23(m23), m31(m31), m32(m32), m33(m33) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix3_f64::matrix3_f64( f64 arg ) {}

        TYON_CUDA_SHARED
        CONSTRUCTOR matrix4_f32::matrix4_f32() : m11(0.0f), m12(0.0f), m13(0.0f), m14(0.0f), m21(0.0f), m22(0.0f), m23(0.0f), m24(0.0f), m31(0.0f), m32(0.0f), m33(0.0f), m34(0.0f), m41(0.0f), m42(0.0f), m43(0.0f), m44(0.0f) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix4_f32::matrix4_f32( f32 arg ) : m11(arg), m12(arg), m13(arg), m14(arg), m21(arg), m22(arg), m23(arg), m24(arg), m31(arg), m32(arg), m33(arg), m34(arg), m41(arg), m42(arg), m43(arg), m44(arg) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix4_f32::matrix4_f32( f32 m11, f32 m12, f32 m13, f32 m14, f32 m21, f32 m22, f32 m23, f32 m24, f32 m31, f32 m32, f32 m33, f32 m34, f32 m41, f32 m42, f32 m43, f32 m44) : m11(m11), m12(m12), m13(m13), m14(m14), m21(m21), m22(m22), m23(m23), m24(m24), m31(m31), m32(m32), m33(m33), m34(m34), m41(m41), m42(m42), m43(m43), m44(m44) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix4_f32::matrix4_f32( f64 arg ) {}

        TYON_CUDA_SHARED
        CONSTRUCTOR matrix4_f64::matrix4_f64() : m11(0.0), m12(0.0), m13(0.0), m14(0.0), m21(0.0), m22(0.0), m23(0.0), m24(0.0), m31(0.0), m32(0.0), m33(0.0), m34(0.0), m41(0.0), m42(0.0), m43(0.0), m44(0.0) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix4_f64::matrix4_f64( f64 arg ) : m11(arg), m12(arg), m13(arg), m14(arg), m21(arg), m22(arg), m23(arg), m24(arg), m31(arg), m32(arg), m33(arg), m34(arg), m41(arg), m42(arg), m43(arg), m44(arg) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix4_f64::matrix4_f64( f64 m11, f64 m12, f64 m13, f64 m14, f64 m21, f64 m22, f64 m23, f64 m24, f64 m31, f64 m32, f64 m33, f64 m34, f64 m41, f64 m42, f64 m43, f64 m44) : m11(m11), m12(m12), m13(m13), m14(m14), m21(m21), m22(m22), m23(m23), m24(m24), m31(m31), m32(m32), m33(m33), m34(m34), m41(m41), m42(m42), m43(m43), m44(m44) {}
        TYON_CUDA_SHARED
        CONSTRUCTOR matrix4_f64::matrix4_f64( f32 arg ) {}



    /** Operators */
        // Complex Numbers
            // Addition
            TYON_CUDA_SHARED
            PROC operator+(const c32& z0, const c32& z1) -> c32
            {
                c32 result;
                result.real = z0.real + z1.real;
                result.imag = z0.imag + z1.imag;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const c64& z0, const c64& z1) -> c64
            {
                c64 result;
                result.real = z0.real + z1.real;
                result.imag = z0.imag + z1.imag;
                return result;
            }

            // Subtraction
            TYON_CUDA_SHARED
            PROC operator-(const c32& z0, const c32& z1) -> c32
            {
                c32 result;
                result.real = z0.real - z1.real;
                result.imag = z0.imag - z1.imag;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const c64& z0, const c64& z1) -> c64
            {
                c64 result;
                result.real = z0.real - z1.real;
                result.imag = z0.imag - z1.imag;
                return result;
            }

            // Multiplication
            TYON_CUDA_SHARED
            PROC operator*(const c32& z0, const c32& z1) -> c32
            {
                c32 result;
                result.real = (z0.real * z1.real) - (z0.imag * z1.imag);
                result.imag = (z0.real * z1.imag) + (z0.imag * z1.real);
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const c64& z0, const c64& z1) -> c64
            {
                c64 result;
                result.real = (z0.real * z1.real) - (z0.imag * z1.imag);
                result.imag = (z0.real * z1.imag) + (z0.imag * z1.real);
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const c32& z0, const f32& s0) -> c32
            {
                return c32{z0.real * s0, z0.real * s0};
            }

            TYON_CUDA_SHARED
            PROC operator*(const c64& z0, const f64& s0) -> c64
            {
                return c64{z0.real * s0, z0.real * s0};
            }

            // Division
            TYON_CUDA_SHARED
            PROC operator/(const c32& z0, const c32& z1) -> c32
            {
                c32 result;
                result.real = ((z0.real * z1.real) + (z0.imag * z1.imag)) / ((z1.real * z1.real) + (z1.imag * z1.imag));
                result.imag = ((z0.imag * z1.real) - (z0.real * z1.imag)) / ((z1.real * z1.real) + (z1.imag * z1.imag));
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator/(const c64& z0, const c64& z1) -> c64
            {
                c64 result;
                result.real = ((z0.real * z1.real) + (z0.imag * z1.imag)) / ((z1.real * z1.real) + (z1.imag * z1.imag));
                result.imag = ((z0.imag * z1.real) - (z0.real * z1.imag)) / ((z1.real * z1.real) + (z1.imag * z1.imag));
                return result;
            }

            // Inverse
            TYON_CUDA_SHARED
            PROC operator-(const c32& z0) -> c32
            {
                c32 result;
                result.real = -z0.real;
                result.imag = z0.imag;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const c64& z0) -> c64
            {
                c64 result;
                result.real = -z0.real;
                result.imag = z0.imag;
                return result;
            }



        // Vector-Vector
            // Addition
            TYON_CUDA_SHARED
            PROC operator+(const v2_f32& v0, const v2_f32& v1) -> v2_f32
            {
                v2_f32 result;
                result.x = v0.x + v1.x;
                result.y = v0.y + v1.y;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const v2_f64& v0, const v2_f64& v1) -> v2_f64
            {
                v2_f64 result;
                result.x = v0.x + v1.x;
                result.y = v0.y + v1.y;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const v3_f32& v0, const v3_f32& v1) -> v3_f32
            {
                v3_f32 result;
                result.x = v0.x + v1.x;
                result.y = v0.y + v1.y;
                result.z = v0.z + v1.z;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const v3_f64& v0, const v3_f64& v1) -> v3_f64
            {
                v3_f64 result;
                result.x = v0.x + v1.x;
                result.y = v0.y + v1.y;
                result.z = v0.z + v1.z;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const v4_f32& v0, const v4_f32& v1) -> v4_f32
            {
                v4_f32 result;
                result.x = v0.x + v1.x;
                result.y = v0.y + v1.y;
                result.z = v0.z + v1.z;
                result.z = v0.w + v1.w;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const v4_f64& v0, const v4_f64& v1) -> v4_f64
            {
                v4_f64 result;
                result.x = v0.x + v1.x;
                result.y = v0.y + v1.y;
                result.z = v0.z + v1.z;
                result.z = v0.w + v1.w;
                return result;
            }

            // Subtraction
            TYON_CUDA_SHARED
            PROC operator-(const v2_f32& v0, const v2_f32& v1) -> v2_f32
            {
                v2_f32 result;
                result.x = v0.x - v1.x;
                result.y = v0.y - v1.y;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const v2_f64& v0, const v2_f64& v1) -> v2_f64
            {
                v2_f64 result;
                result.x = v0.x - v1.x;
                result.y = v0.y - v1.y;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const v3_f32& v0, const v3_f32& v1) -> v3_f32
            {
                v3_f32 result;
                result.x = v0.x - v1.x;
                result.y = v0.y - v1.y;
                result.z = v0.z - v1.z;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const v3_f64& v0, const v3_f64& v1) -> v3_f64
            {
                v3_f64 result;
                result.x = v0.x - v1.x;
                result.y = v0.y - v1.y;
                result.z = v0.z - v1.z;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const v4_f32& v0, const v4_f32& v1) -> v4_f32
            {
                v4_f32 result;
                result.x = v0.x - v1.x;
                result.y = v0.y - v1.y;
                result.z = v0.z - v1.z;
                result.z = v0.w - v1.w;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const v4_f64& v0, const v4_f64& v1) -> v4_f64
            {
                v4_f64 result;
                result.x = v0.x - v1.x;
                result.y = v0.y - v1.y;
                result.z = v0.z - v1.z;
                result.z = v0.w - v1.w;
                return result;
            }

            // Multiplication
            TYON_CUDA_SHARED
            PROC operator*(const v2_f32& v0, const v2_f32& v1) -> v2_f32
            {
                v2_f32 result;
                result.x = v0.x * v1.x;
                result.y = v0.y * v1.y;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const v2_f64& v0, const v2_f64& v1) -> v2_f64
            {
                v2_f64 result;
                result.x = v0.x * v1.x;
                result.y = v0.y * v1.y;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const v3_f32& v0, const v3_f32& v1) -> v3_f32
            {
                v3_f32 result;
                result.x = v0.x * v1.x;
                result.y = v0.y * v1.y;
                result.z = v0.z * v1.z;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const v3_f64& v0, const v3_f64& v1) -> v3_f64
            {
                v3_f64 result;
                result.x = v0.x * v1.x;
                result.y = v0.y * v1.y;
                result.z = v0.z * v1.z;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const v4_f32& v0, const v4_f32& v1) -> v4_f32
            {
                v4_f32 result;
                result.x = v0.x * v1.x;
                result.y = v0.y * v1.y;
                result.z = v0.z * v1.z;
                result.z = v0.w * v1.w;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const v4_f64& v0, const v4_f64& v1) -> v4_f64
            {
                v4_f64 result;
                result.x = v0.x * v1.x;
                result.y = v0.y * v1.y;
                result.z = v0.z * v1.z;
                result.z = v0.w * v1.w;
                return result;
            }

            // Division
            TYON_CUDA_SHARED
            PROC operator/(const v2_f32& v0, const v2_f32& v1) -> v2_f32
            {
                v2_f32 result;
                result.x = v0.x / v1.x;
                result.y = v0.y / v1.y;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator/(const v2_f64& v0, const v2_f64& v1) -> v2_f64
            {
                v2_f64 result;
                result.x = v0.x / v1.x;
                result.y = v0.y / v1.y;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator/(const v3_f32& v0, const v3_f32& v1) -> v3_f32
            {
                v3_f32 result;
                result.x = v0.x / v1.x;
                result.y = v0.y / v1.y;
                result.z = v0.z / v1.z;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator/(const v3_f64& v0, const v3_f64& v1) -> v3_f64
            {
                v3_f64 result;
                result.x = v0.x / v1.x;
                result.y = v0.y / v1.y;
                result.z = v0.z / v1.z;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator/(const v4_f32& v0, const v4_f32& v1) -> v4_f32
            {
                v4_f32 result;
                result.x = v0.x / v1.x;
                result.y = v0.y / v1.y;
                result.z = v0.z / v1.z;
                result.z = v0.w / v1.w;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator/(const v4_f64& v0, const v4_f64& v1) -> v4_f64
            {
                v4_f64 result;
                result.x = v0.x / v1.x;
                result.y = v0.y / v1.y;
                result.z = v0.z / v1.z;
                result.z = v0.w / v1.w;
                return result;
            }

            // Inverse
            TYON_CUDA_SHARED
            PROC operator-(const v2_f32& v) -> v2_f32
            {
                return v2_f32(-v.x, -v.y);
            }

            TYON_CUDA_SHARED
            PROC operator-(const v2_f64& v) -> v2_f64
            {
                return v2_f64(-v.x, -v.y);
            }

            TYON_CUDA_SHARED
            PROC operator-(const v3_f32& v) -> v3_f32
            {
                return v3_f32(-v.x, -v.y, -v.z);
            }

            TYON_CUDA_SHARED
            PROC operator-(const v3_f64& v) -> v3_f64
            {
                return v3_f64(-v.x, -v.y, -v.z);
            }

            TYON_CUDA_SHARED
            PROC operator-(const v4_f32& v) -> v4_f32
            {
                return v4_f32(-v.x, -v.y, -v.z, -v.w);
            }

            TYON_CUDA_SHARED
            PROC operator-(const v4_f64& v) -> v4_f64
            {
                return v4_f64(-v.x, -v.y, -v.z, -v.w);
            }



        // Vector-scalar
            // Multiplication
            TYON_CUDA_SHARED
            PROC operator*(const v2_f32& v0, const f32 s0) -> v2_f32
            {
                return v2_f32(v0.x * s0, v0.y * s0);
            }

            TYON_CUDA_SHARED
            PROC operator*(const v2_f64& v0, const f64 s0) -> v2_f64
            {
                return v2_f64(v0.x * s0, v0.y * s0);
            }

            TYON_CUDA_SHARED
            PROC operator*(const f32 s0, const v2_f32& v0) -> v2_f32
            {
                return v2_f32(v0.x * s0, v0.y * s0);
            }

            TYON_CUDA_SHARED
            PROC operator*(const f64 s0, const v2_f64& v0) -> v2_f64
            {
                return v2_f64(v0.x * s0, v0.y * s0);
            }

            TYON_CUDA_SHARED
            PROC operator*(const v3_f32& v0, const f32 s0) -> v3_f32
            {
                return v3_f32(v0.x * s0, v0.y * s0, v0.z * s0);
            }

            TYON_CUDA_SHARED
            PROC operator*(const v3_f64& v0, const f64 s0) -> v3_f64
            {
                return v3_f64(v0.x * s0, v0.y * s0, v0.z * s0);
            }

            TYON_CUDA_SHARED
            PROC operator*(const f32 s0, const v3_f32& v0) -> v3_f32
            {
                return v3_f32(v0.x * s0, v0.y * s0, v0.z * s0);
            }

            TYON_CUDA_SHARED
            PROC operator*(const f64 s0, const v3_f64& v0) -> v3_f64
            {
                return v3_f64(v0.x * s0, v0.y * s0, v0.z * s0);
            }

            TYON_CUDA_SHARED
            PROC operator*(const v4_f32& v0, const f32 s0) -> v4_f32
            {
                return v4_f32(v0.x * s0, v0.y * s0, v0.z * s0, v0.w * s0);
            }

            TYON_CUDA_SHARED
            PROC operator*(const v4_f64& v0, const f64 s0) -> v4_f64
            {
                return v4_f64(v0.x * s0, v0.y * s0, v0.z * s0, v0.w * s0);
            }

            TYON_CUDA_SHARED
            PROC operator*(const f32 s0, const v4_f32& v0) -> v4_f32
            {
                return v4_f32(v0.x * s0, v0.y * s0, v0.z * s0, v0.w * s0);
            }

            TYON_CUDA_SHARED
            PROC operator*(const f64 s0, const v4_f64& v0) -> v4_f64
            {
                return v4_f64(v0.x * s0, v0.y * s0, v0.z * s0, v0.w * s0);
            }

            // Division
            TYON_CUDA_SHARED
            PROC operator/(const v2_f32& v0, const f32 s0) -> v2_f32
            {
                return v2_f32(v0.x / s0, v0.y / s0);
            }

            TYON_CUDA_SHARED
            PROC operator/(const v2_f64& v0, const f64 s0) -> v2_f64
            {
                return v2_f64(v0.x / s0, v0.y / s0);
            }

            TYON_CUDA_SHARED
            PROC operator/(const f32 s0, const v2_f32& v0) -> v2_f32
            {
                return v2_f32(s0 / v0.x, s0 / v0.y);
            }

            TYON_CUDA_SHARED
            PROC operator/(const f64 s0, const v2_f64& v0) -> v2_f64
            {
                return v2_f64(s0 / v0.x, s0 / v0.y);
            }

            TYON_CUDA_SHARED
            PROC operator/(const v3_f32& v0, const f32 s0) -> v3_f32
            {
                return v3_f32(v0.x / s0, v0.y / s0, v0.z / s0);
            }

            TYON_CUDA_SHARED
            PROC operator/(const v3_f64& v0, const f64 s0) -> v3_f64
            {
                return v3_f64(v0.x / s0, v0.y / s0, v0.z / s0);
            }

            TYON_CUDA_SHARED
            PROC operator/(const f32 s0, const v3_f32& v0) -> v3_f32
            {
                return v3_f32(s0 / v0.x, s0 / v0.y, s0 / v0.z);
            }

            TYON_CUDA_SHARED
            PROC operator/(const f64 s0, const v3_f64& v0) -> v3_f64
            {
                return v3_f64(s0 / v0.x, s0 / v0.y, s0 / v0.z);
            }

            TYON_CUDA_SHARED
            PROC operator/(const v4_f32& v0, const f32 s0) -> v4_f32
            {
                return v4_f32(v0.x / s0, v0.y / s0, v0.z / s0, v0.w / s0);
            }

            TYON_CUDA_SHARED
            PROC operator/(const v4_f64& v0, const f64 s0) -> v4_f64
            {
                return v4_f64(v0.x / s0, v0.y / s0, v0.z / s0, v0.w / s0);
            }

            TYON_CUDA_SHARED
            PROC operator/(const f32 s0, const v4_f32& v0) -> v4_f32
            {
                return v4_f32(s0 / v0.x, s0 / v0.y, s0 / v0.z, s0 / v0.w);
            }

            TYON_CUDA_SHARED
            PROC operator/(const f64 s0, const v4_f64& v0) -> v4_f64
            {
                return v4_f64(s0 / v0.x, s0 / v0.y, s0 / v0.z, s0 / v0.w);
            }



        // Vector-Matrix
            TYON_CUDA_SHARED
            PROC operator*(const v2_f32& v0, const matrix2_f32& m0) -> v2_f32;

            TYON_CUDA_SHARED
            PROC operator*(const matrix2_f32& m0, const v2_f32& v0) -> v2_f32
            {
                v2_f32 result;
                result.x = m0.m11 * v0.x + m0.m12 * v0.y;
                result.y = m0.m21 * v0.x + m0.m22 * v0.y;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const v2_f64& v0, const matrix2_f64& m0) -> v2_f64;

            TYON_CUDA_SHARED
            PROC operator*(const matrix2_f64& m0, const v2_f64& v0) -> v2_f64
            {
                v2_f64 result;
                result.x = m0.m11 * v0.x + m0.m12 * v0.y;
                result.y = m0.m21 * v0.x + m0.m22 * v0.y;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const v3_f32& v0, const matrix3_f32& m0) -> v3_f32;

            TYON_CUDA_SHARED
            PROC operator*(const matrix3_f32& m0, const v3_f32& v0) -> v3_f32
            {
                v3_f32 result;
                result.x = m0.m11 * v0.x + m0.m12 * v0.y + m0.m13 * v0.z;
                result.y = m0.m21 * v0.x + m0.m22 * v0.y + m0.m23 * v0.z;
                result.z = m0.m31 * v0.x + m0.m32 * v0.y + m0.m33 * v0.z;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const v3_f64& v0, const matrix3_f64& m0) -> v3_f64;

            TYON_CUDA_SHARED
            PROC operator*(const matrix3_f64& m0, const v3_f64& v0) -> v3_f64
            {
                v3_f64 result;
                result.x = m0.m11 * v0.x + m0.m12 * v0.y + m0.m13 * v0.z;
                result.y = m0.m21 * v0.x + m0.m22 * v0.y + m0.m23 * v0.z;
                result.z = m0.m31 * v0.x + m0.m32 * v0.y + m0.m33 * v0.z;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const v4_f32& v0, const matrix4_f32& m0) -> v4_f32;

            TYON_CUDA_SHARED
            PROC operator*(const matrix4_f32& m0, const v4_f32& v0) -> v4_f32
            {
                v4_f32 result;
                result.x = m0.m11 * v0.x + m0.m12 * v0.y + m0.m13 * v0.z + m0.m14 * v0.w;
                result.y = m0.m21 * v0.x + m0.m22 * v0.y + m0.m23 * v0.z + m0.m24 * v0.w;
                result.z = m0.m31 * v0.x + m0.m32 * v0.y + m0.m33 * v0.z + m0.m34 * v0.w;
                result.w = m0.m41 * v0.x + m0.m42 * v0.y + m0.m43 * v0.z + m0.m44 * v0.w;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const v4_f64& v0, const matrix4_f64& m0) -> v4_f64;

            TYON_CUDA_SHARED
            PROC operator*(const matrix4_f64& m0, const v4_f64& v0) -> v4_f64
            {
                v4_f64 result;
                result.x = m0.m11 * v0.x + m0.m12 * v0.y + m0.m13 * v0.z + m0.m14 * v0.w;
                result.y = m0.m21 * v0.x + m0.m22 * v0.y + m0.m23 * v0.z + m0.m24 * v0.w;
                result.z = m0.m31 * v0.x + m0.m32 * v0.y + m0.m33 * v0.z + m0.m34 * v0.w;
                result.w = m0.m41 * v0.x + m0.m42 * v0.y + m0.m43 * v0.z + m0.m44 * v0.w;
                return result;
            }



        // Matrices
            // Matrix Addition
            TYON_CUDA_SHARED
            PROC operator+(const matrix2_f32& m0, const matrix2_f32& m1) -> matrix2_f32
            {
                matrix2_f32 result;
                result.m11 = m0.m11 + m1.m11;
                result.m12 = m0.m12 + m1.m12;

                result.m21 = m0.m21 + m1.m21;
                result.m22 = m0.m22 + m1.m22;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const matrix2_f64& m0, const matrix2_f64& m1) -> matrix2_f64
            {
                matrix2_f64 result;
                result.m11 = m0.m11 + m1.m11;
                result.m12 = m0.m12 + m1.m12;

                result.m21 = m0.m21 + m1.m21;
                result.m22 = m0.m22 + m1.m22;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const matrix3_f32& m0, const matrix3_f32& m1) -> matrix3_f32
            {
                matrix3_f32 result;
                result.m11 = m0.m11 + m1.m11;
                result.m12 = m0.m12 + m1.m12;
                result.m13 = m0.m13 + m1.m13;

                result.m21 = m0.m21 + m1.m21;
                result.m22 = m0.m22 + m1.m22;
                result.m23 = m0.m23 + m1.m23;

                result.m31 = m0.m31 + m1.m31;
                result.m32 = m0.m32 + m1.m32;
                result.m33 = m0.m33 + m1.m33;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const matrix3_f64& m0, const matrix3_f64& m1) -> matrix3_f64
            {
                matrix3_f64 result;
                result.m11 = m0.m11 + m1.m11;
                result.m12 = m0.m12 + m1.m12;
                result.m13 = m0.m13 + m1.m13;

                result.m21 = m0.m21 + m1.m21;
                result.m22 = m0.m22 + m1.m22;
                result.m23 = m0.m23 + m1.m23;

                result.m31 = m0.m31 + m1.m31;
                result.m32 = m0.m32 + m1.m32;
                result.m33 = m0.m33 + m1.m33;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const matrix4_f32& m0, const matrix4_f32& m1) -> matrix4_f32
            {
                matrix4_f32 result;
                result.m11 = m0.m11 + m1.m11;
                result.m12 = m0.m12 + m1.m12;
                result.m13 = m0.m13 + m1.m13;
                result.m14 = m0.m14 + m1.m14;

                result.m21 = m0.m21 + m1.m21;
                result.m22 = m0.m22 + m1.m22;
                result.m23 = m0.m23 + m1.m23;
                result.m24 = m0.m24 + m1.m24;

                result.m31 = m0.m31 + m1.m31;
                result.m32 = m0.m32 + m1.m32;
                result.m33 = m0.m33 + m1.m33;
                result.m34 = m0.m34 + m1.m34;

                result.m41 = m0.m41 + m1.m41;
                result.m42 = m0.m42 + m1.m42;
                result.m43 = m0.m43 + m1.m43;
                result.m44 = m0.m44 + m1.m44;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const matrix4_f64& m0, const matrix4_f64& m1) -> matrix4_f64
            {
                matrix4_f64 result;
                result.m11 = m0.m11 + m1.m11;
                result.m12 = m0.m12 + m1.m12;
                result.m13 = m0.m13 + m1.m13;
                result.m14 = m0.m14 + m1.m14;

                result.m21 = m0.m21 + m1.m21;
                result.m22 = m0.m22 + m1.m22;
                result.m23 = m0.m23 + m1.m23;
                result.m24 = m0.m24 + m1.m24;

                result.m31 = m0.m31 + m1.m31;
                result.m32 = m0.m32 + m1.m32;
                result.m33 = m0.m33 + m1.m33;
                result.m34 = m0.m34 + m1.m34;

                result.m41 = m0.m41 + m1.m41;
                result.m42 = m0.m42 + m1.m42;
                result.m43 = m0.m43 + m1.m43;
                result.m44 = m0.m44 + m1.m44;
                return result;
            }

            // Scalar Addition
            TYON_CUDA_SHARED
            PROC operator+(const matrix2_f32& m0, const f32& s0) -> matrix2_f32
            {
                matrix2_f32 result;
                result.m11 = m0.m11 + s0;
                result.m12 = m0.m12 + s0;
                result.m21 = m0.m21 + s0;
                result.m22 = m0.m22 + s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const f32& s0, const matrix2_f32& m0) -> matrix2_f32
            {
                matrix2_f32 result;
                result.m11 = s0 + m0.m11;
                result.m12 = s0 + m0.m12;
                result.m21 = s0 + m0.m21;
                result.m22 = s0 + m0.m22;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const matrix2_f64& m0, const f64& s0) -> matrix2_f64
            {
                matrix2_f64 result;
                result.m11 = m0.m11 + s0;
                result.m12 = m0.m12 + s0;
                result.m21 = m0.m21 + s0;
                result.m22 = m0.m22 + s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const f64& s0, const matrix2_f64& m0) -> matrix2_f64
            {
                matrix2_f64 result;
                result.m11 = s0 + m0.m11;
                result.m12 = s0 + m0.m12;
                result.m21 = s0 + m0.m21;
                result.m22 = s0 + m0.m22;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const matrix3_f32& m0, const f32& s0) -> matrix3_f32
            {
                matrix3_f32 result;
                result.m11 = m0.m11 + s0;
                result.m12 = m0.m12 + s0;
                result.m13 = m0.m13 + s0;

                result.m21 = m0.m21 + s0;
                result.m22 = m0.m22 + s0;
                result.m23 = m0.m23 + s0;

                result.m31 = m0.m31 + s0;
                result.m32 = m0.m32 + s0;
                result.m33 = m0.m33 + s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const f32& s0, const matrix3_f32& m0) -> matrix3_f32
            {
                matrix3_f32 result;
                result.m11 = s0 + m0.m11;
                result.m12 = s0 + m0.m12;
                result.m13 = s0 + m0.m13;

                result.m21 = s0 + m0.m21;
                result.m22 = s0 + m0.m22;
                result.m23 = s0 + m0.m23;

                result.m31 = s0 + m0.m31;
                result.m32 = s0 + m0.m32;
                result.m33 = s0 + m0.m33;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const matrix3_f64& m0, const f64& s0) -> matrix3_f64
            {
                matrix3_f64 result;
                result.m11 = m0.m11 + s0;
                result.m12 = m0.m12 + s0;
                result.m13 = m0.m13 + s0;

                result.m21 = m0.m21 + s0;
                result.m22 = m0.m22 + s0;
                result.m23 = m0.m23 + s0;

                result.m31 = m0.m31 + s0;
                result.m32 = m0.m32 + s0;
                result.m33 = m0.m33 + s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const f32& s0, const matrix3_f64& m0) -> matrix3_f64
            {
                matrix3_f64 result;
                result.m11 = s0 + m0.m11;
                result.m12 = s0 + m0.m12;
                result.m13 = s0 + m0.m13;

                result.m21 = s0 + m0.m21;
                result.m22 = s0 + m0.m22;
                result.m23 = s0 + m0.m23;

                result.m31 = s0 + m0.m31;
                result.m32 = s0 + m0.m32;
                result.m33 = s0 + m0.m33;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const matrix4_f32& m0, const f32& s0) -> matrix4_f32
            {
                matrix4_f32 result;
                result.m11 = m0.m11 + s0;
                result.m12 = m0.m12 + s0;
                result.m13 = m0.m13 + s0;
                result.m14 = m0.m14 + s0;

                result.m21 = m0.m21 + s0;
                result.m22 = m0.m22 + s0;
                result.m23 = m0.m23 + s0;
                result.m24 = m0.m24 + s0;

                result.m31 = m0.m31 + s0;
                result.m32 = m0.m32 + s0;
                result.m33 = m0.m33 + s0;
                result.m34 = m0.m34 + s0;

                result.m41 = m0.m41 + s0;
                result.m42 = m0.m42 + s0;
                result.m43 = m0.m43 + s0;
                result.m44 = m0.m44 + s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const f32& s0, const matrix4_f32& m0) -> matrix4_f32
            {
                matrix4_f32 result;
                result.m11 = s0 + m0.m11;
                result.m12 = s0 + m0.m12;
                result.m13 = s0 + m0.m13;
                result.m14 = s0 + m0.m14;

                result.m21 = s0 + m0.m21;
                result.m22 = s0 + m0.m22;
                result.m23 = s0 + m0.m23;
                result.m24 = s0 + m0.m24;

                result.m31 = s0 + m0.m31;
                result.m32 = s0 + m0.m32;
                result.m33 = s0 + m0.m33;
                result.m34 = s0 + m0.m34;

                result.m41 = s0 + m0.m41;
                result.m42 = s0 + m0.m42;
                result.m43 = s0 + m0.m43;
                result.m44 = s0 + m0.m44;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const matrix4_f64& m0, const f64& s0) -> matrix4_f64
            {
                matrix4_f64 result;
                result.m11 = m0.m11 + s0;
                result.m12 = m0.m12 + s0;
                result.m13 = m0.m13 + s0;
                result.m14 = m0.m14 + s0;

                result.m21 = m0.m21 + s0;
                result.m22 = m0.m22 + s0;
                result.m23 = m0.m23 + s0;
                result.m24 = m0.m24 + s0;

                result.m31 = m0.m31 + s0;
                result.m32 = m0.m32 + s0;
                result.m33 = m0.m33 + s0;
                result.m34 = m0.m34 + s0;

                result.m41 = m0.m41 + s0;
                result.m42 = m0.m42 + s0;
                result.m43 = m0.m43 + s0;
                result.m44 = m0.m44 + s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator+(const f32& s0, const matrix4_f64& m0) -> matrix4_f64
            {
                matrix4_f64 result;
                result.m11 = s0 + m0.m11;
                result.m12 = s0 + m0.m12;
                result.m13 = s0 + m0.m13;
                result.m14 = s0 + m0.m14;

                result.m21 = s0 + m0.m21;
                result.m22 = s0 + m0.m22;
                result.m23 = s0 + m0.m23;
                result.m24 = s0 + m0.m24;

                result.m31 = s0 + m0.m31;
                result.m32 = s0 + m0.m32;
                result.m33 = s0 + m0.m33;
                result.m34 = s0 + m0.m34;

                result.m41 = s0 + m0.m41;
                result.m42 = s0 + m0.m42;
                result.m43 = s0 + m0.m43;
                result.m44 = s0 + m0.m44;
                return result;
            }

            // Matrix Subtraction
            TYON_CUDA_SHARED
            PROC operator-(const matrix2_f32& m0, const matrix2_f32& m1) -> matrix2_f32
            {
                matrix2_f32 result;
                result.m11 = m0.m11 - m1.m11;
                result.m12 = m0.m12 - m1.m12;

                result.m21 = m0.m21 - m1.m21;
                result.m22 = m0.m22 - m1.m22;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const matrix2_f64& m0, const matrix2_f64& m1) -> matrix2_f64
            {
                matrix2_f64 result;
                result.m11 = m0.m11 - m1.m11;
                result.m12 = m0.m12 - m1.m12;

                result.m21 = m0.m21 - m1.m21;
                result.m22 = m0.m22 - m1.m22;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const matrix3_f32& m0, const matrix3_f32& m1) -> matrix3_f32
            {
                matrix3_f32 result;
                result.m11 = m0.m11 - m1.m11;
                result.m12 = m0.m12 - m1.m12;
                result.m13 = m0.m13 - m1.m13;

                result.m21 = m0.m21 - m1.m21;
                result.m22 = m0.m22 - m1.m22;
                result.m23 = m0.m23 - m1.m23;

                result.m31 = m0.m31 - m1.m31;
                result.m32 = m0.m32 - m1.m32;
                result.m33 = m0.m33 - m1.m33;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const matrix3_f64& m0, const matrix3_f64& m1) -> matrix3_f64
            {
                matrix3_f64 result;
                result.m11 = m0.m11 - m1.m11;
                result.m12 = m0.m12 - m1.m12;
                result.m13 = m0.m13 - m1.m13;

                result.m21 = m0.m21 - m1.m21;
                result.m22 = m0.m22 - m1.m22;
                result.m23 = m0.m23 - m1.m23;

                result.m31 = m0.m31 - m1.m31;
                result.m32 = m0.m32 - m1.m32;
                result.m33 = m0.m33 - m1.m33;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const matrix4_f32& m0, const matrix4_f32& m1) -> matrix4_f32
            {
                matrix4_f32 result;
                result.m11 = m0.m11 - m1.m11;
                result.m12 = m0.m12 - m1.m12;
                result.m13 = m0.m13 - m1.m13;
                result.m14 = m0.m14 - m1.m14;

                result.m21 = m0.m21 - m1.m21;
                result.m22 = m0.m22 - m1.m22;
                result.m23 = m0.m23 - m1.m23;
                result.m24 = m0.m24 - m1.m24;

                result.m31 = m0.m31 - m1.m31;
                result.m32 = m0.m32 - m1.m32;
                result.m33 = m0.m33 - m1.m33;
                result.m34 = m0.m34 - m1.m34;

                result.m41 = m0.m41 - m1.m41;
                result.m42 = m0.m42 - m1.m42;
                result.m43 = m0.m43 - m1.m43;
                result.m44 = m0.m44 - m1.m44;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const matrix4_f64& m0, const matrix4_f64& m1) -> matrix4_f64
            {
                matrix4_f64 result;
                result.m11 = m0.m11 - m1.m11;
                result.m12 = m0.m12 - m1.m12;
                result.m13 = m0.m13 - m1.m13;
                result.m14 = m0.m14 - m1.m14;

                result.m21 = m0.m21 - m1.m21;
                result.m22 = m0.m22 - m1.m22;
                result.m23 = m0.m23 - m1.m23;
                result.m24 = m0.m24 - m1.m24;

                result.m31 = m0.m31 - m1.m31;
                result.m32 = m0.m32 - m1.m32;
                result.m33 = m0.m33 - m1.m33;
                result.m34 = m0.m34 - m1.m34;

                result.m41 = m0.m41 - m1.m41;
                result.m42 = m0.m42 - m1.m42;
                result.m43 = m0.m43 - m1.m43;
                result.m44 = m0.m44 - m1.m44;
                return result;
            }

            // Scalar Subtraction 
            TYON_CUDA_SHARED
            PROC operator-(const matrix2_f32& m0, const f32& s0) -> matrix2_f32
            {
                matrix2_f32 result;
                result.m11 = m0.m11 - s0;
                result.m12 = m0.m12 - s0;
                result.m21 = m0.m21 - s0;
                result.m22 = m0.m22 - s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const f32& s0, const matrix2_f32& m0) -> matrix2_f32
            {
                matrix2_f32 result;
                result.m11 = s0 - m0.m11;
                result.m12 = s0 - m0.m12;
                result.m21 = s0 - m0.m21;
                result.m22 = s0 - m0.m22;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const matrix2_f64& m0, const f64& s0) -> matrix2_f64
            {
                matrix2_f64 result;
                result.m11 = m0.m11 - s0;
                result.m12 = m0.m12 - s0;
                result.m21 = m0.m21 - s0;
                result.m22 = m0.m22 - s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const f64& s0, const matrix2_f64& m0) -> matrix2_f64
            {
                matrix2_f64 result;
                result.m11 = s0 - m0.m11;
                result.m12 = s0 - m0.m12;
                result.m21 = s0 - m0.m21;
                result.m22 = s0 - m0.m22;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const matrix3_f32& m0, const f32& s0) -> matrix3_f32
            {
                matrix3_f32 result;
                result.m11 = m0.m11 - s0;
                result.m12 = m0.m12 - s0;
                result.m13 = m0.m13 - s0;

                result.m21 = m0.m21 - s0;
                result.m22 = m0.m22 - s0;
                result.m23 = m0.m23 - s0;

                result.m31 = m0.m31 - s0;
                result.m32 = m0.m32 - s0;
                result.m33 = m0.m33 - s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const f32& s0, const matrix3_f32& m0) -> matrix3_f32
            {
                matrix3_f32 result;
                result.m11 = s0 - m0.m11;
                result.m12 = s0 - m0.m12;
                result.m13 = s0 - m0.m13;

                result.m21 = s0 - m0.m21;
                result.m22 = s0 - m0.m22;
                result.m23 = s0 - m0.m23;

                result.m31 = s0 - m0.m31;
                result.m32 = s0 - m0.m32;
                result.m33 = s0 - m0.m33;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const matrix3_f64& m0, const f64& s0) -> matrix3_f64
            {
                matrix3_f64 result;
                result.m11 = m0.m11 - s0;
                result.m12 = m0.m12 - s0;
                result.m13 = m0.m13 - s0;

                result.m21 = m0.m21 - s0;
                result.m22 = m0.m22 - s0;
                result.m23 = m0.m23 - s0;

                result.m31 = m0.m31 - s0;
                result.m32 = m0.m32 - s0;
                result.m33 = m0.m33 - s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const f32& s0, const matrix3_f64& m0) -> matrix3_f64
            {
                matrix3_f64 result;
                result.m11 = s0 - m0.m11;
                result.m12 = s0 - m0.m12;
                result.m13 = s0 - m0.m13;

                result.m21 = s0 - m0.m21;
                result.m22 = s0 - m0.m22;
                result.m23 = s0 - m0.m23;

                result.m31 = s0 - m0.m31;
                result.m32 = s0 - m0.m32;
                result.m33 = s0 - m0.m33;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const matrix4_f32& m0, const f32& s0) -> matrix4_f32
            {
                matrix4_f32 result;
                result.m11 = m0.m11 - s0;
                result.m12 = m0.m12 - s0;
                result.m13 = m0.m13 - s0;
                result.m14 = m0.m14 - s0;

                result.m21 = m0.m21 - s0;
                result.m22 = m0.m22 - s0;
                result.m23 = m0.m23 - s0;
                result.m24 = m0.m24 - s0;

                result.m31 = m0.m31 - s0;
                result.m32 = m0.m32 - s0;
                result.m33 = m0.m33 - s0;
                result.m34 = m0.m34 - s0;

                result.m41 = m0.m41 - s0;
                result.m42 = m0.m42 - s0;
                result.m43 = m0.m43 - s0;
                result.m44 = m0.m44 - s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const f32& s0, const matrix4_f32& m0) -> matrix4_f32
            {
                matrix4_f32 result;
                result.m11 = s0 - m0.m11;
                result.m12 = s0 - m0.m12;
                result.m13 = s0 - m0.m13;
                result.m14 = s0 - m0.m14;

                result.m21 = s0 - m0.m21;
                result.m22 = s0 - m0.m22;
                result.m23 = s0 - m0.m23;
                result.m24 = s0 - m0.m24;

                result.m31 = s0 - m0.m31;
                result.m32 = s0 - m0.m32;
                result.m33 = s0 - m0.m33;
                result.m34 = s0 - m0.m34;

                result.m41 = s0 - m0.m41;
                result.m42 = s0 - m0.m42;
                result.m43 = s0 - m0.m43;
                result.m44 = s0 - m0.m44;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const matrix4_f64& m0, const f64& s0) -> matrix4_f64
            {
                matrix4_f64 result;
                result.m11 = m0.m11 - s0;
                result.m12 = m0.m12 - s0;
                result.m13 = m0.m13 - s0;
                result.m14 = m0.m14 - s0;

                result.m21 = m0.m21 - s0;
                result.m22 = m0.m22 - s0;
                result.m23 = m0.m23 - s0;
                result.m24 = m0.m24 - s0;

                result.m31 = m0.m31 - s0;
                result.m32 = m0.m32 - s0;
                result.m33 = m0.m33 - s0;
                result.m34 = m0.m34 - s0;

                result.m41 = m0.m41 - s0;
                result.m42 = m0.m42 - s0;
                result.m43 = m0.m43 - s0;
                result.m44 = m0.m44 - s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator-(const f32& s0, const matrix4_f64& m0) -> matrix4_f64
            {
                matrix4_f64 result;
                result.m11 = s0 - m0.m11;
                result.m12 = s0 - m0.m12;
                result.m13 = s0 - m0.m13;
                result.m14 = s0 - m0.m14;

                result.m21 = s0 - m0.m21;
                result.m22 = s0 - m0.m22;
                result.m23 = s0 - m0.m23;
                result.m24 = s0 - m0.m24;

                result.m31 = s0 - m0.m31;
                result.m32 = s0 - m0.m32;
                result.m33 = s0 - m0.m33;
                result.m34 = s0 - m0.m34;

                result.m41 = s0 - m0.m41;
                result.m42 = s0 - m0.m42;
                result.m43 = s0 - m0.m43;
                result.m44 = s0 - m0.m44;
                return result;
            }

            // Matrix Multiplication
            TYON_CUDA_SHARED
            PROC operator*(const matrix2_f32& m0, const matrix2_f32& m1) -> matrix2_f32
            {
                matrix2_f32 result;
                result.m11 = m0.m11 * m1.m11 + m0.m12 * m1.m21;
                result.m12 = m0.m11 * m1.m12 + m0.m12 * m1.m22;
                result.m21 = m0.m21 * m1.m11 + m0.m22 * m1.m21;
                result.m22 = m0.m21 * m1.m12 + m0.m22 * m1.m22;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const matrix2_f64& m0, const matrix2_f64& m1) -> matrix2_f64
            {
                matrix2_f64 result;
                result.m11 = m0.m11 * m1.m11 + m0.m12 * m1.m21;
                result.m12 = m0.m11 * m1.m12 + m0.m12 * m1.m22;
                result.m21 = m0.m21 * m1.m11 + m0.m22 * m1.m21;
                result.m22 = m0.m21 * m1.m12 + m0.m22 * m1.m22;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const matrix3_f32& m0, const matrix3_f32& m1) -> matrix3_f32
            {
                matrix3_f32 result;
                result.m11 = m0.m11 * m1.m11 + m0.m12 * m1.m21 + m0.m13 * m1.m31;
                result.m12 = m0.m11 * m1.m12 + m0.m12 * m1.m22 + m0.m13 * m1.m32;
                result.m13 = m0.m11 * m1.m13 + m0.m12 * m1.m23 + m0.m13 * m1.m33;
                result.m21 = m0.m21 * m1.m11 + m0.m22 * m1.m21 + m0.m23 * m1.m31;
                result.m22 = m0.m21 * m1.m12 + m0.m22 * m1.m22 + m0.m23 * m1.m32;
                result.m23 = m0.m21 * m1.m13 + m0.m22 * m1.m23 + m0.m23 * m1.m33;
                result.m31 = m0.m31 * m1.m11 + m0.m32 * m1.m21 + m0.m33 * m1.m31;
                result.m32 = m0.m31 * m1.m12 + m0.m32 * m1.m22 + m0.m33 * m1.m32;
                result.m33 = m0.m31 * m1.m13 + m0.m32 * m1.m23 + m0.m33 * m1.m33;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const matrix3_f64& m0, const matrix3_f64& m1) -> matrix3_f64
            {
                matrix3_f64 result;
                result.m11 = m0.m11 * m1.m11 + m0.m12 * m1.m21 + m0.m13 * m1.m31;
                result.m12 = m0.m11 * m1.m12 + m0.m12 * m1.m22 + m0.m13 * m1.m32;
                result.m13 = m0.m11 * m1.m13 + m0.m12 * m1.m23 + m0.m13 * m1.m33;
                result.m21 = m0.m21 * m1.m11 + m0.m22 * m1.m21 + m0.m23 * m1.m31;
                result.m22 = m0.m21 * m1.m12 + m0.m22 * m1.m22 + m0.m23 * m1.m32;
                result.m23 = m0.m21 * m1.m13 + m0.m22 * m1.m23 + m0.m23 * m1.m33;
                result.m31 = m0.m31 * m1.m11 + m0.m32 * m1.m21 + m0.m33 * m1.m31;
                result.m32 = m0.m31 * m1.m12 + m0.m32 * m1.m22 + m0.m33 * m1.m32;
                result.m33 = m0.m31 * m1.m13 + m0.m32 * m1.m23 + m0.m33 * m1.m33;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const matrix4_f32& m0, const matrix4_f32& m1) -> matrix4_f32
            {
                matrix4_f32 result;
                result.m11 = m0.m11 * m1.m11 + m0.m12 * m1.m21 + m0.m13 * m1.m31 + m0.m14 * m1.m41;
                result.m12 = m0.m11 * m1.m12 + m0.m12 * m1.m22 + m0.m13 * m1.m32 + m0.m14 * m1.m42;
                result.m13 = m0.m11 * m1.m13 + m0.m12 * m1.m23 + m0.m13 * m1.m33 + m0.m14 * m1.m43;
                result.m14 = m0.m11 * m1.m14 + m0.m12 * m1.m24 + m0.m13 * m1.m34 + m0.m14 * m1.m44;
                result.m21 = m0.m21 * m1.m11 + m0.m22 * m1.m21 + m0.m23 * m1.m31 + m0.m24 * m1.m41;
                result.m22 = m0.m21 * m1.m12 + m0.m22 * m1.m22 + m0.m23 * m1.m32 + m0.m24 * m1.m42;
                result.m23 = m0.m21 * m1.m13 + m0.m22 * m1.m23 + m0.m23 * m1.m33 + m0.m24 * m1.m43;
                result.m24 = m0.m21 * m1.m14 + m0.m22 * m1.m24 + m0.m23 * m1.m34 + m0.m24 * m1.m44;
                result.m31 = m0.m31 * m1.m11 + m0.m32 * m1.m21 + m0.m33 * m1.m31 + m0.m34 * m1.m41;
                result.m32 = m0.m31 * m1.m12 + m0.m32 * m1.m22 + m0.m33 * m1.m32 + m0.m34 * m1.m42;
                result.m33 = m0.m31 * m1.m13 + m0.m32 * m1.m23 + m0.m33 * m1.m33 + m0.m34 * m1.m43;
                result.m34 = m0.m31 * m1.m14 + m0.m32 * m1.m24 + m0.m33 * m1.m34 + m0.m34 * m1.m44;
                result.m41 = m0.m41 * m1.m11 + m0.m42 * m1.m21 + m0.m43 * m1.m31 + m0.m44 * m1.m41;
                result.m42 = m0.m41 * m1.m12 + m0.m42 * m1.m22 + m0.m43 * m1.m32 + m0.m44 * m1.m42;
                result.m43 = m0.m41 * m1.m13 + m0.m42 * m1.m23 + m0.m43 * m1.m33 + m0.m44 * m1.m43;
                result.m44 = m0.m41 * m1.m14 + m0.m42 * m1.m24 + m0.m43 * m1.m34 + m0.m44 * m1.m44;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const matrix4_f64& m0, const matrix4_f64& m1) -> matrix4_f64
            {
                matrix4_f64 result;
                result.m11 = m0.m11 * m1.m11 + m0.m12 * m1.m21 + m0.m13 * m1.m31 + m0.m14 * m1.m41;
                result.m12 = m0.m11 * m1.m12 + m0.m12 * m1.m22 + m0.m13 * m1.m32 + m0.m14 * m1.m42;
                result.m13 = m0.m11 * m1.m13 + m0.m12 * m1.m23 + m0.m13 * m1.m33 + m0.m14 * m1.m43;
                result.m14 = m0.m11 * m1.m14 + m0.m12 * m1.m24 + m0.m13 * m1.m34 + m0.m14 * m1.m44;
                result.m21 = m0.m21 * m1.m11 + m0.m22 * m1.m21 + m0.m23 * m1.m31 + m0.m24 * m1.m41;
                result.m22 = m0.m21 * m1.m12 + m0.m22 * m1.m22 + m0.m23 * m1.m32 + m0.m24 * m1.m42;
                result.m23 = m0.m21 * m1.m13 + m0.m22 * m1.m23 + m0.m23 * m1.m33 + m0.m24 * m1.m43;
                result.m24 = m0.m21 * m1.m14 + m0.m22 * m1.m24 + m0.m23 * m1.m34 + m0.m24 * m1.m44;
                result.m31 = m0.m31 * m1.m11 + m0.m32 * m1.m21 + m0.m33 * m1.m31 + m0.m34 * m1.m41;
                result.m32 = m0.m31 * m1.m12 + m0.m32 * m1.m22 + m0.m33 * m1.m32 + m0.m34 * m1.m42;
                result.m33 = m0.m31 * m1.m13 + m0.m32 * m1.m23 + m0.m33 * m1.m33 + m0.m34 * m1.m43;
                result.m34 = m0.m31 * m1.m14 + m0.m32 * m1.m24 + m0.m33 * m1.m34 + m0.m34 * m1.m44;
                result.m41 = m0.m41 * m1.m11 + m0.m42 * m1.m21 + m0.m43 * m1.m31 + m0.m44 * m1.m41;
                result.m42 = m0.m41 * m1.m12 + m0.m42 * m1.m22 + m0.m43 * m1.m32 + m0.m44 * m1.m42;
                result.m43 = m0.m41 * m1.m13 + m0.m42 * m1.m23 + m0.m43 * m1.m33 + m0.m44 * m1.m43;
                result.m44 = m0.m41 * m1.m14 + m0.m42 * m1.m24 + m0.m43 * m1.m34 + m0.m44 * m1.m44;
                return result;
            }

            // Scalar Multiplication
            TYON_CUDA_SHARED
            PROC operator*(const matrix2_f32& m0, const f32& s0) -> matrix2_f32
            {
                matrix2_f32 result;
                result.m11 = m0.m11 * s0;
                result.m12 = m0.m12 * s0;

                result.m21 = m0.m21 * s0;
                result.m22 = m0.m22 * s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const f32& s0, const matrix2_f32& m0) -> matrix2_f32
            {
                matrix2_f32 result;
                result.m11 = m0.m11 * s0;
                result.m12 = m0.m12 * s0;

                result.m21 = m0.m21 * s0;
                result.m22 = m0.m22 * s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const matrix2_f64& m0, const f64& s0) -> matrix2_f64
            {
                matrix2_f64 result;
                result.m11 = m0.m11 * s0;
                result.m12 = m0.m12 * s0;

                result.m21 = m0.m21 * s0;
                result.m22 = m0.m22 * s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const f64& s0, const matrix2_f64& m0) -> matrix2_f64
            {
                matrix2_f64 result;
                result.m11 = m0.m11 * s0;
                result.m12 = m0.m12 * s0;

                result.m21 = m0.m21 * s0;
                result.m22 = m0.m22 * s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const matrix3_f32& m0, const f32& s0) -> matrix3_f32
            {
                matrix3_f32 result;
                result.m11 = m0.m11 * s0;
                result.m12 = m0.m12 * s0;
                result.m13 = m0.m13 * s0;

                result.m21 = m0.m21 * s0;
                result.m22 = m0.m22 * s0;
                result.m23 = m0.m23 * s0;

                result.m31 = m0.m31 * s0;
                result.m32 = m0.m32 * s0;
                result.m33 = m0.m33 * s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const f32& s0, const matrix3_f32& m0) -> matrix3_f32
            {
                matrix3_f32 result;
                result.m11 = m0.m11 * s0;
                result.m12 = m0.m12 * s0;
                result.m13 = m0.m13 * s0;

                result.m21 = m0.m21 * s0;
                result.m22 = m0.m22 * s0;
                result.m23 = m0.m23 * s0;

                result.m31 = m0.m31 * s0;
                result.m32 = m0.m32 * s0;
                result.m33 = m0.m33 * s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const matrix3_f64& m0, const f64& s0) -> matrix3_f64
            {
                matrix3_f64 result;
                result.m11 = m0.m11 * s0;
                result.m12 = m0.m12 * s0;
                result.m13 = m0.m13 * s0;

                result.m21 = m0.m21 * s0;
                result.m22 = m0.m22 * s0;
                result.m23 = m0.m23 * s0;

                result.m31 = m0.m31 * s0;
                result.m32 = m0.m32 * s0;
                result.m33 = m0.m33 * s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const f32& s0, const matrix3_f64& m0) -> matrix3_f64
            {
                matrix3_f64 result;
                result.m11 = m0.m11 * s0;
                result.m12 = m0.m12 * s0;
                result.m13 = m0.m13 * s0;

                result.m21 = m0.m21 * s0;
                result.m22 = m0.m22 * s0;
                result.m23 = m0.m23 * s0;

                result.m31 = m0.m31 * s0;
                result.m32 = m0.m32 * s0;
                result.m33 = m0.m33 * s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const matrix4_f32& m0, const f32& s0) -> matrix4_f32
            {
                matrix4_f32 result;
                result.m11 = m0.m11 * s0;
                result.m12 = m0.m12 * s0;
                result.m13 = m0.m13 * s0;
                result.m14 = m0.m14 * s0;

                result.m21 = m0.m21 * s0;
                result.m22 = m0.m22 * s0;
                result.m23 = m0.m23 * s0;
                result.m24 = m0.m24 * s0;

                result.m31 = m0.m31 * s0;
                result.m32 = m0.m32 * s0;
                result.m33 = m0.m33 * s0;
                result.m34 = m0.m34 * s0;

                result.m41 = m0.m41 * s0;
                result.m42 = m0.m42 * s0;
                result.m43 = m0.m43 * s0;
                result.m44 = m0.m44 * s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const f32& s0, const matrix4_f32& m0) -> matrix4_f32
            {
                matrix4_f32 result;
                result.m11 = m0.m11 * s0;
                result.m12 = m0.m12 * s0;
                result.m13 = m0.m13 * s0;
                result.m14 = m0.m14 * s0;

                result.m21 = m0.m21 * s0;
                result.m22 = m0.m22 * s0;
                result.m23 = m0.m23 * s0;
                result.m24 = m0.m24 * s0;

                result.m31 = m0.m31 * s0;
                result.m32 = m0.m32 * s0;
                result.m33 = m0.m33 * s0;
                result.m34 = m0.m34 * s0;

                result.m41 = m0.m41 * s0;
                result.m42 = m0.m42 * s0;
                result.m43 = m0.m43 * s0;
                result.m44 = m0.m44 * s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const matrix4_f64& m0, const f64& s0) -> matrix4_f64
            {
                matrix4_f64 result;
                result.m11 = m0.m11 * s0;
                result.m12 = m0.m12 * s0;
                result.m13 = m0.m13 * s0;
                result.m14 = m0.m14 * s0;

                result.m21 = m0.m21 * s0;
                result.m22 = m0.m22 * s0;
                result.m23 = m0.m23 * s0;
                result.m24 = m0.m24 * s0;

                result.m31 = m0.m31 * s0;
                result.m32 = m0.m32 * s0;
                result.m33 = m0.m33 * s0;
                result.m34 = m0.m34 * s0;

                result.m41 = m0.m41 * s0;
                result.m42 = m0.m42 * s0;
                result.m43 = m0.m43 * s0;
                result.m44 = m0.m44 * s0;
                return result;
            }

            TYON_CUDA_SHARED
            PROC operator*(const f32& s0, const matrix4_f64& m0) -> matrix4_f64
            {
                matrix4_f64 result;
                result.m11 = m0.m11 * s0;
                result.m12 = m0.m12 * s0;
                result.m13 = m0.m13 * s0;
                result.m14 = m0.m14 * s0;

                result.m21 = m0.m21 * s0;
                result.m22 = m0.m22 * s0;
                result.m23 = m0.m23 * s0;
                result.m24 = m0.m24 * s0;

                result.m31 = m0.m31 * s0;
                result.m32 = m0.m32 * s0;
                result.m33 = m0.m33 * s0;
                result.m34 = m0.m34 * s0;

                result.m41 = m0.m41 * s0;
                result.m42 = m0.m42 * s0;
                result.m43 = m0.m43 * s0;
                result.m44 = m0.m44 * s0;
                return result;
            }



    /** Functions */
        // Complex Numbers
        TYON_CUDA_SHARED
        PROC complex_conjugate(const c32& z) -> c32
        {
            return c32(z.real, -z.imag);
        }

        TYON_CUDA_SHARED
        PROC complex_conjugate(const c64& z) -> c64
        {
            return c64(z.real, -z.imag);
        }

        TYON_CUDA_SHARED
        PROC complex_modulus(const c32& z) -> f32
        {
            return square_root( z.real * z.real + z.imag * z.imag );
        }

        TYON_CUDA_SHARED
        PROC complex_modulus(const c64& z) -> f64
        {
            return square_root( z.real * z.real + z.imag * z.imag );
        }

        TYON_CUDA_SHARED
        PROC complex_arg(const c32& z) -> f32
        {
            return arctan2(z.imag, z.real);
        }

        TYON_CUDA_SHARED
        PROC complex_arg(const c64& z) -> f64
        {
            return arctan2(z.imag, z.real);
        }



        // Square root
        TYON_CUDA_SHARED
        PROC square_root(const f32& a) -> f32
        {
            return std::sqrtf(a);
        }

        TYON_CUDA_SHARED
        PROC square_root(const f64& a) -> f64
        {
            return std::sqrt(a);
        }

        TYON_CUDA_SHARED
        PROC square_root(const c32& z) -> c32
        {
            // Branch cut along the negative real axis to follow 
            // the std::sqrt(std::complex) implementation. 

            f32 x = z.real;
            f32 y = z.imag;

            if(x == 0.0f && y == 0.0f)
            {
                return c32(0.0f, 0.0f); 
            }

            f32 theta = arctan2(y, x);
            f32 power_term = power(x * x + y * y, 0.25f);
            f32 x2 = power_term * cosinus(theta);
            f32 y2 = power_term * sinus(theta);

            if(x2 < 0.0f)
            {
                x2 *= -1.0f;
                y2 *= -1.0f;
            }

            return c32(x2, y2);
        }



        TYON_CUDA_SHARED
        PROC square_root(const c64& z) -> c64
        {
            // Branch cut along the negative real axis to follow 
            // the std::sqrt(std::complex) implementation. 

            f64 x = z.real;
            f64 y = z.imag;

            if(x == 0.0 && y == 0.0)
            {
                return c64(0.0f, 0.0f); 
            }

            f64 theta = arctan2(y, x);
            f64 power_term = power(x * x + y * y, 0.25);
            f64 x2 = power_term * cosinus(theta);
            f64 y2 = power_term * sinus(theta);

            if(x2 < 0.0)
            {
                x2 *= -1.0;
                y2 *= -1.0;
            }

            return c64(x2, y2);
        }



        // Exponential
        TYON_CUDA_SHARED
        PROC power(const f32& base, const f32& exponent) -> f32
        {
            return std::powf(base, exponent);
        }

        TYON_CUDA_SHARED
        PROC power(const f64& base, const f64& exponent) -> f64
        {
            return std::pow(base, exponent);
        }

        TYON_CUDA_SHARED
        PROC exponential(const f32& exponent) -> f32
        {
            return std::expf(exponent);
        }

        TYON_CUDA_SHARED
        PROC exponential(const f64& exponent) -> f64
        {
            return std::exp(exponent);
        }
 


        // Trigonometry
        TYON_CUDA_SHARED
        PROC sinus(const f32& a) -> f32
        {
            return std::sinf(a);
        }

        TYON_CUDA_SHARED
        PROC sinus(const f64& a) -> f64
        {
            return std::sin(a);
        }

        TYON_CUDA_SHARED
        PROC cosinus(const f32& a) -> f32
        {
            return std::cosf(a);
        }

        TYON_CUDA_SHARED
        PROC cosinus(const f64& a) -> f64
        {
            return std::cos(a);
        }

        TYON_CUDA_SHARED
        PROC tangent(const f32& a) -> f32
        {
            return std::tanf(a);
        }

        TYON_CUDA_SHARED
        PROC tangent(const f64& a) -> f64
        {
            return std::tan(a);
        }

        TYON_CUDA_SHARED
        PROC arcsin(const f32& a) -> f32
        {
            return std::asinf(a);
        }

        TYON_CUDA_SHARED
        PROC arcsin(const f64& a) -> f64
        {
            return std::asin(a);
        }

        TYON_CUDA_SHARED
        PROC arccos(const f32& a) -> f32
        {
            return std::acosf(a);
        }

        TYON_CUDA_SHARED
        PROC arccos(const f64& a) -> f64
        {
            return std::acos(a);
        }

        TYON_CUDA_SHARED
        PROC arctan(const f32& a) -> f32
        {
            return atanf(a);
        }

        TYON_CUDA_SHARED
        PROC arctan(const f64& a) -> f64
        {
            return atan(a);
        }

        TYON_CUDA_SHARED
        PROC arctan2(const f32& x, const f32& y) -> f32
        {
            return std::atan2f(x,y);
        }

        TYON_CUDA_SHARED
        PROC arctan2(const f64& x, const f64& y) -> f64
        {
            return std::atan2(x,y);
        }



        // Probability
        TYON_CUDA_SHARED
        PROC error_function(const f32& a) -> f32
        {
            return std::erff(a);
        }

        TYON_CUDA_SHARED
        PROC error_function(const f64& a) -> f64
        {
            return std::erf(a);
        }

        TYON_CUDA_SHARED
        PROC norm_gaussian_cdf(const f32& mean, const f32& x, const f32& standard_deviation) -> f32
        {
            return 0.5f * (1.0f + error_function((x - mean) / (standard_deviation * square_root(2.0f))));
        }

        TYON_CUDA_SHARED
        PROC norm_gaussian_cdf(const f64& mean, const f64& x, const f64& standard_deviation) -> f64
        {
            return 0.5 * (1.0 + error_function((x - mean) / (standard_deviation * square_root(2.0))));
        }



        // Vector
            // Dot Product
            TYON_CUDA_SHARED
            PROC vector_dot_product(const v2_f32& v0, const v2_f32& v1) -> f32
            {
                return v0.x * v1.x + v0.y * v1.y;
            }

            TYON_CUDA_SHARED
            PROC vector_dot_product(const v2_f64& v0, const v2_f64& v1) -> f64
            {
                return v0.x * v1.x + v0.y * v1.y;
            }

            TYON_CUDA_SHARED
            PROC vector_dot_product(const v3_f32& v0, const v3_f32& v1) -> f32
            {
                return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
            }

            TYON_CUDA_SHARED
            PROC vector_dot_product(const v3_f64& v0, const v3_f64& v1) -> f64
            {
                return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
            }

            TYON_CUDA_SHARED
            PROC vector_dot_product(const v4_f32& v0, const v4_f32& v1) -> f32
            {
                return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z + v0.w * v1.w;
            }

            TYON_CUDA_SHARED
            PROC vector_dot_product(const v4_f64& v0, const v4_f64& v1) -> f64
            {
                return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z + v0.w * v1.w;
            }



            // Cross Product
            TYON_CUDA_SHARED
            PROC vector_cross_product(const v3_f32& v0, const v3_f32& v1) -> v3_f32
            {
                return v3_f32( v0.y*v1.z - v0.z*v1.y , v0.z*v1.x - v0.x*v1.z , v0.x*v1.y - v0.y*v1.x );

            }

            TYON_CUDA_SHARED
            PROC vector_cross_product(const v3_f64& v0, const v3_f64& v1) -> v3_f64
            {
                return v3_f64( v0.y*v1.z - v0.z*v1.y , v0.z*v1.x - v0.x*v1.z , v0.x*v1.y - v0.y*v1.x );
            }



            // Angle of two normalized vectors
            TYON_CUDA_SHARED
            PROC angle_radians(const v2_f32& v0, const v2_f32& v1) -> f32
            {
                return arccos(vector_dot_product(v0, v1));
            }

            TYON_CUDA_SHARED
            PROC angle_radians(const v2_f64& v0, const v2_f64& v1) -> f64
            {
                return arccos(vector_dot_product(v0, v1));
            }

            TYON_CUDA_SHARED
            PROC angle_radians(const v3_f32& v0, const v3_f32& v1) -> f32
            {
                return arccos(vector_dot_product(v0, v1));
            }

            TYON_CUDA_SHARED
            PROC angle_radians(const v3_f64& v0, const v3_f64& v1) -> f64
            {
                return arccos(vector_dot_product(v0, v1));
            }

            TYON_CUDA_SHARED
            PROC angle_radians(const v4_f32& v0, const v4_f32& v1) -> f32
            {
                return arccos(vector_dot_product(v0, v1));
            }

            TYON_CUDA_SHARED
            PROC angle_radians(const v4_f64& v0, const v4_f64& v1) -> f64
            {
                return arccos(vector_dot_product(v0, v1));
            }



            // Normalize
            TYON_CUDA_SHARED
            PROC vector_normalize(const v2_f32& v0) -> v2_f32
            {
                return v0 / vector_length(v0);
            }

            TYON_CUDA_SHARED
            PROC vector_normalize(const v2_f64& v0) -> v2_f64
            {
                return v0 / vector_length(v0);
            }

            TYON_CUDA_SHARED
            PROC vector_normalize(const v3_f32& v0) -> v3_f32
            {
                return v0 / vector_length(v0);
            }

            TYON_CUDA_SHARED
            PROC vector_normalize(const v3_f64& v0) -> v3_f64
            {
                return v0 / vector_length(v0);
            }

            TYON_CUDA_SHARED
            PROC vector_normalize(const v4_f32& v0) -> v4_f32
            {
                return v0 / vector_length(v0);
            }

            TYON_CUDA_SHARED
            PROC vector_normalize(const v4_f64& v0) -> v4_f64
            {
                return v0 / vector_length(v0);
            }



            // Reflect
            TYON_CUDA_SHARED
            PROC vector_reflect(const v2_f32& d, const v2_f32& n) -> v2_f32
            {
                return (d - (2.0f * n * vector_dot_product(d, n)));
            }

            TYON_CUDA_SHARED
            PROC vector_reflect(const v2_f64& d, const v2_f64& n) -> v2_f64
            {
                return (d - (2.0 * n * vector_dot_product(d, n)));
            }

            TYON_CUDA_SHARED
            PROC vector_reflect(const v3_f32& d, const v3_f32& n) -> v3_f32
            {
                return (d - (2.0f * n * vector_dot_product(d, n)));
            }

            TYON_CUDA_SHARED
            PROC vector_reflect(const v3_f64& d, const v3_f64& n) -> v3_f64
            {
                return (d - (2.0 * n * vector_dot_product(d, n)));
            }

            TYON_CUDA_SHARED
            PROC vector_reflect(const v4_f32& d, const v4_f32& n) -> v4_f32
            {
                return (d - (2.0f * n * vector_dot_product(d, n)));
            }

            TYON_CUDA_SHARED
            PROC vector_reflect(const v4_f64& d, const v4_f64& n) -> v4_f64
            {
                return (d - (2.0 * n * vector_dot_product(d, n)));
            }



            // Refract
            TYON_CUDA_SHARED
            PROC vector_refract(const v2_f32& d, const v2_f32& n, const f32& eta_0, const f32& eta_1) -> v2_f32
            {
                f32 cos_theta_i = vector_dot_product(d, n);
                f32 eta_relative = eta_0 / eta_1;
                f32 sin2_theta_t = eta_relative * eta_relative * (1.0f - cos_theta_i * cos_theta_i);
                return (eta_relative * cos_theta_i - square_root(1.0f - sin2_theta_t)) * n - eta_relative * d;
            }

            TYON_CUDA_SHARED
            PROC vector_refract(const v2_f64& d, const v2_f64& n, const f64& eta_0, const f64& eta_1) -> v2_f64
            {
                f32 cos_theta_i = vector_dot_product(d, n);
                f32 eta_relative = eta_0 / eta_1;
                f32 sin2_theta_t = eta_relative * eta_relative * (1.0 - cos_theta_i * cos_theta_i);
                return (eta_relative * cos_theta_i - square_root(1.0 - sin2_theta_t)) * n - eta_relative * d;
            }

            TYON_CUDA_SHARED
            PROC vector_refract(const v3_f32& d, const v3_f32& n, const f32& eta_0, const f32& eta_1) -> v3_f32
            {
                f32 cos_theta_i = vector_dot_product(d, n);
                f32 eta_relative = eta_0 / eta_1;
                f32 sin2_theta_t = eta_relative * eta_relative * (1.0f - cos_theta_i * cos_theta_i);
                return (eta_relative * cos_theta_i - square_root(1.0f - sin2_theta_t)) * n - eta_relative * d;
            }

            TYON_CUDA_SHARED
            PROC vector_refract(const v3_f64& d, const v3_f64& n, const f64& eta_0, const f64& eta_1) -> v3_f64
            {
                f32 cos_theta_i = vector_dot_product(d, n);
                f32 eta_relative = eta_0 / eta_1;
                f32 sin2_theta_t = eta_relative * eta_relative * (1.0 - cos_theta_i * cos_theta_i);
                return (eta_relative * cos_theta_i - square_root(1.0 - sin2_theta_t)) * n - eta_relative * d;
            }

            TYON_CUDA_SHARED
            PROC vector_refract(const v4_f32& d, const v4_f32& n, const f32& eta_0, const f32& eta_1) -> v4_f32
            {
                f32 cos_theta_i = vector_dot_product(d, n);
                f32 eta_relative = eta_0 / eta_1;
                f32 sin2_theta_t = eta_relative * eta_relative * (1.0f - cos_theta_i * cos_theta_i);
                return (eta_relative * cos_theta_i - square_root(1.0f - sin2_theta_t)) * n - eta_relative * d;
            }

            TYON_CUDA_SHARED
            PROC vector_refract(const v4_f64& d, const v4_f64& n, const f64& eta_0, const f64& eta_1) -> v4_f64
            {
                f32 cos_theta_i = vector_dot_product(d, n);
                f32 eta_relative = eta_0 / eta_1;
                f32 sin2_theta_t = eta_relative * eta_relative * (1.0 - cos_theta_i * cos_theta_i);
                return (eta_relative * cos_theta_i - square_root(1.0 - sin2_theta_t)) * n - eta_relative * d;
            }



            // Project
            TYON_CUDA_SHARED
            PROC vector_project(const v2_f32& v0, const v2_f32& v1) -> v2_f32
            {
                return (vector_dot_product(v0, v1) * v1) / vector_dot_product(v1, v1);
            }

            TYON_CUDA_SHARED
            PROC vector_project(const v2_f64& v0, const v2_f64& v1) -> v2_f64
            {
                return (vector_dot_product(v0, v1) * v1) / vector_dot_product(v1, v1);
            }

            TYON_CUDA_SHARED
            PROC vector_project(const v3_f32& v0, const v3_f32& v1) -> v3_f32
            {
                return (vector_dot_product(v0, v1) * v1) / vector_dot_product(v1, v1);
            }

            TYON_CUDA_SHARED
            PROC vector_project(const v3_f64& v0, const v3_f64& v1) -> v3_f64
            {
                return (vector_dot_product(v0, v1) * v1) / vector_dot_product(v1, v1);
            }

            TYON_CUDA_SHARED
            PROC vector_project(const v4_f32& v0, const v4_f32& v1) -> v4_f32
            {
                return (vector_dot_product(v0, v1) * v1) / vector_dot_product(v1, v1);
            }

            TYON_CUDA_SHARED
            PROC vector_project(const v4_f64& v0, const v4_f64& v1) -> v4_f64
            {
                return (vector_dot_product(v0, v1) * v1) / vector_dot_product(v1, v1);
            }



            // Barycentric
            TYON_CUDA_SHARED
            PROC v_barycentric(const v2_f32& p0, const v2_f32& p1, const v2_f32& p2, const v2_f32& barycentric_coordinates) -> v2_f32
            {
                return p0 * barycentric_coordinates.x + p1 * barycentric_coordinates.y + p2 * (1.0f - barycentric_coordinates.x - barycentric_coordinates.y);
            }

            TYON_CUDA_SHARED
            PROC v_barycentric(const v2_f64& p0, const v2_f64& p1, const v2_f64& p2, const v2_f64& barycentric_coordinates) -> v2_f64
            {
                return p0 * barycentric_coordinates.x + p1 * barycentric_coordinates.y + p2 * (1.0 - barycentric_coordinates.x - barycentric_coordinates.y);
            }

            TYON_CUDA_SHARED
            PROC v_barycentric(const v3_f32& p0, const v3_f32& p1, const v3_f32& p2, const v2_f32& barycentric_coordinates) -> v3_f32
            {
                return p0 * barycentric_coordinates.x + p1 * barycentric_coordinates.y + p2 * (1.0f - barycentric_coordinates.x - barycentric_coordinates.y);
            }

            TYON_CUDA_SHARED
            PROC v_barycentric(const v3_f64& p0, const v3_f64& p1, const v3_f64& p2, const v2_f64& barycentric_coordinates) -> v3_f64
            {
                return p0 * barycentric_coordinates.x + p1 * barycentric_coordinates.y + p2 * (1.0 - barycentric_coordinates.x - barycentric_coordinates.y);
            }

            TYON_CUDA_SHARED
            PROC v_barycentric(const v4_f32& p0, const v4_f32& p1, const v4_f32& p2, const v2_f32& barycentric_coordinates) -> v4_f32
            {
                return p0 * barycentric_coordinates.x + p1 * barycentric_coordinates.y + p2 * (1.0f - barycentric_coordinates.x - barycentric_coordinates.y);
            }

            TYON_CUDA_SHARED
            PROC v_barycentric(const v4_f64& p0, const v4_f64& p1, const v4_f64& p2, const v2_f64& barycentric_coordinates) -> v4_f64
            {
                return p0 * barycentric_coordinates.x + p1 * barycentric_coordinates.y + p2 * (1.0 - barycentric_coordinates.x - barycentric_coordinates.y);
            }



            // Length & Lenght2
            TYON_CUDA_SHARED
            PROC vector_length(const v2_f32& v0) -> f32
            {
                return square_root( v0.x * v0.x + v0.y * v0.y );
            }

            TYON_CUDA_SHARED
            PROC vector_length(const v2_f64& v0) -> f64
            {
                return square_root( v0.x * v0.x + v0.y * v0.y );
            }

            TYON_CUDA_SHARED
            PROC vector_length(const v3_f32& v0) -> f32
            {
                return square_root( v0.x * v0.x + v0.y * v0.y + v0.z * v0.z );
            }

            TYON_CUDA_SHARED
            PROC vector_length(const v3_f64& v0) -> f64
            {
                return square_root( v0.x * v0.x + v0.y * v0.y + v0.z * v0.z );
            }

            TYON_CUDA_SHARED
            PROC vector_length(const v4_f32& v0) -> f32
            {
                return square_root( v0.x * v0.x + v0.y * v0.y + v0.z * v0.z + v0.w * v0.w );
            }

            TYON_CUDA_SHARED
            PROC vector_length(const v4_f64& v0) -> f64
            {
                return square_root( v0.x * v0.x + v0.y * v0.y + v0.z * v0.z + v0.w * v0.w );
            }

            TYON_CUDA_SHARED
            PROC vector_length2(const v2_f32& v0) -> f32
            {
                return ( v0.x * v0.x + v0.y * v0.y );
            }

            TYON_CUDA_SHARED
            PROC vector_length2(const v2_f64& v0) -> f64
            {
                return ( v0.x * v0.x + v0.y * v0.y );
            }

            TYON_CUDA_SHARED
            PROC vector_length2(const v3_f32& v0) -> f32
            {
                return ( v0.x * v0.x + v0.y * v0.y + v0.z * v0.z);
            }

            TYON_CUDA_SHARED
            PROC vector_length2(const v3_f64& v0) -> f64
            {
                return ( v0.x * v0.x + v0.y * v0.y + v0.z * v0.z);
            }

            TYON_CUDA_SHARED
            PROC vector_length2(const v4_f32& v0) -> f32
            {
                return ( v0.x * v0.x + v0.y * v0.y + v0.z * v0.z + v0.w * v0.w);
            }

            TYON_CUDA_SHARED
            PROC vector_length2(const v4_f64& v0) -> f64
            {
                return ( v0.x * v0.x + v0.y * v0.y + v0.z * v0.z + v0.w * v0.w);
            }



            // Distance & Distance2
            TYON_CUDA_SHARED
            PROC vector_distance(const v2_f32& v0, const v2_f32& v1) -> f32
            {
                return vector_length(v0 - v1);
            }

            TYON_CUDA_SHARED
            PROC vector_distance(const v2_f64& v0, const v2_f64& v1) -> f64
            {
                return vector_length(v0 - v1);
            }

            TYON_CUDA_SHARED
            PROC vector_distance(const v3_f32& v0, const v3_f32& v1) -> f32
            {
                return vector_length(v0 - v1);
            }

            TYON_CUDA_SHARED
            PROC vector_distance(const v3_f64& v0, const v3_f64& v1) -> f64
            {
                return vector_length(v0 - v1);
            }

            TYON_CUDA_SHARED
            PROC vector_distance(const v4_f32& v0, const v4_f32& v1) -> f32
            {
                return vector_length(v0 - v1);
            }

            TYON_CUDA_SHARED
            PROC vector_distance(const v4_f64& v0, const v4_f64& v1) -> f64
            {
                return vector_length(v0 - v1);
            }

            TYON_CUDA_SHARED
            PROC vector_distance2(const v2_f32& v0, const v2_f32& v1) -> f32
            {
                return vector_length(v0 - v1);
            }

            TYON_CUDA_SHARED
            PROC vector_distance2(const v2_f64& v0, const v2_f64& v1) -> f64
            {
                return vector_length(v0 - v1);
            }

            TYON_CUDA_SHARED
            PROC vector_distance2(const v3_f32& v0, const v3_f32& v1) -> f32
            {
                return vector_length(v0 - v1);
            }

            TYON_CUDA_SHARED
            PROC vector_distance2(const v3_f64& v0, const v3_f64& v1) -> f64
            {
                return vector_length(v0 - v1);
            }

            TYON_CUDA_SHARED
            PROC vector_distance2(const v4_f32& v0, const v4_f32& v1) -> f32
            {
                return vector_length(v0 - v1);
            }

            TYON_CUDA_SHARED
            PROC vector_distance2(const v4_f64& v0, const v4_f64& v1) -> f32
            {
                return vector_length(v0 - v1);
            }



            // Orthonormal basis
            TYON_CUDA_SHARED
            PROC construct_orthonormal_basis(const v3_f32& basis_vector_z, const v3_f32& omega, v3_f32& basis_vector_x, v3_f32& basis_vector_y) -> void
            {
                basis_vector_x = omega - vector_dot_product(omega, basis_vector_z)*basis_vector_z;
                basis_vector_y = vector_cross_product(basis_vector_z, basis_vector_x);

                basis_vector_x = basis_vector_x/vector_length(basis_vector_x);
                basis_vector_y = basis_vector_y/vector_length(basis_vector_y);
            }

            TYON_CUDA_SHARED
            PROC construct_orthonormal_basis(const v3_f64& basis_vector_z, const v3_f64& omega, v3_f64& basis_vector_x, v3_f64& basis_vector_y) -> void
            {
                basis_vector_x = omega - vector_dot_product(omega, basis_vector_z)*basis_vector_z;
                basis_vector_y = vector_cross_product(basis_vector_z, basis_vector_x);

                basis_vector_x = basis_vector_x/vector_length(basis_vector_x);
                basis_vector_y = basis_vector_y/vector_length(basis_vector_y);
            }



            // z-aligned normal
            TYON_CUDA_SHARED
            PROC transform_to_z_aligned_normal(const v3_f32& omega_i, const v3_f32& normal, v3_f32& basis_vector_x, v3_f32& basis_vector_y, v3_f32& basis_vector_z) -> v3_f32
            {
                v3_f32 rotated_omega_i;

                rotated_omega_i.x = vector_dot_product(omega_i, basis_vector_x);
                rotated_omega_i.y = vector_dot_product(omega_i, basis_vector_y);
                rotated_omega_i.z = vector_dot_product(omega_i, basis_vector_z);

                return rotated_omega_i;
            }

            TYON_CUDA_SHARED
            PROC transform_to_z_aligned_normal(const v3_f64& omega_i, const v3_f64& normal, v3_f64& basis_vector_x, v3_f64& basis_vector_y, v3_f64& basis_vector_z) -> v3_f64
            {
                v3_f64 rotated_omega_i;

                rotated_omega_i.x = vector_dot_product(omega_i, basis_vector_x);
                rotated_omega_i.y = vector_dot_product(omega_i, basis_vector_y);
                rotated_omega_i.z = vector_dot_product(omega_i, basis_vector_z);

                return rotated_omega_i;
            }



            // z to world space
            TYON_CUDA_SHARED
            PROC local_direction_to_world_space(const v3_f32& reference_dir, const f32& cos_theta, const f32& phi) -> v3_f32
            {
                f32 sin_theta = square_root(1.0f - cos_theta*cos_theta);

                v3_f32 local_dir(
                    sin_theta*cosinus(phi),
                    sin_theta*sinus(phi),
                    cos_theta
                );

                v3_f32 x_axis;
                if (absolute(reference_dir.z) < 0.9f)
                {
                    x_axis.x = 0.0f;
                    x_axis.y = 0.0f;
                    x_axis.z = 1.0f;
                }
                else
                {
                    x_axis.x = 1.0f;
                    x_axis.y = 0.0f;
                    x_axis.z = 0.0f;
                }

                // Gram-Schmidt orthogonalization
                x_axis = x_axis - reference_dir*vector_dot_product(x_axis, reference_dir);
                x_axis = x_axis/vector_length(x_axis);

                v3_f32 y_axis = vector_cross_product(reference_dir, x_axis);

                return local_dir.x*x_axis + local_dir.y*y_axis + local_dir.z*reference_dir;
            }

            TYON_CUDA_SHARED
            PROC local_direction_to_world_space(const v3_f64& reference_dir, const f64& cos_theta, const f64& phi) -> v3_f64
            {
                f64 sin_theta = square_root(1.0 - cos_theta*cos_theta);

                v3_f64 local_dir(
                    sin_theta*cosinus(phi),
                    sin_theta*sinus(phi),
                    cos_theta
                );

                v3_f64 x_axis;
                if (absolute(reference_dir.z) < 0.9)
                {
                    x_axis.x = 0.0;
                    x_axis.y = 0.0;
                    x_axis.z = 1.0;
                }
                else
                {
                    x_axis.x = 1.0;
                    x_axis.y = 0.0;
                    x_axis.z = 0.0;
                }

                // Gram-Schmidt orthogonalization
                x_axis = x_axis - reference_dir*vector_dot_product(x_axis, reference_dir);
                x_axis = x_axis/vector_length(x_axis);

                v3_f64 y_axis = vector_cross_product(reference_dir, x_axis);

                return local_dir.x*x_axis + local_dir.y*y_axis + local_dir.z*reference_dir;
            }



        // Matrix
            // Rotation
            TYON_CUDA_SHARED
            PROC general_2d_rotation_matrix(const f32& theta) -> matrix2_f32
            {
                matrix2_f32 result;
                result.m11 = cosinus(theta);
                result.m12 = -sinus(theta);
                result.m21 = sinus(theta);
                result.m22 = cosinus(theta);
                return result;
            }

            TYON_CUDA_SHARED
            PROC general_2d_rotation_matrix(const f64& theta) -> matrix2_f64
            {
                matrix2_f64 result;
                result.m11 = cosinus(theta);
                result.m12 = -sinus(theta);
                result.m21 = sinus(theta);
                result.m22 = cosinus(theta);
                return result;
            }

            TYON_CUDA_SHARED
            PROC general_3d_rotation_matrix(const f32& r_x, const f32& r_y, const f32& r_z) -> matrix3_f32
            {
                matrix3_f32 m_x, m_y, m_z;

                // X Rotation
                m_x.m11 = 1.0f;
                m_x.m12 = 0.0f;
                m_x.m13 = 0.0f;

                m_x.m21 = 0.0f;
                m_x.m22 = cosinus(r_x);
                m_x.m23 = -sinus(r_x);

                m_x.m31 = 0.0f;
                m_x.m32 = sinus(r_x);
                m_x.m33 = cosinus(r_x);
            
                // Y Rotation
                m_y.m11 = cosinus(r_y);
                m_y.m12 = 0.0f;
                m_y.m13 = sinus(r_y);

                m_y.m21 = 0.0f;
                m_y.m22 = 1.0f;
                m_y.m23 = 0.0f;

                m_y.m31 = -sinus(r_y);
                m_y.m32 = 0.0f;
                m_y.m33 = cosinus(r_y);

                // Z Rotation
                m_z.m11 = cosinus(r_z);
                m_z.m12= -sinus(r_z);
                m_z.m13 = 0.0f;

                m_z.m21 = sinus(r_z);
                m_z.m22 = cosinus(r_z);
                m_z.m23 = 0.0f;

                m_z.m31 = 0.0f;
                m_z.m32 = 0.0f;
                m_z.m33 = 1.0f;

                return m_x * m_y * m_z;
            }

            TYON_CUDA_SHARED
            PROC general_3d_rotation_matrix(const f64& r_x, const f64& r_y, const f64& r_z) -> matrix3_f64
            {
            {
                matrix3_f64 m_x, m_y, m_z;

                // X Rotation
                m_x.m11 = 1.0;
                m_x.m12 = 0.0;
                m_x.m13 = 0.0;

                m_x.m21 = 0.0;
                m_x.m22 = cosinus(r_x);
                m_x.m23 = -sinus(r_x);

                m_x.m31 = 0.0;
                m_x.m32 = sinus(r_x);
                m_x.m33 = cosinus(r_x);
            
                // Y Rotation
                m_y.m11 = cosinus(r_y);
                m_y.m12 = 0.0;
                m_y.m13 = sinus(r_y);

                m_y.m21 = 0.0;
                m_y.m22 = 1.0;
                m_y.m23 = 0.0;

                m_y.m31 = -sinus(r_y);
                m_y.m32 = 0.0;
                m_y.m33 = cosinus(r_y);

                // Z Rotation
                m_z.m11 = cosinus(r_z);
                m_z.m12= -sinus(r_z);
                m_z.m13 = 0.0;

                m_z.m21 = sinus(r_z);
                m_z.m22 = cosinus(r_z);
                m_z.m23 = 0.0;

                m_z.m31 = 0.0;
                m_z.m32 = 0.0;
                m_z.m33 = 1.0;

                return m_x * m_y * m_z;
            }
            }

            TYON_CUDA_SHARED
            PROC euler_rotation_matrix(const f32& theta, const v3_f32& u) -> matrix3_f32
            {
                matrix3_f32 R;

                R.m11 = cosinus(theta) + u.x * u.x * (1.0f - cosinus(theta));
                R.m12 = u.x * u.y * ( 1.0f - cosinus(theta)) - u.z * sinus(theta);
                R.m13 = u.x * u.z * ( 1.0f - cosinus(theta)) + u.y * sinus(theta);

                R.m21 = u.y * u.x * (1.0f - cosinus(theta)) + u.z * sinus(theta);
                R.m22 = cosinus(theta) + u.y * u.y * (1.0f - cosinus(theta));
                R.m23 = u.y * u.z * (1.0f - cosinus(theta)) - u.x * sinus(theta);

                R.m31 = u.z * u.x * (1.0f - cosinus(theta)) - u.y * sinus(theta);
                R.m32 = u.z * u.y * (1.0f - cosinus(theta)) + u.x * sinus(theta);
                R.m33 = cosinus(theta) + u.z * u.z * (1.0f - cosinus(theta));

                return R;
            }

            TYON_CUDA_SHARED
            PROC euler_rotation_matrix(const f64& theta, const v3_f64& u) -> matrix3_f64
            {
                matrix3_f64 R;

                R.m11 = cosinus(theta) + u.x * u.x * (1.0 - cosinus(theta));
                R.m12 = u.x * u.y * ( 1.0 - cosinus(theta)) - u.z * sinus(theta);
                R.m13 = u.x * u.z * ( 1.0 - cosinus(theta)) + u.y * sinus(theta);

                R.m21 = u.y * u.x * (1.0 - cosinus(theta)) + u.z * sinus(theta);
                R.m22 = cosinus(theta) + u.y * u.y * (1.0f - cosinus(theta));
                R.m23 = u.y * u.z * (1.0 - cosinus(theta)) - u.x * sinus(theta);

                R.m31 = u.z * u.x * (1.0 - cosinus(theta)) - u.y * sinus(theta);
                R.m32 = u.z * u.y * (1.0 - cosinus(theta)) + u.x * sinus(theta);
                R.m33 = cosinus(theta) + u.z * u.z * (1.0 - cosinus(theta));

                return R;
            }



            // Transpose
            TYON_CUDA_SHARED
            PROC transpose_matrix(const matrix2_f32& m) -> matrix2_f32
            {
                matrix2_f32 transpose;
                transpose.m11 = m.m11;
                transpose.m12 = m.m21;
                transpose.m21 = m.m12;
                transpose.m22 = m.m22;

                return transpose;
            }

            TYON_CUDA_SHARED
            PROC transpose_matrix(const matrix2_f64& m) -> matrix2_f64
            {
                matrix2_f64 transpose;
                transpose.m11 = m.m11;
                transpose.m12 = m.m21;
                transpose.m21 = m.m12;
                transpose.m22 = m.m22;

                return transpose;
            }

            TYON_CUDA_SHARED
            PROC transpose_matrix(const matrix3_f32& m) -> matrix3_f32
            {
                matrix3_f32 transpose;
                transpose.m11 = m.m11;
                transpose.m12 = m.m21;
                transpose.m13 = m.m31;
                transpose.m21 = m.m12;
                transpose.m22 = m.m22;
                transpose.m23 = m.m32;
                transpose.m31 = m.m13;
                transpose.m32 = m.m23;
                transpose.m33 = m.m33;

                return transpose;
            }

            TYON_CUDA_SHARED
            PROC transpose_matrix(const matrix3_f64& m) -> matrix3_f64
            {
                matrix3_f64 transpose;
                transpose.m11 = m.m11;
                transpose.m12 = m.m21;
                transpose.m13 = m.m31;
                transpose.m21 = m.m12;
                transpose.m22 = m.m22;
                transpose.m23 = m.m32;
                transpose.m31 = m.m13;
                transpose.m32 = m.m23;
                transpose.m33 = m.m33;

                return transpose;
            }

            TYON_CUDA_SHARED
            PROC transpose_matrix(const matrix4_f32& m) -> matrix4_f32
            {
                matrix4_f32 transpose;
                transpose.m11 = m.m11;
                transpose.m12 = m.m21;
                transpose.m13 = m.m31;
                transpose.m14 = m.m41;
                transpose.m21 = m.m12;
                transpose.m22 = m.m22;
                transpose.m23 = m.m32;
                transpose.m24 = m.m42;
                transpose.m31 = m.m13;
                transpose.m32 = m.m23;
                transpose.m33 = m.m33;
                transpose.m34 = m.m43;
                transpose.m41 = m.m14;
                transpose.m42 = m.m24;
                transpose.m43 = m.m34;
                transpose.m44 = m.m44;

                return transpose;
            }

            TYON_CUDA_SHARED
            PROC transpose_matrix(const matrix4_f64& m) -> matrix4_f64
            {
                matrix4_f64 transpose;
                transpose.m11 = m.m11;
                transpose.m12 = m.m21;
                transpose.m13 = m.m31;
                transpose.m14 = m.m41;
                transpose.m21 = m.m12;
                transpose.m22 = m.m22;
                transpose.m23 = m.m32;
                transpose.m24 = m.m42;
                transpose.m31 = m.m13;
                transpose.m32 = m.m23;
                transpose.m33 = m.m33;
                transpose.m34 = m.m43;
                transpose.m41 = m.m14;
                transpose.m42 = m.m24;
                transpose.m43 = m.m34;
                transpose.m44 = m.m44;

                return transpose;
            }



        // Conversion
            // To radians
            TYON_CUDA_SHARED
            PROC to_radians(const f32& degrees) -> f32
            {
                return (degrees * M_PI) / 180.0f;
            }

            TYON_CUDA_SHARED
            PROC to_radians(const f64& degrees) -> f64
            {
                return (degrees * M_PI) / 180.0;
            }



            // To degrees
            TYON_CUDA_SHARED
            PROC to_degrees(const f32& radians) -> f32
            {
                return radians * (180.0f / M_PI);
            }

            TYON_CUDA_SHARED
            PROC to_degrees(const f64& radians) -> f64
            {
                return radians * (180.0 / M_PI);
            }



            // Spherical coordinates
            TYON_CUDA_SHARED
            PROC cartesian_to_spherical(const v3_f32& cartesian) -> v3_f32
            {
                f32 r = vector_length(cartesian);
                f32 theta = arccos(cartesian.y / r);
                f32 phi = arctan2(cartesian.z, cartesian.x);

                return v3_f32(r, theta, phi);
            }

            TYON_CUDA_SHARED
            PROC cartesian_to_spherical(const v3_f64& cartesian) -> v3_f64
            {
                f64 r = vector_length(cartesian);
                f64 theta = arccos(cartesian.y / r);
                f64 phi = arctan2(cartesian.z, cartesian.x);

                return v3_f64(r, theta, phi);
            }

            TYON_CUDA_SHARED
            PROC spherical_to_cartesian(const v3_f32& spherical) -> v3_f32
            {
                f32 x = spherical.x * sinus(spherical.y) * cosinus(spherical.z);
                f32 y = spherical.x * cosinus(spherical.y);
                f32 z = spherical.x * sinus(spherical.y) * sinus(spherical.z);

                return v3_f32(x, y, z);
            }

            TYON_CUDA_SHARED
            PROC spherical_to_cartesian(const v3_f64& spherical) -> v3_f64
            {
                f32 x = spherical.x * sinus(spherical.y) * cosinus(spherical.z);
                f32 y = spherical.x * cosinus(spherical.y);
                f32 z = spherical.x * sinus(spherical.y) * sinus(spherical.z);

                return v3_f64(x, y, z);
            }



        // Utility
            // Lerp
            TYON_CUDA_SHARED
            PROC lerp(const f32& a, const f32& b, const f32& t) -> f32
            {
                return a + t * (b - a);
            }

            TYON_CUDA_SHARED
            PROC lerp(const f64& a, const f64& b, const f64& t) -> f64
            {
                return a + t * (b - a);
            }

            TYON_CUDA_SHARED
            PROC lerp(const v2_f32& va, const v2_f32& vb, const f32& t) -> v2_f32
            {
                return v2_f32( lerp(va.x, vb.x, t), lerp(va.y, vb.y, t) );
            }

            TYON_CUDA_SHARED
            PROC lerp(const v2_f64& va, const v2_f64& vb, const f64& t) -> v2_f64
            {
                return v2_f64( lerp(va.x, vb.x, t), lerp(va.y, vb.y, t) );
            }

            TYON_CUDA_SHARED
            PROC lerp(const v3_f32& va, const v3_f32& vb, const f32& t) -> v3_f32
            {
                return v3_f32( lerp(va.x, vb.x, t), lerp(va.y, vb.y, t), lerp(va.z, vb.z, t) );
            }

            TYON_CUDA_SHARED
            PROC lerp(const v3_f64& va, const v3_f64& vb, const f64& t) -> v3_f64
            {
                return v3_f64( lerp(va.x, vb.x, t), lerp(va.y, vb.y, t), lerp(va.z, vb.z, t) );
            }

            TYON_CUDA_SHARED
            PROC lerp(const v4_f32& va, const v4_f32& vb, const f32& t) -> v4_f32
            {
                return v4_f32( lerp(va.x, vb.x, t), lerp(va.y, vb.y, t), lerp(va.z, vb.z, t), lerp(va.w, vb.w, t) );
            }

            TYON_CUDA_SHARED
            PROC lerp(const v4_f64& va, const v4_f64& vb, const f64& t) -> v4_f64
            {
                return v4_f64( lerp(va.x, vb.x, t), lerp(va.y, vb.y, t), lerp(va.z, vb.z, t), lerp(va.w, vb.w, t) );
            }



            // Smooth step
            TYON_CUDA_SHARED
            PROC smooth_step(const f32& edge0, const f32& edge1, const f32& t) -> f32
            {
                f32 x = clamp_range(0.0f, 1.0f, ((t - edge0) / (edge1 * edge0)));
                return x * x * (3.0f - 2.0f * x);
            }

            TYON_CUDA_SHARED
            PROC smooth_step(const f64& edge0, const f64& edge1, const f64& t) -> f64
            {
                f64 x = clamp_range(0.0, 1.0, ((t - edge0) / (edge1 * edge0)));
                return x * x * (3.0 - 2.0 * x);
            }



            // Absolute
            TYON_CUDA_SHARED
            PROC absolute(const f32& a) -> f32
            {
                return std::fabs(a);
            }

            TYON_CUDA_SHARED
            PROC absolute(const f64& a) -> f64
            {
                return std::abs(a);
            }



            // Clamp
            TYON_CUDA_SHARED
            PROC clamp_range(const f32& edge0, const f32& edge1, const f32& a) -> f32
            {
                if(a < edge0) return edge0;
                if(a > edge1) return edge1;
                return a;
            }

            TYON_CUDA_SHARED
            PROC clamp_range(const f64& edge0, const f64& edge1, const f64& a) -> f64
            {
                if(a < edge0) return edge0;
                if(a > edge1) return edge1;
                return a;
            }



            // Min
            TYON_CUDA_SHARED
            PROC minimum(const f32& a, const f32& b) -> f32
            {
                if(a < b)
                {
                    return a;
                }
                
                return b;
            }

            TYON_CUDA_SHARED
            PROC minimum(const f64& a, const f64& b) -> f64
            {
                if(a < b)
                {
                    return a;
                }
                
                return b;
            }



            // Max
            TYON_CUDA_SHARED
            PROC maximum(const f32& a, const f32& b) -> f32
            {
                if(a > b)
                {
                    return a;
                }
                
                return b;
            }

            TYON_CUDA_SHARED
            PROC maximum(const f64& a, const f64& b) -> f64
            {
                if(a > b)
                {
                    return a;
                }
                
                return b;
            }



            // Round down
            TYON_CUDA_SHARED
            PROC round_down(const f32& a) -> f32
            {
                return std::floorf(a);
            }

            TYON_CUDA_SHARED
            PROC round_down(const f64& a) -> f64
            {
                return std::floor(a);
            }



            // Round up
            TYON_CUDA_SHARED
            PROC round_up(const f32& a) -> f32
            {
                return std::ceilf(a);
            }

            TYON_CUDA_SHARED
            PROC round_up(const f64& a) -> f64
            {
                return std::ceil(a);
            }



            // Round normal
            TYON_CUDA_SHARED
            PROC round_normal(const f32& a) -> f32
            {
                return std::roundf(a);
            }

            TYON_CUDA_SHARED
            PROC round_normal(const f64& a) -> f64
            {
                return std::round(a);
            }



            // Fraction
            TYON_CUDA_SHARED
            PROC fraction(const f32& a) -> f32
            {
                f32 _fraction;
                return std::modff(a, &_fraction);
            }

            TYON_CUDA_SHARED
            PROC fraction(const f64& a) -> f64
            {
                f64 _fraction;
                return std::modf(a, &_fraction);
            }



            // Remap
            TYON_CUDA_SHARED
            PROC remap(const f32& start0, const f32& end0, const f32& start1, const f32& end1, const f32& value) -> f32
            {
                return start1 + ((end1 - start1) / (end0 - start0)) * (value - start0);
            }

            TYON_CUDA_SHARED
            PROC remap(const f64& start0, const f64& end0, const f64& start1, const f64& end1, const f64& value) -> f64
            {
                return start1 + ((end1 - start1) / (end0 - start0)) * (value - start0);
            }



            // Swap
            TYON_CUDA_SHARED
            PROC swap_pair(f32& a, f32& b) -> void
            {
                f32 temp = b;
                b = a;
                a = temp;
            }

            TYON_CUDA_SHARED
            PROC swap_pair(f64& a, f64& b) -> void
            {
                f64 temp = b;
                b = a;
                a = temp;
            }

            TYON_CUDA_SHARED
            PROC swap_pair(c32& a, c32& b) -> void
            {
                c32 temp = b;
                b = a;
                a = temp;
            }

            TYON_CUDA_SHARED
            PROC swap_pair(c64& a, c64& b) -> void
            {
                c64 temp = b;
                b = a;
                a = temp;
            }

            TYON_CUDA_SHARED
            PROC swap_pair(v2_f32& a, v2_f32& b) -> void
            {
                v2_f32 temp = b;
                b = a;
                a = temp;
            }

            TYON_CUDA_SHARED
            PROC swap_pair(v2_f64& a, v2_f64& b) -> void
            {
                v2_f64 temp = b;
                b = a;
                a = temp;
            }

            TYON_CUDA_SHARED
            PROC swap_pair(v3_f32& a, v3_f32& b) -> void
            {
                v3_f32 temp = b;
                b = a;
                a = temp;
            }

            TYON_CUDA_SHARED
            PROC swap_pair(v3_f64& a, v3_f64& b) -> void
            {
                v3_f64 temp = b;
                b = a;
                a = temp;
            }

            TYON_CUDA_SHARED
            PROC swap_pair(v4_f32& a, v4_f32& b) -> void
            {
                v4_f32 temp = b;
                b = a;
                a = temp;
            }

            TYON_CUDA_SHARED
            PROC swap_pair(v4_f64& a, v4_f64& b) -> void
            {
                v4_f64 temp = b;
                b = a;
                a = temp;
            }
}
