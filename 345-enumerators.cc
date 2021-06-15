#include "std_lib_facilities.h"
using namespace std;
enum class Month{
    jan=1,
    feb, // 2
    mar, // 3
    apr, // 4
    may, // 5
    jun, // ...
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

Month int_to_month(int x){
    if(x<int(Month::jan) || x>int(Month::dec)){
        error("Invalid month!");
        return Month(x);
    }
}

int main(){
    // Month bad = 9999; error: can't convert int to Month
    Month m = Month::feb; // Allowed
    Month good = Month(9999); // Allowed
    Month mm = int_to_month(13);
}