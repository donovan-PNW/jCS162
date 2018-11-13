//This program demos basic pointers to arrays
#include <iostream>
using namespace std;

//global constants
const int CAP = 100;

int main()
{
	int *ptr = NULL, list[CAP];
	int myList[CAP] = {0};

	ptr = list;
	list[0] = 5;
	list[2] = 10;
	//prints the first element
	cout << *ptr << endl;
	//pointer arithmetic
	ptr += 2;
	//prints the third element
	cout << *ptr << endl;
	cout << "Enter 5 numbers:";
	for (ptr = list; ptr < list + 5; ptr++)
	{
		cin >> *ptr;
	}
	//prints the first 5 numbers
	cout << "\nYour numbers are:\n";
	for (ptr = list; ptr < list + 5; ptr++)
	{
		cout << *ptr << endl;
	}
	//prints the first 5 numbers in reverse
	cout << "\nYour numbers are:\n";
	for (ptr = list + 4; ptr >= list; ptr--)
	{
		cout << *ptr << endl;
	}

	ptr = myList;

	return 0;
}
