#include "std_lib_facilities.h"
using namespace std;
constexpr int xscale = 6;
constexpr int yscale = 5;
struct Point{
    int x, y;
};
constexpr Point scale(Point p){
    return {xscale*p.x,yscale*p.y};
};
void user(){
    constexpr Point p1 {10,10};
    constexpr Point actual = scale(p1);
}
