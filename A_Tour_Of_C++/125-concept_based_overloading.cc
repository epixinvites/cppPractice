#include <vector>
#include <list>
template<Forward_iterator Iter> void advance(Iter p, int n){
    for(int i = 0; i<n; ++i){
        ++p;
    }
}

template<Random_access_iterator Iter, int n> void advance(Iter p, int n){
    p+=n;
}

void test(std::vector<int>::iterator vi, std::list<int>::iterator li){
    advance(vi, 5);
    advance(li, 5);
}
