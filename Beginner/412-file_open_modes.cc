#include "std_lib_facilities.h"
using namespace std;
int main(){
    /*
      ios_base::app // append to end of file
      ios_base::ate // op and seek to end
      ios_base::binary // binary mode
      ios_base::in/out // reading and writing
      ios_base::trunc // truncate file to 0 length
     */
    ofstream of1{"test.txt",ios_base::app|ios_base::out};
    fstream fs{"test.txt", ios_base::in|ios_base::out};
}
