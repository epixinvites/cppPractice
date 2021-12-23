#include "std_lib_facilities.h"
using namespace std;
class Even{
    int val;
public:
    Even(int n) {
        if(n%2 != 0)
            throw std::runtime_error("Must be even");
        val = n;
    }
    int value(){
        return val;
    }
};
int main(){
    Even var{2};
    // cout<<var.val; Error: val is a private member
    cout<<var.value(); // Allowed
}