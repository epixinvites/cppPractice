template<typename T, int N> struct Buffer{
    using value_type = T;
    T *elem = new T[N];
    constexpr int size() {return N;}
};

int main(){
    Buffer<char, 1024> glob;
    int size_of_glob = glob.size();
}
