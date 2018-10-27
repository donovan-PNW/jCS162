//array.cpp 

#include "array.h"

//put the implementations of your assigned functions here

int sumOfArray(int list[], int size)
{
    int index;
    int sum = 0;
    for(index = 0; index < size; index++)
    {
        sum = sum + list[index];
    }
    return sum;
}


int remove(int list[], int& size, int target)
{
    int index;
    int subIndex;
    int integersRemoved = 0;
    for(index = 0; index < size; index++)
    {
        if(list[index] == target)
        {
            for(subIndex = index; subIndex < size; subIndex++)
            {
                list[subIndex] = list[subIndex + 1];
            }
            index--;
            size--;
            integersRemoved++;
        }
    }
    return integersRemoved;
}
