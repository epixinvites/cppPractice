#include "std_lib_facilities.h"
using namespace std;
int main(){
    const int *ptr = nullptr;
    ptr = const_cast<int*>(ptr); // casts away the const

    void *pd = nullptr;
    int *pi = static_cast<int*>(pd); // explicitly convert void into int

    int *pi2 = new int;
    double *pd2 = reinterpret_cast<double*>(pi2); // cast between unrelated types
}