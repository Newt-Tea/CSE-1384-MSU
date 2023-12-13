/*
Name:Hudson Hargrvove NetID: HTH113
Date: 10/31/23 Due Date: <enter in due date>
Description: This program takes in a libraries inventory with names and authors and stores them to a list with the ability to add, remove, or insert from anywhere in the list.
As well as view the whole  list or a specific entry
*/
#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList()
{
    if(size > 0)
    {
        Node *temp;

        while(head != nullptr)
        {
            // grabs the node after the head
            temp = head->next;

            // deletes the head
            delete head;

            // reassigns the head
            head = temp;
        }
    }
}

// given to students
void LinkedList::append(string title, string author)
{
    // if the list is currently empty
    if(size == 0)
    {
        // create a new node at the head
        // with the information brought in
        head = new Node(title, author);

        // assigns tail to the head
        tail = head;
    }

    // otherwise, if it's not empty
    else
    {
        // creates a new node
        // with the information brought in
        Node *temp = new Node(title, author);

        // point current tail to new node
        tail->next = temp;

        // make new node the new tail
        tail = temp;
    }

    size++;
}

int LinkedList::pop()
{
    // error check:
    // checks if the current size is zero
    if(size == 0)
    {
        cout << "List was empty -- pop failed!" << endl;
        return 1; // exits from the function with fail flag
    }

    // if removing a node will empty the list
    if(size == 1)
    {
        // store current head
        Node *temp = head;

        // sanity check clear head and tail
        head = nullptr;
        tail = nullptr;

        // delete node
        delete temp;
    }

    // otherwise, if it won't
    else
    {
        // start a temporary node at the head
        Node *temp = head;

        // loop to one before the tail
        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        // delete the current tail
        delete tail;

        // sanity check clear the next pointer
        // and assign the new tail
        tail = temp;
        tail->next = nullptr;
    }

    size--;

    return 0;
}

int LinkedList::display()
{
    // error check:
    // checks if the current size is zero
    if(size == 0)
    {
        cout << "List was empty -- display failed!" << endl;
        return 1; // exits from the function with fail flag
    }

    // starts temporary Node at the beginning (head)
    Node *temp = head;
    int count = 0;

    while(temp != nullptr)
    {
        // displays information
        cout << "Book " << count << ": ";
        cout << temp->title << " by " << temp->author << endl;

        // moves the temp node to the next node in the sequence
        temp = temp->next;

        count++;
    }

    return 0;
}

// you must create
int LinkedList::insert(string title, string author, int position)
{
    int index = 0;
    Node *append = nullptr;
    Node *temp = head;
    Node *prev = nullptr;

    if((position > size) || (position < 0))
    {
        cout << "Not a valid insert -- out of range!" << endl;
        return 1;
    }
    while(index != position )
    {
        //Checks to see if your on the last Node before the append and saves that value
        //to point to the append later
        if(index == position - 1 )
        {
            prev = temp;
        }
        //Moves the temp node to the next node until it reaches the desired position
        temp = temp->next;

        index++;
    }
    //sets the temp node to the next node in to preserve it
    append = new Node(title,author);
    //Checks if your appending to the tail so you can set the new node to the tail
    if (prev != nullptr && prev->next == nullptr)
    {
        tail = append;
        append->next = nullptr;
    }
    else{
    append->next = temp;
    }
    //if previous was never assigned your appending to the head
    if(prev != nullptr)
    {
        prev->next = append;
    }
    else{
        head = append;
    }


    size++;
    return 0;
}
//Traverse through the list until you reach the position
//set the next node to a variable so you dont lose it
//set the new node to the previous nodes next
int LinkedList::remove(int position)
{
    int index = 0;
    Node *temp = head;
    Node *prev = nullptr;

    //Error Checking
    if(size == 0)
    {
        cout << "List was empty -- remove failed!" << endl;
        return 1; // exits from the function with fail flag
    }
    if((position >= size) || (position < 0))
    {
        cout << "Not a valid remove -- out of range!" << endl;
        return 1;
    }

    while(index != position )
    {
        //Checks to see if your on the last Node before the remove and saves that value
        //to point to the node after remove later
        if(index == position - 1 )
        {
            //prev = append;
            prev = temp;
        }
        //Moves the append node to the next node until it reaches the desired position
        //append = append->next;
        temp = temp->next;

        index++;
    }
    if (temp->next == nullptr)
    {
        tail = prev;
    }

    //if previous was never assigned your removing the head
    if(prev != nullptr)
    {
        prev->next = temp->next;
    }
        //sets the head node to the next node in to preserve the order
    else{
        head = temp->next;
    }
    delete temp;
    size --;
    return 0;
}

int LinkedList::view(int position)
{
    if (position > size || position < 0)
    {
        cout << "Not a valid view -- out of range!" << endl;
        return 1;
    }
    Node *temp = head;
    int index = 0;

    while(index != position )
    {

        //Moves the temp node to the next node until it reaches the desired position
        temp = temp->next;

        index++;
    }

    cout << temp->title << " by " << temp->author << endl;


    return 0;
}
