//This is the implementation file for numlist.h (the numlist class)
#include "numlist.h"

//default constructor
Numlist::Numlist()
{
	list = new int[CAP];
	size = 0;
}

//constrcutor from file
Numlist::Numlist(char fileName[])
{
	int temp = 0, i = 0;
	list = new int [CAP];
	size = 0;
	ifstream inFile;
	inFile.open(fileName);
    if(!inFile)
    {
        cout << "File did not open!! Program exiting!!!" << endl;
        exit(0);
    }
    while(inFile >> temp)
    {
        if(size == CAP)
        {
            cout << "Error!! List full!!" << endl;
            return;
        }
        else if(size == 0)
        {
            list[size++] = temp;
        }
        else
        {
            for(i = 0; i < size; i++)
            {
                if(list[i] > temp)
                    break;
            }
            for(int j = size; j > i; j--)
            {
                list[j] = list[j-1];
            }
            list[i] = temp;
            size++;
        }
    }
}

//destructor
Numlist::~Numlist()
{
	delete [] list;
	list = NULL;
}

//accessor function
int Numlist::getSize()
{
	return size;
}

//insert function
void Numlist::addNum(int temp)
{
	if(size == CAP)
	{
		cout << "Array full" << endl;
		return;
	}
	list[size++] = temp;
}

//print function
void Numlist::printList()
{
	for(int i = 0; i < size; i++)
	{
		cout << list[i] << endl;
	}
}

//implementation for friend function for << operator
ostream& operator<< (ostream& out, Numlist& aList)
{
	for(int i = 0; i < aList.size; i++)
    {
        out << aList.list[i] << endl;
    }
	return out;
}








