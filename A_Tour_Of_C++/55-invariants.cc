#include <iostream>
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

int &Vector::operator[](int i){
    if(i<0||size()<=i){
	throw std::out_of_range("Vector::operator[]");
    }
    return elem[i];
}

void test(){
    try{
	Vector v(-27);
    }
    catch(std::length_error &err){
	// handle negative size
	std::cerr<<"Test failed: length_error"<<'\n'<<std::flush;
	throw;
    }
    catch(std::bad_alloc &err){
	// handle memory exhaustion
	std::terminate();
    }
}
