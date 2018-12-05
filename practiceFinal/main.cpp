#include "list.h"
#include <iostream>
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int finalSum;
    int position = 0;
    int newInt = 111;
    finalSum = sumOfList(head);
    cout << "My sum is: " << finalSum << endl;
    cout << "added " << newInt << " at " << position << endl;
    insert(head, position, newInt);


    display(head);
    //destroy(head);
    
    return 0;
}
