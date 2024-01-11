#include <iostream>
#include "Character.hpp"


Character::Character() : _name("default")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = nullptr;
		_ground[i] = nullptr;
	}
}

Character::Character(std::string const &name) : _name(name)
{
	std::cout << "Character name constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = nullptr;
		_ground[i] = nullptr;
	}
}

Character::Character(Character const &other) : _name(other._name)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

Character &Character::operator=(Character const &other)
{
	std::cout << "Character assignation operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (_ground[i])
			delete _ground[i];
	}
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "* this element is not known to the player *" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << "* " << this->getName() << " equipped " << m->getType() << " *" << std::endl;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
	{
		std::cout << "* there is no equipement in the " << idx << " inventory slot *" << std::endl;
		return ;
	}

	// TODO NOT FINISHED

}
