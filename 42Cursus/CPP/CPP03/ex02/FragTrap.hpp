#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : public ClapTrap
{

	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &other);
		FragTrap(std::string name, uint hp, uint attack_damage, uint energy);

		~FragTrap(void);

		FragTrap	&operator=(FragTrap const &other);

		void		highFivesGuys(void);
		void		attack(const std::string &target);

};

#endif
