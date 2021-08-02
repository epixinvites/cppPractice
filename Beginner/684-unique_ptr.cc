#include <memory>
template<typename T> class vector {
    int sz;
    int *elem;
    int space;
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
    int *p = new int[newalloc];
    for(int i = 0; i<sz; i++) p[i]=elem[i];
    delete[] elem;
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
int main(){}
