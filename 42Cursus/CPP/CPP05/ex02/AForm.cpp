# include <iostream>

#include "AForm.hpp"


AForm::AForm() : _name("Default form"), _isSigned(false), _signGrade(100), _execGrade(75)
{
}

AForm::AForm(std::string name) : _name(name), _isSigned(false), _signGrade(100), _execGrade(75)
{
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade < 1 || execGrade < 1)
		throw (AForm::GradeTooHighException());
	if (_signGrade > 150 || execGrade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &other) : _name(other.getName()), _isSigned(other.isSigned()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade())
{
	setTarget(other.getTarget());
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return (*this);
	_isSigned = other.isSigned();
	return (*this);
}

AForm::~AForm()
{

}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::isSigned() const
{
	return (_isSigned);
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExecGrade() const
{
	return (_execGrade);
}

std::string AForm::getTarget() const
{
	return (_target);
}

void AForm::setTarget(std::string target)
{
	_target = target;
}

void AForm::setSigned(bool sign)
{
	_isSigned = sign;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw (AForm::GradeTooLowException());
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw(AForm::FormNotSignedException());
	if (executor.getGrade() > getExecGrade())
		throw(AForm::GradeTooLowException());
	executeImpl(executor);
}


std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Name: " << form.getName() << ", is " << (form.isSigned() ? "" : "not ") << "signed, minimum sign grade: " << form.getSignGrade() << ", minimum execution grade: " << form.getExecGrade();
	return (os);
}
