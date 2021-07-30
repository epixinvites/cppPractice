#include <iostream>
using namespace std;
class vector{
    int sz;
    int *elem;
public:
    vector(int sz):sz{sz},elem{new int[sz]}{
        for(int i = 0; i<sz; i++){
            elem[i] = 0;
        }
    }
    int &operator[](int n);
    int operator[](int n) const;
};
int main(){
    const vector cv(3);
    vector v(3);
    int d = cv[1];
    // cv[1] = 10    error: const
    v[1] = 10;
}