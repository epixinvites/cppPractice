#include <iostream>
#include <regex>
int main(){
    std::regex pattern {R"(\w{2}\s*\d{5}(−\d{4})?)"};
    for(std::string line; std::getline(std::cin, line);){
        std::smatch matches;
        if(std::regex_search(line, matches, pattern)){
            std::cout<<matches[0]<<std::endl;
        }
    }
}
