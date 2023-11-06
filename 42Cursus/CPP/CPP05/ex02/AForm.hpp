
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

# include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration of Bureaucrat class

class AForm
{
public:
	AForm();
	AForm(std::string name);
	AForm(std::string name, int signGrade, int execGrade);
	AForm(const AForm &other);
	virtual ~AForm();

	AForm &operator=(const AForm &form);

	std::string	getName() const;
	bool 		isSigned() const;
	int 		getSignGrade() const;
	int 		getExecGrade() const;
	std::string	getTarget() const;

	void beSigned(Bureaucrat &bureaucrat);

	void execute(Bureaucrat const & executor) const;

	class GradeTooHighException : public std::exception
	{
		virtual const char *what(void) const throw()
		{
			return ("AForm grade can't be higher than 1.");
		}
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what(void) const throw()
		{
			return ("AForm grade can't be smaller than 150. \tOR\t Bureaucrat grade too low to sign or execute the form.");
		}
	};
	class FormNotSignedException : public std::exception
	{
		virtual const char *what(void) const throw()
		{
			return ("The Form is not signed.");
		}
	};

protected:
	void		setTarget(std::string target);
	void		setSigned(bool sign);
	 // Pure virtual function to be implemented in derived classes
    virtual void executeImpl(Bureaucrat const &executor) const = 0;

private:
	const std::string	_name;
	bool 				_isSigned;
	int					_signGrade;
	int					_execGrade;
	std::string			_target;

};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif // FORM_HPP
