#include "std_lib_facilities.h"
using namespace std;
int main(){
    string filename = "test.txt";

    ifstream ist {filename}; // ist is an input stream for the file
    // ist.open(filename, ios_base::in);
    if(!ist){ // check if file is opened properly
        error("Can't open file ",filename);
    }
    ist.close();

    ofstream ost {filename}; // ost is an output stream for the file
    if(!ost){ // check if file is opened properly
        error("Can't open file ", filename);
    }
    ost.close();
}