#include <exception>

struct IncompleteTraining : public _exception
{
public:
	const char* what() const throw();
};

const char* IncompleteTraining::what() const throw()
{
	return "Incomplete Training Exception";
}