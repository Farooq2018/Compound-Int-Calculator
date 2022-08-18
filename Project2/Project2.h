
#ifndef PROJECT2_H
#define PROJECT2_H


#include <iostream>
class Project2 {
public:
    //Default Constructor
    Project2();
    //Parameterize Constructor
    Project2(double initialInv, double monthlyDeposit, double interest, int years);
    bool UserInputandValidation(void);
    void DisplayNoMonthly(void);
    void DisplayWithMonthly(void);
private:
    double initialInvestmentAmount;
    double monthlyDeposit;
    double annualInterest;
    int numberOfYears;


    void CalcYearInterest(double initialAmount, double& interestAmount, double& finalAmount);

};

#endif // !1
