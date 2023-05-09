#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "Default FragTrap constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "Named FragTrap constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other._name, other._hp, other._attack_damage, other._energy)
{
	std::cout << "Copy FragTrap constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(std::string name, uint hp, uint attack_damage, uint energy) : ClapTrap(name, hp, attack_damage, energy)
{
	std::cout << "Full FragTrap constructor called for " << _name << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called for " << _name << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &other)
{
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_energy = other._energy;
	this->_attack_damage = other._attack_damage;
	this->_hp = other._hp;
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (_hp == 0)
		std::cout << "FragTrap " << _name << " has not enough hp to attack..." << std::endl;
	else if (_energy == 0)
		std::cout << "FragTrap " << _name << " has not enough energy to attack..." << std::endl;
	else
	{
		_energy--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
}

void		FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " ask for a high five" << std::endl;
}
