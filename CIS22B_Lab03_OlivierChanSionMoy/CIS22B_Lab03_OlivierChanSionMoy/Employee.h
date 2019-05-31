#pragma once

#include <string>

class Employee
{
protected:
	std::string employeeName;
	int employeeNumber;
	std::string employeeHireDate;
public:
	Employee();
	//Constructor overloading
	Employee(std::string name, int number, std::string hireDate);
	~Employee();

	virtual std::string getEmployeeName(); //This function will get overridden in ShiftSupervisor
	int getEmployeeNumber();
	std::string getEmployeeHireDate();

	void setEmployeeName(std::string na);
	void setEmployeeNumber(int nu);
	void setEmployeeHireDate(std::string da);
};