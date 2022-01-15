#include <thread>
void f();
struct F{
    void operator()();
};

void user(){
    std::thread t1 {f};
    std::thread t2 {F()};

    t1.join();
    t2.join();
}
