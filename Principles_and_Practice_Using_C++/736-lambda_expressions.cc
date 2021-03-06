#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
struct Record{
    std::string name;
    char addr[24];
};
// lambda functions are on-the-spot functions
// [] is the lambda declaration
int main(){
    std::vector<Record> vr;
    std::sort(vr.begin(),vr.end(),[](const Record &a, const Record &b){return a.name<b.name;});
    std::sort(vr.begin(),vr.end(),[](const Record &a, const Record &b){return std::strncmp(a.addr,b.addr,24)<0;});
}
