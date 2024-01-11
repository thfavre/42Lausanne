#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria
{

public:
	AMateria();
	AMateria(AMateria const &other);
	AMateria(std::string const & type);
	virtual ~AMateria(); // Virtual destructor becuase we have virtual functions

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	std::string type;
};

#endif
