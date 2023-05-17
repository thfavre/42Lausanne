#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "Default WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other._type)
{
	std::cout << "Copy WrongCat constructor called." << std::endl;

}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &WrongCat)
{
	if (this == &WrongCat)
		return (*this);
	this->_type = WrongCat._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "MIAOW" << std::endl;
}
