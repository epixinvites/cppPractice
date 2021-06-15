#include "std_lib_facilities.h"
using namespace std;
class Date{
private:
    int y, m, d;
    bool is_valid();
public:
    class Invalid{};
    Date(int y, int m, int d);
    int get_day(){
        return d;
    }
    int get_month(){
        return m;
    }
    int get_year(){
        return y;
    }
};
Date::Date(int yy, int mm, int dd) : y{yy}, m{mm}, d{dd} {
    if(!is_valid()){
        throw Invalid{};
    }
}
bool Date::is_valid(){
    if(m<1||m>12){
        return false;
    }
    // rest of conditions
}
/*
  Date::Date(int yy, int mm, int dd){
      y=yy;
      m=mm;
      d=dd;
  }
*/

int main() {
    try{
        Date p1{1970,0,1};
    }
    catch(Date::Invalid){
        error("Invalid date");
    }
}
