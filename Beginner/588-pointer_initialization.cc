#include "std_lib_facilities.h"
using namespace std;
struct X {
    int a, b;
    X();
};
X::X():a{1},b{2}{};
int main() {

    /*
      int *p0; // uninitialized: likely trouble
      *p0 = 7; // trouble
    */

    int *ptr1 = new int[5]{0, 1, 2, 3, 4};
    int *ptr2 = new int[]{0, 1, 2, 3, 4};

    X *px1 = new X;
    X *px2 = new X[17];
}
