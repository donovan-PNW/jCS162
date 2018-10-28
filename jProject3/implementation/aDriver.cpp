#include "headers.h"

int main()
{
	//create a list of videos.
	char fileName[MAXCHAR] = "cars.txt";
	VideoList store(fileName);
	char option;
    do
    {
        displayMenu();
        option = readOption();
        exeCmd(option, store);
    }while(tolower(option != 'q'));
    store.writeData(fileName);

	return 0;
}

int main()


{
    int size = 0;
    bool quitSignal = false;
    char fileName[MAX_CHAR] = "cars.txt";
    char tempSelection;
    char selection;
    ifstream inFile;
    ofstream outFile;
    carType carList[CAP];
    openFile(fileName, inFile);
    loadData(inFile, carList, size);
    do
    {
        displayMenu();
        quitSignal = getSelection();
    }
    while(getSelection!= 'Q');
    
    return 0;
}

