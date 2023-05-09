#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : public ClapTrap
{

	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &other);
		ScavTrap(std::string name, uint hp, uint attack_damage, uint energy);

		~ScavTrap(void);

		ScavTrap	&operator=(ScavTrap const &other);

		void		guardGate(void);
		void		attack(const std::string &target);

};

#endif
