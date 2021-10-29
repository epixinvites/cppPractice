#include <iostream>
#include <vector>
void test(std::vector<int> v, std::vector<int> &rv){
    v[1]=99;
    rv[2]=66;
}

// void print(int value, int base=10);

void print(int value, int base);

void print(int value){
    print(value, 10);
}

int main(){
    std::vector<int> fib = {1,2,3,5,8,13,21};
    test(fib, fib);
    std::cout<<fib[1]<<' '<<fib[2]<<'\n'<<std::flush;
}
