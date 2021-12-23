#include "PPP2code/Simple_window.h"
#include "PPP2code/Graph.h"
int main(){
    Simple_window win{Point{100,100},600,400,"Canvas"};
    Function sine{sin,0,100,Point{0,150},1000,50,50};
    win.attach(sine);
    win.wait_for_button();
}
