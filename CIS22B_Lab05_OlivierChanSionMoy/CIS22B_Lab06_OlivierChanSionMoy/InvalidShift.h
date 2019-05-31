#pragma once
#include <exception>

struct InvalidShift : public _exception
{
public:
	const char* what() const throw();
};