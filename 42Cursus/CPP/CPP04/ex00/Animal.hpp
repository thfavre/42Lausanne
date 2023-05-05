#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
public:
	Animal(void);
	Animal(Animal &animal);
	virtual ~Animal(void);

	Animal	&operator=(const Animal &animal);

	void virtual	makeSound(void) const;
	std::string		getType(void) const;


protected:
	std::string _type;
};

#endif
