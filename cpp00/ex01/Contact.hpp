/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferma <ruiferma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:30:00 by ruiferma          #+#    #+#             */
/*   Updated: 2025/04/11 10:30:00 by ruiferma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * EX01 - Contact Class
 * 
 * This class represents a single contact in the phonebook.
 * 
 * Learning objectives:
 * - Class declaration (header file)
 * - Private data members (encapsulation)
 * - Public member functions (interface)
 * - Getters and setters (accessors and mutators)
 * - std::string usage
 */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
    /*
     * PRIVATE SECTION:
     * These members can only be accessed from within the class.
     * This is called "encapsulation" - we hide the internal data.
     * Outside code can only access these through the public methods.
     */
    private:
        std::string _firstName;      // Contact's first name
        std::string _lastName;       // Contact's last name
        std::string _nickname;       // Contact's nickname
        std::string _phoneNumber;    // Contact's phone number
        std::string _darkestSecret;  // Contact's darkest secret

    /*
     * PUBLIC SECTION:
     * These methods can be called from outside the class.
     * They provide a controlled way to access and modify the private data.
     */
    public:
        // Constructor: called when a Contact object is created
        Contact(void);
        
        // Destructor: called when a Contact object is destroyed
        ~Contact(void);

        // SETTERS: methods to set the values of private members
        void setFirstName(std::string firstName);
        void setLastName(std::string lastName);
        void setNickname(std::string nickname);
        void setPhoneNumber(std::string phoneNumber);
        void setDarkestSecret(std::string darkestSecret);

        // GETTERS: methods to get the values of private members
        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickname(void) const;
        std::string getPhoneNumber(void) const;
        std::string getDarkestSecret(void) const;
};

#endif
