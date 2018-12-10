#include "list.h"
using namespace std;

int main()
{
    int position = 3;
    int newInt = 555;
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int sum;
    sum = sumOfList(head);
    cout << "The sum of this list is: " << sum << endl;
    insert(head, 3, 100);
    display(head);
    remove(head, 3);
    display(head);

    return 0;
}
