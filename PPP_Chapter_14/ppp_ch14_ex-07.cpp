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

int main()
try
{
    Point tl{ 200,200 };
    Simple_window win{ tl,1600,1000,"Chapter 14 Ex 07" };

	Striped_closed_polyline sp1;
	sp1.add(Point{ 200,250 });
	sp1.add(Point{ 300,375 });
	sp1.add(Point{ 900,200 });
	sp1.add(Point{ 350,150 });
	sp1.add(Point{ 300,150 });

	win.attach(sp1);
	win.wait_for_button();

	sp1.move(400,400);
	win.attach(sp1);
	win.wait_for_button();
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}
