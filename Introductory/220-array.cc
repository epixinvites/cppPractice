#include <algorithm>
#include <array>
void f(int *p, int sz);
int main(){
    std::array<int, 3> a1 = {1, 2, 3};
    f(&a1[0], a1.size());

    auto p = std::find(a1.begin(), a1.end(), 3);
}
