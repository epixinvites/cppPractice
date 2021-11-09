#include <memory>
template<typename T, typename ... Args> std::unique_ptr<T> make_unique(Args&&... args){
    return std::unique_ptr<T>{new T{std::forward<Args>(args)...}};
}

int main(){
    auto p = std::make_unique<int>(0);
    auto q = std::move(p);
}
