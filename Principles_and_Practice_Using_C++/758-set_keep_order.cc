#include <iostream>
#include <iterator>
#include <set>
#include <string>
int main(){
    std::string from, to;
    std::cin>>from>>to;
    std::ifstream is{from};
    std::ofstream os{to};
    std::set<std::string> b {std::istream_iterator<std::string> {is}, std::istream_iterator<std::string>()};
    std::copy(b.begin(), b.end(), std::ostream_iterator<std::string>{os," "});
}
