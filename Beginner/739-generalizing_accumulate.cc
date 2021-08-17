#include <vector>
#include <functional>
template<typename ln, typename T, typename BinOp>T accumulate(ln first, ln last, T init, BinOp op){
    while(first!=last){
	init=op(init, *first);
	++first;
    }
    return init;
}
int main(){
    std::vector<double> a={1.1,2.2,3.3,4.4};
    double sum=accumulate(a.begin(), a.end(), 1.0, std::multiplies<double>());
}
