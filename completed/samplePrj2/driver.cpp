//This is the main driver file
//main
#include "video.h"
#include "tools.h"
int main()
{
    //create a variable for a single video
    Video store[CAP];
    char fileName[MAXCHAR] = "videos.txt";
    char option;
    ifstream inFile;
    ofstream outFile;
    int size = 0;
    openFile(fileName, inFile);
    loadData(inFile, store, size);
    do
    {
        displayMenu();
        option = readOption();
        exeCmd(option, store, size);
    }while(tolower(option != 'q'));
    openFile(fileName, outFile);
    writeData(store, size, outFile);
    return 0;
}

