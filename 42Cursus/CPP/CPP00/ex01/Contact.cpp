#include <iostream>
#include "Contact.hpp"

void	Contact::getInput(const std::string& text, std::string& input) {
	input.clear();
	do {
		std::cout << text;
		std::getline(std::cin, input);
	} while (input.empty());
}

void	Contact::fillFields(void) {
	getInput("Enter first name: ", _firstName);
	getInput("Enter last name: ", _lastName);
	getInput("Enter nickname: ", _nickName);
	getInput("Enter phone number: ", _phoneNum);
	getInput("Enter secret: ", _secret);
}

const std::string&	Contact::getFirstName() const {
	return _firstName;
}

const std::string&	Contact::getLastName() const {
	return _lastName;
}

const std::string&	Contact::getNickname() const {
	return _nickName;
}

const std::string&	Contact::getPhoneNumber() const {
	return _phoneNum;
}

const std::string&	Contact::getDarkestSecret() const {
	return _secret;
}
