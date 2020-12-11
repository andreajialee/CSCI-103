# Makefile for Takeoff

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

main: Takeoff.o TakeoffItem.o Rectangle.o Triangle.o Circle.o Logger.o 
	$(CXX) $(CXXFLAGS) -o main Takeoff.o TakeoffItem.o Rectangle.o Triangle.o Circle.o Logger.o 

Takeoff.o: Takeoff.cpp TakeoffItem.h Rectangle.h Triangle.h Circle.h Logger.h
	$(CXX) $(CXXFLAGS) -c Takeoff.cpp

TakeoffItem.o: TakeoffItem.h Rectangle.h Triangle.h Circle.h Logger.h

Circle.o: Circle.h Shape.h

Rectangle.o: Rectangle.h Shape.h 

Triangle.o: Triangle.h Shape.h

Shape.o: Shape.h

Logger.o: Logger.h 