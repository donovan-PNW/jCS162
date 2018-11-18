//This program demos a video class
#include <iostream>
#include <cstring>
using namespace std;

//constants
const int MAXCHAR = 101;

//enumerated data type for Genre
enum Genre {ACTION, FAMILY, COMEDY, HORROR, ILLEGAL};

//function prototypes for enum
Genre readGenre(char);
void printGenre(Genre, char []);

//class Video
class Video
{
	//private data members
	private:
		char title[MAXCHAR];
		int qty;
		double rating;
		Genre genre;
	public:
		//default constructor
		Video();
		//constructor with parameters
		Video(char tempTitle[], int tempQty, double tempRating, Genre tempGenre);
		//member functions
		//accessor functions
		void getTitle(char returnTitle[]);
		int getQty();
		void getRating(double &returnRating);
		Genre getGenre();
		//mutator functions
		void setTitle(char newTitle[]);
		void setQty(int newQty);
		void setRating(double newRating);
		void setGenre(Genre newGenre);
		//print function
		void printVideo() const;
};

//implementation for the Video Class
Video::Video()
{
	strcpy(title, "No title");
    qty = 0;
    rating = 0;
	genre = ILLEGAL;
}

Video::Video(char tempTitle[], int tempQty, double tempRating, Genre tempGenre)
{
	strcpy(title, tempTitle);
	qty = tempQty;
	rating = tempRating;
	genre = tempGenre;
}

void Video::getTitle(char returnTitle[])
{
	strcpy(returnTitle, title);
}

int Video::getQty()
{
	return qty;
}

void Video::getRating(double &returnRating)
{
	returnRating = rating;
}

Genre Video::getGenre()
{
	return genre;
}

//mutator functions
void Video::setTitle(char newTitle[])
{
	strcpy(title, newTitle);
}

void Video::setQty(int newQty)
{
	qty = newQty;
}
void Video::setRating(double newRating)
{
	rating = newRating;
}
void Video::setGenre(Genre newGenre)
{
	genre = newGenre;
}

//print function
void Video::printVideo() const
{
	char genreDesc[101];
	printGenre(genre, genreDesc); 
	cout << title << ';' << qty << ';' << rating << ';' << genreDesc << endl;
}

//This function assigns a Genre based on the letter and returns the Genre
Genre readGenre(char letter)
{
    Genre tempGenre;
    switch(tolower(letter))
    {
        case 'a':
            tempGenre = static_cast<Genre>(0);
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
        case 0:
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


//main
int main()
{
	char tempTitle[101];
	int tempQty;
	double tempRating;
	Genre tempGenre;
	char option;

	Video aVideo("The Lion King", 23, 5.0, FAMILY);
	aVideo.printVideo();
	cout << "Please enter a movie title:";
	cin.get(tempTitle, 101);
	cin.ignore(5, '\n');
	cout << "Enter quantity:";
	cin >> tempQty;
	cout << "Enter rating:";
	cin >> tempRating;
	cout << "Please pick one of the following: (a) Action,(f) FAMILY, (c) COMEDY, (h) HORROR: ";
	cin >> option;
	tempGenre = readGenre(option);
	//populate aVideo using the mutator functions
	aVideo.setTitle(tempTitle);
	aVideo.setQty(tempQty);
	aVideo.setRating(tempRating);
	aVideo.setGenre(tempGenre);
	 
	/*aVideo.setTitle("Happy Feet");
	aVideo.setQty(45);
	aVideo.setRating(3.5);
	aVideo.setGenre(HORROR);*/
	Video myVideo;
	//array of videos
	Video list[10];
	aVideo.printVideo();
	myVideo.printVideo();
	for(int i = 0; i < 10; i++)
	{
		list[i].printVideo();
	}

	return 0;
}














		
