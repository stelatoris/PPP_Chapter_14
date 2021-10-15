// tools.cpp
// Programming: Principles and Practices using c++ - Bjarne Stroustrup
// 
// Chapter 14 Drill and Exercise solutions

#include "Simple_window.h"
#include "tools.h"
#include <math.h>

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

Striped_rectangle::Striped_rectangle(Point xy, int ww, int hh) :
	Rectangle{ xy ,ww ,hh }
{
	add(xy);
	for (int i = 0; i < ww; i += 10) {
		stripes.add(Point{ 5+ xy.x + i,xy.y }, Point{5+ xy.x + i,xy.y + hh });
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
	
