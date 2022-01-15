#include "std_lib_facilities.h"
using namespace std;
struct Even{
    int val;
    Even(int n) {
        if(n%2 != 0)
            throw std::runtime_error("Must be even");
        val = n;
    }
};
int main(){
    Even p1(2);
    Even p2(3);
}
