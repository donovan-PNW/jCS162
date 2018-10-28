#ifndef HEADERS_H
#define HEADERS_H
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

const int CAP = 1000;
const int MAX_CHAR = 101;



//data type for car

enum whereFrom {US, Europe, Japan, Illegal};

class carType 
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
		carType();
		//constructor with parameters
		carType(char [], double, int, double, double, double, double, int, whereFrom);
		//destructor
		~carType();
		//mutator functions
		void newCarName(char []);
		void setGenre(Genre);
		void setQty(int);
		void setRating(double);
		//accessor functions
		void getTitle(char []) const;
		Genre getGenre() const;
		int getQty() const;
		double getRating() const;
		//print video
		void printVideo();
		void printVideo(ofstream &);		
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

#endif
