#include "std_lib_facilities.h"
using namespace std;
double str_to_double(string s){
    istringstream is{s}; // istringstream
    double d; is>>d;
    if(!is){
        throw runtime_error("double format error");
    }
    return d;
}
int main(){
    double d1 = str_to_double("12.4");
    ostringstream name; // ostringstream
    name << "abc" << "def";
    cout<<name.str()<<endl;
}