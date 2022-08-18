// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Project2.h"
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;
int main()
{
    //Declare variables to store information for investment
    Project2* project2;
    double initialAmount;
    double monthlyDeposit;
    double annualInterest;
    int years;
    char userResponse = 'y';

    while (tolower(userResponse) != 'n') {
        //Gather information from the user for investment
        cout << fixed << setprecision(2);
        cout << setfill('*') << setw(30);
        cout << "**" << endl;
        cout << "********* Data Input *********" << endl;
        cout << "Initial Investment Amount: ";
        cin >> initialAmount;
        cout << "Monthly Deposit: ";
        cin >> monthlyDeposit;
        cout << "Annual Interest: ";
        cin >> annualInterest;
        cout << "Number of years: ";
        cin >> years;
        system("pause");
        
        cout << endl;

        //Output the formatted data
        cout << setfill('*') << setw(30);
        cout << "**" << endl;
        cout << "********* Data Input *********" << endl;
        cout << "Initial Investment Amount:   $" << initialAmount << endl;
        cout << "Monthly Deposit:   $" << monthlyDeposit << endl;
        cout << "Annual Interest:   %" << annualInterest << endl;
        cout << "Number of years:   " << years << endl;
        system("pause");

        //Pass the values to Project2 Constructor
        project2 = new Project2(initialAmount, monthlyDeposit, annualInterest, years);

        //Call the DisplayNoMonthly function
        project2->DisplayNoMonthly();
        system("pause");

        //Call the DisplayWithMonthly function
        project2->DisplayWithMonthly();
        system("pause");
        //Ask user after displaying the result for different set of values
        cout << "Would you like to try different values? (Y/y or N/n): ";
        cin >> userResponse;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
