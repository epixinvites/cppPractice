constexpr double C = 299792.458;
void f(double speed){
    constexpr double local_max = 160.0/(60*60);
    static_assert(speed<C, "Too fast"); // speed is not a constant
    static_assert(local_max<C, "Too fast");
}
