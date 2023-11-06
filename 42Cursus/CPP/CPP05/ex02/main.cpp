#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{


		Bureaucrat Bob = Bureaucrat("Bob", 70);
		Bureaucrat GoodBureaucrat = Bureaucrat("GoodBureaucrat", 1);

		std::cout << "\nForms creation time\n" << std::endl;

		ShrubberyCreationForm shrubberyForm = ShrubberyCreationForm("Garden");
		RobotomyRequestForm robotomyForm = RobotomyRequestForm("Dog");
		PresidentialPardonForm pardonForm = PresidentialPardonForm("Putin");

		std::cout << shrubberyForm << std::endl;
		std::cout << robotomyForm << std::endl;
		std::cout << pardonForm << std::endl;

		// Bob.executeForm(shrubberyForm);; // The Form is not signed exception.


		std::cout << "\n\nSign time\n" << std::endl;

		Bob.signForm(shrubberyForm);
		Bob.signForm(robotomyForm);
		Bob.signForm(pardonForm); // Bob couldn't sign Presidential Pardon Form because...
		GoodBureaucrat.signForm(pardonForm);
		std::cout << shrubberyForm << std::endl;



		std::cout << "\n\nExecution time\n" << std::endl;

		Bob.executeForm(shrubberyForm);
		// Bob.executeForm(robotomyForm); // Bob's grade is too Low to execute this
		GoodBureaucrat.executeForm(robotomyForm);
		GoodBureaucrat.executeForm(pardonForm);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
