

#include "Mortgage.h"
#include <cmath>

Mortgage::Mortgage(double loanAmount, double annualInterestRate, int totalYearsToRepay) {
  this->loanAmount = loanAmount;
  this->annualInterestRate = annualInterestRate;
  this->totalYearsToRepay = totalYearsToRepay;
  this->monthlyInterestRate = annualInterestRate / 12;
  this->numberOfPayments = totalYearsToRepay * 12;
}

int Mortgage::getTotalYearsToRepay() const {
  return totalYearsToRepay;
}

double Mortgage::getLoanAmount() const {
  return loanAmount;
}

double Mortgage::getAnnualInterestRate() const {
  return annualInterestRate;
}

double Mortgage::calculateMonthlyPayment() {
  double powerFactor = pow(1 + monthlyInterestRate, numberOfPayments);
  return (loanAmount * monthlyInterestRate * powerFactor) / (powerFactor - 1);
}

double Mortgage::calculateTotalPayback() {
  return calculateMonthlyPayment() * numberOfPayments;
}
