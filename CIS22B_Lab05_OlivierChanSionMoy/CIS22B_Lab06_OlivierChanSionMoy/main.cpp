/*
CIS 22B
Lab 06: Basing off of Lab 03, add exceptions to various classes previously created.
Name: Olivier Chan Sion Moy

Pseudocode:

[START]

Enter main function
	Throw and catch an InvalidEmployeeNumber exception
	Throw and catch an InvalidShift exception
	Throw and catch an InvalidPayRate exception
	Throw and catch an IncompleteTraining exception

[END]

*/

#include <iostream>
#include <string>
#include "Employee.h"
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"

int main()
{
	//Throw and catch an InvalidEmployeeNumber exception
	Employee employee = Employee();
	
	std::cout << "Setting an Employee's Employee number to -1..." << std::endl;
	try
	{
		employee.setEmployeeNumber(-1);
	}
	catch (InvalidEmployeeNumber& e)
	{
		std::cout<< e.what() << std::endl << std::endl;
	}

	//Throw and catch an InvalidShift exception
	ProductionWorker productionWorker = ProductionWorker();

	std::cout << "Setting a Production Worker's shift to 0..." << std::endl;
	try
	{
		productionWorker.setShift(0);
	}
	catch (InvalidShift& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	
	//Throw and catch an InvalidPayRate exception
	std::cout << "Setting a Production Worker's hourly pay rate to -1..." << std::endl;
	try
	{
		productionWorker.setHourlyPayRate(-1);
	}
	catch (InvalidPayRate& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	//Throw and catch an IncompleteTraining exception
	TeamLeader teamLeader = TeamLeader();

	std::cout << "Setting a Team Leader's attended training to 7..." << std::endl;
	try
	{
		teamLeader.setAttendedTrainingHours(7);
	}
	catch (IncompleteTraining& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	//End program
	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}