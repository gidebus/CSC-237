

#include <iostream>
#include <iomanip>
#include "Mortgage.h"

using namespace std;

int main() {
  char userInput;

  do {
    double loanAmount, annualInterestRate, monthlyPayments, totalRepayment;
    int totalYearsToRepay;

    cout << "\nEnter the amount of the loan: ";
    cin >> loanAmount;

    cout << "\nEnter the annual interest rate in decimal form (example .075): ";
    cin >> annualInterestRate;

    cout << "\nEnter the length of the loan in years: ";
    cin >> totalYearsToRepay;

    Mortgage loan = Mortgage(loanAmount, annualInterestRate, totalYearsToRepay);
    monthlyPayments = loan.calculateMonthlyPayment();
    totalRepayment = loan.calculateTotalPayback();

    cout << endl;
    cout << "Loan Amount: $" << fixed << setprecision(2) << loan.getLoanAmount() << endl;
    cout << "Annual Interest Rate: " << fixed << setprecision(5) << loan.getAnnualInterestRate() << endl;
    cout << "Years to repay: " << loan.getTotalYearsToRepay() << endl;
    cout << "Monthly Payment: $" << fixed << setprecision(2) << monthlyPayments << endl;
    cout << "Total Pay Back: $" << fixed << setprecision(2) << totalRepayment << endl;

    cout << "\nDo you wish to process another loan? y/n: ";
    cin >> userInput;
  } while(userInput == 'y' || userInput == 'Y');

  cout << "\nExiting program. Goodbye!" << endl;

  return 0;
}
