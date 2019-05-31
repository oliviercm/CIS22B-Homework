#include "ProductionWorker.h"

ProductionWorker::ProductionWorker()
{
	
}

ProductionWorker::ProductionWorker(int ho)
{
	hourlyPayRate = ho;
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
	shift = sh;
	return;
}

void ProductionWorker::setHourlyPayRate(double ho)
{
	hourlyPayRate = ho;
	return;
}