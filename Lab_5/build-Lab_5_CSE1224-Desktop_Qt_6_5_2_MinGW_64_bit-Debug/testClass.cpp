#include <iostream>

#include "course.h"

using std::cout;
using std::endl;

int main()
{
    // tests empty constructor
    Course class1;

    // and all resultant setters...
    class1.setName("Test Class 1");
    class1.setHours(3);
    class1.setGrade('A');


    // tests constructor with parameters
    Course class2("Test Class 2", 4, 'C');


    // tests getters and return points
    cout << "Course object 1: " << endl;
    cout << "Name: " << class1.getName() << endl;
    cout << "Hours: " << class1.getHours() << "\tGrade: " << class1.getGrade() << endl;
    cout << "Resultant grade points: " << class1.returnPoints() << endl << endl;

    cout << "Course object 2: " << endl;
    cout << "Name: " << class2.getName() << endl;
    cout << "Hours: " << class2.getHours() << "\tGrade: " << class2.getGrade() << endl;
    cout << "Resultant grade points: " << class2.returnPoints() << endl << endl;

    return 0;
}
