#include "std_lib_facilities.h"
using namespace std;
int main(){
    int x = 10;
    int *p = &x; // & to get a pointer
    *p = 7; // * to assign x through p
    int x2 = *p; // read x through p
    int *p2 = &x2; // get a pointer to another int
    p2 = p; // p2 and p both point to x
    p = &x2; // make p point to another object
}
