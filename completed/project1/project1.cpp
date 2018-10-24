
#include <iostream>
#include <fstream>
using namespace std;

void carCategory(char nextChar, int& usCount, int& euroCount, int& japanCount);
void weightClass(char nextChar, int& betweeen1And2, int& between2And3, int& between3And4, int& above4);


int main()
{
  int semiCount;
  int index;
  char letter;
  char nextChar;
  int usCount = 0;
  int euroCount = 0;
  int japanCount = 0;
  int betweeen1And2 = 0;
  int between2And3 = 0;
  int between3And4 = 0;
  int above4 = 0;
  //char carLine [1000]

  //TO DO: make an if/else statement for index 6 (weight) and 9 (category)
  //then for if, do a weight function, and for 9 do a category thing
  // make sure of these numbers
  //use .peek() to get next character



  ifstream inputFile;
  inputFile.open("cars.txt");


//Here I'm reading through each character to find semicolons
//and then using the modulus operator to figure out what part of the data file I'm in
  while(!inputFile.eof())
  {
    inputFile >> letter;
    nextChar = inputFile.peek();
    if (letter == ';')
    {
      semiCount++; //consider switching these two
      index = semiCount % 8; //9 separate categories

      //cout << semiCount << index << endl;
      if (index == 0)
      {
        carCategory(nextChar, usCount, euroCount, japanCount);
      }
      else if (index == 5)
      {
        weightClass(nextChar, betweeen1And2, between2And3, between3And4, above4);
      }

    }

  }
  //cout << semiCount << endl << index << endl;
  cout << "CAR CATEGORY COUNT:" << endl;
  cout << "US: " << usCount << "\nEuropean: " << euroCount << "\nJapanese: " << japanCount << endl;
  cout << endl << endl << "WEIGHT CLASS COUNTS:" << endl;
  cout << "Cars between 1000 and 2000 lbs: " << betweeen1And2;
  cout << "\nCars between 2000 and 3000 lbs: " << between2And3;
  cout << "\nCars between 3000 and 4000 lbs: " <<  between3And4;
  cout << "\nCars above 4000 lbs: " << above4 << endl;


  return 0;
}

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
  //cout << "supbro!" << endl << endl; //this is where you pull category
  //Again put this elsewhere. Pulls 1st character after last semicolon on line

  return;
}

void weightClass(char nextChar, int& betweeen1And2, int& between2And3, int& between3And4, int& above4)
{
  //cout << "     " << nextChar;
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
// backup void carCategory(int index, char nextChar, int& usCount, int& euroCount, int& japanCount)
