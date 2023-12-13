#include <iostream>
#include <string>

#include "stack.h"

using namespace std;

int main()
{
    Stack temp;
    string userInput;

    cout << "Enter a word: ";
    getline(cin, userInput);
    cout << endl;

    // loops through the word, adding each character to the Stack
    for(int i = 0; i < userInput.size(); i++)
    {
        temp.add(userInput[i]);
    }

    // then ... loops through the Stack, outputing items as it removes from the Stack
    for(int i = 0; i < userInput.size(); i++)
    {
        cout << temp.remove();
    }
    cout << endl;

    return 0;
}
