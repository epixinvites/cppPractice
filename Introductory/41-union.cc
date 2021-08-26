#include <iostream>
#include <string>
enum Type { ptr, num };
union Value{
    int *p;
    int i;
};
struct Entry{
    std::string name;
    Type t;
    Value v;
};
void f(Entry *pe){
    if(pe->t==num){
	std::cout<<pe->v.i;
    }
}
