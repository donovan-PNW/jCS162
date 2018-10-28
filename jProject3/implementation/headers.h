#ifndef HEADERS_H
#define HEADERS_H
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

const int CAP = 1000;
const int MAX_CHAR = 101;



//data type for carEntry

enum whereFrom {US, Europe, Japan, Illegal};

class carEntry 
{
    private:
        char name[MAX_CHAR];
        double mpg;
        int cylinders;
        double displacement;
        double horsepower;
        double weight;
        double acceleration;
        int model;
        whereFrom origin;
	public:
		//constructors
		//default constructor
		carEntry();
		//constructor with parameters
		carEntry(char [], double, int, double, double, double, double, int, whereFrom);
		//destructor
		~carEntry();
		//mutator functions
		void setCarName(char []);
        void setMPG();
        void setCylinders();
        void setDisplacement();
        void setHorsepower();
        void setWeight();
        void setAcceleration();
        void setModel();
		void setOrigin(whereFrom);
		//accessor functions
		void getCarName(char []) const;
        void getMPG() const;
        void getCylinders() const;
        void getDisplacement() const;
        void getHorsepower() const;
        void getWeight() const;
        void getAcceleration() const;
        void getModel() const;
		void getOrigin(whereFrom) const;
		//print video
		void printCarEntry();
		void printCarEntry(ofstream &);		
};

class carEntryList
{
    private:
        carEntry list[CAP];
        int size;
    public:
        //constructors
        carEntryList();
        carEntryLost(char []);
        //destructor
        ~carEntryList(); 
        //data manipulators
        void addEntry();
        void removeEntry();
        void displayList();
        void searchByName();
        void searchByOrigin();
        void searchByMPG();
        void writeAndQuit();
};

void openFile(char [], ifstream &);
void openFile(char [], ofstream &);
void loadData(ifstream &, carEntry [], int &);
void displayList(carEntry [], int);
void searchByName(carEntry carEntryList[], int size);
void searchByOrigin(carEntry carEntryList[], int size);
void searchByMPG(carEntry carEntryList[], int size);
void convertCase(char tempStr[]);
void addEntry(carEntry carEntryList[], int &size);
int readInt(char prompt[]);
double readDouble(char prompt[]);
whereFrom newCarLocation(char letter);
void removeEntry(carEntry carEntryList[], int &size);
void writeAndQuit(carEntry carEntryList[], char fileName[], int size, ofstream &outFile);
void displayMenu();

#endif
