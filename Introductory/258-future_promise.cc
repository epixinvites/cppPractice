#include <future>
struct X {};
void f(std::promise<X> &px){
    try{
        X res;
        // compute res
        px.set_value(res);
    }
    catch(...){
        px.set_exception(std::current_exception());
    }
}
void g(std::future<X> &fx){
    try{
        X v = fx.get();
        // use v
    }
    catch(...){
        // handle errors
    }
}
