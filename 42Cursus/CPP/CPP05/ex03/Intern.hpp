#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();
	Intern &operator=(const Intern &copy);

	class FormNotFoundException : public std::exception
	{
		virtual const char *what(void) const throw()
		{
			return ("This Form does exist.");
		}
	};

	AForm *makeForm(std::string name, std::string target);
};

#endif // INTERN_HPP
