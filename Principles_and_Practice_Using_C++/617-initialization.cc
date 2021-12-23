#include <iostream>
using namespace std;
class vector{
    int sz;
    int *elem;
public:
    vector(int s):sz{s},elem{new int[sz]}{
        for(int i = 0; i<sz; i++){
            elem[i] = 0;
        }
    }
    vector(initializer_list<int> lst):sz{lst.size()},elem{new int[sz]}{
        copy(lst.begin(),lst.end(),elem);
    }
};
int main(){
    vector v1 = {1,2,3}; // creates a vector with 3 elements {1,2,3}; can be written as "vector v1{1,2,3}"
    vector v2(3); // creates a vector with 3 elements all with the value 0
}
