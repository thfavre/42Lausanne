#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

# include <string>

class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal const &WrongAnimal);
	virtual ~WrongAnimal(void); // with the virtual it will call
		// the WrongCat destructor if Animal* name = new WrongCat();

	WrongAnimal	&operator=(const WrongAnimal &WrongAnimal);

	void	makeSound(void) const; // NO virutal -> will not call the WrongCat
		// make sound if Animal* name = new WrongCat();
	std::string		getType(void) const;


protected:
	std::string _type;
};

#endif
