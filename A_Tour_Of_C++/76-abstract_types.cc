#include <iostream>
#include <stdexcept>
class Vector{
    int *elem;
    int sz;
public:
    Vector(int s);
    int &operator[](int i);
    int size() const {return sz;}
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

class Container{
public:
    virtual int &operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container() { }
};

class Vector_container : public Container {
    Vector v;
public:
    Vector_container(int s):v(s){}
    ~Vector_container(){}
    int &operator[](int i) override { return v[i]; }
    int size() const override { return v.size(); }
};

void use(Container &c){
    const int sz = c.size();
    for(int i = 0; i < sz; i++){
        std::cout<<c[i]<<'\n';
    }
}

int main(){
    Container *p = new Vector_container(10);
}
