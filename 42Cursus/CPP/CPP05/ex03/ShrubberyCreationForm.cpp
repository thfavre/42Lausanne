#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137)
{
	setTarget("DEFAULT_TARGET");
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137)
{
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), other.getSignGrade(), other.getExecGrade())
{
	setTarget(other.getTarget());
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	if (this == &form)
		return (*this);
	setTarget(form.getTarget());
	setSigned(form.isSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeImpl(Bureaucrat const & executor) const
{
	std::ofstream outfile(getTarget() + "_shrubbery");
	outfile << TREE << std::endl;
	outfile.close();
}
