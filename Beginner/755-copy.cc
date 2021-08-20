#include <list>
#include <stdexcept>
#include <vector>
template<typename ln, typename Out>Out copy(ln first, ln last, Out res){
    while(first!=last){
	*res=*first;
	++res;
	++first;
    }
    return res;
}
void f(std::vector<int> &vd, std::list<int> &li){
    if(vd.size()<li.size()) throw std::runtime_error("Target container too small");
    copy(li.begin(), li.end(), vd.begin());
}
