#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
class Message{
    std::vector<std::string>::const_iterator first;
    std::vector<std::string>::const_iterator last;
public:
    Message(std::vector<std::string>::const_iterator p1, std::vector<std::string>::const_iterator p2):first{p1},last{p2}{}
    std::vector<std::string>::const_iterator begin() const {return first;}
    std::vector<std::string>::const_iterator end() const {return last;}
};
struct Mail_file{
    std::string name;
    std::vector<std::string> lines;
    std::vector<Message> m;
    Mail_file(const std::string &n);
    std::vector<Message>::const_iterator begin() const {return m.begin();}
    std::vector<Message>::const_iterator end() const {return m.end();}
};
Mail_file::Mail_file(const std::string &n){
    std::ifstream in{n};
    if(!in){
	std::cerr<<n<<" not found"<<std::endl;
	std::exit(1);
    }
    for(std::string s; std::getline(in,s);){
	lines.push_back(s);
    }
    auto first = lines.begin();
    for(auto p = lines.begin(); p!=lines.end(); ++p){
	if(*p=="––––"){
	    m.push_back(Message(first,p));
	    first=p+1;
	}
    }
}
int is_prefix(const std::string &s, const std::string &p){
    int n = p.size();
    if(std::string(s,0,n)==p) return n;
    return 0;
}
bool find_from_addr(const Message *m, std::string &s){
    for(const auto &x:*m){
	if(int n = is_prefix(x, "From: ")){
	    s=std::string(x,n);
	    return true;
	}
    }
    return false;
}
std::string find_subject(const Message *m){
    for(const auto &x:*m){
	if(int n = is_prefix(x, "Subject: ")) return std::string(x,n);
    }
    return "";
}
int main(){
    Mail_file mfile{"mail_file.txt"};
    std::multimap<std::string, const Message*> sender;
    for(const auto &m:mfile){
	std::string s;
	if(find_from_addr(&m,s)){
	    sender.insert(make_pair(s,&m));
	}
    }
    auto pp = sender.equal_range("The Wayfarrer <epixunknown@protonmail.com>");
    for(auto p  = pp.first; p!=pp.second; p++){
	std::cout<<find_subject(p->second)<<std::endl;
    }
}
