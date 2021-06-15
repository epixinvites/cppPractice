#include "std_lib_facilities.h"
using namespace std;
struct Date {
  int year, month, day;
};
void print_date(Date &dd) {
  cout << dd.year << endl << dd.month << endl << dd.day << endl;
}
void init(Date &dd, int y, int m, int d){
    dd.year = y;
    dd.month = m;
    dd.day = d;
    print_date(dd);
}
void set_date_if_valid(Date &dd, int y, int m, int d){
    if(y<0){
        cerr<<"Incorrect year! Year cannot be smaller than 0!";
        return;
    }
    if(m<0||m>12){
        cerr<<"Incorrect month! Range of month (1-12)";
        return;
    }
    if(y%4==0&&d>29&&m==2){
        cerr<<"Incorrect day! Range of day (1-29 for leap years)";
        return;
    }
    if(y%4!=0&&d>28&&m==2){
        cerr<<"Incorrect day! Range of day (1-28)";
        return;
    }
    if(d>31&&m!=2){
        cerr<<"Incorrect day! Range of day(1-31)";
        return;
    }
    init(dd, y, m, d);
}
int main(){
    Date today;
    set_date_if_valid(today, 2020, 2, 29);
}
