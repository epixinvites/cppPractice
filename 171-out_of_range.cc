//5.6.2 Range Errors P171
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
int main(){
    try{
        vector<int> v;
        for(int i = 0; i<3; i++){
            int x; cin>>x;
            v.push_back(x);
        }
        for(int i = 0; i<=v.size(); i++){
            cout<<v[i]<<endl;
        }
    }
    catch(out_of_range){
        cerr<<"Out of range.";
        return 1;
    }
}
