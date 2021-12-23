#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
class Message {};
void consumer(std::mutex &mmutex, std::condition_variable &mcond, std::queue<Message> &mqueue){
    while(true){
        std::unique_lock lck {mmutex};
        mcond.wait(lck, [&mqueue]{return !mqueue.empty();});
        auto m = mqueue.front();
        mqueue.pop();
        lck.unlock();
        // process m
    }
}
void producer(std::mutex &mmutex, std::condition_variable &mcond, std::queue<Message> &mqueue){
    while(true){
        Message m;
        // fill message
        std::scoped_lock lck{mmutex};
        mqueue.push(m);
        mcond.notify_one();
    }
}
int main(){
    std::queue<Message> mqueue;
    std::condition_variable mcond;
    std::mutex mmutex;

    std::thread consumer_thread{consumer, std::ref(mmutex), std::ref(mcond), std::ref(mqueue)};
    std::thread producer_thread{producer, std::ref(mmutex), std::ref(mcond), std::ref(mqueue)};
    consumer_thread.join();
    producer_thread.join();
}
