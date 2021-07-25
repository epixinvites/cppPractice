#include "std_lib_facilities.h"
using namespace std;
class custom_vect{
    int sz;
    int* elem;
public:
    custom_vect(int s):sz{s},elem{new int[s]}{
        for(int i = 0; i<s; i++){
            elem[i] = 0;
        }
    }
    ~custom_vect(){
        delete[] elem;
    }
    int size() const{return sz;}
    // ...
};
int main(){

}
