#include "std_lib_facilities.h"
using namespace std;
int main(){
    fstream fs{"test.txt",ios_base::in};
    if (!fs) {
        throw runtime_error("Can't open test.txt");
    }
    fs.seekg(5); // read 6th character
    char ch; fs>>ch;
    cout<<"character[5] of the file is "<<ch;

    fs.seekp(1); // move writing position to 1
    fs<<'y'; // write 'y' to position 1
}
