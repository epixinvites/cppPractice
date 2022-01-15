#include "std_lib_facilities.h"
using namespace std;
enum class Month{
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

Month operator++(Month &m){
    m = (m==Month::dec) ? Month::jan : Month(int(m)+1); // m becomes Month::jan if (m==Month::dec) and Month(int(m)+1) otherwise 
    return m;
}



int main(){
    Month m = Month::dec;
    ++m; // m becomes Month::jan
}