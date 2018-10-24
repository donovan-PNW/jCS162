
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int semiCount;
  int index;
  char letter;
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
    if (letter == ';')
    {
      semiCount++; //consider switching these two
      index = semiCount % 8; //9 separate categories

      cout << semiCount << index << endl;
      if (index == 0)
      {
        cout << "supbro!" << endl << endl; //this is where you pull category
        //Again put this elsewhere. Pulls 1st character after last semicolon on line
        char lett = inputFile.peek();
        cout << lett;
        //but put it in its own function
      }
    }
  }
  cout << semiCount << endl << index << endl;


  return 0;
}
