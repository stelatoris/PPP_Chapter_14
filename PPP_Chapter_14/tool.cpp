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

//----------------------------------------------------------------------