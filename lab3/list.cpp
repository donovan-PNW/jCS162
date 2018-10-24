#include "list.h"
#include <iostream>
using namespace std;

bool insert(int position, int val, int intList[], int& size)
{
	//insert your code here and modify the following line
    intList[position] = val;
    if(size < (position + 1))
    {
        size++;
    }
	return true;
}

bool remove(int position, int& val, int intList[], int& size)
{
	//insert your code here and modify the following line
    int counter;
    val = intList[position];
    if(position > size)
    {
        cout << "entered value is higher than list size" << endl;
        return false;
    }
    for(counter=0; counter < size; counter++)
    {
        if(counter >= position)
        {
            intList[counter] = intList[counter + 1];
        }
    }
    size--;
	return true;
}

void print(const int intList[], int size)
{
	cout << endl << "[ ";
	for(int i=0; i<size; i++)
	{
		cout << intList[i] << " ";
	}
	cout << "]" << endl;
}



