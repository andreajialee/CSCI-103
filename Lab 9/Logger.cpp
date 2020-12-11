#include "Logger.h"
#include <iomanip>
#include <ctime>
#include <sstream>
#include <iostream>

std::ofstream Logger::_logStream;

const std::string Logger::ITEM_ERROR = "ERR 004 - Error while creating a takeoff item.";
const std::string Logger::RECTANGLE_ERROR = "ERR 001 - Error while creating a rectangle.";
const std::string Logger::TRIANGLE_ERROR = "ERR 002 - Error while creating a triangle.";
const std::string Logger::CIRCLE_ERROR = "ERR 003 - Error while creating a circle.";

void Logger::open(std::string fileName)
{
	//Create a log file
	Logger::_logStream.open(fileName);
	if(_logStream.fail())
		std::cout << "Error" << std::endl;
	
}

void Logger::log(LogType logType, const std::string info)
{
	//Get the current date and time in the form of "%d-%m-%Y %H-%M-%S
	time_t now;
	struct tm* timeInfo;
	char buff[80];
	
	time(&now);
	timeInfo = localtime(&now);
	
	strftime(buff, 20, "%d-%m-%Y %H-%M-%S", timeInfo);
	for(int i=0; i<19; i++){
		_logStream << buff[i];
	}
	//use the log type add a relevant line to the log file. In the for of: 
	//	[time-date]: Info/Error: [info]
	
	if(logType == Error)
		_logStream << ": Error: " << info << std::endl;
	else if(logType ==Info)
		_logStream << ": Info: " << info << std::endl;
	
}

void Logger::close()
{
    //Close the log gile
	Logger::_logStream.close();
}
