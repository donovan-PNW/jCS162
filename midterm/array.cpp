//array.cpp 

#include "array.h"

//put the implementations of your assigned functions here

//compute and return the number of even integers in list
int numOfEven(int list[], int size)
{
    int index;
    int count = 0;
    for(index=0;index < size; index++)
    {
        if(list[index] % 2 == 0)
        {
            cout << list[index] << " ";
            count++;
        }
    }
    return count;
}
//insert newInt into the list at index “position” and update the size of the list
void insert(int list[], int& size, int newInt, int position)
{
    return;
}
