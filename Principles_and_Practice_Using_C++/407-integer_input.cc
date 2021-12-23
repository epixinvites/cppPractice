#include "std_lib_facilities.h"
using namespace std;
int main(){
    int a, b, c, d;
    cin.unsetf(ios::dec);
    cin.unsetf(ios::oct);
    cin.unsetf(ios::hex);
    cin>>a>>b>>c>>d;
    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
}
