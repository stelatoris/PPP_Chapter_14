// tools.h
// Programming: Principles and Practices using c++ - Bjarne Stroustrup
// 
// Chapter 14 Drill and Exercise solutions

#include "Graph.h"
#include "std_lib_facilities.h"
#define PI 3.14159265

using namespace Graph_lib;

namespace Graph_lib {

	struct Arc :Shape {
		Arc(Point p, int w, int h, int b, int e);

		void draw_lines() const;

	private:
		int width;
		int height;
		int begin;  // beginning of angle to be drawn
		int end;    // end of angle to be drawn
	};

	//1. Define two classes Smiley and Frowny, which are both derived from class
	//	Circleand have two eyesand a mouth.Next, derive classes from Smiley
	//	and Frowny which add an appropriate hat to each.

	class Smiley :public Circle {
	public:
		Smiley(Point p, int rr);
		void draw_lines() const;
		void set_eye_size(int r) {
			l_eye.set_radius(r);
			r_eye.set_radius(r);
		}

	private:
		Circle r_eye;
		Circle l_eye;
		Arc m;	// mouth
		int r;	// head radius
	};

}	// end of namespace Graph_lib