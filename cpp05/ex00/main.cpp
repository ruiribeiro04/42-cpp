/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/05 12:00:00 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

// ANSI Color Codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void    printHeader(std::string title)
{
    std::cout << BOLD << CYAN << "\n========================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "========================================" << RESET << std::endl;
}

int main(void)
{
    printHeader("TEST 1: Valid Bureaucrat Construction");
    {
        Bureaucrat    highRank("Zaphod", 1);
        Bureaucrat    midRank("Trillian", 75);
        Bureaucrat    lowRank("Marvin", 150);

        std::cout << GREEN << highRank << RESET << std::endl;
        std::cout << GREEN << midRank << RESET << std::endl;
        std::cout << GREEN << lowRank << RESET << std::endl;
    }

    printHeader("TEST 2: Invalid Construction (Grade Too High)");
    {
        try
        {
            std::cout << YELLOW << "Trying to create a bureaucrat with grade 0..." << RESET << std::endl;
            Bureaucrat    invalid("TooGood", 0);
            std::cout << invalid << std::endl;
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "Caught: " << e.what() << RESET << std::endl;
        }
    }

    printHeader("TEST 3: Invalid Construction (Grade Too Low)");
    {
        try
        {
            std::cout << YELLOW << "Trying to create a bureaucrat with grade 151..." << RESET << std::endl;
            Bureaucrat    invalid("TooBad", 151);
            std::cout << invalid << std::endl;
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "Caught: " << e.what() << RESET << std::endl;
        }
    }

    printHeader("TEST 4: Getters");
    {
        Bureaucrat    b("Ford", 42);

        std::cout << BLUE << "getName():  " << GREEN << b.getName() << RESET << std::endl;
        std::cout << BLUE << "getGrade(): " << GREEN << b.getGrade() << RESET << std::endl;
    }

    printHeader("TEST 5: Increment / Decrement");
    {
        Bureaucrat    b("Arthur", 3);

        std::cout << BLUE << "Before: " << b << RESET << std::endl;
        b.incrementGrade();
        std::cout << BLUE << "After increment: " << b << RESET << " (expected grade 2)" << std::endl;
        b.decrementGrade();
        b.decrementGrade();
        std::cout << BLUE << "After 2 decrements: " << b << RESET << " (expected grade 4)" << std::endl;
    }

    printHeader("TEST 6: Increment Past the Limit");
    {
        Bureaucrat    b("Perfect", 1);

        std::cout << BLUE << "Before: " << b << RESET << std::endl;
        try
        {
            b.incrementGrade();
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "Caught: " << e.what() << RESET << std::endl;
        }
        std::cout << BLUE << "After:  " << b << RESET << " (grade unchanged)" << std::endl;
    }

    printHeader("TEST 7: Decrement Past the Limit");
    {
        Bureaucrat    b("Hopeless", 150);

        std::cout << BLUE << "Before: " << b << RESET << std::endl;
        try
        {
            b.decrementGrade();
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "Caught: " << e.what() << RESET << std::endl;
        }
        std::cout << BLUE << "After:  " << b << RESET << " (grade unchanged)" << std::endl;
    }

    printHeader("TEST 8: Orthodox Canonical Form");
    {
        Bureaucrat    original("Original", 10);
        Bureaucrat    copy(original);
        Bureaucrat    assigned("Assigned", 100);

        std::cout << MAGENTA << "--- Copy construction ---" << RESET << std::endl;
        std::cout << BLUE << "Original: " << original << RESET << std::endl;
        std::cout << BLUE << "Copy:     " << copy << RESET << std::endl;

        std::cout << MAGENTA << "--- Copy assignment (grade only, name is const) ---" << RESET << std::endl;
        assigned = original;
        std::cout << BLUE << "Assigned: " << assigned << RESET << std::endl;
    }

    printHeader("TEST 9: Direct Exception Types");
    {
        try
        {
            throw (Bureaucrat::GradeTooHighException());
        }
        catch (Bureaucrat::GradeTooHighException const& e)
        {
            std::cout << RED << "GradeTooHighException: " << e.what() << RESET << std::endl;
        }
        try
        {
            throw (Bureaucrat::GradeTooLowException());
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "Caught as std::exception: " << e.what() << RESET << std::endl;
        }
    }

    std::cout << BOLD << GREEN << "\n========================================" << std::endl;
    std::cout << "END OF TESTS: All tests completed successfully!" << std::endl;
    std::cout << "========================================" << RESET << std::endl;

    return (0);
}
