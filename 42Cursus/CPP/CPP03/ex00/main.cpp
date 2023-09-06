#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap thom("Thom");
	ClapTrap tim("Tim", 15, 2, 100);
	std::cout << std::endl;

	thom.getStatus();
	tim.getStatus();
	std::cout << std::endl;

	thom.attack("Tim");
	tim.takeDamage(thom.getAttackDamage());
	thom.getStatus();
	tim.getStatus();
	std::cout << std::endl;

	tim.attack("Thom");
	thom.takeDamage(tim.getAttackDamage());
	thom.getStatus();
	tim.getStatus();
	std::cout << std::endl;

	tim. beRepaired(999);
	tim.getStatus();
	std::cout << std::endl;

}
