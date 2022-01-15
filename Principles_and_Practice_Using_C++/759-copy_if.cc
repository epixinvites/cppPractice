#include <vector>
template<typename ln, typename Out, typename Pred>Out copy_if(ln first, ln last, Out res, Pred p){
    while(first!=last){
	if(p*(first)) *res++ = *first;
	++first;
    }
    return res;
}
void f(const std::vector<int> &v){
    std::vector<int> v2(v.size());
    copy_if(v.begin(),v.end(),v2.begin(),Larger_than(6));
}
