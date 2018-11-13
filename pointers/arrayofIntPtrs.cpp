//This program demos an array of dynamic pointers
#include <iostream>
using namespace std;

void fill(int **ptr, int rows, int cols);
void print(int **ptr, int rows, int cols);

int main()
{
	int rows = 5, cols = 4;
	//declares a 2 dim pointer
	int **ptr;
	//allocates mem for rows
	ptr = new int *[rows];
	//allocates mem for columsn
	for (int i = 0; i < rows; i++)
	{
		ptr[i] = new int[cols];
	}
	//fill it
	fill(ptr, rows, cols);
	print(ptr, rows, cols);
//bad idea to delete like this
	//delete [] ptr;
	//go through the for loop
	for(int i = 0; i < rows; i++)
	{
		delete [] ptr[i];
	}
	delete [] ptr;
	ptr = NULL;

	return 0;
}

//fill the array
void fill(int **ptr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			ptr[i][j] = 3 * i;
		}
	}
}

//print the array
void print(int **ptr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
}
