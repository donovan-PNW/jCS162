#include "student.h"

int main()
{
    double minGpaForHonor = 3.7;
	Student s1("G10", 3.9);
    Student s2("G20", 3.5);

    s1.print();
    s2.print();
    cout << "Minimum GPA for honors: " << minGpaForHonor << endl;

	//write code to test Student::isLessThanByID
    //test for s2 vs s1
    if(s2.isLessThanByID(s1))
    {
        cout << "This student (s2) has a lower ID number than its comparison" << endl;
    }
    else
    {
        cout << "Student s2's ID is greater than (or equal to) its comparison" << endl;
    }
    //test for s1 vs s2
    if(s1.isLessThanByID(s2))
    {
        cout << "This student (s1) has a lower ID number than its comparison" << endl;
    }
    else
    {
        cout << "Student s1's ID is greater than (or equal to) its comparison" << endl;
    }
	//write code to test Student::qualifyForHonor
    //test for s1
    if(s1.qualifyForHonor(minGpaForHonor))
    {
        cout << "Student s1 qualifies for honors!" << endl;
    }
    else
    {
        cout << "Student s1 does not qualify for honors :(" << endl;
    }
    //test for s2
    if(s2.qualifyForHonor(minGpaForHonor))
    {
        cout << "Student s2 qualifies for honors! :)" << endl;
    }
    else
    {
        cout << "Student s2 does not qualify for honors :(" << endl;
    }
	return 0;
}














