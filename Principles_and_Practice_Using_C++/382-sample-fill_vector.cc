#include "std_lib_facilities.h"
using namespace std;
void fill_vector(istream &ist, vector<int> &v, char terminator){
    for(int i; ist>>i;){
        v.push_back(i);
    }
    if(ist.eof()){ // end of input
        return;
    }
    if(ist.bad()){ // stream corrupted
        error("Input stream bad"); // ist.exceptions(ist.exceptions()|ios_base::failbit);
    }
    if(ist.fail()){ // clean up the mess and report the problem
        ist.clear(); // lear stream state
        char c; ist>>c;
        if(c!=terminator){ //unexpected char
            ist.unget(); // put char back
            ist.clear(ios_base::failbit); // set state to fail()
        }
    }
}

void fill_vector_v2(istream &ist, vector<int> &v, char terminator){
    for(int i; ist>>i;){
        v.push_back(i);
    }
    if(ist.eof()){
        return;
    }
    ist.clear(); // not good(), bad(), eof() then it should be fail(). clear() stream state
    char c; ist>>c;
    if(c!=terminator){
        ist.unget();
        ist.clear(ios_base::failbit);
    }
}
