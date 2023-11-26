#include <iostream>

#include "Intern.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;
		AForm *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Dog");
		std::cout << *rrf << std::endl;
		delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Trump");
		std::cout << *rrf << std::endl;
		delete rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Park");
		std::cout << *rrf << std::endl;
		delete rrf;

		// will throw exception
		rrf = someRandomIntern.makeForm("BLABLAA", "...");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;

	}
}
