#include "std_lib_facilities.h"
using namespace std;
struct Link{
    string value;
    Link* prev;
    Link* succ;
    Link(const string &v, Link *p = nullptr, Link *s = nullptr):value{v},prev{p},succ{s}{}
};
Link *insert(Link *p, Link *n){
    if(n==nullptr) return p;
    if(p==nullptr) return n;
    n->succ=p;
    if(p->prev) p->prev->succ = n;
    n->prev=p->prev;
    p->prev=n;
    return n;
}
Link *erase(Link *p){
    if(p==nullptr) return nullptr;
    if(p->succ) p->succ->prev = p->prev;
    if(p->prev) p->prev->succ = p->succ;
    return p->succ;
}
Link *find(Link *p, const string &s){
    while(p){
        if(p->value==s) return p;
        p = p->succ;
    }
    return nullptr;
}
Link *advance(Link *p, int n){
    if(p==nullptr) return nullptr;
    if(0<n){
        while(n--){
            if(p->succ==nullptr) return nullptr;
            p=p->succ;
        }
    }
    else if(n<0){
        while(n++){
            if(p->prev==nullptr) return nullptr;
            p=p->prev;
        }
    }
    return p;
}
void print_all(Link *p){
    cout<<"{";
    while (p) {
      cout << p->value;
      if (p = p->succ)
        cout << ",";
    }
    cout << "}";
}
int main(){
    Link* norse_gods = new Link("Thor");
    norse_gods=insert(norse_gods, new Link{"Odin"});
    norse_gods=insert(norse_gods, new Link{"Freia"});
    print_all(norse_gods);
}
