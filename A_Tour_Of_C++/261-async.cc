#include <vector>
#include <numeric>
#include <future>
int accum(int *begin, int *end, int init){
    return std::accumulate(begin, end, init);
}
int comp4(std::vector<int> &v){
    if(v.size()<10000){
        return accum(&v[0], &v[0]+v.size(), 0);
    }
    auto f0 = std::async(accum, &v[0], &v[0]+v.size()/2, 0);
    auto f1 = std::async(accum, &v[0]+v.size()/2, &v[0]+v.size(), 0);

    return f0.get()+f1.get();
}
