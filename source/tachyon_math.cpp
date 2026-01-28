
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



    /** Vector 3 type **/
    TYON_CUDA_SHARED
    CONSTRUCTOR v3_f32::v3_f32( f32 arg ) : x(arg), y(arg), z(arg) {}
    TYON_CUDA_SHARED
    CONSTRUCTOR v3_f32::v3_f32( f32 x, f32 y, f32 z ) {}
    TYON_CUDA_SHARED
    CONSTRUCTOR v3_f32::v3_f32( f64 arg ) {}

    TYON_CUDA_SHARED
    PROC operator*( v3_f32 lhs, v3_f32 rhs ) -> v3_f32
    {
        return {};
    }
}
