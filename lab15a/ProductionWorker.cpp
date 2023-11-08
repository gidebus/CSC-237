

#include "ProductionWorker.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

ProductionWorker::ProductionWorker() : Employee() {
  shift = 0; payRate = 0.0;
}

ProductionWorker::ProductionWorker(string aName, string aDate, int aShift, double aPayRate)
  : Employee(aName, aDate) {
  shift = aShift; payRate = aPayRate;
}

void ProductionWorker::setShift(int s) {
  this->shift = s;
}

void ProductionWorker::setPayRate(double r) {
  this->payRate = r;
}

int ProductionWorker::getShiftNumber() const {
  return shift;
}

string ProductionWorker::getShiftName() const {
  return (shift == 1) ? "Day" : "Night";
}

double ProductionWorker::getPayRate() const {
  return payRate;
}

void ProductionWorker::printWorkerData() const {
  cout << "Name: " << getEmployeeName() << endl;
  cout << "Employee number: " << getEmployeeNumber() << endl;
  cout << "Hire date: " << getHireDate() << endl;
  cout << "Shift: " << getShiftName() << endl;
  cout << "Shift number: " << getShiftNumber() << endl;
  cout << "Pay rate: " << getPayRate() << endl;
}

ProductionWorker* ProductionWorker::createNewProductionWorker() {
  string employeeName, hireDate;
  int shift;
  double hourlyPayRate;

  cout << "\nEnter name of new employee: ";
  cin.ignore();
  getline(cin, employeeName);

  cout << "Enter hire date of new employee: ";
  getline(cin, hireDate);

  cout << "Enter shift for new employee (1=day, 2=night): ";
  cin >> shift;

  cout << "Enter hourly pay rate for new employee: ";
  cin >> hourlyPayRate;

  return new ProductionWorker(employeeName, hireDate, shift, hourlyPayRate);
}