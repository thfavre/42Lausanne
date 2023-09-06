#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
public:
	Animal(void);
	Animal(std::string type);
	Animal(Animal const &animal);
	virtual ~Animal(void); // virtual keyword is mendatory to ensure proper destruction of derived class objects when deleting through a base class

	Animal	&operator=(const Animal &animal);

	void virtual	makeSound(void) const = 0; // pure virtual, to be instantiated in derived classes if they defined the function
	std::string		getType(void) const;

protected:
	std::string _type;
};

#endif
