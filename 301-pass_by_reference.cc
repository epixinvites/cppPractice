#include "std_lib_facilities.h"
using namespace std;
void init(vector<int> &v){
    for(int i = 0; i<v.size(); i++){
        v[i]=i;
    }
}
int main(){
    vector<int> v1(5);
    init(v1);
    vector<int> v2(100000);
    init(v2);
}