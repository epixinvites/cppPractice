#include <iostream>
#include <string>
#include <algorithm>
bool has_c(const std::string &s, char c){
    return std::find(s.begin(), s.end(), c)!=s.end();
}

template<typename C, typename V> std::vector<typename C::iterator> find_all(C &c, V v){
    std::vector<typename C::iterator> res;
    for(auto p = c.begin(); p != c.end(); ++p){
        if(*p==v){
            res.push_back(p);
        }
    }
    return res;
}

void test(){
    std::string m = "Mary had a little lamb";
    for(auto p:find_all(m, 'a')){
        if(*p!='a'){
            std::cerr<<"A bug\n";
        }
    }
}
