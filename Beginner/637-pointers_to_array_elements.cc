#include "std_lib_facilities.h"
using namespace std;
int main(){
    int ad[10];
    int *p = &ad[5]; // p points to ad[5]
    *p = 7; // ad[5] = 7
    p[2] = 6; // ad[7] = 6
    p[-3] = 9; // ad[2] = 9
    p += 2; // now p points to ad[7]
    p -= 5; // now p points to ad[2]
}