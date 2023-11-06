#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>

# include "AForm.hpp"


# define TREE "              v .   ._, |_  ., \n           `-._\\/  .  \\ /    |/_\n        _\\_.___\\\\, \\\\/ -.\\||\n               \\\\  _\\, y | \\//\n           `7-,--.`._||  / / ,\n           /'     `-. `./ / |/_.'\n                     |    |//\n                     |_    /\n                     |-   |\n                     |   =|\n                     |    |\n--------------------/ ,  . \\--------._"


class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);

	void executeImpl(Bureaucrat const & executor) const;

};

#endif // SHRUBBERYCREATIONFORM_HPP
