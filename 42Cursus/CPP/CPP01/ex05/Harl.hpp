#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl {

public:
	Harl(void);
	void	complain(std::string level);

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	std::string	_levels[4];
	void		(Harl::*_complainFunctions[4])(void);

} ;

#endif // HARL_HPP
