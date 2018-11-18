//This program demos basic pointers
#include <iostream>

using namespace std;

int main()
{
	int x = 0;
	double y = 0;
	//create 2 pointers
	int *xptr = NULL;
	double *yptr = NULL;
	//make the pointers point to x and y
	xptr = &x;
	yptr = &y;
	//change the values of x and y through pointers
	*xptr = 15;
	*yptr = 3.6;
	//output some values
	cout << "x = " << x << endl;
	cout << "&x = " << &x << endl;
	cout << "y = " << y << endl;
    cout << "&y = " << &y << endl;
	cout << "*xptr = " << *xptr << endl;
	cout << "*yptr = " << *yptr << endl;
	cout << "xptr = " << xptr << endl;
	cout << "yptr = " << yptr << endl;
	cout << "&xptr = " << &xptr << endl;
	cout << "&yptr = " << &yptr << endl;

	return 0;
}
