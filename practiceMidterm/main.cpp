#include "array.h"
using namespace std;

const int CAP = 100;
int main()
{
	int list[CAP];
	int size = 10;
    build(list, size);
    display(list, size);
    int target = 77;
    int totalSum;
    int integersRemoved;

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    totalSum = sumOfArray(list, size);
    cout << endl << "Total sum of list: " << totalSum << endl;
    integersRemoved = remove(list, size, target);
    cout << endl << "New list: " << endl;
    display(list, size);
    cout << endl << "All instances of "<< target << " have been removed!" << endl;
    cout << "Number of integers removed: " << integersRemoved << endl;

    
    return 0;
}
