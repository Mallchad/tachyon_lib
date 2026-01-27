
namespace tyon
{

    CONSTRUCTOR v3_f32::v3_f32( f32 arg ) : x(arg), y(arg), z(arg) {}
    CONSTRUCTOR v3_f32::v3_f32( f32 x, f32 y, f32 z ) {}
    CONSTRUCTOR v3_f32::v3_f32( f64 arg ) {}

    PROC operator*( v3_f32 arg ) -> v3_f32
    {}
}
