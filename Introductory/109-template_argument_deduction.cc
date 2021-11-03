#include <initializer_list>
template<typename T> class Vector{
public:
    Vector(int);
    Vector(std::initializer_list<T>);
};

template<typename T> class Vector2{
public:
    Vector2(std::initializer_list<T>);
    template<typename Iter> Vector2(Iter b, Iter e); // range constructor
    template<typename Iter> Vector2(Iter, Iter) -> Vector2<typename Iter::T>;
};

int main(){
    Vector v1 = {1, 2, 3};
    Vector v2 = {'a', 'b', 'c'};
}
