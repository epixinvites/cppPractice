#include <iostream>
#include <algorithm>
class vector{
    int sz;
    int *elem;
public:
    vector(const vector&);
    ~vector(){delete[] elem;}
};
vector::vector(const vector& arg):sz{arg.sz},elem{new int[arg.sz]}{
    std::copy(arg.elem,arg.elem+sz,elem);
}
