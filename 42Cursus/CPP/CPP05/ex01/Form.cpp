# include <iostream>

#include "Form.hpp"


Form::Form() : _name("Default form"), _isSigned(false), _signGrade(100), _execGrade(75)
{
}

Form::Form(std::string name) : _name(name), _isSigned(false), _signGrade(100), _execGrade(75)
{
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade < 1 || execGrade < 1)
		throw (Form::GradeTooHighException());
	if (_signGrade > 150 || execGrade > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(const Form &other) : _name(other.getName()), _isSigned(other.isSigned()), _signGrade(other.getSignGrade()), _execGrade(other.getExecGrade())
{

}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return (*this);
	_isSigned = other.isSigned();
	return (*this);
}

Form::~Form()
{

}

std::string Form::getName() const
{
	return (_name);
}

bool Form::isSigned() const
{
	return (_isSigned);
}

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecGrade() const
{
	return (_execGrade);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw (Form::GradeTooLowException());
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Name: " << form.getName() << ", is " << (form.isSigned() ? "" : "not ") << "signed, minimum sign grade: " << form.getSignGrade() << ", minimum execution grade: " << form.getExecGrade();
	return (os);
}
