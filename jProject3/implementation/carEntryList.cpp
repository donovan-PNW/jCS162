//Implementation for carEntryList
#include "headers.h"

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
	while(!inFile.eof())
	{
        inFile.getline(tempName, MAX_CHAR, ';');
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
        //getline to get raw string, read it with readOrigin
        inFile.getline(originDesc, MAX_CHAR, '\n');
        tempOrigin = readOrigin(originDesc[0]);
        //cout << tempName << ';' << tempMpg << ';' << tempCylinders  << tempDisplacement << ';' << tempHorsepower << ';' << tempWeight << ';' << tempAcceleration << ';' << tempModel << ';' << tempOrigin << endl;
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
		addEntry(thisCar);
        //starts the loop again
        if(inFile.peek() == EOF)
        {
            break;
        }
	}
	inFile.close();

}

//destructor
carEntryList::~carEntryList()
{
    //KABOOM!!
}
void carEntryList::addEntry(carEntry thisCar)
{
    list[size++] = thisCar;
}

void carEntryList::removeEntry()
{
	int delIndex = 1;
    delIndex = readInt("Please enter index of the car you would like to remove: ");
    if(delIndex < size)
    {
         for(int i = delIndex; i < size; i++)
        {
            list[i-1] = list[i];
        }
    }
    cout << "this car has beeen removed!" << endl;
    size--;
}

void carEntryList::displayList()
{
	for(int i = 0; i < size; i++)
	{
		cout << i+1 << ") ";
		list[i].printCarEntry();
	}
	cout << endl;
}

void carEntryList::searchByName()
{
    
	char searchName[MAX_CHAR];
	char tempName[MAX_CHAR];
	cout << "Please enter the name of the car you would like to search for (can be a partial match):";
	cin.get(searchName, MAX_CHAR);
	convertCase(searchName);
	for(int i = 0; i < size; i++)
	{
		list[i].getCarName(tempName);
		convertCase(tempName);
		if(strstr(tempName, searchName) != NULL)
		{
            cout << i+1 << ") ";
			list[i].printCarEntry();
		}
	}
}

void carEntryList::searchByOrigin()
{
    char firstLetter;
    whereFrom searchOrigin;
    whereFrom tempOrigin;
    cout << "Please select a filter to display cars from a particular region: ";
    cin >> firstLetter;
    searchOrigin = readOrigin(firstLetter);
    for(int index = 0; index < size; index++)
    {
        tempOrigin = list[index].getOrigin();
        if(searchOrigin == tempOrigin)
        {
            cout << index+1 << ") ";
            list[index].printCarEntry();
        }
    
    }

}
void carEntryList::searchByMPG()
{
    double tempMPG;
    double selectedMPG;
    int index;
    cout << "Please enter the minimum number of miles per gallon: " << endl;
    cin >> selectedMPG;
    while(!cin)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a number!  ";
        cin >> selectedMPG;
    }
    for(index = 0; index < size; index++)
    {
        tempMPG = list[index].getMPG();
        if(tempMPG >= selectedMPG)
        {
            cout << index+1 << ") ";
            list[index].printCarEntry();
        }
    }
}

void carEntryList::writeAndQuit(char fileName[])
{
	ofstream outFile;
	outFile.open(fileName);
	for(int index = 0; index < size; index++)
	{
	    list[index].printCarEntry(outFile);

	}
}





