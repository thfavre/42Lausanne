#ifndef WrongCat_HPP
# define WrongCat_HPP

# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(WrongCat const &other);
	~WrongCat(void);

	WrongCat	&operator=(const WrongCat &WrongCat);

	void	makeSound(void) const;

private:
	std::string	_type;
};

#endif
