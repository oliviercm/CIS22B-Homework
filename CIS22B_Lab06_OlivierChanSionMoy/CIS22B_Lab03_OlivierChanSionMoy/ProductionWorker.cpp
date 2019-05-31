#include "ProductionWorker.h"

ProductionWorker::ProductionWorker()
{
	
}

ProductionWorker::ProductionWorker(int ho)
{
	if (ho < 0)
	{
		throw InvalidPayRate();
	}
	else
	{
		hourlyPayRate = ho;
	}
}

ProductionWorker::~ProductionWorker()
{

}

int ProductionWorker::getShift()
{
	return shift;
}

double ProductionWorker::getHourlyPayRate()
{
	return hourlyPayRate;
}

void ProductionWorker::setShift(int sh)
{
	if (sh != 1 && sh != 2)
	{
		throw InvalidShift();
	}
	else
	{
		shift = sh;
	}
	return;
}

void ProductionWorker::setHourlyPayRate(double ho)
{
	if (ho < 0)
	{
		throw InvalidPayRate();
	}
	else
	{
		hourlyPayRate = ho;
	}
	return;
}