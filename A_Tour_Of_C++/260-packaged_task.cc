#include <numeric>
#include <vector>
#include <future>
#include <thread>
int accum(int *begin, int *end, int init){
    return std::accumulate(begin, end, init);
}
int cmp2(std::vector<int> &v){
    using Task_type = int(int*, int*, int);

    std::packaged_task<Task_type> pt0{accum};
    std::packaged_task<Task_type> pt1{accum};

    std::future<int> f0{pt0.get_future()};
    std::future<int> f1{pt1.get_future()};

    int *first=&v[0];
    std::thread t1 {std::move(pt0), first, first+v.size()/2, 0};
    std::thread t2 {std::move(pt1), first+v.size()/2, first+v.size()/2, 0};

    return f0.get()+f1.get();
}
