#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("None")
{
	std::cout << "Default WrongAnimal constructor called. (type : " << _type << ")" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "Typed WrongAnimal constructor called. (type : " << _type << ")" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &WrongAnimal) : _type(WrongAnimal._type)
{
	std::cout << "Copy WrongAnimal constructor called. (type : " << _type << ")" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Default WrongAnimal destructor called. (type : " << _type << ")" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &WrongAnimal)
{
	if (this == &WrongAnimal)
		return (*this);
	this->_type = WrongAnimal._type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "...WrongAnimal sound..." << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}
