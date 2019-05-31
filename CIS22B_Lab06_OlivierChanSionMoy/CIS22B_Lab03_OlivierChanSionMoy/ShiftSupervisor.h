#pragma once

#include "Employee.h"

class ShiftSupervisor : public Employee
{
protected:
	int annualSalary;
	int annualBonus;
public:
	ShiftSupervisor();
	~ShiftSupervisor();

	int getAnnualSalary();
	int getAnnualBonus();

	void setAnnualSalary(int sa);
	void setAnnualBonus(int bo);

	//Dynamic binding over virtual Employee functions
	std::string getEmployeeName(); //Supervisors get "Supervisor " added before their name
};