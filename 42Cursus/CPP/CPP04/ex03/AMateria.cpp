#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type("")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
	this->type = src.type;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &src)
{
	if (&src == this)
		return *this;
	this->type = src.type;
	return *this;
}

void				AMateria::use(ICharacter &target)
{
	std::cout << "use " << this->type << " on " << target.getName() << std::endl;
}

std::string const	&AMateria::getType() const
{
	return this->type;
}
