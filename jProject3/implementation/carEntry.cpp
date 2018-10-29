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


