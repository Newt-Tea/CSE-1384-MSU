#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        char data;
        Node *next;

        // zero constructor
        Node()
        {
            data = ' ';
            next = nullptr;
        }

        Node(char data, Node *next)
        {
            this->data = data;
            this->next = next;
        };
};

#endif // NODE_H
