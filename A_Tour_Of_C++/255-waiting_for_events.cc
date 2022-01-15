#include <chrono>
#include <thread>
#include <iostream>
int main(){
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds{20}); // sleep this thread for 20 milliseconds
    auto end = std::chrono::high_resolution_clock::now();
    std::cout<<std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()<<std::endl;
}
