#include <iostream>
using namespace std;
class vector{
    int sz;
    int *elem;
public:
    int &operator[](int n){
        return elem[n];
    }
    vector(int s):sz{s},elem{new int[s]}{
        for(int i = 0; i<s; i++){
            elem[i]=0;
        }
    }
};
int main(){
    vector v(3);
    v[0] = 9;
    cout<<v[0]; // 9
}