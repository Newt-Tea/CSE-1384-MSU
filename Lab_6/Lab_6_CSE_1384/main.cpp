/*
 * Name: Hudson Hargrove        NetID: HTH113
 * Date: 10/16/2023             Due Date: 10/19/2023
 *
 * Description: This program uses a dynamic pointer based array to store information about animals name type age and weight.
 */

#include <iostream>
#include <string>
#include <fstream>
#include "animal.h"

using namespace std;

// given to you:
void displayAnimals(Animal *animals, int size);

// ***************************************
// list your function declarations here!
void populateArray(Animal *animals, int size);
void editArray(Animal *animals, int size);
int saveArray(Animal *animals, int size);


// ***************************************

int main()
{
    // ***************************************
    // add code here to:
    // create the array and initialize it


    int size;

    cout << "How many animals are you entering: ";
    cin >> size;

    //Creating the Dynamic Array
    Animal *animals = nullptr;

    animals = new Animal[size];

    populateArray(animals, size);





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
            editArray(animals,size);
        }

        // write
        else if(option == "3")
        {
            int check;
            //Closes program if there is an error is detected opening the file to write to
            check = saveArray(animals,size);
            if (check == 1)
            {
                return 1;
            }
        }

        // wrong option
        else
        {
            cout << "That wasn't an option. Please try again." << endl;
        }
    }
    //Deallocates the array pointer
    delete [] animals;

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

void populateArray(Animal *animals, int size)
{
    string tempWord;
    int tempAge;
    float tempWeight;
    for (int i = 0; i < size; i++)
    {

        //Takes user input to set the object variables for however many animals are in the array
        cout << endl << "Enter in the animal name (no spaces!): " ;
        cin >> tempWord;
        animals[i].setName(tempWord);

        cout << "Enter in the animal type (species): ";
        cin >> tempWord;
        animals[i].setType(tempWord);

        cout << "Enter in the animal age: ";
        cin >> tempAge;
        animals[i].setAge(tempAge);

        cout << "Enter in the animal weight: ";
        cin >> tempWeight;
        animals[i].setWeight(tempWeight);

    }
}

void editArray(Animal *animals, int size)
{
    int idx;
    int tempAge;
    float tempWeight;

    //Displays all animal names in the array
    for (int i = 0; i < size; i++)
    {
        cout << "Animal " << i+1 << ": " << animals[i].getName() << endl;
    }

    cout << endl << "Which animal would you like to edit: ";
    cin >> idx;
    //Brings the user input back to regular index values
    idx -= 1;
    //Checks to make sure the index is valid for the array
    while(idx >= size || idx < 0)
    {
        cout <<  endl << "Invalid Position. Please try again." << endl;
        cout << "Which animal would you like to edit: ";
        cin >> idx;
        idx -= 1;
    }
    //Takes user input to change the value of the object chosen earlier in the function
    cout << endl << "Enter in the new age: ";
    cin >> tempAge;
    animals[idx].setAge(tempAge);

    cout << "Enter in the new weight: ";
    cin >> tempWeight;
    animals[idx].setWeight(tempWeight);

}

int saveArray(Animal *animals, int size)
{
    ofstream outFile;
    string fileName;

    //Creates the file indicated by the user
    cout << "Enter the file you'd like to save to (including extenstion): ";
    cin >> fileName;
    outFile.open(fileName);
    //Error checking
    if(!outFile.is_open()) {
        cout << "Error opening/creating file. Exiting program." << endl;
        delete [] animals;
        return 1;
    }
    //saves the values from the array into the file
    for(int i = 0; i < size; i++) {
        outFile << animals[i].getName() << " " << animals[i].getType() << " " << animals[i].getAge() << " " << animals[i].getWeight() << endl;
    }

    cout << endl;

    outFile.close();

    cout << "Animals saved." << endl;

    return 0;

}
