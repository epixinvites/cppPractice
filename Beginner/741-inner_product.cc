#include <vector>
#include <list>
template <typename ln, typename ln2, typename T>T inner_product(ln first, ln last, ln2 first2, T init){
    while(first!=last){
	init=init+(*first)*(*first2);
	++first;
	++first2;
    }
    return init;
}
int main(){
    std::vector<int> vi={1,2,3,4,5};
    std::list<int> li={1,2,3,4,5};
    int sum=inner_product(vi.begin(),vi.end(),li.begin(),0);
}
