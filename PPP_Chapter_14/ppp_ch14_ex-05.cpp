//main.cpp
// Programming: Principles and Practices using c++ - Bjarne Stroustrup
// 
// Chapter 14 Drill and Exercise solutions

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include <math.h>
#include "tools.h"

using namespace Graph_lib;

int main()
try
{
    Point tl{ 200,200 };
    Simple_window win{ tl,1600,1000,"Chapter 14 Ex 05" };

    //Striped_rectangle sr1{ Point{100,100},200,50, 2 };
    Striped_rectangle srec1{ Point{100,100},300,100 };
    srec1.set_stripes_color(Color::blue);
    win.attach(srec1);
    win.wait_for_button();
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}
