#include <memory>
#include <fstream>
struct X {
    X();
    X(int i);
};
void unique_ptr_f(int i){
    X *p = new X; // bad
    std::unique_ptr<X> up {new X};

    if(i<100) return; // p is not deleted

    delete p;
}
std::unique_ptr<X> make_X(int i){
    // something
    return std::unique_ptr<X>{new X{i}};
}

void user(std::shared_ptr<std::fstream>);

void shared_ptr_f(const std::string &name, std::ios_base::openmode mode){
    std::shared_ptr<std::fstream> fp {new std::fstream(name, mode)};
    user(fp);
    // ...
}

int main(){
    auto sp = std::make_shared<X>;
    auto up = std::make_unique<X>;
}
