#include "std_lib_facilities.h"
using namespace std;
int main(){
    int *ptr0 = new int;
    int *ptr1 = new int[100];
    int *nullp = nullptr;

    delete ptr0; // free memory
    delete[] ptr1; // free memory
    delete nullp; // No action needed
}
