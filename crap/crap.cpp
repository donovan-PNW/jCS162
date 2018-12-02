#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int *x;
    x = new int;
    *x = 5;
    cout << x << endl;
    cout << &x << endl;
    cout << *x << endl;
    return 0;
}
