#include <regex>
#include <iostream>
#include <string>
#include <fstream>
int main(){
    std::ifstream in{"file.txt"};
    if(!in) std::cerr<<"file.txt not found";
    std::regex pattern{R"(\w{2}\s*\d{5}(-\d{4})?)"};
    int lineno = 0;
    for(std::string line; std::getline(in,line);){
	++lineno;
	std::smatch matches;
	if(std::regex_search(line,matches,pattern)){
	    std::cout<<lineno<<": "<<matches[0]<<std::endl;
	}
    }
}
