
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {

public:
		PhoneBook(void);

		void	addContact();
		void	displayContact(int index) const;
		void	displayContactList(void) const;

private:
	int 	_getSize() const;

	Contact	_contacts[8];
	int		_contact_count;
};

#endif // PHONEBOOK_H
