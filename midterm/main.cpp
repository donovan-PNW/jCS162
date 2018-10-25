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
    display(list, size);
    //PLEASE PUT YOUR CODE HERE to call the function assigned
    count = numOfEven(list, size);
    cout << count;
    insert(list, size, newInt, position)
    display(list, size);
    
    
    return 0;
}
