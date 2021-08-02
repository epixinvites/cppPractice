#include <iostream>
using namespace std;
class vector {
    int sz;
    int *elem;
    int space;
public:
    vector();
    void reserve(int newalloc);
    int capacity() const { return space;}
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