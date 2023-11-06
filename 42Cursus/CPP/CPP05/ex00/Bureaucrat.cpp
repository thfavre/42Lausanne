
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this == &bureaucrat)
		return (*this);
	_grade = bureaucrat._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	_grade--;
	if (_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

void Bureaucrat::decrementGrade()
{
	_grade++;
	if (_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}



