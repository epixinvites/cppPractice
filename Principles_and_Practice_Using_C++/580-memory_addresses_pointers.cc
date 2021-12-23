#include "std_lib_facilities.h"
using namespace std;
int main() {
    int var = 17;
    int *ptr = &var; // ptr holds the address of var

    double x = 1.234;
    double *x_ptr = &x; // x_ptr holds the address of x

    int var1 = 1;
    int var2 = 2;
    int *var1_ptr = &var1;
    int *var2_ptr = &var2;

    *var1_ptr = 3; // var1 = 3
    *var2_ptr = 4; // var2 = 4

    *var1_ptr = *var2_ptr; // var1 now has var2's value

    // var1_ptr = 3 Errpr: can't assign int to int*
}
