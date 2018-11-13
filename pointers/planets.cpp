//Reads a list of planet names from the file and populates a
//dynamic 2 dim char array
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>

using namespace std;

//print function
void print(char **planets, int rows);

int main()
{
	int rows = 9;
	ifstream inFile;
	char **planets, tempName[31];
	inFile.open("planets.txt");
	if (!inFile)
	{
		cout << "File not found! Program terminating!!";
		exit(0);
	}
	//allocate mem
	planets = new char *[rows];
	int i = 0;
	while (!inFile.eof())
	{
		inFile.getline(tempName, 31);
		planets[i] = new char[strlen(tempName) + 1];
		strcpy(planets[i], tempName);
		i++;
	}
	print(planets, i);
	inFile.close();
	//deallocate all the memory
	for (i = 0; i < rows; i++)
	{
		delete[] planets[i];
	}
	delete[]planets;
	planets = NULL;
	return 0;
}

//print the array
void print(char **planets, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		cout << planets[i] << endl;
	}
}

