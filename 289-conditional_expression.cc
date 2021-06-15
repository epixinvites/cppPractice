#include "std_lib_facilities.h"
using namespace std;
int long_process(int a, int b){
    int m;
    if(a>=b){
        m=a;
    }
    else{
        m=b;
    }
    return m;
}
int short_process(int a, int b){
    return(a>=b)?a:b; // return a if a>=b, return b otherwise
}
