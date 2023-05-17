#ifndef Dog_HPP
# define Dog_HPP

# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(Dog const &other);
	virtual ~Dog(void); // virtual keyword Not mandatory, but added for clarity

	Dog	&operator=(const Dog &dog);

	void	makeSound(void) const;

private:
	Brain		*_brain;
};

#endif
