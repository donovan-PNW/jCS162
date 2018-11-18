//This is the swap function using reference params
#include <iostream>
using namespace std;

//function prototype
void swap(int &, int &);
void swap(int *, int *);

//main
int main()
{
	int x = 10, y = 15;
	cout << "Before swap reference function:" << endl;
	cout << "x = " << x << " and y = " << y << endl;
	swap(x, y);
	cout << "After swap reference function:" << endl;
	cout << "x = " << x << " and y = " << y << endl;
	swap(&x, &y);
	cout << "After swap pointers function:" << endl;
	cout << "x = " << x << " and y =" << y << endl;
	return 0;
}

//swap function using reference parameters
void swap(int &x, int &y)
{
	int temp = 0;
	temp = x;
	x = y;
	y = temp;
}

//swap function that receives pointers or addresses
void swap(int *xptr, int *yptr)
{
	int temp = 0;
	temp = *xptr;
	*xptr = *yptr;
	*yptr = temp;
	cout << "Inside the function: xptr = " << xptr << " and yptr = " << yptr << endl;	
}


