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
