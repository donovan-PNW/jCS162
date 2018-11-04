#include "student.h"

//implement the required 3 functions here

Student::Student()
{
    strcpy(id, "0");
    gpa = 0.00;
}

Student::Student(const char initID[], double initGPA)
{
    strcpy(id, initID);
    gpa = initGPA;
}

bool Student::isLessThanByID(const Student &aStudent) const
{
    bool isLessThan = false;
    char otherStudent[MAX_CHAR];
    strcpy(otherStudent, aStudent.id);
    int value = strcmp(id, otherStudent);
    cout << value << endl;
    if(value < 0)
    {
        isLessThan = true; 
        cout << "This student has a lower ID number than its comparison" << endl;
    }
    else if(value > 0)
    {
        cout << "This student has a higher ID number than its comparison" << endl;
    
    }
    cout << isLessThan << endl;
    return isLessThan;
}

bool Student::qualifyForHonor(double &minGpaForHonor) const
{
    bool qualifies = false;
    if(gpa >= minGpaForHonor)
    {
        qualifies = true;
    }
    return qualifies;
}

void Student::print() const
{
	cout << id << '\t' << gpa << endl;
    return;
}
