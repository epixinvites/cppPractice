//5.6.1 Bad Arguements P168
#include <iostream>
using namespace std;

class Bad_Area{};

int area(int length, int width){
    if(length<=0||width<=0){
        throw Bad_Area{};
    }
    return length*width;
}

int main(){
    try{
        int x = 10, y = 15, z = -23;
        int area1 = area(x,y);
        int area2 = area(y,z);
    }
    catch (Bad_Area){
        cout<<"Bad Arguements Detected."<<endl;
    }
}
