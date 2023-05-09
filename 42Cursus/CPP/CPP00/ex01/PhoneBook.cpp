#include <iostream>
#include <algorithm>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _contact_count(0) {
}

void	PhoneBook::addContact() {
	int	contact_index;

	contact_index = _contact_count % 8;
	_contacts[contact_index].fillFields();

	_contact_count++;
}

int PhoneBook::_getSize() const {
	return std::min(_contact_count, 8);
}

void	PhoneBook::displayContact(int index) const {
	if (index < 0 || index >= _getSize()) {
		std::cout << "Invalid index" << std::endl;
		return;
	}
	std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::displayContactList(void) const {
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;

	for (int i = 0; i < _getSize(); ++i) {
		std::string firstName = _contacts[i].getFirstName();
		std::string lastName = _contacts[i].getLastName();
		std::string nickname = _contacts[i].getNickname();

		if (firstName.length() > 10)
			firstName = firstName.substr(0, 9) + ".";
		if (lastName.length() > 10)
			lastName = lastName.substr(0, 9) + ".";
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << firstName << "|";
		std::cout << std::setw(10) << lastName << "|";
		std::cout << std::setw(10) << nickname << std::endl;
	}
}
