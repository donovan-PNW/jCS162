#include "student.h"

int main()
{
	Student s1("G10", 3.9);
    Student s2("G20", 3.5);

    s1.print();
    s2.print();

	//write code to test Student::isLessThanByID
    s1.isLessThanByID(s2);
	
	//write code to test Student::qualifyForHonor
    s1.qualifyForHonor(minGpaForHonor);
	return 0;
}
