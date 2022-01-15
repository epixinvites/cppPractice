#include <iostream>
using namespace std;
template<typename T, int N> struct array{
    T elem[N];
    T &operator[](int n);
    const T &operator[](int n) const;
    T *data(){return elem;}
    int size() const{return N;}
};
int main(){
    array<int,256>gb;
    array<double,6> ad = {0.0,1.1,2.2,3.3,4.4,5.5};
}