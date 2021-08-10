#include <iostream>
#include <vector>
template<typename ln, typename T>T accumulate(ln first, ln last, T init){
    while(first!=last){
	init=init+*first;
	++first;
    }
    return init;
}
void f(std::vector<double> &vd, int *p, int n) {
    double sum = accumulate(vd.begin(), vd.end(), 0.0);
    int sum2 = accumulate(p, p+n, 0);
}
int main(){
    int a[] = {1,2,3,4,5};
    std::cout<<accumulate(a,a+sizeof(a)/sizeof(int),0);
}
