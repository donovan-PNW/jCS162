//This is the main driver file
//main


//these should be added to a .h file later NOTA
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int CAP = 100;
const int MAX_CHAR = 101;

void openFile(char fileName[], ifstream &inFile);

int main()
{

//keeps track of cars in a list
    char fileName[MAX_CHAR] = "cars.txt";
    char option;
    car entry[CAP];
    ifstream inFile;
    ofstream outFile;
    int size = 0;
    openFile(fileName, inFile);
    loadData(inFile, store, size);
    while(tolower(option != 'q'))
    {
        displayMenu();
        option = readOption();
        exeCmd(option, store, size);
    }
    openFile(fileName, outFile);
    writeData(store, size, outFile);
    return 0;
}

//open the file and check to make sure it is open
void openFile(char fileName[], ifstream &inFile)
{
    inFile.open(fileName);
    if(!inFile)
    {
        cout << "Input file did not open!! Program exiting!!!" << endl;
        exit(0);
    }
}


//This opens the output file
void openFile(char fileName[], ofstream &outFile)
{
    outFile.open(fileName);
    if(!outFile)
    {
        cout << "Output file did not open!! Program exiting!!!" << endl;
        exit(0);
    }
}


//load data from file
//DEPRICATED!! SEE LOADdATAfUNC.CPP
void loadData(ifstream &inFile, Video store[], int &size)
{
    char tempGenre[MAXCHAR];
    inFile.get(store[size].title, MAXCHAR, ';');
    while(inFile)
    {
        inFile.ignore(100, ';');
        inFile.get(tempGenre, MAXCHAR, ';');
        if(strcmp(tempGenre, "ACTION") == 0)
        {
            store[size].genre = ACTION;
        }
        else if(strcmp(tempGenre, "FAMILY") == 0)
        {
            store[size].genre = FAMILY;
        }
        else if(strcmp(tempGenre, "COMEDY") == 0)
        {
            store[size].genre = COMEDY;
        }
        else if(strcmp(tempGenre, "HORROR") == 0)
        {
            store[size].genre = HORROR;
        }
        else
        {
            store[size].genre = ILLEGAL;
        }

        inFile.ignore(100, ';');
        inFile >> store[size].qty;
        inFile.ignore(100, ';');
        inFile >> store[size].rating;
        inFile.ignore(100, '\n');
        size++;
        inFile.get(store[size].title, MAXCHAR, ';');
    }
    inFile.close();
}



//save and quit
void writeData(const Video store[], int size, ofstream &outFile)
{
    char genreDesc[MAX_CHAR];
    for(int i = 0; i < size; i++)
    {
        printGenre(store[i].genre, genreDesc);
        outFile << store[i].title << ";" << genreDesc << ";" << store[i].qty << ";" << store[i].rating << endl;
    }
    outFile.close();
}

