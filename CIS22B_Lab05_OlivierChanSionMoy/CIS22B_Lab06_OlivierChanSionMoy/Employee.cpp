#include "Employee.h"

Employee::Employee()
{
	employeeName = "Generic Employee";
}

Employee::Employee(std::string name, int number, std::string hireDate)
{
	employeeName = name;
	employeeHireDate = hireDate;

	if (number < 0 || number > 9999)
	{
		throw InvalidEmployeeNumber();
	}
	else
	{
		employeeNumber = number;
	}

}

Employee::~Employee()
{

}

std::string Employee::getEmployeeName()
{
	return employeeName;
}

int Employee::getEmployeeNumber()
{
	return employeeNumber;
}

std::string Employee::getEmployeeHireDate()
{
	return employeeHireDate;
}

void Employee::setEmployeeName(std::string name)
{
	employeeName = name;
	return;
}

void Employee::setEmployeeNumber(int number)
{
	if (number < 0 || number > 9999)
	{
		throw InvalidEmployeeNumber();
	}
	else
	{
		employeeNumber = number;
	}
	return;
}

void Employee::setEmployeeHireDate(std::string date)
{
	employeeHireDate = date;
	return;
}