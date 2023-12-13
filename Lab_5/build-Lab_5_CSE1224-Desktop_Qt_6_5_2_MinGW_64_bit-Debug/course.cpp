#include "course.h"

Course::Course()
{
    name = "";
    hours = 0;
    grade = 'n';
}

Course::Course(string name, int hours, char grade)
{
    this->name = name;
    this->hours = hours;
    this->grade = grade;
}

void Course::setName(string newName){
    this->name = newName;
}
void Course::setHours(int newHours){
    this->hours = newHours;
}
void Course::setGrade(char newGrade){
    this->grade = newGrade;
}

string Course::getName()
{
    return name;
}
int Course::getHours()
{
    return hours;
}
char Course::getGrade()
{
    return grade;
}

int Course::returnPoints()
{

    if (grade == 'A')
    {
            return 4;
    }
    else if (grade == 'B')
    {
        return 3;
    }
    else if (grade == 'C')
    {
            return 2;
    }
    else if (grade == 'D')
    {
            return 1;
    }
    else if (grade == 'F')
    {
            return 0;
    }
    return 0;
}
