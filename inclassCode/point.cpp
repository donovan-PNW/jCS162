#include "point.h"

 //constructors
Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int initX, int initY)
{
	x = initX;
	y = initY;
}
//accessor functions
void Point::getX(int &returnX)
{
	returnX = x;
}
void Point::getY(int &returnY)
{
	returnY = y;
}
//mutator functions
void Point::setX(int newX)
{
	x = newX;
}

void Point::setY(int newY)
{
	y = newY;
}
//function to check the point's quadrant
void Point::quadCheck()
{
	if(x > 0 && y > 0)
	{
		cout << "Quadrant 1!" << endl;
	}
	else if(x < 0 && y > 0)
	{
		cout << "Quadrant 2!" << endl;
	}
	else if (x < 0 && y < 0)
	{
		cout << "Quadrant 3!" << endl;
	}
	else if (x > 0 && y < 0)
	{
		cout << "Quadrant 4!" << endl;
	}
	else if( x == 0 && y == 0)
	{
		cout << "Origin!" << endl;
	}
}

//distance function
double Point::distance(const Point aPoint)
{
	double temp1 = aPoint.x - x;
	double temp2 = aPoint.y - y;
	return(sqrt(pow(temp1, 2)+pow(temp2, 2)));
}
    //check equality
bool Point::pointEqual(const Point aPoint)
{
	if(aPoint.x == x && aPoint.y == y)
		return true;
	else
		return false;
}

