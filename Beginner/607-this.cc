#include "std_lib_facilities.h"
using namespace std;
class Number {
    int num_ = 0;
public:
    Number& add(int n) {
        num_+=n;
        return *this;
    }
    Number& mul(int n) {
        // TODO
    }
    int value() const { return num_; }
};
int main() {
    Number test;
    test.add(1);
}
