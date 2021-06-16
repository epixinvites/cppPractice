#include "std_lib_facilities.h"
using namespace std;
class Date{
private:
    int y;
    int m;
    int d;
public:
    Date(int y, int m, int d);
    int day() const; // const member, can't modify it directly
    int month() const; // const member, can't modify it directly
    int year() const; // const member, can't modify it directly

    void add_day(int n); // non-const: can modify object
    void add_month(int n); // non-const: can modify object
    void add_year(int n); // non-const: can modify object
};

Date::Date(int y, int m, int d):y{y},m{m},d{d}{}

int main(){
    Date d {1970,1,1};
}