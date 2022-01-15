#include <vector>
#include <thread>
void f(std::vector<int> &vi);
struct F{
    std::vector<int> &v;
    F(std::vector<int> &vv):v{vv}{}
    void operator()();
};

int main(){
    std::vector<int> v1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> v2 {11, 12, 13};
    std::thread t1 {f, std::ref(v1)};
    std::thread t2 {F{v2}};

    t1.join();
    t2.join();
}
