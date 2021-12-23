// 5.6.3 Bad Input P172
#include <iostream>
#include <stdexcept>
using namespace std;
int main(){
    try{
        double input; cin>>input;
        cout<<input<<endl;
        return 0;
    }
    catch(runtime_error& e){
        cerr<<"Runtime error: "<<e.what()<<endl;
        return 1;
    }
}
