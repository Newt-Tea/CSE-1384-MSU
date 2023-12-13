#include <cmath>
#include "stack.h"
#include <iostream>

using namespace std;


Stack::Stack()
{
    size = 0;
    head = nullptr;
    tail = nullptr;

}
Stack::~Stack()
{
    if (size > 0)
    {
        Node* temp;

        while(head != nullptr)
        {
            temp = head->next;

            delete head;
            head = temp;
        }
    }
}

void Stack::add(char item)
{
    //If the list is empty make a new node and assign it as both the head and tail
    if (size == 0)
    {
        head = new Node(item,nullptr);
        tail = head;
    }
    else
    {
        //Create a new Node at the begininning of the list and point it to the head
        Node* temp = new Node(item,head);
        head = temp;
    }
    size++;
}
char Stack::remove()
{
    if (size == 0)
    {
        cout << "The Stack is empty you cannot remove anything" << endl;
        return 'l';
    }

        Node* temp = head->next;
        char stored = head->data;
        delete head;
        head = temp;

        size --;
        return stored;

}
