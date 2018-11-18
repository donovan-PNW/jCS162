//This code demos enums and their functions
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

enum Genre {ACTION, FAMILY, COMEDY, HORROR, ILLEGAL};

//function prototypes
Genre readGenre(char);
void printGenre(Genre, char []);

//main
int main()
{
	Genre genre;
	char option;
	char genreDesc[101];
	
	cout << "Please pick a genre (a: Action, f: Family, c: Comedy, h: Horror" << endl;
	cin >> option;
	genre = readGenre(option);
	printGenre(genre, genreDesc);
	cout << "You entered: " << genreDesc << endl; 
	
	return 0;
}


//This function assigns a Genre based on the letter and returns the Genre
Genre readGenre(char letter)
{
    Genre tempGenre;
    switch(tolower(letter))
    {
        case 'a':
            //tempGenre = static_cast<Genre>(0);
			tempGenre = ACTION;
            break;
        case 'f':
            tempGenre = static_cast<Genre>(1);
            break;
        case 'c':
            tempGenre = static_cast<Genre>(2);
            break;
        case 'h':
            tempGenre = static_cast<Genre>(3);
            break;
        default:
            tempGenre = static_cast<Genre>(4);
    }
    return tempGenre;
}

//This function populates the genreDesc based on the Genre
void printGenre(Genre tempGenre, char genreDesc[])
{
    switch(tempGenre)
    {
        case ACTION:
            strcpy(genreDesc, "ACTION");
            break;
        case 1:
            strcpy(genreDesc, "FAMILY");
            break;
        case 2:
            strcpy(genreDesc, "COMEDY");
            break;
        case 3:
            strcpy(genreDesc, "HORROR");
            break;
        case 4:
            strcpy(genreDesc, "ILLEGAL");
            break;
    }
    return;
}

