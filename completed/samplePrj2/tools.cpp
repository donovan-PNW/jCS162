//This is the implementation file for tools.h
#include "tools.h"
#include "video.h"
//Function implementations


//displays the menu
void displayMenu()
{
	cout << "Welcome to the VideoStore:" << endl << endl;
	cout << "Pick an option" << endl;
	cout << "[A-a]: Add a movie" << endl;
	cout << "[D-d]: Display the List" << endl;
	cout << "[T-t]: Find a movie by title" << endl;
    cout << "[G-g]: Find a movie by Genre" << endl;
	cout << "[R-r]: Remove a movie" << endl;
	cout << "[Q-q]: Quit" << endl;
}

//read the option from the user
char readOption()
{
	char input;
	cin >> input;
	cin.ignore(100, '\n');
	return input;
}

//execute the option
void exeCmd(char option, Video store[], int &size)
{
	Video aVideo;
	switch (tolower(option))
	{
	case 'a':
	    if(size == CAP)
        {
            cout << "Your list is Full! Movie not added!!";
            return;
        }
        addVideo(aVideo);
		addVideo(store, size, aVideo);
        break;
	case 'd':
		showList(store, size);
		break;
	case 'r':
        showList(store, size);
        removeVideo(store, size);
		break;
	case 't':
        searchByTitle(store, size);
		break;
    case 'g':
        searchByGenre(store, size);
        break;
	case 'q':
		break;
	default:
		cout << "Invalid input, please try again!!" << endl;
	}
}

//Name: readInt (reads and validates an integer)
//input: none
//output: error message
//return: int
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
		cout << "Invalid input!! Please try again!!";
		cin >> temp;
	}
	cin.ignore(100, '\n');

	return temp;
}

//standalone overloaded addVideo function
//populate aVideo from the user
void addVideo(Video &aVideo)
{
    char letter;
    cout << "Enter a movie name:";
    cin.get(aVideo.title, MAXCHAR, '\n');
    cin.ignore(100, '\n');
    aVideo.qty = readInt("Enter quantity:");
    cout << "Enter movie genre: (A-ACTION, F-FAMILY, C-COMEDY, H-HORROR): " ;
    cin >> letter;
    cin.ignore(100, '\n');
    aVideo.genre = readGenre(letter);
    cout << "Please enter the rating of the movie:";
    cin >> aVideo.rating;
}

//converts all text to upper case
void convertCase(char tempStr[])
{
	//for(int i = 0; tempStr[i] != '\0'; i++)

	for (int i = 0; i < strlen(tempStr); i++)
	{
		tempStr[i] = toupper(tempStr[i]);
	}
}
