#include "std_lib_facilities.h"
using namespace std;
int main(){
    ifstream ifs("test.in",ios_base::binary);
    ofstream ofs("test.out",ios_base::binary);
    if(!ifs||!ofs){
        throw runtime_error("Bad file");
    }
    vector<int> v;
    for(int x; ifs.read(as_bytes(x),sizeof(int));){
        v.push_back(x);
    }
    for(int x:v){
        ofs.write(as_bytes(x),sizeof(int));
    }
}
