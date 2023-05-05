#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("None")
{
	std::cout << "Default Animal constructor called." << std::endl;
}

Animal::Animal(Animal &animal) : _type(animal._type)
{
	std::cout << "Copy Animal constructor called." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Default Animal destructor called." << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "..??.." << std::endl;
}
