//This program demos dynamic arrays
#include <iostream>
using namespace std;

int main()
{
	int *ptr = NULL, *tempPtr = NULL, cap = 100;
	//point it to a dynamic array
	ptr = new int[cap];
	//read 5 values into the array
	cout << "Please enter 5 values:";
	for(int i = 0; i < 5; i++)
	{
		cin >> ptr[i];
	}
	cout << "Your values are:" << endl;
	//output values using tempPtr
	for(tempPtr = ptr; tempPtr < ptr + 5; tempPtr++)
	{
		cout << *tempPtr << endl;
	}
	delete [] ptr;
	//bad idea since the memory has already been allocated
	//cout << *tempPtr << endl;
	//delete [] tempPtr;
	ptr = NULL;
	tempPtr = NULL;
	return 0;
}
	
