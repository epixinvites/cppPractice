#include <stdexcept>
class Vector{
    int *elem;
    int sz;
public:
    Vector(int s);
    int &operator[](int i);
    int size(){return sz;}
};

Vector::Vector(int s){
    if(s<0){
	throw std::length_error("Vector constructor: negative size");
    }
    elem=new int[s];
    sz=s;
}

int &Vector::operator[](int i){ // This is returned by reference because we want to provide access to something to something not local to the function
    if(i<0||size()<=i){
	throw std::out_of_range("Vector::operator[]");
    }
    return elem[i];
}
