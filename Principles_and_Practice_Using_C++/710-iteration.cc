#include <list>
#include <iostream>
#include <vector>
#include <algorithm>
class Text_iterator{
    std::list<std::vector<char>>::iterator ln;
    std::vector<char>::iterator pos;
public:
    Text_iterator(std::list<std::vector<char>>::iterator ll, std::vector<char>::iterator pp):ln{ll}, pos{pp}{}
    char &operator*(){return *pos;}
    Text_iterator &operator++();
    bool operator==(const Text_iterator &other) const{return ln==other.ln&&pos==other.pos;}
    bool operator!=(const Text_iterator &other) const{return !(*this==other);}
};
Text_iterator &Text_iterator::operator++(){
    pos++;
    if(pos==(*ln).end()){
        ln++;
        pos=(*ln).begin();
    }
    return *this;
}
struct Document {
    std::list<std::vector<char>> line;
    Text_iterator begin(){return Text_iterator(line.begin(),(*line.begin()).begin());}
    Text_iterator end(){
        auto last = line.end();
        --last;
        return Text_iterator(last,(*last).end());
    }
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
void print(Document &d){
    for(auto p:d) std::cout<<p;
}
void erase_line(Document &d, int n){
    if(n<0||d.line.size()-1<=n) return;
    auto p = d.line.begin();
    advance(p,n);
    d.line.erase(p);
}
template<typename Iter> void advance(Iter &p, int n){
    while(0<n){++p; --n;}
}
Text_iterator find_txt(Text_iterator first, Text_iterator last, const std::string &s){
    if(s.size()==0) return last;
    char first_char=s[0];
    while(true){
	auto p = std::find(first,last,first_char);
	if(p==last||match(p,last,s)) return p;
	first = ++p;
    }
}
