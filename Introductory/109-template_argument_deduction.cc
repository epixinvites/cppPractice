#include <initializer_list>
template<typename T> class Vector{
public:
    Vector(int);
    Vector(std::initializer_list<T>);
};

int main(){
    Vector v1 = {1, 2, 3};
    Vector v2 = {'a', 'b', 'c'};
}
