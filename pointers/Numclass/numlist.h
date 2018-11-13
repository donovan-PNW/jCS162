#ifndef NUMLIST_H
#define NUMLIST_H
//Class object for a list of numbers and its size
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//constants
const int CAP = 50;

//data type for numlist
class Numlist
{
	friend ostream& operator<< (ostream& out, Numlist &);
	private:
		int *list;
		int size;
	public:
		//constructor
		Numlist();
		Numlist(char fileName[]);
		//destructor
		~Numlist();
		//accessor function
		int getSize();
		//insert function
		void addNum(int);
		void printList();
};

#endif

