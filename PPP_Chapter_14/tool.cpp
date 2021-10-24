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
	//----------------------------------------------------
	// find the boundary of the Closed_polygon
	// then "draw" vertical stripes in that boundary with number of stripes set
	// find all intersection points between stripes and polygon
	// use those points to add points to Lines stripes

	vector<Point>v_intrsct;	// to store intersection points

	int stripe_num{ 10 };	// number of stripes set

	int x_max{ Closed_polyline::point(0).x };
	int y_max{ Closed_polyline::point(0).x };
	int x_min{ Closed_polyline::point(0).y };
	int y_min{ Closed_polyline::point(0).y };

	// find the boundary of the Closed_polygon
	for (int i = 0; i < Closed_polyline::number_of_points(); ++i) {
		if (Closed_polyline::point(i).x > x_max) x_max = Closed_polyline::point(i).x;
		if (Closed_polyline::point(i).x < x_min) x_min = Closed_polyline::point(i).x;
		if (Closed_polyline::point(i).y > y_max) y_max = Closed_polyline::point(i).y;
		if (Closed_polyline::point(i).y < y_min) y_min = Closed_polyline::point(i).y;
	}

	int x_diff = x_max - x_min;
	int x_gap = x_diff / stripe_num;

	y_min -= 5;
	y_max += 5;

	int x1 = x_min;	// x coordinate of verticle line

	// find intersecting points along x till x_max with a gap of (x_diff / 10)		
	for (int i = 0; i < stripe_num; ++i) {	// verticle lines
		// b1=y1-m.x1
		// b2=y2-m.x2

		for (int ii = 1; ii <= Closed_polyline::number_of_points(); ++ii) {	// polygon lines
			float slope, intercept;
			int xx1, yy1, xx2, yy2;
			float dx2, dy2;

			//connect last point to first point to find intersection on closing side of polygon
			if (ii == Closed_polyline::number_of_points()) {
				xx1 = Closed_polyline::point(ii - 1).x;
				yy1 = Closed_polyline::point(ii - 1).y;
				xx2 = Closed_polyline::point(0).x;
				yy2 = Closed_polyline::point(0).y;
			}

			else {
				xx1 = Closed_polyline::point(ii - 1).x;
				yy1 = Closed_polyline::point(ii - 1).y;
				xx2 = Closed_polyline::point(ii).x;
				yy2 = Closed_polyline::point(ii).y;
			}

			dx2 = xx2 - xx1;
			dy2 = yy2 - yy1;

			if (dx2 == 0) {
				break;
			}

			slope = dy2 / dx2;
			// y = mx + c
			// intercept c = y - mx
			intercept = yy1 - slope * xx1;

			bool horizontal{ false };	// intersecting with horizontal line
			if (dy2 == 0) { horizontal = true; }

			bool out_of_line{ false };	// point is outside of line connecting 2 points
			if ((x1 >= xx2 && x1 >= xx1) || (x1 <= xx2 && x1 <= xx1)) { out_of_line = true; }

			Point p;	// intersection point

			if (horizontal && !out_of_line) {
				p.x = x1;
				p.y = yy1;
			}
			else if (!horizontal && !out_of_line) {
				p.x = x1;
				p.y = (slope * x1) + intercept;
			}

			if (!out_of_line) {
				v_intrsct.push_back(p);
			}
		}
		x1 += x_gap;
	}
	
	for (int i = 1; i < v_intrsct.size(); i += 2) {
		fl_line(v_intrsct[i - 1].x, v_intrsct[i - 1].y, v_intrsct[i].x, v_intrsct[i].y);		
	}	
}

//------------------------------------------------------------------------------
// Exercise 08

Regular_octagon::Regular_octagon(Point p, int distance)
	: c{ p }, d{ distance }
{
	add(Point{p.x-d,p.y});	// add point left of center as 1st point
	find_points();
}

void Regular_octagon::draw_lines() const
{
	Closed_polyline::draw_lines();
}

void Regular_octagon::find_points()
{
	for (int x = 1; x <= 360; x += 45) {	// 1st was already added in constructor
		int p_x{ 0 };
		int p_y{ 0 };

		p_x = c.x - cos(x * (PI / 180)) * d;
		p_y = c.y - sin(x * (PI / 180)) * d;

		Closed_polyline::add(Point{ p_x ,p_y });
	}
}

//------------------------------------------------------------------------------
// Exercise 11

Binary_tree::Binary_tree(Point xy, int levels) :
	lvls{ levels }
{
	if (levels < 0) error("number of nodes can't be less than zero");
	if (levels == 0) return;	// tree is empty
	add(xy);	// nodes 1 and higher

	build_nodes(levels);
	//draw_lines();
}

void Binary_tree::add_sub_nodes(Point p)
{
	Point r_node{ p.x + 100,p.y + 100 };
	Point l_node{ p.x - 100,p.y + 100 };

	// draw right node
	//nodes.push_back(new Circle{ r_node,50 });
	add(r_node);
	add(l_node);
	//nodes.push_back(new Line{ p,r_node });

	// draw left node
	
	//nodes.push_back(new Line{ p,l_node });
}

void Binary_tree::build_nodes(int l)
{
	for (int i = 1; i < pow(2, l - 2); ++i) {
		add_sub_nodes(point(i-1));
	}
	
	/*int n{ 1 };
	int sub_n{ 1 };

	if (l > 1) {
		for (int i = 0; i < l;++i) {
			
			n = n + (pow(2, i) * 2);
			
			cout << "Total nodes: " << n << '\n';
		}
	}*/	
}

void Binary_tree::draw_lines() const
{
	int r = 25;
	if (color().visibility()) {
		for (int i = 0; i < nodes.size(); ++i) {
			fl_arc(point(i).x, point(i).y, r + r, r + r, 0, 360);
		}
	}
}

void Binary_tree::set_color(Color col)
{
	for (int i = 0; i < nodes.size(); ++i) {
		nodes[i].set_color(col);
	}
}

