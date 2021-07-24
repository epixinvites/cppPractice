#include "PPP2code/Simple_window.h"
#include "PPP2code/Graph.h"
int main(){
    Simple_window win{Point{0,0},x_max(),y_max(),"Canvas"};
    Image ii{Point{0,0},"Images/linus.jpg"};
    win.attach(ii);
    win.wait_for_button();
}

