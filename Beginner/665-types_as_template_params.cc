#include <iostream>
using namespace std;
template<typename T>
class vector{
    int sz;
    T* elem;
    int space;
public:
    vector():sz{0},elem{nullptr},space{0}{}
    explicit vector(int s):sz{s},elem{new T[s]}, space{s}{
        for(int i = 0; i<sz; i++) elem[i]=0;
    }
    T& operator[](int n){return elem[n];}
    const T& operator[](int n) const{return elem[n];}
};
int main(){
    vector<int> vi;
    vector<char> vc;
}