#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(Cat const &other);
	virtual ~Cat(void); // virtual keyword Not mandatory, but added for clarity

	Cat	&operator=(const Cat &cat);

	void	makeSound(void) const;

private:
	Brain		*_brain;
};

#endif
