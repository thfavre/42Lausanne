
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
typedef unsigned int	uint;

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(const ClapTrap &other);
	ClapTrap(std::string name);
	ClapTrap(std::string name, uint hp, uint attack_damage, uint energy);
	~ClapTrap(void);

	ClapTrap	&operator=(const ClapTrap &rhs);

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	uint		getAttackDamage(void);
	void		getStatus(void);

private:
	std::string	_name;
	uint		_hp;
	uint		_attack_damage;
	uint		_energy;
};

#endif
