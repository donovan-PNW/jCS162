#ifndef HEADERS_H
#define HEADERS_H
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

const int CAP = 3;
const int GROWTH = 2;
const int MAX_CHAR = 101;



//data type for carEntry

enum whereFrom {US, EUROPE, JAPAN, ILLEGAL};

class carEntry 
{
    private:
        char *name;
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
        void setMPG(double);
        void setCylinders(int);
        void setDisplacement(double);
        void setHorsepower(double);
        void setWeight(double);
        void setAcceleration(double);
        void setModel(int);
		void setOrigin(whereFrom);
		//accessor functions
		void getCarName(char []) const;
        double getMPG() const;
        int getCylinders() const;
        double getDisplacement() const;
        double getHorsepower() const;
        double getWeight() const;
        double getAcceleration() const;
        int getModel() const;
		whereFrom getOrigin() const;
		//print video
		void printCarEntry();
		void printCarEntry(ofstream &);		
};

class carEntryList
{
    private:
        carEntry *list;
        int size;
    public:
        //constructors
        carEntryList();
        carEntryList(char []);
        //destructor
        ~carEntryList(); 
        //data manipulators
        void addEntry(carEntry);
        void removeEntry();
        void displayList();
        void searchByName();
        void searchByOrigin();
        void searchByMPG();
        void writeAndQuit(char[]);
        void growList();
};

int readInt(char prompt[]);
double readDouble(char prompt[]);
void displayMenu();
char readOption();
void exeCmd(char, carEntryList & );
void printOrigin(whereFrom tempOrigin, char originDesc[]);
whereFrom readOrigin(char letter);
void addEntry(carEntry &thisCar);
void convertCase(char tempStr[]);

#endif
