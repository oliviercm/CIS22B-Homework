#pragma once
#include <exception>

struct IncompleteTraining : public _exception
{
public:
	const char* what() const throw();
};