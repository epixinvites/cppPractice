#include <concepts>
template <typename T>
concept Equality_comparable = requires(T a, T b) {
    {a==b} -> std::same_as<bool>;
    {a!=b} -> std::same_as<bool>;
};
