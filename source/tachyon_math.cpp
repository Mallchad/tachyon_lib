
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
}
