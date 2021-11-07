#include <string>
std::string compose(const std::string &name, const std::string &domain){
    return name + '@' + domain;
}
int main(){
    auto addr = compose("dmr", "bell-labs.com");

    std::string name = "Neil Stroustup";
    std::string name_substr = name.substr(6, 10);
}
