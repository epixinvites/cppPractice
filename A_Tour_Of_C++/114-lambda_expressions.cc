#include <vector>
#include <iostream>
template<typename C, typename P> int count(const C& c, P pred){
    int cnt = 0;
    for(const auto &x:c){
        if(pred(x)){
            ++cnt;
        }
    }
    return cnt;
}

void f(const std::vector<int> &vec, int x){
    std::cout<<count(vec, [&](int a){return a < x;});
}
