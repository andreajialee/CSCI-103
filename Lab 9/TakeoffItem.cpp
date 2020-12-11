#include <iostream>
#include <fstream>
#include "TakeoffItem.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Logger.h"

TakeoffItem::TakeoffItem(std::string name, double pricePerSqF, std::ifstream& stream)
{
	_name = name;
	_pricePerSqF = pricePerSqF;
	std::string shapeType;
	
	stream >> shapeType;
	//Instantiate the right shape
	if(shapeType == "r")
		_shape = new Rectangle(stream);
	else if(shapeType == "t")
		_shape = new Triangle(stream);
	else if(shapeType == "c")
		_shape = new Circle(stream);
}

TakeoffItem::~TakeoffItem()
{
	//Add necessaery code
	delete _shape;
}

double TakeoffItem::calculatePrice()
{
	//Add necessaery code
	return _pricePerSqF * _shape->calculateArea();
}

void TakeoffItem::showDetails()
{
	//Add a cout line to print the details.
  //eg:
  //Wall: 2.50 sqft, $7.50
	std::cout << _name << ": ";
	std::cout << _shape->calculateArea() << " sqft, $" << calculatePrice() << std::endl;
	
}
