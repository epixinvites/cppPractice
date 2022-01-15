#include <iostream>
template<typename T, typename ... Tail> void print(T head, Tail... tail){
    std::cout<<head<<' ';
    if constexpr(sizeof...(tail)>0){
        print(tail...);
    }
}

int main(){
    print('a', 'b', 1, 2, 3, "aaaaaaaaa");
}
