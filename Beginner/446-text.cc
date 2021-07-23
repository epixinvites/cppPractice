#include "PPP2code/Simple_window.h"
#include "PPP2code/Graph.h"
int main(){
    Simple_window win{Point{0,0},600,400,"Canvas"};
    Text t(Point{150,150},"Hello world!");
    win.attach(t);
    win.wait_for_button();
}
