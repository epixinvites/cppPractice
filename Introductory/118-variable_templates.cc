#include <type_traits>
template <class T> constexpr T viscosity = 0.4;
template <class T> constexpr space_vector<T> external_acceleration = T{-9.8};

template<typename T, typename T2> constexpr bool Assignable = std::is_assignable<T&, T2>::value;

template <typename T> void test(){
    static_assert(Assignable<T&, double>, "Can't assign a double");
}

int main(){
    auto vis2 = 2*viscosity<double>;
    auto acc = external_acceleration<float>;
}
