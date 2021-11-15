#include <chrono>
#include <iostream>
#include <thread>
int main(){
    auto start = std::chrono::high_resolution_clock::now();
    // do something - Example:
    std::this_thread::sleep_for(std::chrono::milliseconds(10)+std::chrono::microseconds(40));
    auto end = std::chrono::high_resolution_clock::now();
    std::cout<<std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()<<" milliseconds"<<std::endl;
}
