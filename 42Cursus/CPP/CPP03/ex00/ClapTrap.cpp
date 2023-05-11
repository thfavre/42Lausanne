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

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hp(other._hp), _attack_damage(other._attack_damage), _energy(other._energy)
{
	// *this = other; // instead of copying the values, we can use the operator= to do it
	std::cout << "Copy constructor called for " << _name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called for " << _name << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this == &rhs)
		return *this;
	this->_attack_damage = rhs._attack_damage;
	this->_energy = rhs._energy;
	this->_hp = rhs._hp;
	this->_name = rhs._name;
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hp == 0)
		std::cout << "ClapTrap " << _name << " has not enough hp to attack..." << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << _name << " has not enough energy to attack..." << std::endl;
	else
	{
		_energy--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp == 0)
		std::cout << "ClapTrap " << _name << " has not enough hp to be attacked..." << std::endl;
	else
	{
		if (amount > _hp)
			amount = _hp;
		_hp -= amount;
		std::cout << "ClapTrap " << _name << " get attacked of " << amount << "hp, he has now " << _hp << " hp" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp == 0)
		std::cout << "ClapTrap " << _name << " has not enough hp to be repaired..." << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << _name << " has not enough energy to be reapaired..." << std::endl;
	else
	{
		_energy--;
		_hp += amount;
		std::cout << "ClapTrap " << _name << " get repaired of " << amount << " hp, he has now " << _hp << " hp" << std::endl;
	}
}

unsigned int	ClapTrap::getAttackDamage(void)
{
	return (_attack_damage);
}

void	ClapTrap::getStatus(void)
{
	std::cout << "ClapTrap " << _name << " has :"<< std::endl;
	std::cout << "\t" << _hp << "\t hp" << std::endl;
	std::cout << "\t" << _energy << "\t energy" << std::endl;
	std::cout << "\t" << _attack_damage << "\t attack damage" << std::endl;
}
