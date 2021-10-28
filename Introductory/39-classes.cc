class Vector{
    int *elem;
    int sz;
public:
    Vector(int s):elem{new int[s]}, sz{s}{}
    int &operator[](int i){return elem[i];}
    int size(){return sz;}
};

int main(){
    Vector v(6);
}
