//This program is similar to project2
//Uses structs to maintain a VideoStore
#include "video.h"
#include "tools.h"
void openFile(char fileName[], ifstream &inFile)
{
    inFile.open(fileName);
    if(!inFile)
    {
        cout << "Input file did not open!! Program exiting!!!" << endl;
        exit(0);
    }
}

//This opens the output file
void openFile(char fileName[], ofstream &outFile)
{
    outFile.open(fileName);
    if(!outFile)
    {
        cout << "Output file did not open!! Program exiting!!!" << endl;
        exit(0);
    }
}

void searchByTitle( Video store[], int size )
{
    char searchTitle[MAXCHAR];
    char genreDesc[MAXCHAR];
    cout << "Please enter title" << endl;
    cin.get(searchTitle, MAXCHAR, '\n');

    for(int i = 0; i < size; i++)
    {
       convertCase(searchTitle);
       convertCase(store[i].title);     
       if( strstr (store[i].title,  searchTitle) != NULL )
       {
            printGenre(store[i].genre, genreDesc);
            cout << store[i].title << ";" << genreDesc << ";" << store[i].qty << ";" << store[i].rating << endl;
       }
    }
}

//This function does a search by Genre
void searchByGenre(Video store[], int size)
{
    char letter;
    Genre srchGenre;
    char genreDesc[MAXCHAR];
    cout << "Please enter the genre to search for (A-ACTION, F-FAMILY, C-COMEDY, H-HORROR):"; 
    cin >> letter;
    srchGenre = readGenre(letter);
    for(int i = 0; i < size; i++)
    {
        if(srchGenre == store[i].genre)
        {
            printGenre(store[i].genre, genreDesc);
            cout << store[i].title << ";" << genreDesc << ";" << store[i].qty << ";" << store[i].rating << endl;
       }
    }
}    

                 
void loadData(ifstream &inFile, Video store[], int &size)
{
    char tempGenre[MAXCHAR];
    inFile.get(store[size].title, MAXCHAR, ';');
    while(inFile)
    {
        inFile.ignore(100, ';');
        inFile.get(tempGenre, MAXCHAR, ';');
        if(strcmp(tempGenre, "ACTION") == 0)
        {
            store[size].genre = ACTION;
        }
        else if(strcmp(tempGenre, "FAMILY") == 0)
        {
            store[size].genre = FAMILY;
        }
        else if(strcmp(tempGenre, "COMEDY") == 0)
        {
            store[size].genre = COMEDY;
        }
        else if(strcmp(tempGenre, "HORROR") == 0)
        {
            store[size].genre = HORROR;
        }
        else
        {
            store[size].genre = ILLEGAL;
        }

        inFile.ignore(100, ';');
        inFile >> store[size].qty;
        inFile.ignore(100, ';');
        inFile >> store[size].rating;
        inFile.ignore(100, '\n');
        size++;
        inFile.get(store[size].title, MAXCHAR, ';');
    }
    inFile.close();
}

//This is an overloaded function to add a video to the list
void addVideo(Video store[], int &size, const Video &aVideo)
{
    store[size++] = aVideo;
}

//This function prints the list of videos
    
void showList(const Video store[], const int size)
{
    char genreDesc[MAXCHAR];
    for(int i = 0; i < size; i++)
    {
        printGenre(store[i].genre, genreDesc);
        cout << i+1 << "." << store[i].title << ";" << genreDesc << ";" << store[i].qty << ";" << store[i].rating << endl;
    }
    cout << endl;
}     

//Removes a video from the list
void removeVideo(Video store[], int &size)
{
    int delIndex = 0;
    cout << "Please enter index of video to delete:";
    cin >> delIndex;
    cin.ignore(100, '\n');
    if(delIndex < size)
    {
         for(int i = delIndex; i < size; i++)
        {
            store[i-1] = store[i];
        }
    }
    size--;
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
//This function writes the data to the file
void writeData(const Video store[], int size, ofstream &outFile)
{
    char genreDesc[MAXCHAR];
    for(int i = 0; i < size; i++)
    {
        printGenre(store[i].genre, genreDesc);
        outFile << store[i].title << ";" << genreDesc << ";" << store[i].qty << ";" << store[i].rating << endl;
    }
    outFile.close();
}




























