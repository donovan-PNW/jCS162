//This program demos dynamic char arrays
#include <iostream>
#include <string.h>
using namespace std;

//gloabl constants
const int MAXCHAR = 101;

int main()
{
	char *title1 = NULL, *title2 = NULL;
	//allocate memory for 
	title1 = new char[MAXCHAR];
	//put some value in it
	cout << "Enter a movie name:";
	cin.get(title1, MAXCHAR);
	//copy title1 to title2 using assignment operator
	//shallow copy!!!!bad!! do not use assignment operator
	//title2 = title1;

	////allocate just enough memory for title2
	title2 = new char[strlen(title1) + 1];
	//copy from title1 to title2
	strcpy(title2, title1);
	cout << "title1: " << title1 << endl;
	cout << "title2: " << title2 << endl;

	delete[] title1;

	cout << "title2: " << title2 << endl;
	delete [] title2;

	return 0;
}
