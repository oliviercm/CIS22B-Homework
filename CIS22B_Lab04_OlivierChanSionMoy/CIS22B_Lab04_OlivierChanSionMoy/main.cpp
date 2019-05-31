/*
CIS 22B
Lab 04: Using function templates only, create mimimum, maximum, absolute value, and running total functions.
Name: Olivier Chan Sion Moy

Pseudocode:

[START]

	Enter main function
	Minimum of A and B
		If A less than B
			Return A
		Else
			Return B
	Maximum of A and B
		If A greater than B
			Return A
		Else
			Return B
	Absolute value of A
		If A greater than 0
			Return A
		Else
			Return -A
	Total is 0.
	Add A to total.
	Total is A.
	Add B to total.
	Total is A + B.
	Exit main function

[END]

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "minimum.cpp"
#include "maximum.cpp"
#include "abs.cpp"
#include "total.cpp"

int main()
{
	constexpr int iA = 1;

	constexpr double dA = 3.14159;
	constexpr double dB = -2.71828;

	std::cout << "The minimum of the two doubles " << dA << " and " << dB << " is: (" << minimum<double>(dA, dB) << "). The maximum is: (" << maximum<double>(dA, dB) << ")." << std::endl << std::endl;

	std::cout << "The absolute value of integer " << iA << " is: (" << abs<int>(iA) << "). The absolute value of double " << dB << " is: (" << abs<double>(dB) << ")." << std::endl << std::endl;

	std::cout << "Total is 0. Adding double " << dA << ". Total is (" << total<double>(dA) << "). ";
	std::cout << "Adding double " << dB << ". Total is (" << total<double>(dB) << ")." << std::endl << std::endl;

	std::cout << "Press ENTER to exit." << std::endl;
	std::cin.get();
	return 0;
}