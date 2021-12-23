template <typename T, int N>struct array{
    T elems[N];
    T *begin(){return elems;}
    const T *begin() const{return elems;}
    T *end(){return elems+N;}
    const T *end()const{return elems+N;}
    unsigned int size() const;
    T &operator[](int n){return elems[n];}
    const T &operator[](int n)const{return elems[n];}
    const T &at(int n)const;
    T &at(int n);
    T *data(){return elems;}
    const T *data()const{return elems;}
};
