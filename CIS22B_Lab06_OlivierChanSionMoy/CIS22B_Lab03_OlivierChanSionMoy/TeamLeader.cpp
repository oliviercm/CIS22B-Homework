#include "TeamLeader.h"

TeamLeader::TeamLeader()
{

}

TeamLeader::~TeamLeader()
{

}

double TeamLeader::getHourlyPayRate()
{
	return 30;
}

void TeamLeader::setAttendedTrainingHours(int hours)
{
	if (hours < 8)
	{
		throw IncompleteTraining();
	}
	else
	{
		attendedTrainingHours = hours;
	}
}