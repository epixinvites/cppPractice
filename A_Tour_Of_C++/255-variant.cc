#include <iostream>
#include <variant>
#include <string>
std::variant<std::string, int> compose_message(std::istream& stream){
    std::string mess;
    bool no_problems = true;
    // .. process the message ...
    if(no_problems){
        return mess;
    }
    else{
        return 0;
    }
}

int main(){
    auto m = compose_message(std::cin);
    if(std::holds_alternative<std::string>(m)){
        std::cout<<std::get<std::string>(m);
    }
    else{
        int err = std::get<int>(m);
    }
}
