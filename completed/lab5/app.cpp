#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char ** names;

	//write code here to allocate memory for at most 10 names 

    names = new char *[9];

	//write code here to allocate memory and populate the first name as "charlie"
	//it has to be just big enough for "charlie" which is 8 chars including '\0'

    names[0] = new char[8];
    strcpy(names[0], "charlie");
	
    //write code here to allocate memory and populate the second name as "sarah"
	//it has to be just big enough for "sarah"

	names[1] = new char[6];
    strcpy(names[1], "sarah");

    //write code here to print the names

    cout << "Name 1: " << names[0] << endl;
    cout << "Name 2: " << names[1] << endl;

	//write code here to deallocate memory for the names
    
    for (int index=0; index < 9; index++)
    {
        delete [] names[index];
    }
    delete [] names;
    names = NULL;

	return 0;
}

