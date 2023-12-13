/*
Name: Hudson Hargrove                       NetID: HTH113
Date: 9/24/2023                        Due Date: 9/28/2023
Description: This a program to take in two MadLib formatted txt files and allow the user
to complete the MadLib then return the completed MadLib to them with the option to save
it to a file of their choosing.
*/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void generateMadLib(vector<string>& madLib, vector<string>& label);

string getArticle(string word);

int main()
{

//Init Variables
    ifstream infiletxt;
    ifstream infilelabel;
    string file;
    vector <string> MadLibs;
    vector <string> Labels;
    string save = "";
    ofstream outfile;

//Find the name of the mad lib files and open them to read
    cout << "Enter the name of your mad lib (Do not include extenstion): ";
    cin >> file;
    cin.ignore();

    string madLibFile = file + ".txt.";
    string labelFile = file +"_labels.txt";

    infiletxt.open(madLibFile);
    infilelabel.open(labelFile);
//Error checking to make sure the file is real
    while (!infiletxt.is_open()) {
        cout << "Invalid file. Please try again" << endl;

        cout << "Enter the name of your mad lib (Do not include extenstion): ";
        cin >> file;
        cin.ignore();

        string madLibFile = file + ".txt.";
        string labelFile = file +"_labels.txt";

        infiletxt.open(madLibFile);
        infilelabel.open(labelFile);
    }

//Moving both file contents into two vectors
    while(!infiletxt.eof()) {
        string tmp;
        infiletxt >> tmp;
        MadLibs.push_back(tmp);
    }

    while(!infilelabel.eof()) {
        string tmp;
        getline(infilelabel, tmp);
        Labels.push_back(tmp);
    }

//Call to manipulate the MadLib with user input

    generateMadLib(MadLibs,Labels);
    cout << endl;

//Output the completed MadLib

    for (int i = 0; i < MadLibs.size(); i++)
    {
        cout << MadLibs.at(i) << " ";
    }
    cout << endl;

//Option to save the MadLib to a file of the users choosing

    cout << "Would you like to save this story? (yes/no) ";
    cin >> save;
    while (true)
    {
        if (save == "yes")
        {
            string fileName;
            cout << "What would you like to name the file? ";
            cin >> fileName;

            outfile.open(fileName);

//Error checking

            if(outfile.is_open() != true)
            {
                cout << "Error opening file. Exiting program";
                return 1;
            }

//Writing MadLib to the file

            for (int i = 0; i < MadLibs.size(); i++)
            {
                outfile << MadLibs.at(i) << " ";
            }
            outfile.close();
            break;
        }
        else if(save == "no")
        {
            break;
        }
//Error checking
        else
        {
            cout << "Invalid answer. Try again" << endl << "Would you like to save this story? (yes/no) ";
            cin >> save;
        }
    }

    return 0;
}

void generateMadLib(vector<string>& MadLibs, vector<string>& Labels)
{
    int labelNum = 0;

//Changes all occurences of REPLACE in the MadLib file to a value based on user input

    for( int i = 0; i < MadLibs.size(); i++ )
    {
        if (MadLibs.at(i) == "REPLACE")
        {
            cout << "Enter in " << getArticle(Labels.at(labelNum)) << Labels.at(labelNum) << ": ";
            getline(cin, MadLibs.at(i));
            labelNum ++;
        }
    }
}

string getArticle (string word)
{
//Checks if the word begins with a vowel

    if (word.at(0) == ('a') || word.at(0) == ('e') || word.at(0) == ('i') || word.at(0) == ('o') || word.at(0) == ('u'))
    {
        return "an ";
    }
    else
    {
        return "a ";
    }

}
