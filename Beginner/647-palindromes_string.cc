#include "std_lib_facilities.h"
using namespace std;
bool is_palindrome(const string &s){
    int first = 0;
    int last = s.length()-1;
    while(first<last){
        if(s[first]!=s[last]) return false;
        ++first;
        --last;
    }
    return true;
}