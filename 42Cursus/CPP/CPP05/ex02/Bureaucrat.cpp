
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

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	_grade = other._grade;
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
	return (_name);
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

void Bureaucrat::signForm(AForm &form)
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because ";
		std::cout << e.what() << std::endl;
	}
}

void  Bureaucrat::executeForm(AForm const & form)
{
	form.execute(*this);
	std::cout << getName() << " executed " << form.getName() << std::endl;
}



std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}



