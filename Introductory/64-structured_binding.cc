#include <string>
#include <iostream>
#include <map>
struct Entry{
    std::string name;
    int value;
};

Entry read_entry(std::istream &is){
    std::string s;
    int i;
    is>>s>>i;
    return {s,i};
}

void incr(std::map<std::string, int> &m){
    for(auto &[key, value]:m){
        ++value;
    }
}

int main(){
    auto e = read_entry(std::cin); // e will be type Entry
    auto [n, v] = read_entry(std::cin); // n will be a std::string while v will be an int

    std::map<std::string, int> m;

    for(const auto [key, value]:m){
        std::cout<<'{'<<key<<','<<value<<'}'<<'\n';
    }
}
