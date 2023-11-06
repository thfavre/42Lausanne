#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &bureaucrat);

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception
	{
		virtual const char *what(void) const throw()
		{
			return ("Bureaucrat grade can't be less than 0.");
		}
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what(void) const throw()
		{
			return ("Bureaucrat grade can't be higher than 150.");
		}
	};

private:
	std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
