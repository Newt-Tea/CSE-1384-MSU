/*
Name: Hudson Hargrove NetID: hth113
Date: 11/15/2023> Due Date: 11/16/2023
Description: A program to sort books from a txt file as well as functionality to shuffle reverse sort and search through the library
*/
#include "library.h"
#include <stdlib.h>
#include <time.h>

// constructor and destructor (given to you)
Library::Library()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

Library::~Library()
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

// display and add functions (given to you)
void Library::display()
{
    // starts temporary Node at the beginning (head)
    Node *temp = head;

    while(temp != nullptr)
    {
        // displays information
        cout << temp->title << " by " << temp->author << endl;

        // moves the temp node to the next node in the sequence
        temp = temp->next;
    }
}

void Library::append(string title, string author)
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

// this shows selection sort
// as applied to linked lists
// sorting on TITLE basis
void Library::sort()
{
    // example shows: selection sort
    for(int i = 0; i < size - 1; i++)
    {
        int smallIndex = i;

        for(int j = i + 1; j < size; j++)
        {
            // gets node at j
            Node *jItem = head;
            for(int k = 0; k < j; k++)
            {
                jItem = jItem->next;
            }

            // gets node at smallIndex
            Node *smallIndexItem = head;
            for(int k = 0; k < smallIndex; k++)
            {
                smallIndexItem = smallIndexItem->next;
            }

            // runs comparison
            if(jItem->title < smallIndexItem->title)
            {
                smallIndex = j;
            }
        }

        // grabs node at index i
        Node *current = head;
        for(int k = 0; k < i; k++)
        {
            current = current->next;
        }

        // grabs node at index smallIndex
        Node *small = head;
        for(int k = 0; k < smallIndex; k++)
        {
            small = small->next;
        }

        // grabs the information at the current node
        // stores it
        string tempTitle = current->title;
        string tempAuthor = current->author;

        // swaps current data to small data
        current->title = small->title;
        current->author = small->author;

        // overwrites small data to the stored data
        // (what used to be in current)
        small->title = tempTitle;
        small->author = tempAuthor;
    }
}

// ****************************************************************
// ** you should make **
// all of these should work on a TITLE of the book basis
// ****************************************************************

// any links to resources to make it work: instructor slides
int Library::binarySearch(string title)
{
    int low = 1, high = size , mid;
    Node* temp;

    //Checks to see if the list is ascending sort or desending sort
    if(head->title < tail->title)
    {
        while(high >= low)
        {
            temp = head;
            mid = (high + low) / 2;

            for(int i = 1; i < mid; i++)
            {
                temp = temp->next;
            }
            if (temp->title < title)
            {
                low = mid + 1;
            }
            else if(temp->title > title)
            {
                high = mid - 1;
            }
            else
            {
                return mid;
            }
        }
    }
    else if(head->title > tail->title)
    {
        while(high >= low)
        {
            temp = head;
            mid = (high + low) / 2;

            for(int i = 1; i < mid; i++)
            {
                temp = temp->next;
            }
            if (temp->title > title)
            {
                low = mid + 1;
            }
            else if(temp->title < title)
            {
                high = mid - 1;
            }
            else
            {
                return mid;
            }
        }
    }
    return -1;
}

// strategy: Create an Array to hold all the indexes to make sure there are no duplicates then loop
// through to check the array for the index your going to put in if it's found reroll the integer
// until you don't find it in the array. Fill out the whole array with all 11 numbers
// then swap the value in the linked list at the index stored in the array with the head and keep going
// through the list until you swap every value
// It does this 3 times to make sure the list is shuffled well

// any links to resources to make it work: https://cplusplus.com/reference/cstdlib/
// instructor slides
// https://cplusplus.com/reference/cstdlib/srand/
void Library::shuffle()
{


    int idx = 0;
    Node* target;
    Node* swap = head;
    int arr[size];
    int count = 0;
    srand(time(NULL));
    bool dupe;
    string swapTitle = "";
    string swapAuthor = "";
    string targetTitle = "";
    string targetAuthor = "";
    int shuffles = 0;

    // Runs the shuffle 3 times to ensure it's shuffled well
    while(shuffles < 3)
    {
        // Checks to see if the index value is already taken by another list value and rerolls if true
        for (int i = 0; i < size; i++)
        {
            dupe = true;
            while(dupe == true)
            {
                idx = rand() % size;
                for(int k = 0; k <= count; k++)
                {
                    if (arr[k] == idx){
                        dupe = true;
                    }
                    else
                    {
                        dupe = false;
                        break;
                    }

                }
            }
            count ++;
            arr[i] = idx;
        }
        // Swaps the values at i with the values at idx
        for (int i = 0; i < size; i++)
        {
            target = head;

            // Iterates through the list until it's at idx
            for(int j = 0; j < arr[i]; j++)
            {
                target = target->next;
            }
            //Saves the previous values to swap them
            swapTitle = swap->title;
            swapAuthor = swap->author;

            targetTitle = target->title;
            targetAuthor = target->author;
            // Swaps the values between the two list objects
            target->author = swapAuthor;
            target->title = swapTitle;

            swap->author = targetAuthor;
            swap->title = targetTitle;
            // Moves down the list
            swap = swap->next;
        }
        // resets the swap to the front of the list
        swap = head;
        shuffles++;
    }
}

// algorithm of choice: Bubble Sort
// any links to resources to make it work:Instructor Slides
void Library::reverseSort()
{
    Node* sort;
    string jItem;
    string tempAuthor;
    string tempTitle;
    for (int i = 0; i < size - 1; i++)
    {
        sort = head;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (sort->title < sort->next->title)
            {
                //Stores the value of the orginal to swap
                tempAuthor = sort->author;
                tempTitle = sort->title;
                //Swaps the values of each with the other
                sort->title = sort->next->title;
                sort->author = sort->next->author;
                sort->next->author = tempAuthor;
                sort->next->title = tempTitle;
            }
                        sort = sort->next;

        }
    }
}


// ****************************************************************
// ****************************************************************


// HONORS / BONUS credit
// optional unless you're honors
// if not implementing, just leave it here
void Library::sortByAuthor()
{
    
}
