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

	AForm *forms[] = {
		new PresidentialPardonForm(target), // robotomy request
		new RobotomyRequestForm(target),	// presidential pardon
		new ShrubberyCreationForm(target)	// shrubbery creation
	};

	std::string formNames[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"};

	int numForms = sizeof(forms) / sizeof(forms[0]);

	for (int i = 0; i < numForms; i++)
	{
		if (formNames[i] == name)
		{
			form = forms[i];
			break;
		}
	}

	if (!form)
		throw FormNotFoundException();

	return form;
}
