#pragma once

#include <fstream>
#include "Shape.h"

class Circle : public Shape
{
private:
	double _radius;
public:
	Circle(std::ifstream& stream);
	virtual double calculateArea();
};

