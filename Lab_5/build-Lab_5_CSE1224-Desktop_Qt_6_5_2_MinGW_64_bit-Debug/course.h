#include<string>

#ifndef COURSE_H
#define COURSE_H



using namespace std;


class Course
{
private:
    string name;
    int hours;
    char grade;

public:
    Course();
    Course(string name, int hours, char grade);


    //setters
    void setName(string newName);
    void setHours(int newHours);
    void setGrade(char newGrade);

    //getters
    string getName();
    int getHours();
    char getGrade();

    int returnPoints();



};



#endif // COURSE_H
