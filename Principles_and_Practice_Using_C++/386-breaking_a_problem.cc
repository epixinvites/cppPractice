#include "std_lib_facilities.h"
using namespace std;
void skip_to_int(){
    if(cin.fail()){
        cin.clear();
        for(char ch; cin>>ch;){
            if(isdigit(ch)||ch=='-'){
                cin.unget();
                return;
            }
        }
    }
    error("No input");
}

int get_int(int low, int high){
    cout<<"Please enter an integer in the range of "<<low<<"<x<"<<high<<": ";
    int n = 0;
    while(true){
        if(cin>>n){
            if(n>low&&n<high){
                return n;
            }
            cout<<"Sorry, "<<n<<" is not in the range of [1:10]."<<endl;
        }
        else{
            cout<<"Sorry, that was not a number."<<endl;
            skip_to_int();
        }
    }
}

int main(){
    int n = get_int(1,10);
    cout<<n<<endl;
}

