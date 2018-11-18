//This program demos dynamic integer arrays in a class.
//This is the driver file.
#include "numlist.h"

const int MAXCHAR = 101;

int main()
{
    Numlist myList("numbers.txt");
	myList.addNum(12);
	myList.addNum(23);
	//myList.printList();
	cout << myList;

    return 0;
}



