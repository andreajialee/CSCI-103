#pragma once

#include <string>
#include <fstream>

enum LogType
{
	Info,
	Error
};

class Logger
{
private:
	static std::ofstream _logStream;
	static bool _hasErrors;
public:
	static const std::string ITEM_ERROR;
	static const std::string RECTANGLE_ERROR;	
	static const std::string TRIANGLE_ERROR;		
	static const std::string CIRCLE_ERROR;

	static void open(std::string fileName);
	static void log(LogType logType, const std::string info);
	static void close();
	static bool hasErrors();
};