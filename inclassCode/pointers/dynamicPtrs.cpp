//This program demos new and delete keywords to create dynamic pointers
#include <iostream>
using namespace std;

int main()
{
	int *ptr = NULL;
	//bad idea to do anything before allocating memory
	//cout << "Bad ptr value = " << *ptr << endl;
	ptr = new int;
	*ptr = 15;
	cout << "ptr's value = " << *ptr << endl;
	//bad idea to allocate new memory without deleting previous memory
	delete ptr;
	ptr = NULL;
	ptr = new int;
	*ptr = 20;
	cout << "New ptr value = " << *ptr << endl;
	//deallocate ptr
	delete ptr;

	return 0;
}
	
