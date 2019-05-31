#include <exception>

struct InvalidPayRate : public _exception
{
public:
	const char* what() const throw();
};

const char* InvalidPayRate::what() const throw()
{
	return "Invalid Pay Rate Exception";
}