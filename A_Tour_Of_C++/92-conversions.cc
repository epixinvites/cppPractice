class Vector{
    int *elem;
    int sz;
public:
    explicit Vector(int s):elem{new int[s]}, sz{s}{}
    int &operator[](int i){return elem[i];}
    int size(){return sz;}
};

int main(){
    Vector v1(7); // Allowed
    // Vector v2 = 7; Error: Cannot convert int to Vector
}
