#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>

# include "AForm.hpp"


# define TREE "              v .   ._, |_  ., \n           `-._\\/  .  \\ /    |/_\n        _\\_.___\\\\, \\\\/ -.\\||\n               \\\\  _\\, y | \\//\n           `7-,--.`._||  / / ,\n           /'     `-. `./ / |/_.'\n                     |    |//\n                     |_    /\n                     |-   |\n                     |   =|\n                     |    |\n--------------------/ ,  . \\--------._"


class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &form);

	void executeImpl(Bureaucrat const & executor) const;

};

#endif // PRESIDENTIALPARDONFORM_HPP
