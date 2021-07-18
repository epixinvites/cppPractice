#include "std_lib_facilities.h"
using namespace std;
int main(){
    string name; cin>>name; // input: ABC DEF, {name}: ABC

    getline(cin,name); // input: ABC DEF, {name}: ABC DEF
    stringstream ss {name};
    vector<string> words;
    for(string s; ss>>s;){
        words.push_back(s); // extract every word
    }
}
