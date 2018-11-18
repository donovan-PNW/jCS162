#ifndef VIDEO_H
#define VIDEO_H
//Struct object for video has title, genre, quantity, and rating
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

//constants
const int CAP = 1000;
const int MAXCHAR = 101;
//enumerated data type for Genre
enum Genre {ACTION, FAMILY, COMEDY, HORROR, ILLEGAL};
//data type for Video
struct Video
{
    char title[MAXCHAR];
    Genre genre;
    int qty;
    double rating;
};

//function prototypes
Genre readGenre(char);
void printGenre(Genre, char []);
void openFile(char [], ifstream &);
void openFile(char [], ofstream &);
void searchByTitle( Video [], int );
void searchByGenre( Video [], int );
void loadData(ifstream &, Video [], int &);
void addVideo(Video [], int &, const Video &);
void showList(const Video [], const int);
void removeVideo(Video [], int &);
void writeData(const Video [], int size, ofstream &);
#endif
