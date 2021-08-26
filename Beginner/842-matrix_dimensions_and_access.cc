#include "PPP2code/Matrix.h"
#include <iostream>
void f(int n1, int n2, int n3){
    Numeric_lib::Matrix<double,1> ad1(n1); // double elements with one dimension
    Numeric_lib::Matrix<int,2> ai1(n1,n2); // int elements with two dimensions
    Numeric_lib::Matrix<int,3> ai2(n1,n2,n3);
    ai1(0,0)=10;
    ai2(0,0,0)=20;
    std::cout<<ai1(0,0)<<std::endl<<ai2(0,0,0)<<std::endl;
}
int main(){
    f(10,10,10);
}
