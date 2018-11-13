#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

const int CAP = 1000;
const int MAX_CHAR = 101;
//
enum whereFrom {US, Europe, Japan, Illegal};

struct carType
{
    char name[MAX_CHAR];
    double mpg;
    int cylinders;
    double displacement;
    double horsepower;
    double weight;
    double acceleration;
    int model;
    whereFrom origin;
};


void openFile(char [], ifstream &);
void openFile(char [], ofstream &);
void loadData(ifstream &, carType [], int &);
void displayList(carType [], int);
void searchByName(carType carList[], int size);
void searchByOrigin(carType carList[], int size);
void searchByMPG(carType carList[], int size);
void convertCase(char tempStr[]);
void addEntry(carType carList[], int &size);
int readInt(char prompt[]);
double readDouble(char prompt[]);
whereFrom newCarLocation(char letter);
void removeEntry(carType carList[], int &size);
void writeAndQuit(carType carList[], char fileName[], int size, ofstream &outFile);
void displayMenu();
int main()

{
    int size = 0;
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
        cin >> tempSelection;
        cin.ignore(100, '\n');
        /*while(!cin)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "not an option! Please enter a valid option";
            cin >> tempSelection;
        }*/
        selection = toupper(tempSelection);
        switch(selection)
        {
            case 'S':
                displayList(carList, size);
                break;

            case 'I':
                addEntry(carList, size);
                break;
            case 'D':
                removeEntry(carList, size);
                break;
            case 'R':
                searchByOrigin(carList, size);
                break;
            case 'N':
                searchByName(carList, size);
                break;
            case 'M':
                searchByMPG(carList, size);
                break;
            case 'Q':
                writeAndQuit(carList, fileName, size, outFile);
                break;
            default:
            cout << "not an option! Please enter a valid option";

        }
    
    }while(selection != 'Q');
    return 0;
}


void loadData(ifstream &inFile, carType carList[], int &size)
{
    char temporaryCar[MAX_CHAR];
    inFile.ignore(100, '\r');
    inFile.ignore(100, '\r');
    inFile.get(carList[size].name, MAX_CHAR, ';');
    while(inFile)
    {
        //two ignores which will skip the first two (informational) lines.
        //IT ASSUMES THAT THE FIRST TWO LINES ARE FOR INFORMATIONAL PURPOSES AND ARE NOT ACTUAL DATA
        //cout << size << carList[size].name << endl;
        inFile.ignore(100, ';');
        inFile >> carList[size].mpg;
        inFile.ignore(100, ';');
        inFile >> carList[size].cylinders;
        inFile.ignore(100, ';');
        inFile >> carList[size].displacement;
        inFile.ignore(100, ';');
        inFile >> carList[size].horsepower;
        inFile.ignore(100, ';');
        inFile >> carList[size].weight;
        inFile.ignore(100, ';');
        inFile >> carList[size].acceleration;
        inFile.ignore(100, ';');
        inFile >> carList[size].model;
        inFile.ignore(100, ';');
        //give origin info enum origin based on cstring using strcmp
        inFile.get(temporaryCar, MAX_CHAR, '\n');
        if(strcmp(temporaryCar, "US") == 0)
        {
            carList[size].origin = US;
        }
        else if(strcmp(temporaryCar, "Europe") == 0)
        {
            carList[size].origin = Europe;
        }
        else if(strcmp(temporaryCar, "Japan") == 0)
        {
            carList[size].origin = Japan;
        }
        else
        {
            carList[size].origin = Illegal;
        }

        size++;
        inFile.get(carList[size].name, MAX_CHAR, ';');
    }
    inFile.close();
    size--; // I have no idea what caused size to shift but this fixes it
    return;
}

