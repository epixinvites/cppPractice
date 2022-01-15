#include <iostream>
#include <iterator>
int main(){
    std::ostream_iterator<std::string> oo{std::cout};
    std::istream_iterator<std::string> ii{std::cin};
    *oo = "Hello ";
    ++oo;
    *oo="World\n";
    std::string s1 = *ii;
    ++ii;
    std::string s2 = *ii;
}
