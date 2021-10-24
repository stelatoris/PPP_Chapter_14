//main.cpp
// Programming: Principles and Practices using c++ - Bjarne Stroustrup
// 
// Chapter 14 Drill and Exercise solutions

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include <math.h>
#include "tools.h"
using namespace std;

using namespace Graph_lib;

void test_reg_octagon(Regular_octagon& r, Simple_window& win)
{
    r.move(600,200);
    win.attach(r);
    win.wait_for_button();

    r.set_color(Color::blue);
    win.attach(r);
    win.wait_for_button();

    r.set_style(Line_style::dash);
    win.attach(r);
    win.wait_for_button();

    r.set_fill_color(Color::yellow);
    win.attach(r);
    win.wait_for_button();
}

int main()
try
{
    Point tl{ 200,200 };
    Simple_window win{ tl,1600,1000,"Chapter 14 Ex 08" };

    Binary_tree bt1{ Point {200,200},3 };
    bt1.set_color(Color::red);
    win.attach(bt1);
    win.wait_for_button();


}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}
