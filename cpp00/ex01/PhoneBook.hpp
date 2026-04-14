/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferma <ruiferma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:30:00 by ruiferma          #+#    #+#             */
/*   Updated: 2025/04/11 10:30:00 by ruiferma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * EX01 - PhoneBook Class
 * 
 * This class manages a phonebook with up to 8 contacts.
 * 
 * Learning objectives:
 * - Class composition (using objects as members)
 * - Array management (fixed-size array)
 * - Circular buffer logic (replacing oldest contact when full)
 * - std::string manipulation and truncation
 * - Formatted output with <iomanip>
 */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook {
    /*
     * PRIVATE SECTION:
     * Internal data and helper functions
     */
    private:
        Contact _contacts[8];     // Fixed array of 8 contacts (no dynamic allocation!)
        int     _contactCount;    // Total number of contacts added (can exceed 8)

        // Helper function to truncate strings for display
        std::string _truncateString(std::string str);

    /*
     * PUBLIC SECTION:
     * Methods that can be called from main()
     */
    public:
        // Constructor: initialize an empty phonebook
        PhoneBook(void);
        
        // Destructor: clean up when phonebook is destroyed
        ~PhoneBook(void);

        // Add a new contact to the phonebook
        void addContact(void);

        // Display all contacts and show details of a selected contact
        void searchContact(void);
};

#endif
