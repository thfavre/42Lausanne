#include <string>

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
typedef unsigned int	uint;

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(ClapTrap &other);
	ClapTrap(std::string name);
	ClapTrap(std::string name, uint hp, uint attack_damage, uint energy);
	~ClapTrap(void);

	ClapTrap	&operator=(ClapTrap const & rhs);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	std::string	_name;
	int			_hp;
	int			_attack_damage;
	int			_energy;
};

#endif
