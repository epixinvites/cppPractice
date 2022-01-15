#include <iostream>
using namespace std;
template<typename T>
class vector {
    int sz;
    int *elem;
    int space;
public:
    vector():sz{0},elem{nullptr},space{0}{}
    explicit vector(int s):sz{s},elem{new T[s]}, space{s}{
        for(int i = 0; i<sz; i++) elem[i]=0;
    }
    T& operator[](int n){return elem[n];}
    const T& operator[](int n) const{return elem[n];}
    void reserve(int newalloc);
    void resize(int newsize, T def=T());
    int capacity() const { return space;}
    void push_back(int d);
    vector &operator=(const vector &a);
};
template<typename T>void vector<T>::reserve(int newalloc){
    if(newalloc<=space) return;
    int *p = new int[newalloc];
    for(int i = 0; i<sz; i++) p[i]=elem[i];
    delete[] elem;
    elem = p;
    space=newalloc;
}
template<typename T>void vector<T>::resize(int newsize, T def){
    reserve(newsize);
    for(int i = sz; i<newsize; i++) elem[i]=0;
    sz=newsize;
}
template<typename T>void vector<T>::push_back(int d){
    if(space==0) reserve(8);
    else if (sz==space) reserve(2*space);
    elem[sz]=d;
    sz++;
}
template<typename T>vector<T> &vector<T>::operator=(const vector &a){
    if(this==&a) return *this;
    if(a.sz<=space){
        for(int i = 0; i<a.sz; i++){
            elem[i] = a.elem[i];
        }
        sz=a.sz;
        return *this;
    }
    int *p = new int[a.sz];
    for(int i = 0; i<a.sz; i++){
        p[i]=a.elem[i];
    }
    delete[] elem;
    space=sz=a.sz;
    elem=p;
    return *this;
}
