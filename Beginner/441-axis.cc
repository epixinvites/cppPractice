#include "PPP2code/Simple_window.h"
#include "PPP2code/Graph.h"
int main(){
    Simple_window win {Point{100,100},600,400,"Canvas"};
    Axis xa{Axis::x,Point{20,300},280,10,"x axis"};
    Axis ya{Axis::y,Point{20,300},280,10,"y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(xa);
    win.attach(ya);
    win.set_label("Canvas #2");
    win.wait_for_button();
}
