#include <string>
#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hp(10), _attack_damage(0), _energy(10)
{
	std::cout << "Default constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _attack_damage(0), _energy(10)
{
	std::cout << "Named constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name, uint hp, uint attack_damage, uint energy) : _name(name), _hp(hp), _attack_damage(attack_damage), _energy(energy)
{
	std::cout << "Full constructor called for " << _name << std::endl;
}


ClapTrap::ClapTrap(ClapTrap &other) : _name(other._name), _hp(other._hp), _attack_damage(other._attack_damage), _energy(other._energy)
{
	std::cout << "Copy constructor called for " << _name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called for " << _name << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_attack_damage = rhs._attack_damage;
	this->_energy = rhs._energy;
	this->_hp = rhs._hp;
	this->_name = rhs._name;
	return *this;
}
