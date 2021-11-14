#include <bitset>
#include <iostream>
void binary(int i){
    std::bitset<8*sizeof(int)> b = i;
    std::cout<<b.to_string()<<std::endl;
}
int main(){
    std::bitset<9> bs1 {"110001111"};
    std::bitset<9> bs2 {0b1'1000'1111};

    std::bitset<bs1.size()> bs3 = ~bs1; // 001110000
    std::bitset<bs1.size()> bs4 = bs1 & bs3; // 000000000
    std::bitset<bs1.size()> bs5 = bs1<<2; // 000111100

}
