// Implementation file for the Employee class

#include "Employee.h"
#include <string>
#include <cctype>

using namespace std;

int Employee::lastEmployeeNumberIssued=0;   // Sequential employee number

	// Default constructor
	Employee::Employee()
	{
		lastEmployeeNumberIssued++;
		employeeNumber = lastEmployeeNumberIssued;
		employeeName = "";
		hireDate = "";
	}


	// Constructor
	Employee::Employee(string aName, string aDate)
	{
		lastEmployeeNumberIssued++;
		employeeNumber = lastEmployeeNumberIssued;
		employeeName = aName;
		isValidDate(aDate);
    hireDate = aDate;
	}

  Employee::InvalidHireDate::InvalidHireDate(string val) : value(val) {};
	string Employee::InvalidHireDate::getValue() const {
		return value;
	}
	// Mutators
	void Employee::setEmployeeName(string n)
	{
		employeeName = n;
	}


	void Employee::setHireDate(string date)
	{
		hireDate = date;
	}

	// Accessors
	string Employee::getEmployeeName() const
	{
		return employeeName;
	}

	int Employee::getEmployeeNumber() const
	{
		return employeeNumber;
	}

	string Employee::getHireDate() const
	{
		return hireDate;
	}

	int Employee::getLastEmployeeNumberIssued()
	{
		return lastEmployeeNumberIssued;
	}
  
  void Employee::isValidDate(string date) {

    if(date.length() != 10) {
      throw InvalidHireDate(date);
    }

    if(date[2] != '/' || date[5] != '/') {
      throw InvalidHireDate(date);
    }

    for(int i = 0; i < 10; i++) {
      if(i == 2 || i == 5) {
        continue;
      } 

      if(!isdigit(date[i])) {
        throw InvalidHireDate(date);
      }
    }
  }
