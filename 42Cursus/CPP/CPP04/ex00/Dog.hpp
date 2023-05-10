#ifndef Dog_HPP
# define Dog_HPP

# include <string>
# include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(Dog const &other);
	virtual ~Dog(void); // virtual keyword Not mandatory, but added for clarity

	Dog	&operator=(const Dog &Dog);

	void	makeSound(void) const;

private:
	std::string	_type;
};

#endif
