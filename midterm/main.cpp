#include "array.h"
using namespace std;

const int CAP = 100;
int main()
{
    int count;
    int newInt = 19;
    int position = 3;
	int list[CAP];
	int size = 10;
    build(list, size);
    //PLEASE PUT YOUR CODE HERE to call the function assigned
    count = numOfEven(list, size);
    cout << "\nEVEN COUNT: " << count;
    display(list, size);
    insert(list, size, newInt, position);
    display(list, size);
    cout << "ARRAY SIZE: " << size;
    
    
    return 0;
}
