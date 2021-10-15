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
    Simple_window win{ tl,1600,1000,"Chapter 14 Ex 01" };

    Graph_lib::Frowny_hat fh1{ Point {400,400}, 100 };
    win.attach(fh1);

    Graph_lib::Smiley_hat sh1{ Point{800,400},100 };
    win.attach(sh1);

    win.wait_for_button();
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}
