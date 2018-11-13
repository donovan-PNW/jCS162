#include <iostream>
#include <fstream>
using namespace std;

const int CAP = 100;
const int MAX_CHAR = 101;

void displayMenu();
void extraMenu();

int main()
{
    displayMenu();
    extraMenu();


    return 0;
}
void displayMenu()
{
    cout << "Welcome to the AutoWorld database!"<< endl << endl;
	cout << "Please select from one of the following (case insensitive) options" << endl << endl;
	cout << "[I]nput information for a new car" << endl;
	cout << "[D]isplay information for all cars in the database" << endl;
	cout << "[R]emove a car" << endl;
	cout << "[S]earch for a car by region of origin" << endl;
	cout << "[S]earch for a car by name (partial or full)" << endl;
	cout << "[S]earch for a car by model" << endl;
	cout << "[S]earch for a car by other criteria" << endl;
	cout << "[Q-q]: Quit" << endl << endl;

    return;
}


void extraMenu()
{
    cout << "Search by:" << endl << endl;
	cout << "[M]iles per gallon" << endl;
	cout << "[N]umber of cylinders" << endl;
	cout << "[E]ngine displacement" << endl;
	cout << "[H]orsepower" << endl;
	cout << "[W]eight of vehicle" << endl;
	cout << "[A]cceleration of vehicle" << endl;
    cout << "[B]ack" << endl; 

    return;
}
