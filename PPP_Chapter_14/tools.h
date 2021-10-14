// tools.h
// Programming: Principles and Practices using c++ - Bjarne Stroustrup
// 
// Chapter 14 Drill and Exercise solutions

#include "Graph.h"
#include "std_lib_facilities.h"
#define PI 3.14159265

using namespace Graph_lib;

namespace Graph_lib {	

}

//------------------------------------------------------------------------------------------
// Drill
/*
	1. Define a class B1 with a virtual function vf() and a non-virtual function f().
	Define both of these functions within class B1. Implement each function
	to output its name (e.g., B1::vf()). Make the functions public. Make a B1
	object and call each function.


// 5. Add a pure virtual function called pvf() to B1 and try to repeat 1–4. Explain
// the result.
*/

class B1 {
public:
	virtual void vf() const { std::cout << "B1::vf()" << '\n'; }
	void f() const { std::cout << "B1::f()" << '\n'; }
	virtual void pvf() = 0;		// pure virtual function for Drill 5
};

// 2. Derive a class D1 from B1 and override vf(). Make a D1 object and call vf()
// and f() for it.
// 4. Now define a function called f() for D1 and repeat 1–3. Explain the results.

class D1 :public B1 {
public:
	void vf() const override { std::cout << "D1::vf()" << '\n'; }
	void f() const { std::cout << "D1::f()" << '\n'; }	// defined at Drill 4.
	
};

// 6. Define a class D2 derived from D1 and override pvf() in D2.Make an
// object of class D2 and invoke f(), vf(), and pvf() for it.

class D2 : public D1 {
public:
	void pvf() override { std::cout << "D2::pvf()" << '\n'; }
};

//	7. Define a class B2 with a pure virtual function pvf().Define a class D21
//	with a string data member and a member function that overrides pvf();
//	D21::pvf() should output the value of the string. Define a class D22 that
//	is just like D21 except that its data member is an int.Define a function f()
//	that takes a B2& argument and calls pvf() for its argument.Call f() with a
//	D21 and a D22.

class B2 {
public:
	virtual void pvf() = 0;
};

class D21 : public B2 {
public:
	void pvf() override { std::cout << s << '\n'; }
private:
	string s{"D21::pvf()"};
};

struct D22 :public B2 {
	void pvf() override { std::cout << n << '\n'; }	
private:
	int n{ 100 };
};



//------------------------------------------------------------------------------------------

