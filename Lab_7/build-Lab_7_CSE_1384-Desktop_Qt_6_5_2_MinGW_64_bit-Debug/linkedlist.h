#include <iostream>
#include "node.h"

using std::cout;
using std::endl;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class LinkedList
{
    private:
        Node *head, *tail;
        int size;

    public:
        // constructor and destructor
        LinkedList();
        ~LinkedList();

        // given to students
        void append(string title, string author);   // adds to the end of the linked list
        int pop();                                 // removes from the end of the linked list
        int display();                             // displays the entire linked list

        // you must create
        int insert(string title, string author, int position);
        int remove(int position);
        int view(int position);
};

#endif // LINKEDLIST_H
