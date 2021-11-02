class Vector{
    int *elem;
    int sz;
public:
    Vector(int s);
    ~Vector(){delete[] elem;}
    Vector(const Vector &a);
    Vector& operator=(const Vector &a);
    int& operator[](int i);
    const int& operator[](int i) const;
    int size() const;
};

Vector::Vector(const Vector &a):elem{new int[a.sz]}, sz{a.sz}{
    for(int i = 0; i<sz; i++){
        elem[i]=a.elem[i];
    }
}

Vector& Vector::operator=(const Vector &a){
    int *p = new int[a.sz];
    for(int i = 0; i<a.sz; i++){
        p[i]=a.elem[i];
    }
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
}
