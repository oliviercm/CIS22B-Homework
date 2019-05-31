#include "ShiftSupervisor.h"

ShiftSupervisor::ShiftSupervisor()
{
	
}

ShiftSupervisor::~ShiftSupervisor()
{

}

int ShiftSupervisor::getAnnualSalary()
{
	return annualSalary;
}

int ShiftSupervisor::getAnnualBonus()
{
	return annualBonus;
}

void ShiftSupervisor::setAnnualSalary(int sa)
{
	annualSalary = sa;
	return;
}

void ShiftSupervisor::setAnnualBonus(int bo)
{
	annualBonus = bo;
	return;
}

std::string ShiftSupervisor::getEmployeeName()
{
	return "Supervisor " + employeeName;
}