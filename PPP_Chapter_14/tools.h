// tools.h
// Programming: Principles and Practices using c++ - Bjarne Stroustrup
// 
// Chapter 14 Drill and Exercise solutions

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

	//--------------------------------------------------------------------------------
	//1. Define two classes Smiley and Frowny, which are both derived from class
	//	Circleand have two eyesand a mouth.Next, derive classes from Smiley
	//	and Frowny which add an appropriate hat to each.

	struct Smiley : Circle {
	
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
	//--------

	struct Frowny : Circle {

		Frowny(Point p, int rr);
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
	//--------

	struct Smiley_hat :Smiley {
		Smiley_hat(Point p, int rr);
		void draw_lines() const;		

	private:
		Polygon h;	// pointy hat
		void position_hat();
	};
	//--------

	struct Frowny_hat :Frowny {
		Frowny_hat(Point p, int rr);
		void draw_lines() const;

	private:
		Polygon h;	// pointy hat
		void position_hat();
	};
	
	//--------------------------------------------------------------------------------
	//4. Define a class Immobile_Circle, which is just like Circle but can’t be moved.

	struct Immobile_Circle :Circle {
		using Circle::Circle;

		void move(int dx, int dy) {}		
	};

	//--------------------------------------------------------------------------------
	/*5.Define a Striped_rectangle where instead of fill, the rectangle is “filled”
		by drawing one - pixel - wide horizontal lines across the inside of the rectangle
		(say, draw every second line like that).You may have to play with the
		width of lines and the line spacing to get a pattern you like.
	*/	
	struct Striped_rectangle : Rectangle {
		Striped_rectangle(Point p, int w, int h);
		void draw_lines() const;
		void set_stripes_color(Color c);

	private:
		Lines stripes;		
	};

	//--------------------------------------------------------------------------------
	// 6. Define a Striped_circle using the technique from Striped_rectangle.
	
	struct Striped_circle : Circle {
		Striped_circle(Point p, int r);
		void draw_lines() const;
		void set_stripes_color(Color c);

	private:
		Lines stripes;
		void stripe_points();
	};

	//------------------------------------------------------------------------------
	//7. Define a Striped_closed_polyline using the technique from Striped_
	//   rectangle(this requires some algorithmic inventiveness).

	struct Striped_closed_polyline : Closed_polyline {
		void draw_lines() const;
		void set_stripes_color(Color c);	
	};

	//------------------------------------------------------------------------------
	// 8. Define a class Octagon to be a regular octagon.Write a test that exercises
	// all of its functions(as defined by you or inherited from Shape).

	struct Regular_octagon :Closed_polyline {

		Regular_octagon(Point p, int distance);
		void draw_lines() const;
		int get_width() const { return d; }
		int get_height() const { return point(0).y - point(2).y; }  // get top left point y distance

	private:
		int d;      // distance from center
		Point c;    // center point		
		void find_points();
	};	

}	// end of namespace Graph_lib