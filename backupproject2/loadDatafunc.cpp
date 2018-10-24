//Car;MPG;Cylinders;Displacement;Horsepower;Weight;Acceleration;Model;Origin
//CHAR ARRAY;DOUBLE;INT;DOUBLE;DOUBLE;DOUBLE;DOUBLE;INT;CAT

#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

const int CAP = 1000;
const int MAX_CHAR = 101;

//enum origin {US, Europe, Japan};


enum whereFrom {US, Europe, Japan, Illegal};

struct vehicle
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
void loadData(ifstream &, vehicle [], int &);
void displayList(vehicle [], int);
void searchByName(vehicle entry[], int size);
void convertCase(char tempStr[]);
void addEntry(vehicle entry[], int &size);
int readInt(char prompt[]);
double readDouble(char prompt[]);
whereFrom newCarLocation(char letter);
void removeEntry(vehicle entry[], int &size);

int main()
{
    int size = 0;
    char fileName[MAX_CHAR] = "cars.txt";
    ifstream inFile;
    ofstream outFile;
    vehicle entry[CAP];
    openFile(fileName, inFile);
    loadData(inFile, entry, size);
    displayList(entry, size);
    //searchByName(entry, size);
    //addEntry(entry, size);
    //displayList(entry, size);
    //addEntry(entry, size);
    cout << size << endl;
    removeEntry(entry, size);
    displayList(entry, size);
    cout << size << endl;
    
    //cout << size;
    return 0;
}


void loadData(ifstream &inFile, vehicle entry[], int &size)
{
    char temporaryCar[MAX_CHAR];
    inFile.ignore(100, '\r');
    inFile.ignore(100, '\r');
    inFile.get(entry[size].name, MAX_CHAR, ';');
    while(inFile)
    {
        //two ignores which will skip the first two (informational) lines.
        //IT ASSUMES THAT THE FIRST TWO LINES ARE FOR INFORMATIONAL PURPOSES AND ARE NOT ACTUAL DATA
        //cout << size << entry[size].name << endl;
        inFile.ignore(100, ';');
        inFile >> entry[size].mpg;
        inFile.ignore(100, ';');
        inFile >> entry[size].cylinders;
        inFile.ignore(100, ';');
        inFile >> entry[size].displacement;
        inFile.ignore(100, ';');
        inFile >> entry[size].horsepower;
        inFile.ignore(100, ';');
        inFile >> entry[size].weight;
        inFile.ignore(100, ';');
        inFile >> entry[size].acceleration;
        inFile.ignore(100, ';');
        inFile >> entry[size].model;
        inFile.ignore(100, ';');
        //give origin info enum origin based on cstring using strcmp
        inFile.get(temporaryCar, MAX_CHAR, '\n');
        //I have no idea what == 0 is about
        if(strcmp(temporaryCar, "US") == 0)
        {//change to entry[size]
            entry[size].origin = US;
        }
        else if(strcmp(temporaryCar, "Europe") == 0)
        {
            entry[size].origin = Europe;
        }
        else if(strcmp(temporaryCar, "Japan") == 0)
        {
            entry[size].origin = Japan;
        }
        else
        {
            entry[size].origin = Illegal;
        }

        size++;
        //inFile.ignore(100, '\n');
        inFile.get(entry[size].name, MAX_CHAR, ';');
    }
    inFile.close();
    size--; // I have no idea what caused size to shift but this fixes it
    return;
}

void displayList(vehicle entry[], int size)
{
    int i;
    for(i = 0; i < (size); i++)
    {
        cout << "index no: " << (i + 1) << "; ";
        cout << "vehicle name: " << entry[i].name << "; ";
        cout << "MPG: ";
        cout << entry[i].mpg << "; ";
        cout << "cylinders: ";
        cout << entry[i].cylinders << "; ";
        cout << "displacement: ";
        cout << entry[i].displacement << "; ";
        cout << "horsepower: ";
        cout << entry[i].horsepower << "; ";
        cout << "weight: ";
        cout << entry[i].weight << "; ";
        cout << "acceleration: ";
        cout << entry[i].acceleration << "; ";
        cout << "model: ";
        cout << entry[i].model << "; ";
        cout << "country of origin: ";
        cout << entry[i].origin << "; " << endl << endl;
       /* 
        cout << i << "; ";
        cout << entry[i].name << "; ";
        cout << entry[i].mpg << "; ";
        cout << entry[i].cylinders << "; ";
        cout << entry[i].displacement << "; ";
        cout << entry[i].horsepower << "; ";
        cout << entry[i].weight << "; ";
        cout << entry[i].acceleration << "; ";
        cout << entry[i].model << "; ";
        cout << entry[i].origin << "; " << endl;*/
    }
    return;
}





//This opens the input and output files
//but is experimental because I combined 2 from the example
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

void openFile(char fileName[], ofstream &outFile)
{
    outFile.open(fileName);
    if(!outFile)
    {
        cout << "Output file did not open! Program exiting!" << endl;
        exit(0);
    }
    return;
}


void searchByName(vehicle entry[], int size)
{
    int i;
    char searchName[MAX_CHAR];
    cout << "Please enter a vehicle name" << endl;
    cin.get(searchName, MAX_CHAR, '\n');
    for(int i=0; i < (size); i++) //(size-1)?
    {
        convertCase(searchName);
        convertCase(entry[i].name);
        if(strstr(entry[i].name, searchName) != NULL)
        {
            cout << "index no:" << i << "; ";
            cout << "vehicle name: ";
            cout << entry[i].name << "; ";
            cout << "MPG: ";
            cout << entry[i].mpg << "; ";
            cout << "cylinders: ";
            cout << entry[i].cylinders << "; ";
            cout << "displacement: ";
            cout << entry[i].displacement << "; ";
            cout << "horsepower: ";
            cout << entry[i].horsepower << "; ";
            cout << "weight: ";
            cout << entry[i].weight << "; ";
            cout << "acceleration: ";
            cout << entry[i].acceleration << "; ";
            cout << "model: ";
            cout << entry[i].model << "; ";
            cout << "country of origin: ";
            cout << entry[i].origin << "; " << endl << endl;
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
}
void addEntry(vehicle entry[], int &size)
{
    char option;
    cin.ignore(100, '\n');
    cout << "Enter the new vehicle's name: ";
    cin.get(entry[size].name, MAX_CHAR, '\n');
    cout << entry[size].name;
    cin.ignore(100, '\n');
    entry[size].mpg = readDouble("Enter the vehicle's MPG rating: ");
    cout << entry[size].mpg;
    entry[size].cylinders = readInt("Enter the vehicle's number of cylinders: ");
    entry[size].displacement = readDouble("Enter the vehicle's displacement: ");
    entry[size].horsepower = readDouble("Enter the vehicle's horsepower: ");
    entry[size].weight = readDouble("Enter the vehicle's weight: ");
    entry[size].acceleration = readDouble("Enter the vehicle's acceleration: ");
    entry[size].model = readInt("Enter the vehicle's model: ");
    cout << "Enter the new vehicle's place of manufacture: [U]s, [E]urope, [J]apan: ";
    cin >> option;
    entry[size].origin = newCarLocation(option);
    cout << entry[size].origin << endl << endl;
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

//Removes an entry from the list
void removeEntry(vehicle entry[], int &size)
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
            entry[i] = entry[i+1];
        }
    }
    size--;
    return;
}    






