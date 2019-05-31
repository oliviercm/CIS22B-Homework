#pragma once
#include <exception>

struct InvalidPayRate : public _exception
{
public:
	const char* what() const throw();
};