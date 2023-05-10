#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Default Dog constructor called." << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other._type)
{
	std::cout << "Copy Dog constructor called." << std::endl;

}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called." << std::endl;
}

Dog	&Dog::operator=(const Dog &Dog)
{
	if (this == &Dog)
		return (*this);
	this->_type = Dog._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Grr Wouaf!" << std::endl;
}
