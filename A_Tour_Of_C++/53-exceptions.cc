#include <iostream>
#include <stdexcept>
class Vector{
    int *elem;
    int sz;
public:
    Vector(int s):elem{new int[s]}, sz{s}{}
    int &operator[](int i);
    int size(){return sz;}
};

int &Vector::operator[](int i){
    if(i<0||size()<=i){
	throw std::out_of_range("Vector::operator[]");
    }
    return elem[i];
}

void f(Vector &v){
    try{
	v[v.size()]=7;
    }
    catch(std::out_of_range &err){
	std::cerr<<err.what()<<'\n'<<std::flush;
    }
}

void f_noexcept(Vector &v) noexcept{ // noexcept will ensure the function will not throw any exceptions
    v[v.size()]=7;
}
