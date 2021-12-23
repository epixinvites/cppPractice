#include "std_lib_facilities.h"
using namespace std;
enum Month{
    jan=1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};
int main(){
    Month m = feb; // Same as Month m = Month::feb
    // m = 7 isn't allowed
    int n = m;
    Month mm = Month(10);
}