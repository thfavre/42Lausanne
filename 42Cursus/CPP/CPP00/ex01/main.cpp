#include <string>
#include <iostream>
#include "PhoneBook.hpp"


int main() {

	std::string	input;
	PhoneBook	phoneBook;

	while (1) {
		std::cout << "PhoneBook> ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
		{
			phoneBook.displayContactList();
			std::cout << "Enter index: ";
			std::getline(std::cin, input);
			if (input.length() == 1)
				phoneBook.displayContact(input[0] - '0');
		}
		else if (input == "EXIT" || std::cin.eof())
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}

}
