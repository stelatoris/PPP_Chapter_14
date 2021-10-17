// tools.cpp
// Programming: Principles and Practices using c++ - Bjarne Stroustrup
// 
// Chapter 14 Drill and Exercise solutions

#include "Simple_window.h"
#include "tools.h"
#include <math.h>
using namespace std;

using namespace Graph_lib;

Arc::Arc(Point p, int w, int h, int b, int e)
    : width{ w }, height{ h }, begin{ b }, end{ e }
{
    add(Point{ p.x - width,p.y - height });
}

void Arc::draw_lines() const
{
    if (color().visibility())
        fl_arc(point(0).x, point(0).y, width, height, begin, end);
}

//----------------------------------------------------------------------
// Exercise 01

Smiley::Smiley(Point p, int rr) :
	Circle	{ p,rr },
	r		{ rr },
	r_eye	{ Point{p.x - rr / 3, p.y - rr / 3}, rr / 4 },
	l_eye	{ Point{p.x + rr / 3, p.y - rr / 3}, rr / 4 },
	m		{ Point{int(p.x+rr*0.5),int(p.y+rr*0.65)},(rr),(rr),200,340 }
{
	add(p);
}

void Smiley::draw_lines() const
{
	Circle::draw_lines();
	r_eye.draw_lines();
	l_eye.draw_lines();
	m.draw_lines();
}

//--------
Frowny::Frowny(Point p, int rr) :
	Circle{ p,rr },
	r{ rr },
	r_eye{ Point{p.x - rr / 3, p.y - rr / 3}, rr / 4 },
	l_eye{ Point{p.x + rr / 3, p.y - rr / 3}, rr / 4 },
	m{ Point{int(p.x + rr * 0.5),int(p.y + rr * 1.3)},(rr),(rr),20,160 }
{
	add(p);
}

void Frowny::draw_lines() const
{
	Circle::draw_lines();
	r_eye.draw_lines();
	l_eye.draw_lines();
	m.draw_lines();
}

//--------
Smiley_hat::Smiley_hat(Point p, int rr) :
	Smiley{p,rr}	
{
	add(p);
	position_hat();
}

void Smiley_hat::draw_lines() const
{
	Circle::draw_lines();
	Smiley::draw_lines();
	h.draw_lines();
}

void Smiley_hat::position_hat()
{
	Point p1;	// right
	p1.x = Circle::center().x + (Circle::radius() * sin(45 * (PI / 180)));
	p1.y = Circle::center().y - (Circle::radius() * cos(45 * (PI / 180)));

	Point p2;	// left
	p2.x = Circle::center().x + (Circle::radius() * sin(315 * (PI / 180)));
	p2.y = Circle::center().y - (Circle::radius() * cos(315 * (PI / 180)));

	Point p3;	// tip
	p3.x = Circle::center().x;
	p3.y = Circle::center().y - Circle::radius() * 3;

	h.add(p1);
	h.add(p2);
	h.add(p3);
}

//--------

Frowny_hat::Frowny_hat(Point p, int rr) :
	Frowny{ p,rr }
{
	add(p);
	position_hat();
}

void Frowny_hat::draw_lines() const
{
	Circle::draw_lines();
	Frowny::draw_lines();
	h.draw_lines();
}

void Frowny_hat::position_hat()
{
	Point p1;	// bottom right
	p1.x = Circle::center().x + (Circle::radius() * sin(45 * (PI / 180)));
	p1.y = Circle::center().y - (Circle::radius() * cos(45 * (PI / 180)));

	Point p2;	// bottom left
	p2.x = Circle::center().x + (Circle::radius() * sin(315 * (PI / 180)));
	p2.y = Circle::center().y - (Circle::radius() * cos(315 * (PI / 180)));

	Point p3;	// top left
	p3.x = Circle::center().x + (Circle::radius() * sin(315 * (PI / 180))) + (Circle::radius() / 2);
	p3.y = Circle::center().y - (Circle::radius() * cos(315 * (PI / 180))) - (Circle::radius() / 2);

	Point p4;	// bottom right
	p4.x = Circle::center().x + (Circle::radius() * sin(45 * (PI / 180))) - (Circle::radius() / 2);
	p4.y = Circle::center().y - (Circle::radius() * cos(45 * (PI / 180))) - (Circle::radius() / 2);

	h.add(p1);
	h.add(p2);
	h.add(p3);
	h.add(p4);
}

//------------------------------------------------------------------------------
// Exercise 05

Striped_rectangle::Striped_rectangle(Point p, int w, int h) :
	Rectangle{ p ,w ,h }
{
	add(p);
	for (int i = 0; i < w; i += 10) {
		stripes.add(Point{ 5+ p.x + i,p.y }, Point{5+ p.x + i,p.y + h });
	}
	set_stripes_color(Color::black);
}

void Striped_rectangle::set_stripes_color(Color c)
{
	stripes.set_style(Line_style(Line_style::solid,4));
	stripes.set_color(c);
}

