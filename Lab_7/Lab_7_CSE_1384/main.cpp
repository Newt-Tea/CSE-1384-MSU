#include <iostream>
#include <string>
#include <fstream>
#include "linkedlist.h"

using namespace std;

// functions
// makes it easier to comment out what you don't have working
// just comment out the function call if you're not ready for it in main
void checkErrorMessages(LinkedList &library);
void runInserts(LinkedList &library);
void runRemoves(LinkedList &library);
void checkPointerIntegrity(LinkedList &library);
void validPeek(LinkedList &library);
void checkClear(LinkedList &library);

int main()
{
    // ********************************************************************
    // ********************************************************************
    // ALL OF THIS SHOULD WORK WITHOUT YOU CHANGING / ADDING ANY FUNCTIONS TO LINKEDLIST
    // if you want to test your setup, comment out the portion AFTER this to see if it works

    // creates a linked list
    LinkedList library;

    // attempts to create and open the file to read
    // initializes the starting place
    ifstream infile;
    infile.open("books.txt");

    // if it isn't there...
    // end program
    if(!infile.is_open())
    {
        cout << "Couldn't locate file -- ending program." << endl;
        return 1;
    }

    // otherwise, read file
    string title, author;

    // stores title
    while(getline(infile, title))
    {
        // stores author
        getline(infile, author);

        // adds to linked list
        library.append(title, author);
    }

    // closes file
    infile.close();

    // displays intial setup:
    cout << "Initial list structure: " << endl;
    library.display();

    // ********************************************************************
    // ********************************************************************

    // this portion begins you needing to add things to make it work

    // milestone 1
    // tests a couple of error messages:
    checkErrorMessages(library);

    // milestone 2
    // tests a couple VALID inserts
    runInserts(library);

    // milestone 3
    // tests a couple VALID removes
    runRemoves(library);

    // joint milestone 5
    // run a pop and append to make sure the tail is still accounted for
    checkPointerIntegrity(library);

    // milestone 4
    // view that works
    validPeek(library);

    // joint milestone 5
    // loops until linked list is cleared
    checkClear(library);


    return 0;
}

// calls that should be *invalid* -- should trigger your error messages
void checkErrorMessages(LinkedList &library)
{
    // tests a couple of error messages:
    cout << endl << "Error checking: " << endl;
    library.remove(-1);
    library.remove(7);
    library.insert("Test", "Test", -20);
    library.insert("Test", "Test", 8);
    library.view(-1);
    library.view(8);
    cout << endl;
}

// tests a couple inserts --> tail, head, and middle insertion
void runInserts(LinkedList &library)
{
    // tests a couple VALID inserts
    library.insert("I, Robot", "Isaac Asimov", 7);
    library.insert("Brave New World", "Aldous Huxley", 0);
    library.insert("Animal Farm", "George Orwell", 5);

    cout << "Display after inserts: " << endl;
    library.display();
}

// runs a couple removes --> tail, head, and middle removal
void runRemoves(LinkedList &library)
{
    // tests a couple VALID removes
    library.remove(0);
    library.remove(8);
    library.remove(7);
    library.remove(3);

    cout << endl << "Display after removes: " << endl;
    library.display();
}

// this ultimately sees if your linked list still is linked correctly
// called after some of the items you should have seen
// verifies your pointer integrity part one
void checkPointerIntegrity(LinkedList &library)
{
    // run a pop and append to make sure the tail is still accounted for
    library.pop();
    library.append("Frankenstein", "Mary Shelley");

    cout << endl << "Display after a pop and append:" << endl;
    library.display();
}

// just a simple valid peek
void validPeek(LinkedList &library)
{
    // view that works
    cout << endl << "Viewing a specific book: " << endl;
    library.view(3);
    cout << endl;
}

// removes all items
// checks the error message associated with it
// verifies your pointer integrity part two
void checkClear(LinkedList &library)
{
    // loops until linked list is cleared
    int num = library.pop();

    while(num == 0)
    {
        num = library.pop();
    }


    // attempts to display
    cout << endl << "Display attempt after empty:" << endl;
    library.display();
}
