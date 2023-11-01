#include <iostream>

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat jess = Bureaucrat("Jess", 12);
		std::cout << jess << std::endl;

		Bureaucrat john = Bureaucrat("John", 2993748);
		std::cout << john << std::endl;
		john.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat frank = Bureaucrat("Frank", 150);
		std::cout << frank << std::endl;
		frank.decrementGrade(); // throw an exception because grade > 150
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat lise = Bureaucrat("Lise", 1);
		std::cout << lise << std::endl;
		lise.incrementGrade(); // throw an exception because grade < 1
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}


