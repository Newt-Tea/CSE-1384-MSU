#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    /*
    Name: Hudson Hargrove               NetID: hth113
    Date: 9/6/2023                      Due Date: 9/7/2023

    Description: This program is designed to help the user budget based on their projected budget goal vs their actual expenses
    and tell the user if they stayed true to their budget or if they spent over or under their budget.
    */

    //Initilize variables
    float income;
    float save;
    int expensesNum;
    float expensesTotal = 0;
    float tmpExpense;
    float budget;

    //Set decimal precision to .00 to account for USD format
    cout << fixed;
    cout << setprecision(2);

    //Welcome Message
    cout << "Welcome to the budget calculator." << endl << endl;

    //Determines the total income as well as the budget goal
    cout << "Please enter your starting monthly income: $";
    cin >> income;
    cout << "Please enter the amount you' like to save this month: $";
    cin >> save;
    cout << endl;

    budget = income - save;

    cout << "Your months budget is $" << budget << endl << endl;

    //Determines the number of expenses made in the month
    cout << "How many expenses did you have this month? ";
    cin >> expensesNum;

    //Determines the amount in total spent on expenses throughout the month
    for (int i = 0;i < expensesNum; i++) {
        cout << "How much did you spend on expense " << i+1 << ": ";
        cin >> tmpExpense;
        cout << endl;
        while(tmpExpense < 0.009999999) {
            cout << "You must have spent at least 0.01 for it to be an expense. Try again" << endl;
            cout << "How much did you spend on expense " << i+1 << ": ";
            cin >> tmpExpense;
            cout << endl;
        }
        expensesTotal += tmpExpense;
    }

    cout << endl << "Calculating..." << endl;
    cout << "You spent $" << expensesTotal << " this month." << endl << endl;

    //Determines if the user held true to their budget or, went over/under and by how much.
    if((expensesTotal-5 <= budget) && (expensesTotal + 5 >= budget)) {
        cout << "You were on budget this month!";
    }
    else if (expensesTotal >  budget) {
        cout << "You came in $" << expensesTotal - budget << " over your budget this month.";
    }
    else if (expensesTotal < budget) {
        cout << "You came in $" << budget - expensesTotal << " under your budget this month.";
    }


    return 0;
}
