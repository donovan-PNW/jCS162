//This is the implementation file for the carEntry class
#include "headers.h"

//default constructor
carEntry::carEntry()
{
    //allocate memory
    name = NULL; 
    mpg = 0;
    cylinders = 0;
    displacement = 0;
    horsepower = 0;
    weight = 0;
    acceleration = 0;
    model = 0;
    origin = ILLEGAL;
}
//parameter constructor
carEntry::carEntry(char tempName[MAX_CHAR], double tempMpg, int tempCylinders, double tempDisplacement, double tempHorsepower, double tempWeight, double tempAcceleration, int tempModel, whereFrom tempOrigin)
{
    name = new char[strlen(tempName) + 1];
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

//copy constructor
carEntry::carEntry(const carEntry &thisCar)
{
    name = new char[strlen(thisCar.name) + 1];
    strcpy(name, thisCar.name);
    mpg = thisCar.mpg;
    cylinders = thisCar.cylinders;
    displacement = thisCar.displacement;
    horsepower = thisCar.horsepower;
    weight = thisCar.weight;
    acceleration = thisCar.acceleration;
    model = thisCar.model;
    origin = thisCar.origin;
}
//destructor
carEntry::~carEntry()
{
    //Kaboom!
    if(name)
    {
        delete [] name;
        name = NULL;
    }
}

//mutator functions
void carEntry::setCarName(char newName[])
{
    if(name)
    {
        delete [] name;
    }
    name = new char[strlen(newName)+1];
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
void carEntry::printCarEntry()
{
    char originDesc[MAX_CHAR];
    printOrigin(this->origin, originDesc);
    cout << name << ';' << mpg << ';' << cylinders << ';' << displacement << ';' << horsepower << ';' << weight << ';' << acceleration << ';' << model << ';' << originDesc << endl;
}
void carEntry::printCarEntry(ofstream &outFile)
{
    char originDesc[MAX_CHAR];
    printOrigin(this->origin, originDesc);
    outFile << name << ';' << mpg << ';' << cylinders << ';' << displacement << ';' << horsepower << ';' << weight << ';' << acceleration << ';' << model << ';' << originDesc << endl;
}

//This function assigns a whereFrom based on the letter and returns the whereFrom
whereFrom readOrigin(char letter)
{
    whereFrom tempOrigin;
    switch(toupper(letter))
    {
        case 'U':
            tempOrigin = static_cast<whereFrom>(0);
            break;
        case 'E':
            tempOrigin = static_cast<whereFrom>(1);
            break;
        case 'J':
            tempOrigin = static_cast<whereFrom>(2);
            break;
        default:
            tempOrigin = static_cast<whereFrom>(3);
    }
    return tempOrigin;
}

//This function populates the originDesc based on the whereFrom
void printOrigin(whereFrom tempOrigin, char originDesc[])
{
    switch(tempOrigin)
    {
        case 0:
            strcpy(originDesc, "US");
            break;
        case 1:
            strcpy(originDesc, "EUROPE");
            break;
        case 2:
            strcpy(originDesc, "JAPAN");
            break;
        default:
            strcpy(originDesc, "ILLEGAL");
    }
    return;
}

const carEntry& carEntry::operator= (const carEntry& thisCar)
{
    if(this == &thisCar)
        return *this;
    else
    {
        this->setCarName(thisCar.name);
        this->mpg = thisCar.mpg;
        this->cylinders = thisCar.cylinders;
        this->displacement = thisCar.displacement;
        this->horsepower = thisCar.horsepower;
        this->weight = thisCar.weight;
        this->acceleration = thisCar.acceleration;
        this->model = thisCar.model;
        this->origin = thisCar.origin;

        return *this;
    }

}

