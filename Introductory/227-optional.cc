#include <iostream>
#include <string>
#include <optional>
std::optional<std::string> compose_message(std::istream &s){
    std::string mess;
    bool no_problems = true;
    // process message
    if(no_problems){
        return mess;
    }
    return {}; // equivalent to nullptr
}
int main(){
    if(auto m = compose_message(std::cin)){
        std::cout<<*m;
    }
    else{
        // handle error
    }
}
