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
	Video aVideo;
	switch (tolower(option))
	{
	case 'a':
	    if(size >= CAP)
        {
            cout << "Your list is Full! Car cannot be added.";
            return;
        }
        addVideo(aVideo);
		store.addVideo(aVideo);
        break;
	case 'd':
		store.showList();
		break;
	case 'r':
        store.showList();
        store.removeVideo();
		break;
	case 't':
        store.searchByTitle();
		break;
    case 'g':
        store.searchByGenre();
        break;
	case 'q':
		break;
	default:
		cout << "Invalid input, please try again!!" << endl;
	}
}

//gets selection from user and returns a bool value
//quitSignal=true ends the program (hopefully)
bool getSelection()
{
    bool quitSignal = false;
    cin >> tempSelection;
    cin.ignore(100, '\n');
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
            quitSignal = true;
            break;
        default:
        cout << "not an option! Please enter a valid option";

    return quitSignal;
}





