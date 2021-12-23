#include <iostream>
struct Vector{
    int sz;
    int *elem;
};

void vector_init(Vector &v, int s){
    v.elem = new int[s];
    v.sz = s;
}

int read_and_sum(int s){
    int sum = 0;
    Vector v;
    vector_init(v,s);
    for(int i = 0; i!=s; i++){
	std::cin>>v.elem[i];
	sum+=v.elem[i];
    }
    return sum;
}

void f(Vector v, Vector &rv, Vector *pv){
    int i1=v.sz;
    int i2=rv.sz;
    int i3=pv->sz;
}

int main(){
    Vector v;
}
