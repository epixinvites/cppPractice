#include "std_lib_facilities.h"
using namespace std;
struct Date{
    int year, month, day;
};

ostream &operator<<(ostream &os, const Date &d){
    return os << '(' << d.year << ',' << d.month << ',' << d.day << ')';
}

int main(){
    Date d{1970,1,1};
    cout<<d<<endl; // operator<<(cout,d);
}
