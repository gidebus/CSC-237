
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
  testShift(aShift);
  shift = aShift; 
  testPayRate(aPayRate);
  payRate = aPayRate;
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

ProductionWorker::InvalidShift::InvalidShift(int val)  : value(val) {};
ProductionWorker::InvalidPayRate::InvalidPayRate(double val) : value(val) {};

int ProductionWorker::InvalidShift::getValue() const {
  return value;
}

double ProductionWorker::InvalidPayRate::getValue() const {
  return value;
};

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
  try {
    return new ProductionWorker(employeeName, hireDate, shift, hourlyPayRate);
  } catch(Employee::InvalidHireDate e) {
    cout << "\nError: Invalid hire date " << e.getValue() << ": Hire date must be MM/DD/YYYY format." << endl;
  } catch(ProductionWorker::InvalidShift e) {
    cout << "\nError: Invalid shift number: " << e.getValue() << endl;
  } catch(ProductionWorker::InvalidPayRate e) {
    cout << "\nError: Invalid pay rate number: " << e.getValue() << endl;
  }
  return nullptr;
}

void ProductionWorker::testShift(int aShift) {
  if(aShift != 1 && aShift != 2) {
    throw InvalidShift(aShift);
  }
};

void ProductionWorker::testPayRate(double aPayRate) {
  if(aPayRate < 0) {
    throw InvalidPayRate(aPayRate);
  }
};
