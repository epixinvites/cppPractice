#include <string>
#include <tuple>
int main(){
    std::pair<int, int> p1 = std::make_pair(0, 0);

    std::tuple<std::string, int, double> t1 {"abc", 123, 3.14};
    auto t2 = std::make_tuple(std::string{"abc"}, 123, 3.14);
    std::tuple t3 {"abc", 123, 3.14};

    std::string s = std::get<0>(t1);
    int x = std::get<1>(t2);
    double d = std::get<2>(t3);

    auto s1 = std::get<std::string>(t1);
    auto x1 = std::get<int>(t2);
    auto d1 = std::get<double>(t3);

    std::get<std::string>(t1) = "ABC";
}
