#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//point class definition
class Point
{
//private data members
private:
	int x;
	int y;
public:
	//constructors
	Point();
	Point(int initX, int initY);
	//accessor functions
	void getX(int &returnX);
	void getY(int &returnY);
	//mutator functions
	void setX(int newX);
	void setY(int newY);	
	//function to check the point's quadrant
	void quadCheck();
	//distance function
	double distance(const Point aPoint);
	//check equality
	bool pointEqual(const Point aPoint);
};

#endif
