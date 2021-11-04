#include <vector>
template<typename Sequence, typename Value> Value sum(const Sequence &s, Value v){
    for(auto x:s){
        v+=x;
    }
    return v;
}

int main(){
    std::vector<int> vi{1, 2, 3, 4};
    int x = sum(vi, 0);
}
