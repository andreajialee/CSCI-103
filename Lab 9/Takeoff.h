#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "TakeoffItem.h"

class Takeoff
{
private:
	std::string _name;
	std::vector<TakeoffItem*> _items;
    double calculateTotalPrice();
public:
	Takeoff(std::string fileName);
	~Takeoff();
	void addItem(TakeoffItem* item);
	void showReport();
};

