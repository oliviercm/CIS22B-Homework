/*
CIS 22B
Lab 03: Demonstrate OOP concepts such as construction overloads, constructor initialization syntax, static binding, and dynamic binding.
Name: Olivier Chan Sion Moy

Pseudocode:

[START]

Enter main function
	Demonstrate Constructor Overloading
	Demonstrate Constructor Initalization Syntaxes
	Demonstrate Dynamic Binding
	Demonstrate Static Binding

[END]

*/

#include <iostream>
#include <string>
#include "Employee.h" //Demonstrate Constructor Overloading
#include "ProductionWorker.h" //Demonstrate Constructor Initalization Syntaxes
#include "ShiftSupervisor.h" //Demonstrate Dynamic Binding
#include "TeamLeader.h" //Demonstrate Static Binding

int main()
{
	//Demonstrate Constructor Overloading
	Employee employee1 = Employee();
	Employee employee2 = Employee("Alice", 1, "01/01/1970");
	std::cout << "Hello! I am an Employee constructed using the default constructor!" << std::endl
		<< "My name is " << employee1.getEmployeeName() << "!" << std::endl
		<< "Hello! I am an Employee constructed using an overloaded constructor!"  << std::endl
		<< "My name is " << employee2.getEmployeeName() << "!" << std::endl << std::endl;

	//Demonstrate Constructor Initalization Syntaxes
	ProductionWorker productionWorker1 (8); //Functional form
	ProductionWorker productionWorker2 = 9; //Assignment init.
	ProductionWorker productionWorker3 {10}; //Uniform init.
	ProductionWorker productionWorker4 = {11}; //POD-like

	std::cout << "Hello! We are ProductionWorkers created using different constructor initialization syntaxes!" << std::endl
		<< "I was constructed using functional form initalization! My hourly pay is: $" << productionWorker1.getHourlyPayRate() << std::endl
		<< "I was constructed using assignment initalization! My hourly pay is: $" << productionWorker2.getHourlyPayRate() << std::endl
		<< "I was constructed using uniform initalization! My hourly pay is: $" << productionWorker3.getHourlyPayRate() << std::endl
		<< "I was constructed using POD-like initalization! My hourly pay is: $" << productionWorker4.getHourlyPayRate() << std::endl << std::endl;

	//Demonstrate Dynamic Binding
	Employee* shiftSupervisor1 = new ShiftSupervisor();
	ShiftSupervisor* shiftSupervisor2 = new ShiftSupervisor();

	shiftSupervisor1->setEmployeeName("Bob");
	shiftSupervisor2->setEmployeeName("Charlie");

	std::cout << "Hello! We are ShiftSupervisors, here to demonstrate dynamic binding!" << std::endl
		<< "By the way, ShiftSupervisors get \"Supervisor\" added before their names!" << std::endl
		<< "Hi! I'm a Employee pointer, pointing to a ShiftSupervisor! My name is Bob, and my nametag says " << shiftSupervisor1->getEmployeeName() << "!" << std::endl
		<< "Hi! I'm a ShiftSupervisor pointer, pointing to a ShiftSupervisor! My name is Charlie, and my nametag says " << shiftSupervisor2->getEmployeeName() << "!" << std::endl << std::endl;
	
	delete shiftSupervisor1;
	delete shiftSupervisor2;

	//Demonstrate Static Binding
	ProductionWorker* teamLeader1 = new TeamLeader();
	TeamLeader* teamLeader2 = new TeamLeader();

	teamLeader1->setHourlyPayRate(20);
	teamLeader2->setHourlyPayRate(25);

	std::cout << "Hello! We are TeamLeaders, here to demonstrate static binding!" << std::endl
		<< "By the way, TeamLeaders get paid 30 no matter what!" << std::endl
		<< "Hi! I'm a ProductionWorker pointer, pointing to a TeamLeader! My paycheck says my hourly pay is: $" << teamLeader1->getHourlyPayRate() << "! Whoops!" << std::endl
		<< "Hi! I'm a TeamLeader pointer, pointing to a TeamLeader! My paycheck says my hourly pay is: $" << teamLeader2->getHourlyPayRate() << "!" << std::endl << std::endl;

	delete teamLeader1;
	delete teamLeader2;

	//End program
	std::cout << "Press ENTER to exit.";
	std::cin.get();
	return 0;
}