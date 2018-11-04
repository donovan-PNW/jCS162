#include "headers.h"

int main()
{
	char fileName[MAX_CHAR] = "cars.txt";
    char outFileName[MAX_CHAR] = "outcars.txt";
	carEntryList dealership(fileName);
    dealership.displayList();
	char option;
    do
  {
        displayMenu();
        option = readOption();
        exeCmd(option, dealership);
    }while(toupper(option != 'Q'));


    dealership.writeAndQuit(outFileName);

	return 0;
}



