//This program demos char arrays
#include <iostream>
#include <string.h>
using namespace std;

//constants
const int MAXCHAR = 101;
int main()
{
	char tempTitle[MAXCHAR];
	char *titlePtr = NULL, *tempPtr = NULL;
	titlePtr = new char[MAXCHAR];
	cout << "Please enter a movie title:";
	cin.get(tempTitle, MAXCHAR);
	cin.ignore(100, '\n');
	//check if titlePtr is pointing to something
	if(titlePtr)
	{
		delete [] titlePtr;
		titlePtr = NULL;
	}
	//allocate just enough mem for movie title and then copy
	titlePtr = new char[strlen(tempTitle)+1];
	strcpy(titlePtr, tempTitle);

	cout << "Your title is " << titlePtr << endl;
	//to print the title in reverse using the pointer
	for(tempPtr = titlePtr + strlen(titlePtr); tempPtr >= titlePtr; tempPtr--)
	{
		cout << *tempPtr;
	}
	cout << endl;
	delete [] titlePtr;
	titlePtr = NULL;
	tempPtr = NULL;
	
	return 0;
}
