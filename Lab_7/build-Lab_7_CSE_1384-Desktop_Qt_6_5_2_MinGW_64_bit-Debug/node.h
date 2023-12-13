#include <string>

using std::string;

#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        // defines basic book information
        string title, author;
        Node *next; // points to the next Node in the sequence

        // zero constructor
        Node()
        {
            title = "";
            author = "";
            next = nullptr;
        };

        // takes in basic title and author information
        // assigns next pointer to nullptr
        Node(string title, string author)
        {
            this->title = title;
            this->author = author;
            next = nullptr;
        };

        // takes in basic title and author information
        // assigns next pointer to a taken in Node
        Node(string title, string author, Node *next)
        {
            this->title = title;
            this->author = author;
            this->next = next;
        };
};

#endif // NODE_H
