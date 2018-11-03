//Implementation for carEntryList
#include "headers.h"


//class carEntryList
//{
//    private:
//        carEntry list[CAP];
//        int size;
//    public:
//        //constructors
//        carEntryList();
//        carEntryList(char []);
//        //destructor
//        ~carEntryList(); 
//        //data manipulators
//        void addEntry();
//        void removeEntry();
//        void displayList();
//        void searchByName();
//        void searchByOrigin();
//        void searchByMPG();
//        void writeAndQuit();
//};

//default constructor
carEntryList::carEntryList()
{
    size = 0;
}

carEntryList::carEntryList(char fileName[])
{ 
    size = 0;
    ifstream inFile;
    carEntry thisCar;
    char tempName[MAX_CHAR], originDesc[MAX_CHAR];
    double tempMpg;
    int tempCylinders;
    double tempDisplacement;
    double tempHorsepower;
    double tempWeight;
    double tempAcceleration;
    int tempModel;
    whereFrom tempOrigin;

    inFile.open(fileName);
    if(!inFile)
    {
        cout << "Cannot open file! Exiting!!" << endl;
        exit(0);
    }
//TODO: ask why you start tempName outside of while loop
	inFile.getline(tempName, MAX_CHAR, ';');
	while(!inFile.eof())
	{
        inFile >> tempMpg;
        inFile.ignore(MAX_CHAR, ';');
        inFile >> tempCylinders;
        inFile.ignore(MAX_CHAR, ';');
        inFile >> tempDisplacement;
        inFile.ignore(MAX_CHAR, ';');
        inFile >> tempHorsepower;
        inFile.ignore(MAX_CHAR, ';');
        inFile >> tempWeight;
        inFile.ignore(MAX_CHAR, ';');
        inFile >> tempAcceleration;
        inFile.ignore(MAX_CHAR, ';');
        inFile >> tempModel;
		inFile.ignore(MAX_CHAR, ';');
		inFile.ignore(MAX_CHAR, ';');
		//populate aVideo;
		aVideo.setTitle(tempTitle);
		aVideo.setGenre(tempGenre);
		aVideo.setQty(tempQty);
		aVideo.setRating(tempRating);
		addVideo(aVideo);
        //getline to get raw string, read it with readOrigin
        //3rd line then starts the loop again
		inFile.getline(genreDesc, MAX_CHAR, ';');
		tempGenre = readGenre(genreDesc[0]);
		inFile.getline(tempTitle, MAX_CHAR, ';');
	}
	inFile.close();

}
