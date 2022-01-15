#include <iostream>
#include <limits>
#include <string>
template<typename T>void print(std::string type, bool is_signed, int size, T smallest, T largest){
    std::cout<<"Type:"<<type;
    if(is_signed){
	std::cout<<" Signed:"<<"true";
    }
    else{
	std::cout<<" Signed:"<<"false";
    }
    std::cout<<" Size:"<<size<<" Minimum:"<<smallest<<" Maximum:"<<largest<<std::endl;
}
int main(){
    print("int",std::numeric_limits<int>::is_signed,sizeof(int),std::numeric_limits<int>::min(),std::numeric_limits<int>::max());
    print("char",std::numeric_limits<char>::is_signed,sizeof(char),std::numeric_limits<char>::min(),std::numeric_limits<char>::max());
    print("long long",std::numeric_limits<long long>::is_signed,sizeof(long long),std::numeric_limits<long long>::min(),std::numeric_limits<long long>::max());
    print("double",std::numeric_limits<double>::is_signed,sizeof(double),std::numeric_limits<double>::min(),std::numeric_limits<double>::max());
}
