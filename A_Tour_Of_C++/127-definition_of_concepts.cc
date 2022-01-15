#include <concepts>
template <typename T, typename T2 = T>
concept Equality_comparable = requires (T a, T2 b){
    {a==b} -> std::same_as<bool>;
    {a!=b} -> std::same_as<bool>;
    {b==a} -> std::same_as<bool>;
    {b!=a} -> std::same_as<bool>;
};

int main(){
    static_assert(Equality_comparable<int>);
    static_assert(Equality_comparable<int, double>);
    struct S {int a;};
    // static_assert(Equality_comparable<S>); Error: fails
}
