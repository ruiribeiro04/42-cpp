/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferma <ruiferma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:00:00 by ruiferma          #+#    #+#             */
/*   Updated: 2025/04/11 10:00:00 by ruiferma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * EX00 - Megaphone
 * 
 * This program takes command-line arguments and outputs them in UPPERCASE.
 * If no arguments are provided, it outputs a special message.
 * 
 * Learning objectives:
 * - Using std::cout for output (C++ style instead of printf)
 * - Using std::toupper for character conversion
 * - Understanding command-line arguments (argc, argv)
 * - Basic loops and character manipulation
 */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    /*
     * argc = argument count (number of command-line arguments)
     * argv = argument vector (array of strings)
     * 
     * argv[0] is the program name
     * argv[1] is the first actual argument
     * 
     * If argc == 1, it means only the program name was provided (no arguments)
     */
    
    // Check if no arguments were provided (only program name)
    if (argc == 1)
    {
        // Output the special message for no input
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        // We have arguments! Let's process each one
        // Start at i = 1 because argv[0] is the program name
        
        for (int i = 1; i < argc; i++)
        {
            // For each argument, iterate through each character
            // argv[i][j] accesses the j-th character of the i-th argument
            // The loop continues until we hit the null terminator ('\0')
            
            for (int j = 0; argv[i][j] != '\0'; j++)
            {
                // Convert character to uppercase and print it
                // std::toupper() returns an int, so we cast it back to char
                // static_cast is the C++ way to do type casting
                char upper_char = static_cast<char>(std::toupper(argv[i][j]));
                std::cout << upper_char;
            }
        }
        
        // Print a newline at the end
        std::cout << std::endl;
    }
    
    return 0;
}
