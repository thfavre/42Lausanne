#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(Character const &other);
	Character(std::string const &name);
	~Character();
	Character &operator=(Character const &other);

	std::string const & getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

private:
	std::string _name;
	AMateria *_inventory[4];
	AMateria *_ground[4];
	;
};

# endif
