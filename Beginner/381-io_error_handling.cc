#include "std_lib_facilities.h"
using namespace std;
/*
 * the input stream can be changed to any input stream, for example fstream
 */
int main(){
    int i = 0; cin>>i;
    if(!cin){
        if(cin.bad()){ // corrupted input stream
            error("Bad input");
        }
        if(cin.eof()){ // end of input
            // no more input
        }
        if(cin.fail()){ // input stream encountered something unexpected
            cin.clear(); // make ready for more input
        }
    }
}
