
/*
Name: Hudson Hargrove NetID: hth113
Date: 11/27/2023 Due Date: 11/28/2023
Description: This program takes in a phrase and encodes it using the caeser cipher with a 5 point shift.
*/
#include <iostream>
#include <string>

using namespace std;

string caesarShift(string phrase, int position, bool encode);

int main()
{
    // welcome message
    cout << "Welcome to a recursive Caesar cipher simulator." << endl;

    string option;

    // menu loop
    while(1)
    {
        // menu setup
        cout << endl << "0. Exit" << endl;
        cout << "1. Encode a Message" << endl;
        cout << "2. Decode a Message" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        // spacing
        cout << endl;

        // exit
        if(option == "0")
        {
            cout << "Good-bye!" << endl;
            break;
        }

        // encode
        else if(option == "1")
        {
            string word;
            cin.ignore(); // make sure getline works properly...

            cout << "Enter in a word/phase to encode: ";
            getline(cin, word);

            // encodes
            // calls function with bool --> true
            word = caesarShift(word, 0, true);

            // displays to the user
            cout << endl << "Your encoded message is: " << word << endl;
        }

        // decode
        else if(option == "2")
        {
            // variable creation
            string word;
            cin.ignore(); // make sure getline works properly...

            cout << "Enter in a word/phase to decode: ";
            getline(cin, word);

            // decode
            // calls function with bool --> false
            word = caesarShift(word, 0, false);

            // displays to the user
            cout << endl << "Your decoded message is: " << word << endl;
        }

        // wrong choice
        else
        {
            cout << "You entered an invalid option. Try again." << endl;
        }
    }

    return 0;
}

string caesarShift(string phrase, int position, bool encode)
{
    //if encoding
    if(encode)
    {
        // grabs currently indexed letter
        char letter = phrase[position];

        // checks range of alphabet characters
        // ignores things that aren't letters
        if((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))
        {
            // A - V and a - v
            if((letter >= 'A' && letter <= 'V') || (letter >= 'a' && letter <= 'v'))
            {
                letter += 5;
            }

            // all other letters
            else
            {
                letter -= 21;
            }
        }


        // builds encoded word

        //Recursivly runs through the whole phrase and changes the phrase starting at the end and as the functions
        //complete they will return the phrase with changed letters starting from back to front

        if (position+1 < phrase.length())
        {
            phrase = caesarShift(phrase,position+1,true);
        }
        phrase[position] = letter;
        return phrase;
    }
// if decoding
    else
    {
        // grabs currently indexed letter
        char letter = phrase[position];

        // checks range of alphabet characters
        // ignores things that aren't letters
        if((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))
        {
            // A - E1 and a - e
            if((letter >= 'E' && letter <= 'Z') || (letter >= 'e' && letter <= 'z'))
            {
                letter -= 5;
            }

            // all other letters
            else
            {
                letter += 21;
            }
        }


        // builds encoded word

        //Recursivly runs through the whole phrase and changes the phrase starting at the end and as the functions
        //complete they will return the phrase with changed letters starting from back to front

        if (position+1 < phrase.length())
        {
            phrase = caesarShift(phrase,position+1,false);
        }
        phrase[position] = letter;

        return phrase;
    }
}
