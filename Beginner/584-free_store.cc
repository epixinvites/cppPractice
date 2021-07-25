#include "std_lib_facilities.h"
int main(){
    int *pi = new int; // allocate one int
    double *p = new double[4]; // allocate 4 doubles
    *p = 1.1;
    p[1] = 2.2;
    p[2] = 3.3;
    double x = *p; // read the 1st object for p; same as p[0]
    double y = p[2]; // read the 3rd object for p
}
