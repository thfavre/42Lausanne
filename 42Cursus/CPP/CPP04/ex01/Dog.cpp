#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Default Dog constructor called." << std::endl;
	_brain = new Brain();
}

Dog::Dog(Dog const &other) : Animal(other._type)
{
	std::cout << "Copy Dog constructor called." << std::endl;
	_brain = new Brain(*other._brain);
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructor called." << std::endl;
}

Dog	&Dog::operator=(const Dog &dog)
{
	if (this == &dog)
		return (*this);
	this->_type = dog._type;
	this->_brain = dog._brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Grr Wouaf!" << std::endl;
}
