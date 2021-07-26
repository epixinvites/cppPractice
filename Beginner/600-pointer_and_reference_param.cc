#include "std_lib_facilities.h"
using namespace std;
void incr_p(int *p){
    if(p==nullptr){
        throw runtime_error("Null pointer arguement");
    }
    ++*p;
}
void incr_r(int &r){
    ++r;
}
int main(){
    int x = 7;
    incr_p(&x);
    incr_r(x);
}
