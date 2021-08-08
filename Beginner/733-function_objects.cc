#include <algorithm>
#include <list>
class Larger_than{
    int v;
public:
    Larger_than(int vv):v{vv}{}
    bool operator()(int x)const{return x>v;}
};
void f(std::list<double> &v, int x){
    auto p = std::find_if(v.begin(),v.end(),Larger_than(31));
    if(p!=v.end()){/*value>31 found*/}
    auto q = std::find_if(v.begin(),v.end(),Larger_than(x));
    if(q!=v.end()){/*value>x found*/}
}
