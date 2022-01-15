#include <iostream>
using namespace std;
class vector {
  int sz;
  int *elem;

public:
  vector &operator=(const vector &);
};
vector &vector::operator=(const vector &a){
    int *p = new int[a.sz];
    copy(a.elem,a.elem+a.sz,elem);
    delete[] elem;
    elem = p;
    sz=a.sz;
    return *this;
}
