/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferma <ruiferma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:30:00 by ruiferma          #+#    #+#             */
/*   Updated: 2025/04/11 10:30:00 by ruiferma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * EX01 - Main Program
 * 
 * This is the entry point for the PhoneBook program.
 * 
 * Learning objectives:
 * - Program flow and control
 * - User input handling
 * - Object instantiation
 * - Method calling
 * - Loop management
 */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main(void) {
    // Create a PhoneBook object
    PhoneBook phoneBook;
    
    // String to store user commands
    std::string command;

    // Main program loop
    // Keep running until user enters "EXIT"
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        
        // Read the entire line (including spaces)
        if (!std::getline(std::cin, command)) {
            // Check if EOF (Ctrl+D) was pressed
            if (std::cin.eof()) {
                std::cout << std::endl;
                break;
            }
        }

        // Process the command
        if (command == "ADD") {
            // Add a new contact
            phoneBook.addContact();
        } 
        else if (command == "SEARCH") {
            // Search and display contacts
            phoneBook.searchContact();
        } 
        else if (command == "EXIT") {
            // Exit the program
            break;
        } 
        else {
            // Invalid command - ignore it as per the subject
            std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
        }
    }

    // Program exit
    return 0;
}
