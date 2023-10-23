

#ifndef MORTGAGE_H
#define MORTGAGE_H

class Mortgage {
  private:
    double loanAmount;
    double annualInterestRate;
    double monthlyInterestRate;
    int totalYearsToRepay;
    int numberOfPayments;

  public:
    Mortgage(double, double, int);
    int getTotalYearsToRepay();
    double getLoanAmount();
    double getAnnualInterestRate();
    double getMonthlyPayment();
    double calculateMonthlyPayment();
    double calculateTotalPayback();
};

#endif
