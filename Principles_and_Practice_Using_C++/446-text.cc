#include "PPP2code/Simple_window.h"
#include "PPP2code/Graph.h"
int main(){
    Simple_window win{Point{0,0},600,400,"Canvas"};
    Text t(Point{150,150},"Hello world!");
    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.attach(t);
    win.wait_for_button();
}