void displayList(carType carList[], int size)
{
    int i;
    for(i = 0; i < (size); i++)
    {
        cout << "index no: " << (i + 1) << "; ";
        cout << "vehicle info: " << carList[i].name << "; ";
        cout << "MPG: ";
        cout << carList[i].mpg << "; ";
        cout << "cylinders: ";
        cout << carList[i].cylinders << "; ";
        cout << "displacement: ";
        cout << carList[i].displacement << "; ";
        cout << "horsepower: ";
        cout << carList[i].horsepower << "; ";
        cout << "weight: ";
        cout << carList[i].weight << "; ";
        cout << "acceleration: ";
        cout << carList[i].acceleration << "; ";
        cout << "model: ";
        cout << carList[i].model << "; ";
        cout << "country of origin: ";
        switch(carList[i].origin)
        {
            case 0:
                cout << "US";
                break;
            case 1:
                cout << "Europe";
                break;
            case 2:
                cout << "Japan";
                break;
            default:
                cout << "Illegal";
        }
        cout << endl << endl;
    return;
}





//This opens the input and output files
void openFile(char fileName[], ifstream &inFile)
{
    inFile.open(fileName);
    if(!inFile)
    {
        cout << "Input file was not found! Program exiting!" << endl;
        exit(0);
    }
    return;

}



void searchByName(carType carList[], int size)
{
    int i;
    char searchName[MAX_CHAR];
    cout << "Please enter a vehicle name" << endl;
    cin.get(searchName, MAX_CHAR, '\n');
    for(int i=0; i < (size); i++) //(size-1)?
    {
        convertCase(searchName);
        convertCase(carList[i].name);
        if(strstr(carList[i].name, searchName) != NULL)
        {
            cout << "index no:" << (i + 1) << "; ";
            cout << "vehicle name: ";
            cout << carList[i].name << "; ";
            cout << "MPG: ";
            cout << carList[i].mpg << "; ";
            cout << "cylinders: ";
            cout << carList[i].cylinders << "; ";
            cout << "displacement: ";
            cout << carList[i].displacement << "; ";
            cout << "horsepower: ";
            cout << carList[i].horsepower << "; ";
            cout << "weight: ";
            cout << carList[i].weight << "; ";
            cout << "acceleration: ";
            cout << carList[i].acceleration << "; ";
            cout << "model: ";
            cout << carList[i].model << "; ";
            cout << "country of origin: ";
            switch(carList[i].origin)
            {
                case 0:
                    cout << "US";
                    break;
                case 1:
                    cout << "Europe";
                    break;
                case 2:
                    cout << "Japan";
                    break;
                default:
                    cout << "Illegal";
            }
            cout << endl << endl;
            //cout << carList[i].origin << "; " << endl << endl;
        }
    }
    return;
}

void searchByOrigin(carType carList[], int size)
{
    char thisCarOrigin;
    whereFrom thisCar;
    cout << "Please select the region that you are looking for: [U]s, [E]urope, [Japan]: " << endl;
    cin >> thisCarOrigin;
    if(islower(thisCarOrigin))
    {
        thisCarOrigin = toupper(thisCarOrigin);
    }
    cout << thisCarOrigin;
    switch(thisCarOrigin)
    {
        case 'U':
            thisCar = static_cast<whereFrom>(0);
            break;

        case 'E':
            thisCar = static_cast<whereFrom>(1);
            break;
    
        case 'J':
            thisCar = static_cast<whereFrom>(2);
            break;

        default:
            thisCar = static_cast<whereFrom>(3);
    }
    cout << thisCar;
    for(int i=0; i < (size); i++)
    {
        if(carList[i].origin == thisCar)
        {
            cout << "index no:" << (i + 1) << "; ";
            cout << "vehicle name: ";
            cout << carList[i].name << "; ";
            cout << "MPG: ";
            cout << carList[i].mpg << "; ";
            cout << "cylinders: ";
            cout << carList[i].cylinders << "; ";
            cout << "displacement: ";
            cout << carList[i].displacement << "; ";
            cout << "horsepower: ";
            cout << carList[i].horsepower << "; ";
            cout << "weight: ";
            cout << carList[i].weight << "; ";
            cout << "acceleration: ";
            cout << carList[i].acceleration << "; ";
            cout << "model: ";
            cout << carList[i].model << "; ";
            cout << "country of origin: ";
            //cout << carList[i].origin << "; " << endl << endl;
            switch(carList[i].origin)
            {
                case 0:
                    cout << "US";
                    break;
                case 1:
                    cout << "Europe";
                    break;
                case 2:
                    cout << "Japan";
                    break;
                default:
                    cout << "Illegal";
            }
            cout << endl << endl;
        }
    }


    return;
    }

void searchByMPG(carType carList[], int size)
{
    double selectedMPG;
    char response[MAX_CHAR];
    cout << "Please enter the minimum number of miles per gallon: " << endl;
    cin >> selectedMPG;
    while(!cin)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a number!   :";
        cin >> selectedMPG;
    }
    //selectedMPG = readDouble(response); 
    for(int i = 0; i < size; i++)
    {
        if(selectedMPG <= carList[i].mpg)
        {
            cout << "index no:" << (i + 1) << "; ";
            cout << "vehicle name: ";
            cout << carList[i].name << "; ";
            cout << "MPG: ";
            cout << carList[i].mpg << "; ";
            cout << "cylinders: ";
            cout << carList[i].cylinders << "; ";
            cout << "displacement: ";
            cout << carList[i].displacement << "; ";
            cout << "horsepower: ";
            cout << carList[i].horsepower << "; ";
            cout << "weight: ";
            cout << carList[i].weight << "; ";
            cout << "acceleration: ";
            cout << carList[i].acceleration << "; ";
            cout << "model: ";
            cout << carList[i].model << "; ";
            cout << "country of origin: ";
            switch(carList[i].origin)
            {
                case 0:
                    cout << "US";
                    break;
                case 1:
                    cout << "Europe";
                    break;
                case 2:
                    cout << "Japan";
                    break;
                default:
                    cout << "Illegal";
            }
            cout << endl << endl;
        }
    }
    
    return;
}


