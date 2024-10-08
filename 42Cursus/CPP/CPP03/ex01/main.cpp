#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap thom("Thom");
	ScavTrap tim("Tim", 15, 2, 100);
	ScavTrap thomV2(thom);

	std::cout << std::endl;

	thom.getStatus();
	tim.getStatus();
	thomV2.getStatus();

	std::cout << std::endl;

	thom.attack("Tim");
	tim.takeDamage(thom.getAttackDamage());
	thom.getStatus();
	tim.getStatus();

	std::cout << std::endl;

	thom.guardGate();
	tim.guardGate();
	thomV2.guardGate();

	std::cout << std::endl;

	tim.attack("Thom");
	thom.takeDamage(tim.getAttackDamage());
	thom.getStatus();
	tim.getStatus();

	std::cout << std::endl;

	tim. beRepaired(999);
	tim.getStatus();

	std::cout << std::endl;

	tim.guardGate();

	std::cout << std::endl;

}
