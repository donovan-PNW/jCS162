#include "student.h"

int main()
{
    bool isittho;
	Student s1("G10", 3.9);
    Student s2("G20", 3.5);

    s1.print();
    s2.print();

	//write code to test Student::isLessThanByID
    s1.isLessThanByID(s2);
    //cout << isittho << endl;
	
	//write code to test Student::qualifyForHonor

	return 0;
}
