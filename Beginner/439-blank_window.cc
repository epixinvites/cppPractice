#include "PPP2code/Simple_window.h"
#include "PPP2code/Graph.h"
int main(){
    Point tl{100,100};
    Simple_window win {tl,600,500,"Canvas"};
    win.wait_for_button();
}
