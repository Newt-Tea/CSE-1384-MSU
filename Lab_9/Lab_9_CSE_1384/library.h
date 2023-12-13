#include <string>
#include <iostream>

// Node structure
#include "node.h"

// random number
// used for: shuffle
#include <time.h>
#include <stdlib.h>

using std::string;
using std::cout;
using std::endl;

#ifndef LIBRARY_H
#define LIBRARY_H


class Library
{
    private:
        Node *head, *tail;
        int size;

    public:
        // constructor and destructor (given to you)
        Library();
        ~Library();

        // display and add functions (given to you)
        void display();
        void append(string title, string author);

        // given to you
        // shows: selection sort
        void sort();

        // **** you should complete these ****
        // all of these should work on a TITLE of the book basis
        int binarySearch(string title);
        void shuffle();
        void reverseSort();     // DIFFERENT sorting algorithm of your choice 
                                // (cannot be the same as the one shown)


        // HONORS / BONUS credit
        // optional unless you're honors
        // if not implementing, just leave it here
        void sortByAuthor();    // DIFFERENT sorting algorithm of your choice
};

#endif // LIBRARY_H
