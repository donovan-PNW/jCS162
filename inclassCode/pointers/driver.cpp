//This is the driver file for my video class
//We will create pointers to objects
#include "video.h"
using namespace std;

//function prototypes
void funOne(Video aVideo);

int main()
{
	Video aVideo, bVideo;
	
	char tempTitle[MAXCHAR], letter;
	int tempQty;
	double tempRating;
	//Populate aVideo from the user
	cout << "Please enter a title:";
	cin.get(tempTitle, MAXCHAR);
	cout << "Please enter a genre (A-ACTION, F-FAMILY, C-COMEDY, H-HORROR, I-ILLEGAL)";
	cin >> letter;
	cout << "Please enter a quantity:";
	cin >> tempQty;
	cout << "Please enter a rating:";
	cin >> tempRating;
	//call mutator functions and set the values
	aVideo.setTitle(tempTitle);
	aVideo.setGenre(readGenre(letter));
	aVideo.setQty(tempQty);
	aVideo.setRating(tempRating);
	//output the values
	cout << "You entered:" << endl;
	aVideo.printVideo();
	Video cVideo(aVideo);
	cVideo.printVideo();
	//shallow copy !!! Do not do this unless the assigment op is overloaded!!!!
	//bVideo = aVideo;
	/*do a deep copy
	aVideo.getTitle(tempTitle);
	bVideo.setTitle(tempTitle);
	bVideo.setGenre(aVideo.getGenre());
	bVideo.setQty(aVideo.getQty());
	bVideo.setRating(aVideo.getRating());*/
	//print bVideo
	bVideo.printVideo();
	//change aVideo's title
	aVideo.setTitle("Infinity War");
	aVideo.printVideo();
	//bVideo.printVideo();
	funOne(bVideo);

	return 0;
}


//funOne
void funOne(Video aVideo)
{
	aVideo.printVideo();
}
