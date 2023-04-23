#include <string>
#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{
	_levels[0] = "DEBUG";
	_levels[1] = "INFO";
	_levels[2] = "WARNING";
	_levels[3] = "ERROR";
	_complainFunctions[0] = &Harl::debug;
	_complainFunctions[1] = &Harl::info;
	_complainFunctions[2] = &Harl::warning;
	_complainFunctions[3] = &Harl::error;
}

void	Harl::complain(std::string level)
{
	for (size_t  i = 0; i < _levels->length(); i++)
	{
		if (_levels[i] == level)
		{
			(this->*_complainFunctions[i])();
			return ;
		}
	}
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
