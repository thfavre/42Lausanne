#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("None")
{
	std::cout << "Default Animal constructor called. (type : " << _type << ")" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Typed Animal constructor called. (type : " << _type << ")" << std::endl;
}

Animal::Animal(Animal const &animal) : _type(animal._type)
{
	std::cout << "Copy Animal constructor called. (type : " << _type << ")" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Default Animal destructor called. (type : " << _type << ")" << std::endl;
}

Animal	&Animal::operator=(const Animal &animal)
{
	if (this == &animal)
		return (*this);
	this->_type = animal._type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "..??.." << std::endl;
}

std::string	Animal::getType(void) const
{
	return (_type);
}
