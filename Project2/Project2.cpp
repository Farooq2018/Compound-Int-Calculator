#include "Project2.h"
#include <iomanip>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

double calculateBalanceWithoutMonthlyDeposit(double initialInvestmentAmount,double annualInterest,int numberOfYears);
void printDetails(int year, double yearEndBalance, double interestEarned);
Project2::Project2() {
	this->initialInvestmentAmount = 0.0;
	this->monthlyDeposit = 0.0;
	this->annualInterest = 0.0;
	this->numberOfYears = 0;
}

Project2::Project2(double initialInvestment, double monthlyDeposit, double interest, int years) {
	this->initialInvestmentAmount = initialInvestment;
	this->monthlyDeposit = monthlyDeposit;
	this->annualInterest = interest;
	this->numberOfYears = years;
}
bool Project2::UserInputandValidation() {
	if (initialInvestmentAmount <= 0) {
		cout << "Please enter the amount greater than $0" << endl;
	}
	return 0;
}

void Project2::DisplayNoMonthly() {
	cout << "   Balance and Interest Without Additional Monthly Deposits   " << endl;
	cout << setfill('=') << setw(65);
	cout << "=" << endl;
	cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
	cout << setfill('-') << setw(65);
	cout << "-" << endl;
	calculateBalanceWithoutMonthlyDeposit(initialInvestmentAmount, annualInterest, numberOfYears );
}
void Project2::DisplayWithMonthly() {
	cout << "   Balance and Interest With Additional Monthly Deposits   " << endl;
	cout << setfill('=') << setw(65);
	cout << "=" << endl;
	cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
	cout << setfill('-') << setw(65);
	cout << "-" << endl;
	for (int i = 1; i <= numberOfYears; i++) {
		double interest = 0.0;
		double finalAmt = 0.0;
		CalcYearInterest(initialInvestmentAmount, interest, finalAmt);
		
		printDetails(i, finalAmt, interest);
	}
}

//Calculate the yearly interest amount and balance with a monthly deposit
void Project2::CalcYearInterest(double initialAmount, double& interestAmount, double& finalAmount) {

	interestAmount = 0.0;
	finalAmount = initialAmount;
	for (int month = 0; month < 12; month++) {
		finalAmount += monthlyDeposit;
		double monthlyInterestAmount = finalAmount * ((annualInterest / 100.0) / 12.0);
		finalAmount += monthlyInterestAmount;
		interestAmount += monthlyInterestAmount;
	}
}
void printDetails(int year, double yearEndBalance, double interestEarned) {
	// TODO: your code here to implement the method
	cout << fixed << setprecision(2);
	cout << year << "\t\t$" << yearEndBalance << "\t\t\t$" << interestEarned << endl;
	// returns nothing, just prints output to cout
}

double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {

	double previous = initialInvestment;
	for (int i = 1; i <= numberOfYears; i++) {
		double endBalance;
		double interest;
		endBalance = initialInvestment * pow((1 + ((interestRate / 100.0) / 12.0)), (12.0 * i));
		interest = endBalance - previous;
		previous = endBalance;
		printDetails(i, endBalance, interest);
	}
	// return the final balance
	return 0;
}