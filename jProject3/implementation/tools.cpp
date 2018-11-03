#include "headers.h"

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

char readOption()
{
	char input;
	cin >> input;
	cin.ignore(100, '\n');
	return input;
}

void exeCmd(char option, carEntryList &dealership)
{
	carEntry thisCar;
	switch (toupper(option))
	{
	case 'S':
		dealership.displayList();
		break;
	case 'I':
//	    if(size >= CAP)
//        {
//            cout << "Your list is Full! Car cannot be added.";
//            return;
//        }
        //why twice???
        addEntry(thisCar);
		dealership.addEntry(thisCar);
        break;
	case 'D':
        dealership.displayList();
        dealership.removeEntry();
		break;
	case 'N':
        dealership.searchByName();
		break;
    case 'R':
        dealership.searchByOrigin();
        break;
    case 'M':
        dealership.searchByMPG();
        break;
	case 'Q':
		break;
	default:
		cout << "Invalid input, please try again!!" << endl;
	}
}


void addEntry(carEntry &thisCar)
{
    char option;
    char tempName[MAX_CHAR];
    double tempMPG;
    int tempCylinders;
    double tempDisplacement;
    double tempHorsepower;
    double tempWeight;
    double tempAcceleration;
    int tempModel;
    whereFrom tempOrigin;

    cout << "Enter the new vehicle's name: ";
    cin.get(tempName, MAX_CHAR, '\n');
    cin.ignore(100, '\n');
    tempMPG = readDouble("Enter the vehicle's MPG rating: ");
    tempCylinders = readInt("Enter the vehicle's number of cylinders: ");
    tempDisplacement = readDouble("Enter the vehicle's displacement: ");
    tempHorsepower = readDouble("Enter the vehicle's horsepower: ");
    tempWeight = readDouble("Enter the vehicle's weight: ");
    tempAcceleration = readDouble("Enter the vehicle's acceleration: ");
    tempModel = readInt("Enter the vehicle's model: ");
    cout << "Enter the new vehicle's place of manufacture: [U]s, [E]urope, [J]apan: ";
    cin >> option;
    tempOrigin = readOrigin(option);
    //mutator functions to populate thisCar
    thisCar.setCarName(tempName);
    thisCar.setMPG(tempMPG);
    thisCar.setCylinders(tempCylinders);
    thisCar.setDisplacement(tempDisplacement);
    thisCar.setHorsepower(tempHorsepower);
    thisCar.setWeight(tempWeight);
    thisCar.setAcceleration(tempAcceleration);
    thisCar.setOrigin(tempOrigin);
    return;
}











