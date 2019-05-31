#pragma once
#include "ProductionWorker.h"
#include "IncompleteTraining.h"

class TeamLeader : public ProductionWorker
{
protected:
	int monthlyBonus;
	int requiredTrainingHours;
	int attendedTrainingHours;
public:
	TeamLeader();
	~TeamLeader();

	//Static binding over ShiftSupervisor functions
	double getHourlyPayRate(); //Teamleaders always get paid 30

	void setAttendedTrainingHours(int hours);
};