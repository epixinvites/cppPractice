#include "PPP2code/Simple_window.h"
#include "PPP2code/Graph.h"
int main(){
    Simple_window win{Point{0,0},600,400,"Canvas"};
    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    win.attach(poly);
    win.wait_for_button();
}