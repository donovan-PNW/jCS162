//This is the implementation file for the carEntry class
#include "headers.h"

//default constructor
carEntry::carEntry()
{
    strcpy(name, "Blank Car");
    mpg = 0;
    cylinders = 0;
    displacement = 0;
    horsepower = 0;
    weight = 0;
    acceleration = 0;
    model = 0;
    origin = ILLEGAL;
}
//TODO: ??? Why do you need to use temp variables here? why can't you just put them straight in?
//parameter constructor
carEntry::carEntry(char tempName[MAX_CHAR], double tempMpg, int tempCylinders, double tempDisplacement, double tempHorsepower, double tempWeight, double tempAcceleration, int tempModel, whereFrom tempOrigin)
{
    strcpy(name, tempName);
    mpg = tempMpg;
    cylinders = tempCylinders;
    displacement = tempDisplacement;
    horsepower = tempHorsepower;
    weight = tempWeight;
    acceleration = tempAcceleration;
    model = tempModel;
    origin = tempOrigin;
}

//destructor
carEntry::~carEntry()
{
    //Kaboom!
}

//mutator functions
void carEntry::setCarName(char newName[])
{
    strcpy(name, newName);
}
void carEntry::setMPG(double newMpg)
{
    mpg = newMpg;
}
void carEntry::setCylinders(int newCylinders)
{
    cylinders = newCylinders; 
}
void carEntry::setDisplacement(double newDisplacement)
{
    displacement = newDisplacement;
}
void carEntry::setHorsepower(double newHorsepower)
{
    horsepower = newHorsepower;
}
void carEntry::setWeight(double newWeight)
{
    weight = newWeight;
}
void carEntry::setAcceleration(double newAcceleleration)
{
    acceleration = newAcceleleration;
}
void carEntry::setModel(int newModel)
{
    model = newModel;
}
void carEntry::setOrigin(whereFrom newOrigin)
{
    origin = newOrigin;
}


 
//accessor functions
void carEntry::getCarName(char returnName[]) const
{
    strcpy(returnName, name);
}
double carEntry::getMPG() const
{
    return mpg;
}
int carEntry::getCylinders() const
{
    return cylinders;
}
double carEntry::getDisplacement() const
{
    return displacement;
}
double carEntry::getHorsepower() const
{
    return horsepower;
}
double carEntry::getWeight() const
{
    return weight;
}
double carEntry::getAcceleration() const
{
    return acceleration;
}
int carEntry::getModel() const
{
    return model;
}
whereFrom carEntry::getOrigin() const
{
    return origin;
}
////print video
//void printCarEntry();
//void printCarEntry(ofstream &);		








