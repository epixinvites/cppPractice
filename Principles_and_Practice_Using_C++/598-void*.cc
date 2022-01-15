#include "std_lib_facilities.h"
using namespace std;
int main(){
    void *ptr1 = new int; // int* converts to void*
    void *ptr2 = new double[10]; // double* converts to void*
}