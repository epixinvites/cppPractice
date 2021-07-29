#include <iostream>
using namespace std;
class vector{
    int sz;
    int *elem;
public:
    vector(vector &&a);
    vector &operator=(vector &&a);
};
vector::vector(vector &&a):sz{a.sz},elem{a.elem}{
    a.sz=0;
    a.elem = nullptr;
}
vector &vector::operator=(vector &&a){
    delete[] elem;
    elem = a.elem;
    sz = a.sz;
    a.elem = nullptr;
    a.sz = 0;
    return *this;
}