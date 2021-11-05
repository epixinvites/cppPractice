#include <vector>

template<typename T> class Less_than{
    const T val;
public:
    Less_than(const T &v):val{v}{}
    bool operator()(const T &x) const {return x<val;}
};

template<typename C, typename P> int count(const C& c, P pred){
    int cnt = 0;
    for(const auto &x:c){
        if(pred(x)){
            ++cnt;
        }
    }
    return cnt;
}

int main(){
    Less_than lti{42};
    bool result = lti(3); // true, 3<42

    std::vector<int> vi = {1, 7, 11, 30, 198};
    int smaller_count = count(vi, Less_than{23});
}
