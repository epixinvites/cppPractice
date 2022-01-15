#include <string>
#include <type_traits>
template<typename Scalar> class complex{
    Scalar re, im;
public:
    static_assert(std::is_arithmetic<Scalar>(), "Only arithmetic types are supported");
};

int main(){
    bool b1 = std::is_arithmetic<int>();
    bool b2 = std::is_arithmetic<std::string>();
}
