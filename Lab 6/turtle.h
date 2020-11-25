//This file starts out empty!
//Define the Turtle class here.
#include "draw.h"

class Turtle
{	
	public:
		Turtle(double x0, double y0, double dir0);
		void move(double dist);
		void turn(double deg);
		void setColor(Color c);
		void on();
		void off();

	private:
		double x1;
		double y1;
		double dir;
		Color color;
		int tra;
};
