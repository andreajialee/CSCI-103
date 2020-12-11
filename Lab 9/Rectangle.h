#pragma once

#include <fstream>
#include "Shape.h"

//Add the required code here
class Rectangle : public Shape
{
private:
	double length;
	double width;
public:
	Rectangle(std::ifstream& stream);
	virtual double calculateArea();
};


