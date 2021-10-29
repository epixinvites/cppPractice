#include <iostream>
#include <string>
#include <variant>
enum Type { ptr, num };
union Value{
    void *p; // A node
    int i;
};
struct Entry{
    std::string name;
    Type t;
    Value v;
    std::variant<void*, int> vv;
};
void f(Entry *pe){
    if(pe->t==num){
	std::cout<<pe->v.i;
    }
}
void fv(Entry *pe){
    if(std::holds_alternative<int>(pe->vv)){
	std::cout<<std::get<int>(pe->vv);
    }
}
