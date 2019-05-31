#include <exception>

struct InvalidShift : public _exception
{
public:
	const char* what() const throw();
};

const char* InvalidShift::what() const throw()
{
	return "Invalid Shift Exception";
}