#include "std_lib_facilities.h"
using namespace std;
class complex{
public:
    explicit complex(int);
    explicit complex(int,int);
};
int main(){
    complex z1 = complex(3);
    complex z2 = complex{1,2};
}
