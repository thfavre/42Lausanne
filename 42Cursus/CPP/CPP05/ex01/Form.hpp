
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

# include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration of Bureaucrat class

class Form
{
public:
	Form();
	Form(std::string name);
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form &other);
	~Form();

	Form &operator=(const Form &form);

	std::string getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
		virtual const char *what(void) const throw()
		{
			return ("Form grade can't be higher than 1.");
		}
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what(void) const throw()
		{
			return ("Form grade can't be smaller than 150. \tOR\t Bureaucrat grade too low to sign or execute the form.");
		}
	};

private:
	const std::string	_name;
	bool 				_isSigned;
	int					_signGrade;
	int					_execGrade;

};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif // FORM_HPP
