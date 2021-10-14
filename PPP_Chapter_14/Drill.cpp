//main.cpp
// Programming: Principles and Practices using c++ - Bjarne Stroustrup
// 
// Chapter 14 Drill and Exercise solutions

/*

*/

// header files for later GUI use
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include <math.h>
#include "tools.h"

using namespace Graph_lib;

void f(B2& b) { b.pvf(); }

int main()
try
{
	// Drill
	/*
		1. Define a class B1 with a virtual function vf() and a non-virtual function f().
		Define both of these functions within class B1. Implement each function
		to output its name (e.g., B1::vf()). Make the functions public. Make a B1
		object and call each function.
	*/
	/*std::cout << "Drill 1:" << '\n';
	B1 b;
	b.vf();
	b.f();
	std::cout << '\n';*/

	// 2. Derive a class D1 from B1 and override vf(). Make a D1 object and call vf()
	// and f() for it.


	/*std::cout << "Drill 2:" << '\n';
	D1 d;
	d.vf();
	d.f();
	std::cout << '\n';*/

	// 3. Define a reference to B1 (a B1&) and initialize that to the D1 object you
	// just defined.Call vf() and f() for that reference.

	/*std::cout << "Drill 3:" << '\n';
	B1& r{ d };
	r.vf();
	r.f();
	std::cout << '\n';*/

	// 4. Now define a function called f() for D1and repeat 1–3.Explain the results.
	// Step 1

	// 6. Define a class D2 derived from D1 and override pvf() in D2.Make an
	// object of class D2 and invoke f(), vf(), and pvf() for it.

	D21 dd21;

	D22 dd22b;	
	
	f(dd22b);
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}
