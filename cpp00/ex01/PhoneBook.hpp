#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
	public:
		// -Constructor
		PhoneBook(void);
		
		// -Destructor
		~PhoneBook(void);

		// -Methods
		void	addContact(std::string firstName,
				std::string lastName,
				std::string nickName,
				std::string phoneNumber,
				std::string darkestSecret);
		int		validContact(int index);
		int		getTotalContacts(void) const;
		void	printAllContacts(void) const;
		void	printOneContact(int index) const;

	private:
		Contact	_contacts[8];
		int		_total;
		int		_index;
		void	_printFormattedField(std::string str);
};


#endif