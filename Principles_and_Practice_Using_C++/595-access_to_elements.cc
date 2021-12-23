#include <iostream>
using namespace std;
class vector{
    int sz;
    int *elem;
public:
    vector(int s):sz{s},elem{new int[s]}{
        for(int i = 0; i<s; i++){
            elem[i]=0;
        }
    }
    ~vector(){delete[] elem;}
    int size()const{return sz;}
    int get(int n)const{return elem[n];}
    void set(int n, int v){elem[n]=v;}
};
vector* fill(int s){
    vector* p = new vector(s);
    for(int i = 0; i<s; i++){
        p->set(i,0);
    }
    return p;
}
void ff(){
    vector *q=fill(5);
    // use *q
    delete q;
}
int main(){
    vector *v = new vector(5);
    for(int i=0; i<v->size(); i++){
        v->set(i,i*2);
    }
    cout<<v->get(3)<<endl;
}
