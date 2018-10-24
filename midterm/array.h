#ifndef ARRAY_H
#define ARRAY_H

//array.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

/* These functions are already written and can be called to test out your code */
void build(int list[], int size);  //supplied
void display(int list[], int size);  //supplied

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:
int numOfEven(int list[], int size); //compute and return the number of even integers in list
void insert(int list[], int& size, int newInt, int position); //insert newInt into the list at index “position” and update the size of the list




#endif
