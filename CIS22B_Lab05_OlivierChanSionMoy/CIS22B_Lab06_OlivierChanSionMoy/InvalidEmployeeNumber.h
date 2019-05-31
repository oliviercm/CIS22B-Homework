#pragma once
#include <exception>

struct InvalidEmployeeNumber : public _exception
{
public:
	const char* what() const throw();
};