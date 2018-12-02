#include "headers.h"

int main()
{
	char fileName[MAX_CHAR] = "cars.txt";
	carEntryList dealership(fileName);
    dealership.displayList();
	char option;
    do
  {
        displayMenu();
        option = readOption();
        exeCmd(option, dealership);
    }while(toupper(option != 'Q'));


    dealership.writeAndQuit(fileName);

	return 0;
}

