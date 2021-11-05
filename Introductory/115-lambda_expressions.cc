#include <iostream>
#include <vector>
template<typename C, typename Op> void for_all(C &c, Op op){
    for(auto &i:c){
        op(i);
    }
}

template<typename T> void print_container(T &c){
    for(const auto &i:c){
        std::cout<<i<<' ';
    }
}

int main(){
    std::vector<int> vi{1, 2, 3};
    for_all(vi, [](auto &i){i+=1;});
    for_all(vi, [](auto &i){std::cout<<i<<' ';});
}
