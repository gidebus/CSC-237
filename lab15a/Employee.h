// Specification file for the Employee class
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{

private:
	static int lastEmployeeNumberIssued;   // Sequential employee number
	int employeeNumber;                    // Employee number for current employee
	string employeeName;		           // Employee name
	string hireDate;	                   // Hire date

public:
	// Constructors
	Employee();
	Employee(string aName, string aDate);

	class InvalidHireDate {
		private:
			string value;
		public:
			InvalidHireDate(string val);
			string getValue() const;
	};
	// Mutators
	void setEmployeeName(string n);
	void setHireDate(string date);

	// Accessors
	string getEmployeeName() const;
	int getEmployeeNumber() const;
	string getHireDate() const;
	static int getLastEmployeeNumberIssued();

	// Error Handler
	static void isValidDate(string aDate);
};

#endif
