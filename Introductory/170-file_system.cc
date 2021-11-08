#include <filesystem>
#include <cassert>
int main(){
    std::filesystem::path f = "dir/hypothetical.cc";
    assert(std::filesystem::exists(f)); // path f must exist
}
