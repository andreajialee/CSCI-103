#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Takeoff.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Logger.h"
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        printf("\nPlease specify a takeoff file.\n");
        return 0;
    }
  
    //Add code to start logger
		Logger::open("log.txt");
    Takeoff* takeoff = new Takeoff(argv[1]);
    takeoff->showReport();
	
    cout << endl << endl << "Press enter to quit...";
		getchar();
    takeoff->~Takeoff();
    //Add code to stop logging
		Logger::close();
    return 0;
}

Takeoff::Takeoff(std::string fileName)
{
    //Read the file to add takeoff items
	ifstream file(fileName);
    Logger::log(LogType::Info, "Starting Takeoff");
		getline(file, _name);
	
	double num = 0.00;
	string itemName;
	
    while (true)
    {
        //break if there is no more lines to read from file
			if(file.eof())
				break;
			
        try
        {
            //Add take off item
					if(!(file >> itemName))
						throw Logger::ITEM_ERROR;
					if(!(file >> num))
						throw Logger::ITEM_ERROR;
					
					TakeoffItem * temp = new TakeoffItem(itemName, num, file);
					addItem(temp);
				
        }
        catch (string error)
        {
            //log an error
					Logger::log(LogType::Error, error);
					break;
        }
    }
    Logger::log(LogType::Info, "Finished Takeoff");
}

Takeoff::~Takeoff()
{
    //Clean memory
	for(int i=0; i<(int)_items.size(); i++){
		delete _items[i];
	}
	
}

void Takeoff::addItem(TakeoffItem* item)
{
    //Add necessary code
	_items.push_back(item);
}

double Takeoff::calculateTotalPrice()
{    
    //Add necessary code
	double sum = 0.0;
	for(int i=0; i<(int)_items.size(); i++){
		sum+=_items[i]->calculatePrice();
	}
	return sum;
}

void Takeoff::showReport()
{
	std::cout << std::fixed;
  std::cout << std::setprecision(2);
    //Add necessary code 
	cout << _name << endl << endl;
	cout << "Details" << endl << endl;
	for(int i=0; i<(int)_items.size(); i++){
		_items[i]->showDetails();
	}
	cout << endl;
	cout << "Total Price: " << calculateTotalPrice();
}

