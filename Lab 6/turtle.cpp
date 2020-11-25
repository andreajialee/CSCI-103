//This file also starts out empty.
//Implement the Turtle class here.

#include "turtle.h"
#include <iostream>
#include <cmath>

using namespace std;

Turtle::Turtle(double x0, double y0, double dir0)
{
	x1 = x0;
	y1 = y0;
	dir = dir0;
	color = draw::BLACK;
	tra = 0;
}

void Turtle::move(double dist)
{
	double x2 = x1 + (dist * cos(dir * (M_PI / 180)));
	double y2 = y1 + (dist * sin(dir * (M_PI / 180)));
	draw::setcolor(color);
	if(tra==0){
		draw::line(x1, y1, x2, y2);
	}
	x1 = x2;
	y1 = y2;
}

void Turtle::turn(double deg)
{
	dir = dir + deg;
}

void Turtle::setColor(Color c)
{
	color = c;
}

void Turtle::on()
{
	tra = 0;
}

void Turtle::off()
{
	tra = 1;
}
