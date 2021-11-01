class Vector{
    int *elem;
    int sz;
public:
    Vector(int s):elem{new int[s]}, sz{s}{
        for(int i = 0; i!=s; i++){
            elem[i]=0;
        }
    }
    ~Vector(){delete[] elem;}
    int &operator[](int i);
    int size() const;
};

void fct(int n){
    Vector v(n);
    {
        Vector v2(2*n);
    } // v2 is destroyed
} // v is destroyed
