#include <initializer_list>
#include <iostream>
#include <istream>
class Vector{
    int *elem;
    int sz;
public:
    Vector(std::initializer_list<int>);
    Vector();
    void push_back(int);
};

Vector::Vector(std::initializer_list<int> lst):elem{new int[lst.size()]}, sz{static_cast<int>(lst.size())}{
    std::copy(lst.begin(), lst.end(), elem);
}

Vector read(std::istream &is){
    Vector v;
    for(int n; is>>n;){
        v.push_back(n);
    }
    return v;
}

int main(){
    Vector v1 = {1,2,3,4,5};
    Vector v2 = read(std::cin);
}
