#include <map>
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *form;

	//map
	std::map<std::string, AForm *> forms = {
		{"robotomy request", new PresidentialPardonForm(target)},
		{"presidential pardon", new RobotomyRequestForm(target)},
		{"shrubbery creation", new ShrubberyCreationForm(target)}
	};

	if (forms.find(name) == forms.end())
		throw FormNotFoundException();
	form = forms[name];


	return form;
}


