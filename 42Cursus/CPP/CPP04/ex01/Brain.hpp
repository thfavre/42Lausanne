#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain
{
public:
	Brain(void);
	Brain(Brain const &other);
	~Brain(void);

	Brain	&operator=(const Brain &Brain);

private:
	std::string	_ideas[100];
};


#endif
