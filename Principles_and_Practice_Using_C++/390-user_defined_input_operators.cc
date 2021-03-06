#include "std_lib_facilities.h"
using namespace std;
struct Date{
    int year, month, day;
};

istream &operator>>(istream &is, Date &dd){
    int y, m, d;
    char c1, c2;
    is>>y>>c1>>m>>c2>>d;
    if(!is){
        throw runtime_error("Bad input stream");
        return is;
    }
    if(c1!=','||c2!=','){
        is.clear(ios_base::failbit);
        throw runtime_error("Invalid input format");
        return is;
    }
    dd = Date {y,m,d};
    return is;
}

int main(){
    Date d;
    cout<<"Input date in format yyyy,mm,dd: ";
    cin>>d;
}
