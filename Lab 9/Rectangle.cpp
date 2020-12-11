#include <iostream>
#include <fstream>
#include <sstream>
#include "Rectangle.h"
#include "Logger.h"

Rectangle::Rectangle(std::ifstream& stream)
{
    //Initialize the rectangle
	if (!(stream >> length))
    {
        throw Logger::RECTANGLE_ERROR;
    }
	if (!(stream >> width))
    {
        throw Logger::RECTANGLE_ERROR;
    }
}

//Add the required code here
double Rectangle::calculateArea()
{
	return (length * width);
}