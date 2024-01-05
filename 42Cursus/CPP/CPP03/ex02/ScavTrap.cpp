#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "Default ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 30)
{
	std::cout << "Named ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other._name, other._hp, other._attack_damage, other._energy)
{
	std::cout << "Copy ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name, uint hp, uint attack_damage, uint energy) : ClapTrap(name, hp, attack_damage, energy)
{
	std::cout << "Full ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &other)
{
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_energy = other._energy;
	this->_attack_damage = other._attack_damage;
	this->_hp = other._hp;
	return (*this);
}

void		ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_hp == 0)
		std::cout << "ScavTrap " << _name << " has not enough hp to attack..." << std::endl;
	else if (_energy == 0)
		std::cout << "ScavTrap " << _name << " has not enough energy to attack..." << std::endl;
	else
	{
		_energy--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
}
