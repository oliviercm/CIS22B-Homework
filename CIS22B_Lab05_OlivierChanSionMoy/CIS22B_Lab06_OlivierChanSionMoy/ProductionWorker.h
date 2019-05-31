#pragma once

#include "Employee.h"
#include "InvalidShift.h"
#include "InvalidPayRate.h"

class ProductionWorker : public Employee
{
protected:
	int shift;
	double hourlyPayRate;
public:
	ProductionWorker();
	~ProductionWorker();

	//Constructor for demonstration of different constructor initalization syntaxes
	ProductionWorker(int ho);
	//Constructor initialization list
	ProductionWorker(int sh, int ho) : shift(sh), hourlyPayRate(ho) {};

	int getShift();
	double getHourlyPayRate();

	void setShift(int sh);
	void setHourlyPayRate(double ho);
};