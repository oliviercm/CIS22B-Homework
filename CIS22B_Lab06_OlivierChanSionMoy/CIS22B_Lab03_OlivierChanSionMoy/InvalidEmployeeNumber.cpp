#include <exception>

struct InvalidEmployeeNumber : public _exception
{
public:
	const char* what() const throw();
};

const char* InvalidEmployeeNumber::what() const throw()
{
	return "Invalid Employee Number Exception";
}