#include "std_lib_facilities.h"
using namespace std;
class Number {
    int num_ = 1;
public:
    Number& add(int n) {
        num_+=n;
        return *this; // "this" is "test" in this context
    }
    Number& mul(int n) {
        num_*=n;
        return *this; // "this" is "test" in this context
    }
    int value() const { return num_; }
};
int main() {
    Number test;
    test.add(1).mul(2); // add(&test, 1), mul(&test, 2)   test is the "this" in this context
}
