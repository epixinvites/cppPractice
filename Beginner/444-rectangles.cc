#include "PPP2code/Simple_window.h"
#include "PPP2code/Graph.h"
int main(){
    Simple_window win{Point{0,0},600,400,"Canvas"};
    Rectangle r{Point{200,200},100,50};
    win.attach(r);
    win.wait_for_button();
}
