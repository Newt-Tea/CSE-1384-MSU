/*
 * Name: Hudson Hargrove                    NetID: hth113
 * Date: 9/8/2023                           Due Date:9/14/23
 *
 * Description: This program takes in lab scores as an array then manipulates those values based on user input it can also show the average
 * of all test scores
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    // initial variables
    int labs[10], size = 0;
    string option;
    // receives lab scores
    // loops up to 10 times, otherwise stops when the user enters -1
    cout << "Enter up to 10 lab scores. If you'd like to stop before then, enter -1." << endl << endl;
        for(int i = 0; i < 10; i++)
    {
        // gets user lab score
        int score;
        cout << "Enter in lab score " << i + 1 << ": ";
        cin >> score;
        cin.ignore();
        // breaks if the score was -1
        if(score == -1)
        {
            cout << "Ended lab gathering." << endl;
            break;
        }
        // checks to make sure the score is valid
        while (((score < 0) || (score > 100)) && score != -1) {
            cout << "Invalid item. Try again." << endl;
            cout << "Enter in lab score " << i + 1 << ": ";
            cin >> score;
        }
        if(score == -1)
        {
            cout << "Ended lab gathering." << endl;
            break;
        }
        // otherwise, puts value into the array at index i
        // increases the user size

        labs[i] = score;
        size++;
    }
    cout << endl << "Entering lab score management." << endl;
    // menuing for the user
    while(1)
    {
        // menu options
        cout << endl << "0. Exit" << endl;
        cout << "1. Display lab scores" << endl;
        cout << "2. Edit lab score" << endl;
        cout << "3. Add lab score" << endl;
        cout << "4. Average lab scores" << endl;
        cout << "Enter your menu choice: ";
        cin >> option;
        cout << endl;




        // Menuing code goes here....
        // Exits the program
        if (option == "0") {
            cout << "Good-bye!" << endl;
            return(0);
        }
        // Displays the current lab scores
        else if (option == "1"){
            cout << "Display area" << endl;

            for (int i = 0; i < size; i++){
                cout << "Lab " << i+1 << ": " << labs[i] << endl;
            }
            cout << endl;
        }
        // Allows the user to overwrite one of the lab scores
        else if (option == "2") {
            int score;
            int labNum = -1;

            cout << "Edit area" << endl;
            // takes the lab number then checks to see if it is valid otherwise continues to the lab score
            while ((labNum < 1) || (labNum > size)) {
                cout << "Enter the lab you'd like to change (1-" << size << "): ";
                cin >> labNum;
                if ((labNum < 1 ) || (labNum > size )) {
                    cout << "Invalid lab number. Try again." << endl;
                }
            }
            cout << "Enter the score you'd like to change to: ";
            cin >> score;

            // checks to make sure the score is valid otherwise edits the score in the array
            while((score < 0) || (score > 100)){
                cout << "Invalid item. Try again." << endl;
                cout << "Enter the score you'd like to change to: ";
                cin >> score;

            }
            labs[labNum-1] = score;
        }
        // Allows the user to add a new score as long as they haven't reached the limit
        else if (option == "3"){
            if (size != 10) {
                int score = 0;

                cout << "Add score area" << endl;
                cout << "Enter the score you'd like to add: ";
                cin >> score;
                // checks to make sure the score is valid otherwise adds the score to the array
                while((score < 0) || (score > 100)) {
                    cout << "Invalid score. Try again" << endl;
                    cout << "Enter the score you'd like to add: ";
                    cin >> score;
                }
                labs[size] = score;
                size ++;
            }
            else {
                cout << "Array at max capacity. Try an edit instead." << endl;
            }
        }
        // Prints the average test score
        else if (option == "4") {
            int total = 0;

            cout << "Average score area" << endl;

            //loops through the array to and adds all the scores into total
            for (int i = 0; i < size; i++) {
                total = total + labs[i];
            }
            //finds the average and outputs it
            total = total / size;
            cout << "Your lab score average is: " << total << endl;
        }
        else{
            cout << "Invalid menu option. Try again" << endl;
        }
    }
    return 0;
}
