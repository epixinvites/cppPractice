#include <list>
#include <iostream>
#include <vector>
struct Document {
    std::list<std::vector<char>> line;
    Document() { line.push_back(std::vector<char>{}); }
};
std::istream &operator>>(std::istream is, Document &d){
    for(char ch; is.get(ch);){
        d.line.back().push_back(ch);
        if(ch=='\n'){
            d.line.push_back(std::vector<char>{});
        }
    }
    if(d.line.back().size()) d.line.push_back(std::vector<char>{});
    return is;
}