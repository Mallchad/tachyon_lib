
namespace tyon
{
    /** Complex Numbers **/
        // Types
        CONSTRUCTOR c32::c32() : real(0.0f), imag(0.0f) {}
        CONSTRUCTOR c32::c32( f32 arg ) : real(arg), imag(0.0f) {}
        CONSTRUCTOR c32::c32( f32 real, f32 imag) : real(real), imag(imag) {}
        CONSTRUCTOR c32::c32( f64 arg) {}

        CONSTRUCTOR c64::c64() : real(0.0), imag(0.0) {}
        CONSTRUCTOR c64::c64( f64 arg ) : real(arg), imag(0.0) {}
        CONSTRUCTOR c64::c64( f64 real, f64 imag) : real(real), imag(imag) {}
        CONSTRUCTOR c64::c64( f32 arg) {}

        // Operators
        // Addition
        PROC operator+(const c32& z0, const c32& z1) -> c32
        {
            c32 result;
            result.real = z0.real + z1.real;
            result.imag = z0.imag + z1.imag;
            return result;
        }

        PROC operator+(const c64& z0, const c64& z1) -> c64
        {
            c64 result;
            result.real = z0.real + z1.real;
            result.imag = z0.imag + z1.imag;
            return result;
        }

        // Subtraction
        PROC operator-(const c32& z0, const c32& z1) -> c32
        {
            c32 result;
            result.real = z0.real - z1.real;
            result.imag = z0.imag - z1.imag;
            return result;
        }

        PROC operator-(const c64& z0, const c64& z1) -> c64
        {
            c64 result;
            result.real = z0.real - z1.real;
            result.imag = z0.imag - z1.imag;
            return result;
        }

        // Multiplication
        PROC operator*(const c32& z0, const c32& z1) -> c32
        {
            c32 result;
            result.real = (z0.real * z1.real) - (z0.imag * z1.imag);
            result.imag = (z0.real * z1.imag) + (z0.imag * z1.real);
            return result;
        }

        PROC operator*(const c64& z0, const c64& z1) -> c64
        {
            c64 result;
            result.real = (z0.real * z1.real) - (z0.imag * z1.imag);
            result.imag = (z0.real * z1.imag) + (z0.imag * z1.real);
            return result;
        }

        PROC operator*(const c32& z0, const f32& s0) -> c32
        {
            return c32{z0.real * s0, z0.real * s0};
        }

        PROC operator*(const c64& z0, const f64& s0) -> c64
        {
            return c64{z0.real * s0, z0.real * s0};
        }

        // Division
        PROC operator/(const c32& z0, const c32& z1) -> c32
        {
            c32 result;
            result.real = ((z0.real * z1.real) + (z0.imag * z1.imag)) / ((z1.real * z1.real) + (z1.imag * z1.imag));
            result.imag = ((z0.imag * z1.real) - (z0.real * z1.imag)) / ((z1.real * z1.real) + (z1.imag * z1.imag));
            return result;
        }

        PROC operator/(const c64& z0, const c64& z1) -> c64
        {
            c64 result;
            result.real = ((z0.real * z1.real) + (z0.imag * z1.imag)) / ((z1.real * z1.real) + (z1.imag * z1.imag));
            result.imag = ((z0.imag * z1.real) - (z0.real * z1.imag)) / ((z1.real * z1.real) + (z1.imag * z1.imag));
            return result;
        }

        // Inverse
        PROC operator-(const c32& z0) -> c32
        {
            c32 result;
            result.real = -z0.real;
            result.imag = z0.imag;
            return result;
        }

        PROC operator-(const c64& z0) -> c64
        {
            c64 result;
            result.real = -z0.real;
            result.imag = z0.imag;
            return result;
        }

        // Functions
        PROC complex_conjugate(const c32& z) -> c32
        {
            return c32(z.real, -z.imag);
        }



    /** Vector 3 type **/
    TYON_CUDA_SHARED
    CONSTRUCTOR v3_f32::v3_f32( f32 arg ) : x(arg), y(arg), z(arg) {}
    TYON_CUDA_SHARED
    CONSTRUCTOR v3_f32::v3_f32( f32 x, f32 y, f32 z ) {}
    TYON_CUDA_SHARED
    CONSTRUCTOR v3_f32::v3_f32( f64 arg ) {}

    TYON_CUDA_SHARED
    PROC operator*( v3_f32 lhs, v3_f32 rhs ) -> v3_f32 {}
}
