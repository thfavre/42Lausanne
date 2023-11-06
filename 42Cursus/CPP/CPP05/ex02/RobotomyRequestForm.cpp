#include "RobotomyRequestForm.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45)
{
	setTarget("DEFAULT_TARGET");
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45)
{
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), other.getSignGrade(), other.getExecGrade())
{
	setTarget(other.getTarget());
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	if (this == &form)
		return (*this);
	setTarget(form.getTarget());
	setSigned(form.isSigned());
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::executeImpl(Bureaucrat const & executor) const
{
	std::cout << "BRRRRrrrRRRRRR..." << std::endl;
	if (rand()%2 == 1)
		std::cout << getTarget() << " has been robotomised! "  << std::endl;
	else
		std::cout << getTarget() << " robotomisation failed..." << std::endl;

}
