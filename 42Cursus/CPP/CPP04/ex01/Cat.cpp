#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	_brain = new Brain();
	std::cout << "Default Cat constructor called." << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other._type)
{
	_brain = new Brain(*other._brain);
	std::cout << "Copy Cat constructor called." << std::endl;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructor called." << std::endl;
}

Cat	&Cat::operator=(const Cat &cat)
{
	if (this == &cat)
		return (*this);
	this->_brain = cat._brain;
	this->_type = cat._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "MIAOW <3" << std::endl;
}
