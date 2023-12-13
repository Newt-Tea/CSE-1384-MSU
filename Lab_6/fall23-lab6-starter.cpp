#include <iostream>
#include <string>
#include <fstream>
#include "animal.h"

using namespace std;

// given to you:
void displayAnimals(Animal *animals, int size);

// ***************************************
// list your function declarations here!



// ***************************************

int main()
{
    // ***************************************
    // add code here to:
    // create the array and initialize it




    // ***************************************


    // menu handling
    while(1)
    {
        string option;

        cout << endl << "Menu:" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Display animals" << endl;
        cout << "2. Edit animal" << endl;
        cout << "3. Write to file" << endl;
        cout << "Enter your option: ";
        cin >> option;

        cout << endl;

        // exit
        if(option == "0")
        {
            cout << "Good-bye!" << endl;
            break;
        }

        // display
        else if(option == "1")
        {
            displayAnimals(animals, size);
        }

        // edit
        else if(option == "2")
        {
            
        }

        // write
        else if(option == "3")
        {
            
        }

        // wrong option
        else
        {
            cout << "That wasn't an option. Please try again." << endl;
        }
    }



    return 0;
}

void displayAnimals(Animal *animals, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << "Animal " << i + 1 << ": " << endl;
        cout << "Name: " << animals[i].getName() << endl;
        cout << "Type: " << animals[i].getType() << endl;
        cout << "Age: " << animals[i].getAge() << endl;
        cout << "Weight: " << animals[i].getWeight() << endl;
        cout << endl;
    }
}