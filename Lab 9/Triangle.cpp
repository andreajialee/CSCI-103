#include <sstream>
#include "Triangle.h"
#include "Logger.h"

//Add the required code here
Triangle::Triangle(std::ifstream& stream)
{
    //Initialize the rectangle
	if (!(stream >> base))
    {
        throw Logger::TRIANGLE_ERROR;
    }
	if(!(stream >> height))
	{
		throw Logger::TRIANGLE_ERROR;
	}
}

double Triangle::calculateArea()
{
	return (.5 * base * height);
}