#include <vector>
#include <list>
template<typename ln, typename T> ln find(ln first, ln last, const T &val){
    while(first!=last&&*first!=val)first++;
    return first;
}
void f(std::vector<int> &v, int x) {
    std::vector<int>::iterator p = find(v.begin(), v.end(),x);
}
