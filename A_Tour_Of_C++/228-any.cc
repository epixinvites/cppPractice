#include <any>
#include <iostream>
#include <istream>
#include <string>
std::any compose_message(std::istream &s){
    std::string mess;
    bool no_problems = true;
    // process message
    if(no_problems){
        return mess;
    }
    else{
        return 0;
    }
}
int main(){
    auto m = compose_message(std::cin);
    const std::string &s = std::any_cast<std::string>(m);
    std::cout<<s;
}
