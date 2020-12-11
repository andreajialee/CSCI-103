#pragma once

#include <fstream>
#include <string>
#include "Shape.h"

class TakeoffItem
{
private:
	std::string _name;
	double _pricePerSqF;
	Shape* _shape;
public:
	TakeoffItem(std::string name, double price, std::ifstream& stream);
	~TakeoffItem();
	
	//Define a method to calculate price
	double calculatePrice();
	//Define a method to show the details 
	void showDetails();

};

