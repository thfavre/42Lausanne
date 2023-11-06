#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

	try
	{
		Form notValidForm = Form("NotValidForm", 11, -12);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat badBureaucrat = Bureaucrat("BadBureaucrat", 150);
	Bureaucrat goodBureaucrat = Bureaucrat("GoodBureaucrat", 1);

	Form easyForm = Form("EasyForm", 150, 150);
	std::cout << easyForm << std::endl;

	Form hardForm = Form("HardForm", 1, 1);
	std::cout << hardForm << std::endl;

	std::cout << "\n\n**** Start signing forms! ****\n"
			  << std::endl;
	badBureaucrat.signForm(easyForm);
	badBureaucrat.signForm(hardForm);

	goodBureaucrat.signForm(hardForm);
}
