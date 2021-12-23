#include <iostream>
#include <list>
#include <stdexcept>
class Container{
public:
    virtual int &operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container() { }
};

class List_container:public Container{
    std::list<int> ld;
public:
    List_container(){}
    List_container(std::initializer_list<int> il):ld(il){}
    ~List_container(){}
    int &operator[](int i) override;
    int size() const override { return ld.size(); }
};

int &List_container::operator[](int i){
    for(auto &x:ld){
        if(i==0){
            return x;
        }
        --i;
    }
    throw std::out_of_range("List container");
}

void use(Container &c){
    const int sz = c.size();
    for(int i = 0; i < sz; i++){
        std::cout<<c[i]<<'\n';
    }
}

void h(){
    List_container lc={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    use(lc);
}
