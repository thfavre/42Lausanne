#ifndef HUMAN_B_H
# define HUMAN_B_H

# include <string>
# include "Weapon.hpp"

class HumanB {

public:
	HumanB(std::string name);
	void	attack(void);
	void	setWeapon(Weapon& weapon);

private:
	std::string _name;
	Weapon		*_weapon;
};


#endif // HUMAN_B_H
