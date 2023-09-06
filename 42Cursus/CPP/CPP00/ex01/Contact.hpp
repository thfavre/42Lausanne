#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact {

public:
	void				fillFields(void);
	void				getInput(const std::string& text, std::string& input);
	const std::string&	getFirstName() const;
	const std::string&	getLastName() const;
	const std::string&	getNickname() const;
	const std::string&	getPhoneNumber() const;
	const std::string&	getDarkestSecret() const;

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNum;
	std::string	_secret;
};

#endif // CONTACT_H
