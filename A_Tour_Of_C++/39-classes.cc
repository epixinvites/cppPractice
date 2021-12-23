#include <iostream>
class Vector{
    int *elem;
    int sz;
public:
    Vector(int s):elem{new int[s]}, sz{s}{}
    int &operator[](int i){return elem[i];}
    int size(){return sz;}
};

int read_and_sum(int s){
    int sum=0;
    Vector v(s);
    for(int i=0; i!=v.size(); ++i){
	std::cin>>v[i];
	sum+=v[i];
    }
    return sum;
}

int main(){
    Vector v(6);
}
