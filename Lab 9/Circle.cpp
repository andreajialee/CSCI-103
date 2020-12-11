#define _USE_MATH_DEFINES
#include <math.h>   
#include <fstream>
#include <sstream>
#include "Logger.h"
#include "Circle.h"

Circle::Circle(std::ifstream& stream)
{
    if (!(stream >> _radius))
    {
        throw Logger::CIRCLE_ERROR;
    }
}

double Circle::calculateArea()
{
	return (_radius * _radius * M_PI);
}
