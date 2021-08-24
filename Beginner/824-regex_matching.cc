#include <cstdlib>
#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
struct bad_expression{};
int main(){
    std::regex pattern;
    std::string pat;
    std::cout<<"Input pattern: ";
    std::getline(std::cin,pat);
    try{
	pattern = pat;
    }
    catch(bad_expression){
	std::cout<<pat<<": invalid expression"<<std::endl;
	std::exit(1);
    }
    std::cout<<"Enter lines: "<<std::endl;
    int lineno=0;
    for(std::string line; std::getline(std::cin,line);){
	++lineno;
	std::smatch matches;
	if(std::regex_search(line,matches,pattern)){
	    std::cout<<"Line "<<lineno<<": "<<line<<std::endl;
	    for(int i = 0; i<matches.size(); i++){
		std::cout<<"\tmatches["<<i<<"]: "<<matches[i]<<std::endl;
	    }
	}
	else{
	    std::cout<<"No matches"<<std::endl;
	}
    }
}
