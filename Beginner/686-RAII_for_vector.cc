// RAII: Resource Acquisition Is Initialization

#include <memory>
template<typename T> struct vector_base{
    std::allocator<T> alloc;
    T *elem;
    int sz;
    int space;
    vector_base(const std::allocator<T> &a, int n):alloc{a},elem{alloc.allocate(n)},sz{n},space{n}{}
    ~vector_base(){alloc.deallocate(elem,space);}
};
template<typename T> class vector:private vector_base<T> {
public:
    void reserve(int newalloc);
};
template<typename T>void vector<T>::reserve(int newalloc){
    if(newalloc<=this->space) return;
    vector_base<T> b(this->alloc,newalloc);
    std::uninitialized_copy(b.elem,&b.elem[this->sz],this->elem);
    for(int i = 0; i<this->sz; i++){
        this->alloc.destroy(&this->elem[i]);
    }
    std::swap<vector_base<T>>(*this,b);
}
int main(){}
