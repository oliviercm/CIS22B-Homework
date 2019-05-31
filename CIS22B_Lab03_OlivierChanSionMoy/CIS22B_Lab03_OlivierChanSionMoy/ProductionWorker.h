#pragma once

#include "Employee.h"

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

	int getShift();
	double getHourlyPayRate();

	void setShift(int sh);
	void setHourlyPayRate(double ho);
};