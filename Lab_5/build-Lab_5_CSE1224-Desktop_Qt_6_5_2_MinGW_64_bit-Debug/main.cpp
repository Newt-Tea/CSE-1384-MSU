/*
Name: Hudson Hargrove NetID: HTH113
Date: 10/5/2023 Due Date: 10/5/2023
Description: This program reads in a students course schedule from a .txt file and returns the schedule or the GPA
with the option to add and remove courses from this schedule
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "course.h"

using namespace std;

// functions given to you:
void displaySchedule(vector<Course> &schedule);

// plugs into the average...
int returnTotalQualityPoints(vector<Course> &schedule);
int returnTotalHours(vector<Course> &schedule);
float returnGPA(vector<Course> &schedule);

// student created functions:
// YOU MUST CREATE THESE.
void addClass(vector<Course> &schedule);
void removeClass(vector<Course> &schedule);

//Test function for milestone 1
void tester();

int main()
{
    tester();
    vector<Course> schedule;
    ifstream infile;
    string filename;

    // file opening
    cout << "Enter a file name: ";
    cin >> filename;

    infile.open(filename);

    // validation loop
    while(!infile.is_open())
    {
        cout << endl << "Invalid file. Please try again." << endl;
        cout << "Enter a file name: ";
        cin >> filename;

        infile.open(filename);
    }

    cout << endl << "File reading..." << endl;

    // ******************************************
    // add file reading here
    while(!infile.eof()) {
        string tmpName;
        char tmpGrade;
        int tmpHours;
        string trash;

        //Reads information for the course from the file
        getline(infile,tmpName);
        infile >> tmpHours;
        infile >> tmpGrade;

        //Checks if hours are more then 19 and breaks loop
        if (tmpName == "")
        {
            break;
        }

        //creates a new course with the info from the file then puts it in the schedule vector
        Course class1(tmpName, tmpHours, tmpGrade);
        schedule.push_back(class1);

        //Removes whitespace
        getline(infile,trash);

    }
    // ******************************************


    infile.close();

    cout << "Reading complete. File closed." << endl << endl;

    // menuing
    cout << "Welcome to the GPA manager." << endl;

    string option;

    while(1)
    {
        cout << endl << "0. Exit" << endl;
        cout << "1. View Schedule" << endl;
        cout << "2. Add Class" << endl;
        cout << "3. Remove Class" << endl;
        cout << "4. Display GPA" << endl;
        cout << "Enter menu option: ";
        cin >> option;

        cout << endl;

        // exit
        if(option == "0")
        {
            cout << "Good-bye!" << endl;
            break;
        }

        // display schedule
        else if(option == "1")
        {
            displaySchedule(schedule);
        }

        // ******************************************
        // finish menu options here...

        //Add a course to the vector
        else if(option == "2")
        {
            addClass(schedule);
        }

        //Remove a course from the vector
        else if(option == "3")
        {
            removeClass(schedule);
        }


        // ******************************************

        // display gpa
        else if(option == "4")
        {
            cout << "Your GPA with this schedule is: " << returnGPA(schedule) << endl;
        }

        // wrong menu option
        else
        {
            cout << "Invalid menu option. Try again." << endl;
        }
    }

    return 0;
}

//Tester function for milestone 1
// tests empty constructor
void tester()
{
    cout << "Beginning tester class..." << endl;
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

    cout << "End of tester class" << endl << "----------------------------------------------------------------------------------------------------" << endl << endl;
}

// ******************************************
// ******************************************
// functions given to you

void displaySchedule(vector<Course> &schedule)
{
    for(int i = 0; i < schedule.size(); i++)
    {
        cout << "Course: " << schedule[i].getName() << endl;
        cout << "Hours: " << schedule[i].getHours() << "\tGrade: " << schedule[i].getGrade() << endl << endl;
    }

    cout << "Total schedule hours: " << returnTotalHours(schedule) << endl;

}

int returnTotalQualityPoints(vector<Course> &schedule)
{
    int points = 0;

    for(int i = 0; i < schedule.size(); i++)
    {
        points += (schedule[i].returnPoints() * schedule[i].getHours());
    }

    return points;
}

int returnTotalHours(vector<Course> &schedule)
{
    int hours = 0;

    for(int i = 0; i < schedule.size(); i++)
    {
        hours += schedule[i].getHours();
    }

    return hours;
}

float returnGPA(vector<Course> &schedule)
{
    return float(returnTotalQualityPoints(schedule)) / float(returnTotalHours(schedule));
}

// ******************************************
// ******************************************
void addClass(vector<Course> &schedule)
{
    //Error checking
    if (returnTotalHours(schedule)>=19)
    {
        cout << "You can't add more once you're at 19 hours! Try removing a class first." << endl;
    }
    else
    {
        string tmpName;
        int tmpHours;
        char tmpGrade;

        //Populating course values
        cout << "Enter the course Name: ";
        cin.ignore();
        getline(cin,tmpName);

        cout << "Enter the number of hours the course is(1-4): ";
        cin >> tmpHours;

        //Error checking
        while((tmpHours < 1 || tmpHours > 4))
        {
            cout << "Invalid hour amount. Please try again" << endl;
            cout << "Enter the number of hours the course is (1-4): ";
            cin >> tmpHours;
        }

        //Error checking
        bool goodGrade = false;
        while(!(goodGrade == true))
        {
            cout << "Enter your course grade (A, B, C, D, F): ";
            cin >> tmpGrade;
            switch (tmpGrade) {
            case 'A':
                goodGrade = true;
                break;
            case 'B':
                goodGrade = true;
                break;
            case 'C':
                goodGrade = true;
                break;
            case 'D':
                goodGrade = true;
                break;
            case 'F':
                goodGrade = true;
                break;
            default:
                cout << "Invalid grade. Please try again." << endl;
                goodGrade = false;
                break;
            }
        }
        //Adding the course to the vector with the input from the user
        Course newClass(tmpName,tmpHours,tmpGrade);
        if ((returnTotalHours(schedule) + tmpHours) <= 19){
            schedule.push_back(newClass);
        }

        //Error checking
        else{
            cout << "You can't have more then 19 hours on your schedule returning to menu..." << endl;

        }
    }
}
void removeClass(vector<Course> &schedule)
{
    int classIndex;
    //Error checking
    if(schedule.empty() == true)
    {
        cout << "You have no classes in your schedule. Please try adding them first." << endl;
    }
    else
    {
        //Displays removal options
        for(int i = 0; i < schedule.size(); i++)
        {
            cout << i+1 << ": " << schedule[i].getName() << endl;;
        }
        cout << "Which class would you like to remove: ";
        cin >> classIndex;

        //Error checking
        while((classIndex > schedule.size()) || (classIndex <= 0))
        {
            cout << "Invalid class. Please try again." << endl;
            cout << "Which class would you like to remove: ";
            cin >> classIndex;
        }

        //Deletes selected course
        schedule.erase(schedule.begin() + classIndex-1);
    }

}
