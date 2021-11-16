#include <mutex>
#include <thread>
void f(std::mutex &m, int &sh){
    std::scoped_lock lck{m};
    sh+=7; // only runs if this thread aquires the lock for m
}
