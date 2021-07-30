#include <iostream>
using namespace std;
int strlen(const char *p){
    int count = 0;
    while(*p){
        ++count;
        ++p;
    }
    return count;
}
int main(){
    char ch[] = "Hello world";
    int nchar = strlen(ch);
}