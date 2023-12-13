/*
Name: <Hudson Hargrove> NetID: <hth113>
Date: <11/9/2023> Due Date: <11/9/2023>
Description: <This program takes in Hexidecimal valuse and converts it to a base 10 Decimal Values>
*/

#include <iostream>
#include <string>
#include <cmath>

#include "stack.h"

using namespace std;

string verifyValidHex(string hex);
void hexToDec(string hex);

int main()
{
    string hex;
    string ans = "yes";
    cout << "Welcome to hexadevimal to decimal conversion." << endl << endl;

    while(ans == "yes")
    {
        cout << "Enter in a hexidecimal number to convert: ";
        cin >> hex;
        cin.ignore();
        verifyValidHex(hex);
        hexToDec(hex);


        cout << endl << "Would you like to enter another hexadecimal number (yes/no)? ";
        cin >> ans;
        cin.ignore();
        cout << endl;

        //Error Checking
        while ((ans != "yes") && (ans != "no"))
        {
            cout << "That's not a valid response. Try again. " << endl;
            cout << "Would you like to enter another hexadecimal number (yes/no)? ";
            cin >> ans;
            cin.ignore();
        }
    }

    cout << "Good-Bye!" << endl;


    return 0;
}

string verifyValidHex(string hex)
{
    // finds the index of the first character that doesn't match this set
    // if there's no character not in the set it returns -1
    int num = hex.find_first_not_of("0123456789ABCEDF");

    // runs while a char other than what we want is present
    while(num > -1)
    {
        // error message
        cout << endl << "Error. An invalid character was present in the hex number." << endl;
        cout << "Please try again with characters 0-9 and A-F only." << endl;

        // and new input
        cout << endl << "Enter in a hexadecimal number to convert: ";
        getline(cin, hex);

        // retests...
        num = hex.find_first_not_of("0123456789ABCEDF");
    }

    // returns validated number
    return hex;
}

//Converts the Hex int to Decimal notation
void hexToDec(string hex)
{
    Stack hexValues;
    int size = hex.length();
    char letter = ' ';
    int total = 0;
    //Adding the chars from the hex into our stack
    for  (int i = size; i > 0; i--)
    {
        hexValues.add(hex[i-1]);
    }
    while (size > 0)
    {
        //Removes the letter from the stack and returns it's value to evaulate
        letter = hexValues.remove();

        // checks the current letter's value
        // 0-9
        if(letter >= 48 && letter <= 57)
        {
            // corrects to a 0-9 value from the ASCII char (48 --> ASCII 0)
            int num = int(letter) - 48;
            total += pow(16,size-1)*num;
            // you can use the number from here…
        }
        // A-F
        else
        {
            // corrects to a 10-15 value from the ASCII char (65 --> ASCII A)
            int num = int(letter) - 55;
            total += pow(16,size-1)*num;
            // you can use the number from here…
        }

        size --;
    }

    cout << "Your number converted is: " << total << endl;


}
