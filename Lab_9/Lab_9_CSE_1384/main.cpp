#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "library.h"

using namespace std;

void processFile(Library &books);

int main()
{
    Library books;

    // sets up library
    processFile(books);

    cout << "\nInitial library: " << endl;
    books.display();

    cout << endl << "Welcome to the library display manager." << endl << endl;

    while(1)
    {
        string option;

        cout << "0. Exit" << endl;
        cout << "1. Sort Library" << endl;
        cout << "2. Reverse Sort Library" << endl;
        cout << "3. Search Library" << endl;
        cout << "4. Shuffle Library" << endl;
        //cout << "5. Sort Library by Author" << endl;
        cout << "Which option would you like? ";
        cin >> option;

        cout << endl;

        // exiting
        if(option == "0")
        {
            cout << "Good-bye!" << endl;
            break;
        }

        // sorting
        else if(option == "1")
        {
            books.sort();
            books.display();
        }

        // reversing
        else if(option == "2")
        {
            books.reverseSort();
            books.display();
        }

        // searching
        else if(option == "3")
        {
            string title;

            cout << "What book title would you like to search? ";
            cin.ignore();
            getline(cin, title);

            int result = books.binarySearch(title);

            if(result > 0)
            {
                cout << endl << "Book found at position " << result << endl;
            }

            else
            {
                cout << endl << "Book not found." << endl;
            }
        }

        // shuffle
        else if(option == "4")
        {
            books.shuffle();
            books.display();
        }

        // sort library by author
        // honors / bonus credit
        /*else if(option == "5")
        {
            books.sortByAuthor();
            books.display();
        }*/

        // incorrect option
        else
        {
            cout << "That's not a valid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}

void processFile(Library &books)
{
    ifstream infile;
    string line;

    infile.open("books.txt");

    if(infile.is_open())
    {
        cout << "Successful books opening." << endl;
    }

    else
    {
        cout << "Couldn't locate file. Program closing." << endl;
        exit(EXIT_FAILURE);
    }

    while(getline(infile, line))
    {
        // first line --> title
        // second line --> author

        if(line != "")
        {
            string title, author;

            title = line;

            getline(infile, author);

            books.append(title, author);
        }
    }
}
