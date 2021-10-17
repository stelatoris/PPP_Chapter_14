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

vector<Point>v_intrsct;	// to store intersection points

void find2(Closed_polyline& cp, Simple_window& win)
{
	//----------------------------------------------------
	int stripe_num{ 10 };
	
	int x_max{ cp.point(0).x };
	int y_max{ cp.point(0).x };
	int x_min{ cp.point(0).y };
	int y_min{ cp.point(0).y };

	// find the boundary of the Closed_polygon
	for (int i = 0; i < cp.number_of_points(); ++i) {
		if (cp.point(i).x > x_max) x_max = cp.point(i).x;
		if (cp.point(i).x < x_min) x_min = cp.point(i).x;
		if (cp.point(i).y > y_max) y_max = cp.point(i).y;
		if (cp.point(i).y < y_min) y_min = cp.point(i).y;
	}

	int x_diff = x_max - x_min;	
	int x_gap = x_diff / stripe_num;

	// draw lines within boundaries
	Lines l;
	for (int i = x_min; i < x_max; i += x_gap) {
		l.add(Point{ i,y_min }, Point{ i,y_max });
	}	

	int x1 = l.point(0).x;

	// find intersecting points along x till x_max with a gap of (x_diff / 10)		
	for (int i = 0; i < l.number_of_points(); i += 2) {	// verticle lines
		// b1=y1-m.x1
		// b2=y2-m.x2
	
		for (int ii = 1; ii <= cp.number_of_points(); ++ii) {	// polygon lines
			float slope2, intercept2;
			int xx1, yy1, xx2, yy2;
			float dx2, dy2;

			if (ii == cp.number_of_points()) {
				xx1 = cp.point(ii-1).x;
				yy1 = cp.point(ii-1).y;
				xx2 = cp.point(0).x;
				yy2 = cp.point(0).y;
			}

			else {
				xx1 = cp.point(ii - 1).x;
				yy1 = cp.point(ii - 1).y;
				xx2 = cp.point(ii).x;
				yy2 = cp.point(ii).y;
			}			
			
			dx2 = xx2 - xx1;
			dy2 = yy2 - yy1;

			if (dx2 == 0) {
				break;
			}

			slope2 = dy2 / dx2;
			// y = mx + c
			// intercept c = y - mx
			intercept2 = yy1 - slope2 * xx1;

			bool horizontal{ false };	// intersecting with horizontal line
			if (dy2 == 0) { horizontal = true; }

			bool out_of_line{ false };	// point is outside of line connecting 2 points
			if ((x1 >= xx2 && x1 >= xx1)|| (x1 <= xx2 && x1 <= xx1)) { out_of_line = true; }

			Point p;	// intersection point
			
			if (horizontal && !out_of_line) {
				p.x = x1;
				p.y = yy1;				
			}
			else if (!horizontal && !out_of_line) {
				p.x = x1;
				p.y = (slope2 * x1) + intercept2;
			}			

			if (!out_of_line) {
				v_intrsct.push_back(p);
				Mark m{ p,'x' };
				win.attach(m);
				win.wait_for_button();
			}						
		}
		x1 += x_gap;
	}

	Lines stripes;
	for (int i = 1; i < v_intrsct.size(); i+=2) {
		stripes.add(v_intrsct[i - 1], v_intrsct[i]);
	}

	win.attach(stripes);
	win.wait_for_button();
}


int main()
try
{
    Point tl{ 200,200 };
    Simple_window win{ tl,1600,1000,"Chapter 14 Ex 07" };

	Closed_polyline poly1;
	poly1.add(Point{ 200,250 });	
	poly1.add(Point{ 300,375 });
	poly1.add(Point{ 400,200 });
	poly1.add(Point{ 350,150 });
	poly1.add(Point{ 300,150 });
	poly1.set_color(Color::black);

	win.attach(poly1);
	win.wait_for_button();

	find2(poly1, win);
	//find_stripe_point(poly1, win);
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}
