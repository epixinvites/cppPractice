#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <algorithm>
int main(){
    std::ostream_iterator<std::string> oo {std::cout};
    *oo = "Hello, ";
    ++oo;
    *oo = "world!\n";

    std::istringstream str("1 2 3");
    std::istream_iterator<int> ii {str};
    std::istream_iterator<int> eos {};

    std::vector<int> vi{ii, eos};
    std::ostream_iterator<int> out {std::cout};
    std::copy(vi.begin(), vi.end(), out);
}