//converts all text to upper case
void convertCase(char tempStr[])
{
    for (int i = 0; i < strlen(tempStr); i++)
    {
        tempStr[i] = toupper(tempStr[i]);
    }
    return;
}

void addEntry(carType carList[], int &size)
{
    char option;
    cout << "Enter the new vehicle's name: ";
    cin.get(carList[size].name, MAX_CHAR, '\n');
    cout << carList[size].name;
    cin.ignore(100, '\n');
    carList[size].mpg = readDouble("Enter the vehicle's MPG rating: ");
    cout << carList[size].mpg;
    carList[size].cylinders = readInt("Enter the vehicle's number of cylinders: ");
    carList[size].displacement = readDouble("Enter the vehicle's displacement: ");
    carList[size].horsepower = readDouble("Enter the vehicle's horsepower: ");
    carList[size].weight = readDouble("Enter the vehicle's weight: ");
    carList[size].acceleration = readDouble("Enter the vehicle's acceleration: ");
    carList[size].model = readInt("Enter the vehicle's model: ");
    cout << "Enter the new vehicle's place of manufacture: [U]s, [E]urope, [J]apan: ";
    cin >> option;
    carList[size].origin = newCarLocation(option);
    cout << carList[size].origin << endl << endl;
    size++;
    return;
}


int readInt(char prompt[])
{
    int temp = 0;
    cout << prompt;
    cin >> temp;
    //data validation
    while (!cin)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input!! Please enter an int";
        cin >> temp;
    }
    cin.ignore(100, '\n');

    return temp;
}

double readDouble(char prompt[])
{
    double temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input!! Please enter a double";
        cin >> temp;
    }
    return temp;
}

whereFrom newCarLocation(char letter)
{
    whereFrom thisCar;
    switch(toupper(letter))
    {
        case 'U':
            thisCar = static_cast<whereFrom>(0);
            break;

        case 'E':
            thisCar = static_cast<whereFrom>(1);
            break;
    
        case 'J':
            thisCar = static_cast<whereFrom>(2);
            break;

        default:
            thisCar = static_cast<whereFrom>(3);
    }
    return thisCar;
}

//Removes an carList from the list
void removeEntry(carType carList[], int &size)
{
    int selection;
    int index = 0;
    cout << "Please enter the index number for the car you would like to delete: " << endl;
    cin >> selection;
    index = selection - 1;
    cin.ignore(100, '\n');
    if(index < size)
    {
         for(int i = index; i < size; i++)
        {
            carList[i] = carList[i+1];
        }
    }
    size--;
    return;
}    

//This function writes the data to the file
void writeAndQuit(carType carList[], char fileName[], int size, ofstream &outFile)
{
    outFile.open(fileName);
    if(!outFile)
    {
        cout << "Output file did not open! Program exiting!" << endl;
        exit(0);
    }
    outFile << "Car Name;MPG;Cylinders;Displacement;Horsepower;Weight;Acceleration;Model;Origin\r";
    outFile << "\nCHAR ARRAY;DOUBLE;INT;DOUBLE;DOUBLE;DOUBLE;DOUBLE;INT;CAT\r";
    for(int i = 0; i < size; i++)
    {
        outFile << carList[i].name << ";";
        outFile << carList[i].mpg << ";";
        outFile << carList[i].cylinders << ";";
        outFile << carList[i].displacement << ";";
        outFile << carList[i].horsepower << ";";
        outFile << carList[i].weight << ";";
        outFile << carList[i].acceleration << ";";
        outFile << carList[i].model << ";";
        //I can't figure out how to get it to print direct enum values but don't have time to fix
        switch(carList[i].origin)
        {
            case 0:
                outFile << "US\n";
                break;
            case 1:
                outFile << "Europe\n";
                break;
            case 2:
                outFile << "Japan\n";
                break;
            default:
                outFile << "Illegal\n";
        }
    }
    outFile << endl << endl; 
    outFile.close();
    cout << "goodbye!";
    return;
}

void displayMenu()
{
    cout << "Welcome to the AutoWorld database!"<< endl << endl;
	cout << "Please select from one of the following (case insensitive) options" << endl << endl;
	cout << "[S]how information for all cars in the database" << endl;
	cout << "[I]nput information for a new car" << endl;
	cout << "[D]elete a car" << endl;
	cout << "[R]egion: search for a car by region of origin" << endl;
	cout << "[N]ame: search for a car by name (partial or full)" << endl;
	cout << "[M]PG: search for a car by minimum MPG" << endl;
	cout << "[Q]: Quit" << endl << endl;

    return;
}

