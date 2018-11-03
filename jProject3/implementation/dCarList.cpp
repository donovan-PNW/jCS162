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
    char tempName[MAX_CHAR];
    double tempMpg;
    int tempCylinders;
    double tempDisplacement;
    double tempHorsepower;
    double tempWeight;
    double tempAcceleration;
    int tempModel;
    char originDesc[MAX_CHAR];
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
        inFile.getline(originDesc, MAX_CHAR, '\n');
        tempOrigin = readOrigin(originDesc[0]);
		inFile.ignore(MAX_CHAR, ';');
		//populate carEntry;
		thisCar.setCarName(tempName);
		thisCar.setMPG(tempMpg);
		thisCar.setCylinders(tempCylinders);
		thisCar.setDisplacement(tempDisplacement);
		thisCar.setHorsepower(tempHorsepower);
		thisCar.setWeight(tempWeight);
		thisCar.setAcceleration(tempAcceleration);
		thisCar.setModel(tempModel);
		thisCar.setOrigin(tempOrigin);
		thisCar.setQty(tempQty);
		addCar(thisCar);
        //getline to get raw string, read it with readOrigin
        //3rd line then starts the loop again
		inFile.getline(genreDesc, MAX_CHAR, ';');
		tempGenre = readGenre(genreDesc[0]);
		inFile.getline(tempTitle, MAX_CHAR, ';');
	}
	inFile.close();

}
