#include <vector>
template<typename ln, typename Pred>ln find_if(ln first, ln last, Pred pred){
    while(first!=last&&!pred(*first)) ++first;
    return first;
}
bool odd(int x) { return x % 2; }
bool large_than_42(double x){return x>42;}
void f(std::vector<int> &v) {
    auto p = find_if(v.begin(),v.end(),odd);
    if(p!=v.end()){/*odd number found*/}
}
void ff(std::vector<int> &v){
    auto p = find_if(v.begin(),v.end(),large_than_42);
    if(p!=v.end()){/*value>42 found*/}
}
