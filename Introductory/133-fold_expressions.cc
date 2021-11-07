#include <concepts>
#include <iostream>
#include <string>
template<typename T> concept Number = requires (T x){
    x+x;
};

template<Number ... T> int sum(T... v){
    return (v + ... + 0);
}

int main(){
    std::cout<<sum(1, 2, 3, 4, 5);
}
