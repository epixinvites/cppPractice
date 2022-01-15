class complex{
    double re, im;
public:
    complex(double r, double i):re{r}, im{i}{}
    complex(double r):re{r}, im{0}{}
    complex():re{0}, im{0}{}
    double real() const {return re;}
    void real(double d) {re=d;}
    double imag() const {return im;}
    void imag(double d) {im=d;}

    complex &operator+=(complex z){
        re+=z.re;
        im+=z.im;
        return *this;
    }

    complex &operator-=(complex z){
        re-=z.re;
        im-=z.im;
        return *this;
    }

    complex &operator*=(complex);

    complex &operator/=(complex);
};

complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; }
complex operator*(complex a, complex b) { return a *= b; }
complex operator/(complex a, complex b) { return a /= b; }

bool operator==(complex a, complex b){
    return a.real()==b.real() && a.imag()==b.imag();
}

bool operator!=(complex a, complex b){
    return !(a==b);
}

void f(complex z){
    complex a {2.3};
    complex b {1/a};
    complex c {a+z*complex{1,2.3}};
    if(c!=b){
        c=-(b/a)+a*b;
    }
}

int main(){
    complex z = {1,0};
    const complex cz {1,3};
    z=cz;
    // cz=z; not ok, cz is a const
    double x=z.real();
}
