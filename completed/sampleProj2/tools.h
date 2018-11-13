#ifndef TOOLS_H
#define TOOLS_H

#include "video.h"

//function prototypes
int readInt(char prompt[]);
void displayMenu();
char readOption();
void exeCmd(char option, Video [], int &);
void addVideo(Video &);
void convertCase(char tempStr[]);

#endif
