#include "std_lib_facilities.h"
using namespace std;
int main(){
    // shallow copy
    int *p = new int{77};
    int *q = p; // copy the pointer p
    *p = 88; // changes the value of p and q

    // deep copy
    int *p1 = new int{77};
    int *q1 = new int{*p}; // allocate a new int, then copy the value pointed by p
    *p = 88; // value of p changes while q remains
}
