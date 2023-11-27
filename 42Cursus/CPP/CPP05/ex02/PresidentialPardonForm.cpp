#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5)
{
	setTarget("DEFAULT_TARGET");
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5)
{
	setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.getName(), other.getSignGrade(), other.getExecGrade())
{
	setTarget(other.getTarget());
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	if (this == &form)
		return (*this);
	setTarget(form.getTarget());
	setSigned(form.isSigned());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::executeImpl(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
