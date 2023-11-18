

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
    int getTotalYearsToRepay() const;
    double getLoanAmount() const ;
    double getAnnualInterestRate() const;
    double calculateMonthlyPayment();
    double calculateTotalPayback();
};

#endif
