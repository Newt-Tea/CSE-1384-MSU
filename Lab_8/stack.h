#include "node.h"

#ifndef STACK_H
#define STACK_H


class Stack
{
    private:
        int size;
        Node *head, *tail;

    public:
        Stack();
        ~Stack();

        void add(char item);
        char remove();
};

#endif // STACK_H
