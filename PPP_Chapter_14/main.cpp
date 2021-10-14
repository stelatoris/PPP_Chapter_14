//main.cpp
// Programming: Principles and Practices using c++ - Bjarne Stroustrup
// 
// Chapter 14 Drill and Exercise solutions

// header files for later GUI use
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
    Graph_lib::Smiley sm1{ Point {400,400}, 200 };
    
    win.attach(sm1);

    //Graph_lib::Arc m{ Point{500,500},int(100 * 1.5),int(100 * 1.5),200,340 };
    
    //win.attach(m);
    win.wait_for_button();
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}
