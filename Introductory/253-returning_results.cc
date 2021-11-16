#include <thread>
#include <vector>
void f(const std::vector<int> &v, int *res);
class F{
    const std::vector<int> &v;
    int *res;
public:
    F(const std::vector<int> &vv, int *p):v{vv}, res{p}{}
    void operator()();
};

int g(const std::vector<int> &);

void user(std::vector<int> &v1, std::vector<int> v2, std::vector<int> v3){
    int res1, res2, res3;
    std::thread t1{f, std::cref(v1), &res1};
    std::thread t2{F{v2, &res2}};
    std::thread t3{[&](){res3 = g(v3);}};

    t1.join();
    t2.join();
    t3.join();
}
