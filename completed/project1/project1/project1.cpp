/*
Author: Eamon Donovan
Date: 9/28/2018
This program is written to take data from a database of cars and report the number of vehicles made in different regions,
as well as their weight classes.
It assumes that the input file is correctly written -- data will be corrupted if it is not.
*/


#include <iostream>
#include <fstream>
using namespace std;

//function prototypes
void carCategory(char nextChar, int& usCount, int& euroCount, int& japanCount);
void weightClass(char nextChar, int& betweeen1And2, int& between2And3, int& between3And4, int& above4);


int main()
{
  int semiCount;
  int index;
  char currentChar;
  char nextChar;
  int usCount = 0;
  int euroCount = 0;
  int japanCount = 0;
  int betweeen1And2 = 0;
  int between2And3 = 0;
  int between3And4 = 0;
  int above4 = 0;

  ifstream inputFile;
  inputFile.open("cars.txt");


//Here I'm reading through each character to find semicolons
//and then using the modulus operator to figure out what part of the data file I'm in
//if the category is not relevant, the program will pass by
  while(!inputFile.eof())
  {
    inputFile >> currentChar;
    nextChar = inputFile.peek();
    if (currentChar == ';')
    {
      semiCount++;
      index = semiCount % 8; //9 separate categories per line with 8 ';'s between them
      //if the program reaches the column where the car's category is held, it calls the carCategory function
      if (index == 0)
      {
        carCategory(nextChar, usCount, euroCount, japanCount);
      }
      //if the program reaches the column where the car's weight class is held, it calls the weightClass function
      else if (index == 5)
      {
        weightClass(nextChar, betweeen1And2, between2And3, between3And4, above4);
      }

    }

  }
  //after all data is read, this section of main prints out each variable along with text for readability
  //cout << semiCount << endl << index << endl; <-- debug tool
  cout << endl <<"CAR CATEGORY COUNT:" << endl;
  cout << "US: " << usCount << "\nEuropean: " << euroCount << "\nJapanese: " << japanCount << endl << endl;
  cout << "WEIGHT CLASS COUNTS:" << endl;
  cout << "Cars between 1000 and 2000 lbs: " << betweeen1And2;
  cout << "\nCars between 2000 and 3000 lbs: " << between2And3;
  cout << "\nCars between 3000 and 4000 lbs: " <<  between3And4;
  cout << "\nCars above 4000 lbs: " << above4 << endl << endl;


  return 0;
}

//When the program reaches the car class category, it uses the next character ahead of the ';' character
//to determine the category. U = us, E = european, or else: japanese
void carCategory(char nextChar, int& usCount, int& euroCount, int& japanCount)
{
  if (nextChar == 'U')
  {
    usCount++;
  }
  else if (nextChar == 'E')
  {
    euroCount++;
  }
  else
  {
    japanCount++;
  }

  return;
}

//This one uses a switch statement instead, using the same logic
//1 = 1000 - 1999, 2 = 2000 - 2999, 3 = 3000 - 3999, with a default of above 4000
void weightClass(char nextChar, int& betweeen1And2, int& between2And3, int& between3And4, int& above4)
{
  switch (nextChar)
  {
    case '1':
      betweeen1And2++;
      break;
    case '2':
      between2And3++;
      break;
    case '3':
      between3And4++;
      break;
    default:
      above4++;
      break;
  }
  return;
}
