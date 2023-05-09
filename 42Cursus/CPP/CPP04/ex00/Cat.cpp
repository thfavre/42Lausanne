#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Default Cat constructor called." << std::endl;
}

Cat::Cat(Cat const &other) : Animal(other._type)
{
	std::cout << "Copy Cat constructor called." << std::endl;

}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called." << std::endl;
}

Cat	&Cat::operator=(const Cat &cat)
{
	if (this == &cat)
		return (*this);
	this->_type = cat._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "MIAOW" << std::endl;
}
