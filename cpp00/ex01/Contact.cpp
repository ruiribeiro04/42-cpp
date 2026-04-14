/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferma <ruiferma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:30:00 by ruiferma          #+#    #+#             */
/*   Updated: 2025/04/11 10:30:00 by ruiferma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
 * Default Constructor
 * Initializes a Contact object with empty strings
 */
Contact::Contact(void) {
    this->_firstName = "";
    this->_lastName = "";
    this->_nickname = "";
    this->_phoneNumber = "";
    this->_darkestSecret = "";
}

/*
 * Destructor
 * Called when the Contact object is destroyed
 * We don't have any dynamic memory, so nothing special to do here
 */
Contact::~Contact(void) {
    // Nothing to clean up - we're not using 'new' anywhere
}

/*
 * SETTERS
 * Each setter assigns a value to one of the private members
 * The 'this->' pointer refers to the current object
 */

void Contact::setFirstName(std::string firstName) {
    this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
    this->_lastName = lastName;
}

void Contact::setNickname(std::string nickname) {
    this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
    this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
    this->_darkestSecret = darkestSecret;
}

/*
 * GETTERS
 * Each getter returns the value of one of the private members
 * The 'const' keyword means these methods don't modify the object
 */

std::string Contact::getFirstName(void) const {
    return this->_firstName;
}

std::string Contact::getLastName(void) const {
    return this->_lastName;
}

std::string Contact::getNickname(void) const {
    return this->_nickname;
}

std::string Contact::getPhoneNumber(void) const {
    return this->_phoneNumber;
}

std::string Contact::getDarkestSecret(void) const {
    return this->_darkestSecret;
}
