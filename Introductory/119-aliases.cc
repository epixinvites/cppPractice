#include <vector>
template <typename C> using Value_type = typename C::value_type;

template<typename Container> void algo(Container &c){
    std::vector<Value_type<Container>> vec;
}
