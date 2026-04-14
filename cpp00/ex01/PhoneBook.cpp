/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferma <ruiferma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:30:00 by ruiferma          #+#    #+#             */
/*   Updated: 2025/04/11 10:30:00 by ruiferma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

/*
 * Constructor
 * Initialize the phonebook with zero contacts
 */
PhoneBook::PhoneBook(void) {
    this->_contactCount = 0;
}

/*
 * Destructor
 * Nothing special to clean up - we're using a fixed array
 */
PhoneBook::~PhoneBook(void) {
    // No dynamic memory, so nothing to delete
}

/*
 * Helper function: Truncate a string to 10 characters
 * If longer than 10, replace the last character with a '.'
 */
std::string PhoneBook::_truncateString(std::string str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

/*
 * Add a new contact to the phonebook
 * 
 * Logic:
 * 1. Calculate the position using modulo operator (circular buffer)
 * 2. Prompt the user for each field
 * 3. Validate that no field is empty
 * 4. Store the contact
 */
void PhoneBook::addContact(void) {
    int position;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    // Calculate position using modulo
    // This creates a circular buffer:
    // - First 8 contacts go to positions 0-7
    // - 9th contact goes to position 0 (replaces 1st)
    // - 10th contact goes to position 1 (replaces 2nd)
    // - and so on...
    position = this->_contactCount % 8;

    // Get contact information from user
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);

    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);

    // Validate that no field is empty
    if (firstName.empty() || lastName.empty() || nickname.empty() || 
        phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "Error: All fields must be filled. Contact not added." << std::endl;
        return;
    }

    // Store the contact using setters
    this->_contacts[position].setFirstName(firstName);
    this->_contacts[position].setLastName(lastName);
    this->_contacts[position].setNickname(nickname);
    this->_contacts[position].setPhoneNumber(phoneNumber);
    this->_contacts[position].setDarkestSecret(darkestSecret);

    // Increment the contact counter
    this->_contactCount++;

    std::cout << "Contact added successfully!" << std::endl;
}

/*
 * Search for and display a contact
 * 
 * Logic:
 * 1. Display a table of all contacts
 * 2. Ask user to select an index
 * 3. Display full details of the selected contact
 */
void PhoneBook::searchContact(void) {
    // Check if phonebook is empty
    if (this->_contactCount == 0) {
        std::cout << "Phonebook is empty. Add some contacts first!" << std::endl;
        return;
    }

    // Display the table header
    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << std::endl;

    // Display each contact in the table
    // We only display contacts that have been added (up to _contactCount or 8, whichever is smaller)
    int displayCount = (this->_contactCount < 8) ? this->_contactCount : 8;
    
    for (int i = 0; i < displayCount; i++) {
        std::cout << std::setw(10) << std::right << i << "|";
        std::cout << std::setw(10) << std::right << this->_truncateString(this->_contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << std::right << this->_truncateString(this->_contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << std::right << this->_truncateString(this->_contacts[i].getNickname()) << std::endl;
    }

    // Prompt user to select a contact
    std::string input;
    std::cout << "Enter the index of the contact to display: ";
    std::getline(std::cin, input);

    // Validate the index
    // Check if input is a single digit and within range
    if (input.length() == 1 && input[0] >= '0' && input[0] <= '7') {
        int index = input[0] - '0';  // Convert char digit to integer
        
        // Check if the index is valid (contact exists)
        if (index < displayCount) {
            // Display full contact information
            std::cout << "First Name: " << this->_contacts[index].getFirstName() << std::endl;
            std::cout << "Last Name: " << this->_contacts[index].getLastName() << std::endl;
            std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
            std::cout << "Phone Number: " << this->_contacts[index].getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
        } else {
            std::cout << "Error: No contact at this index." << std::endl;
        }
    } else {
        std::cout << "Error: Invalid index. Please enter a number between 0 and 7." << std::endl;
    }
}
