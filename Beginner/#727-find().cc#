#include <string>
#include <vector>
#include <list>
template<typename ln, typename T> ln find(ln first, ln last, const T &val){
    while(first!=last&&*first!=val)first++;
    return first;
}
void f(std::vector<int> &v, int x) {
    std::vector<int>::iterator p = find(v.begin(), v.end(),x);
    if(p!=v.end()) {/*x is found*/}
}
void ff(std::list<std::string> &v, std::string x){
    std::list<std::string>::iterator p = find(v.begin(), v.end(), x);
    if(p!=v.end()){/*x is found*/}
}
