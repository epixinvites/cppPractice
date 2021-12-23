#include <iostream>
#include <stdexcept>

struct Negative_Size{};

template <typename T> class Vector{
    T *elem;
    int sz;
public:
    explicit Vector(int s);
    ~Vector(){delete[] elem;}
    T &operator[](int i);
    const T &operator[](int i) const;
    int size() const {return sz;}
};

template<typename T> Vector<T>::Vector(int s){
    if(s<0){
        throw Negative_Size{};
    }
    elem = new T[s];
    sz = s;
}

template <typename T> const T &Vector<T>::operator[](int i) const {
    if(i<0||size()<=i){
        throw std::out_of_range("Vector::operator[] out of range");
        return elem[i];
    }
}

template<typename T> T* begin(Vector<T> &x){
    return x.size() ? &x[0] : nullptr; // pointer to first element of the vector
}

template <typename T> T *end(Vector<T> &x) {
    return x.size() ? &x[0]+x.size() : nullptr; // pointer to one-past-last element of the vector
}

int main(){
    Vector<int> vi(100);
    Vector<char> vc(200);
    for(auto &i:vi){
        std::cout<<i<<std::endl;
    }
}
