#include <iostream>
using namespace std;
class vector {
    int sz;
    int *elem;
    int space;
public:
    vector();
    void reserve(int newalloc);
    void resize(int newsize);
    int capacity() const { return space;}
    void push_back(int d);
};
vector::vector():sz{0},elem{nullptr},space{0}{}
void vector::reserve(int newalloc){
    if(newalloc<=space) return;
    int *p = new int[newalloc];
    for(int i = 0; i<sz; i++) p[i]=elem[i];
    delete[] elem;
    elem = p;
    space=newalloc;
}
void vector::resize(int newsize){
    reserve(newsize);
    for(int i = sz; i<newsize; i++) elem[i]=0;
    sz=newsize;
}
void vector::push_back(int d){
    if(space==0) reserve(8);
    else if (sz==space) reserve(2*space);
    elem[sz]=d;
    sz++;
}
