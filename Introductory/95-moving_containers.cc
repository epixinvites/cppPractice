#include <utility>

struct Vector_size_mismatch{};

class Vector{
    int *elem;
    int sz;
public:
    Vector(int s);
    ~Vector(){delete[] elem;}

    Vector(const Vector &a);
    Vector& operator=(const Vector &a);

    Vector(Vector &&a);
    Vector &operator=(const Vector &&a);

    int& operator[](int i);
    const int& operator[](int i) const;
    int size() const;
};

Vector::Vector(const Vector &a):elem{new int[a.sz]}, sz{a.sz}{
    for(int i = 0; i<sz; i++){
        elem[i]=a.elem[i];
    }
}

Vector::Vector(Vector &&a):elem{a.elem}, sz{a.sz}{
    a.elem = nullptr;
    a.sz = 0;
}

Vector operator+(const Vector &a, const Vector &b){
    if(a.size()!=b.size()){
        throw Vector_size_mismatch{};
    }
    Vector res(a.size());
    for(int i = 0; i<a.size(); i++){
        res[i]=a[i]+b[i];
    }
    return res;
}

Vector f(){
    Vector x(1000);
    Vector y(2000);
    Vector z(3000);
    z=x;
    y=std::move(x);
    return z;
}