void Striped_rectangle::draw_lines() const
{
	stripes.draw();
	Rectangle::draw_lines();
}

//------------------------------------------------------------------------------
// Exercise 06

Striped_circle::Striped_circle(Point p, int r) :
	Circle{ p,r }
{
	add(p);
	stripe_points();
	set_stripes_color(Color::blue);
}

void Striped_circle::stripe_points()
{
	int n = 10;	// number of stripes

	for (int i = 0; i <= Circle::radius() * 2; i += (Circle::radius() * 2 / n)) {
		//cos(R)=x/r
		//sin(R)=y/r

		int w = Circle::radius() - i;	//width as in x in cos(R)=x/r
		double cos_rad{ 0.0 };
		cos_rad = double(w) / Circle::radius();	
		double rad{ 0.0 };
		rad = asin(cos_rad);	// find Radian to use to find Y point

		Point m1;	//Upper end of line on circle
		m1.x = Circle::center().x - Circle::radius() + i;
		m1.y = Circle::center().y - (Circle::radius() * cos(rad));

		Point m2;	//Bottom end of line on circle
		m2.x = m1.x;
		m2.y = Circle::center().y + (Circle::radius() * cos(rad));
		
		stripes.add(m1, m2);		
	}
}

void Striped_circle::set_stripes_color(Color c)
{
	stripes.set_style(Line_style(Line_style::solid, 4));
	stripes.set_color(c);
}

void Striped_circle::draw_lines() const
{
	stripes.draw();
	Circle::draw_lines();
}

//------------------------------------------------------------------------------
// Exercise 07

void Striped_closed_polyline::draw_lines() const
{
	Closed_polyline::draw_lines();
	find_stripe_point();
}

void Striped_closed_polyline::find_stripe_point() const
{
	// find the boundary of the Closed_polygon
	// then draw stripes in that boundary
	// find all intersection points between stripes and polygon
	// use those points to add points to Lines stripes

	
	
	//----------------------------------------------------
	int x_max{ point(0).x };
	int y_max{ point(0).x };
	int x_min{ point(0).y };
	int y_min{ point(0).y };

	// find the boundary of the Closed_polygon
	for (int i = 0; i < number_of_points(); ++i) {
		if (point(i).x > x_max) x_max = point(i).x;
		if (point(i).x < x_min) x_min = point(i).x;
		if (point(i).y > y_max) y_max = point(i).y;
		if (point(i).y < y_min) y_min = point(i).y;
	}

	// add a bit of margin for intersection
	x_max += 10; 
	x_min -= 10;
	y_max += 10;
	y_min -= 10;
	int x_diff = x_max - x_min;
	
	// draw lines within boundaries
	Lines l;
	for (int i = x_min; i < x_max; i += (x_diff / 10)) {
		l.add(Point{ i,y_min }, Point{ i,y_max });
	}
	//----------------------------------------------------

	vector<Point>v_intrsct;	// to store intersection points
	
	// find intersection points between verticle lines and polygon lines
	for (int i = 0; i <= l.number_of_points(); i += 2) {	// verticle lines
		// b1=y1-m.x1
		// b2=y2-m.x2
		int slope1, intercept1;
		int x1, y1, x2, y2; //p1(x1,y1) and p2(x2,y2)
		int dx1, dy1;		// difference in points

		x1 = l.point(i).x;
		y1 = l.point(i).y;
		x2 = l.point(i + 1).x;		
		y2 = l.point(i + 1).y;

		dx1 = x2 - x1;
		dy1 = y2 - y1;

		//1. A1x + B1y = C1
		//2. A2x + B2y = C2

		slope1=dy1/dx1;
		// y = mx + c
		// intercept c = y - mx
		intercept1 = y1 - slope1 * x1;

		for (int ii = 0; ii < Closed_polyline::number_of_points(); ++ii) {	// polygon lines
			int slope2, intercept2;
			int xx1, yy1, xx2, yy2;
			int dx2, dy2;

			xx1 = Closed_polyline::point(i).x;
			yy1 = Closed_polyline::point(i).y;
			xx2 = Closed_polyline::point(i + 1).x;
			yy2 = Closed_polyline::point(i + 1).y;

			dx2 = xx2 - xx1;
			dy2 = yy2 - yy1;

			slope2 = dy2 / dx2;
			// y = mx + c
			// intercept c = y - mx
			intercept2 = yy1 - slope2 * xx1;

			Point p;	// intersection point
			p.x = (intercept2 - intercept1) / (slope1 - slope2);
			p.y = ((slope1 * intercept1) - (intercept2 * slope2)) / (slope1 - slope2);

			v_intrsct.push_back(p);
		}
	}

	Marks mark{ "x" };
	for (int i = 0; i < v_intrsct.size(); ++i) {
		mark.add(v_intrsct[i]);
	}
}

void Striped_closed_polyline::set_stripes_color(Color c)
{
	stripes.set_style(Line_style(Line_style::solid, 4));
	stripes.set_color(c);
}

