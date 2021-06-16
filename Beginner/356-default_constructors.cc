#include "std_lib_facilities.h"
using namespace std;
class Date{
private:
    int y; // int y{1970};
    int m; // int m{1};
    int d; // int d{1};
public:
    Date();
    void print_date(){
        cout<<y<<", "<<m<<", "<<d<<endl;
    }
};

Date::Date():y{1970},m{1},d{1}{};

/*
const Date &default_date(){
    static Date dd {1970,1,1};
}
*/

int main() {
    Date def; def.print_date();
}
