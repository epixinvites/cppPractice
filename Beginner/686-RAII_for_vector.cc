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
    vector():sz{0},elem{nullptr},space{0}{}
    explicit vector(int s):sz{s},elem{new T[s]}, space{s}{
        for(int i = 0; i<sz; i++) elem[i]=0;
    }
    T &at(int n);
    const T &at(int n) const;
    void reserve(int newalloc);
    void resize(int newsize, T def=T());
    int capacity() const { return space;}
    void push_back(int d);
    vector &operator=(const vector &a);
};
struct out_of_range{};
template<typename T>T &vector<T>::at(int n){
    if(n<0||sz<=n) throw out_of_range();
    return elem[n];
}
template<typename T>const T &vector<T>::at(int n) const{
    if(n<0||sz<=n) throw out_of_range();
    return elem[n];
}
template<typename T>void vector<T>::reserve(int newalloc){
    if(newalloc<=space) return;
    T *p = alloc.allocate(newalloc);
    for(int i = 0; i<sz; i++) alloc.construct(&p[i],elem[i]);
    for(int i = 0; i<sz; i++) alloc.destroy(&elem[i]);
    alloc.deallocate(elem,space);
    elem = p;
    space=newalloc;
}
template<typename T>void vector<T>::resize(int newsize, T def){
    reserve(newsize);
    for(int i = sz; i<newsize; i++) elem[i]=0;
    sz=newsize;
}
template<typename T>void vector<T>::push_back(int d){
    if(space==0) reserve(8);
    else if (sz==space) reserve(2*space);
    elem[sz]=d;
    sz++;
}
template<typename T>vector<T> &vector<T>::operator=(const vector &a){
    if(this==&a) return *this;
    if(a.sz<=space){
        for(int i = 0; i<a.sz; i++){
            elem[i] = a.elem[i];
        }
        sz=a.sz;
        return *this;
    }
    int *p = new int[a.sz];
    for(int i = 0; i<a.sz; i++){
        p[i]=a.elem[i];
    }
    delete[] elem;
    space=sz=a.sz;
    elem=p;
    return *this;
}
std::unique_ptr<vector<int>> make_vec(){
    std::unique_ptr<vector<int>>p{new vector<int>};
    // process the vector
    return p;
}
int main(){
    vector<int> vi;
}
