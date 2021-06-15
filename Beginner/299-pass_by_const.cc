#include "std_lib_facilities.h"
using namespace std;
void print(const vector<int> &v){
    cout<<'{';
    for(int i = 0; i<v.size(); i++){
        cout<<v[i];
        if (i != v.size() - 1) {
          cout << ',';
        }
    }
    cout << '}' << endl;
}
int main(){
    vector<int> v1{1,2,3,4,5}; // small vector
    print(v1);
    vector<int> v2; // large vector
    for(int i = 0; i<1000000; i++){
        v2.push_back(i);
    }
    print(v2);
}
