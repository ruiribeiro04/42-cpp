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
#include "Form.hpp"
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
    printHeader("TEST 1: Valid Form Construction + << Operator");
    {
        Form    easy("Easy Form", 145, 137);
        Form    hard("Hard Form", 1, 1);

        std::cout << GREEN << easy << RESET << std::endl;
        std::cout << GREEN << hard << RESET << std::endl;
    }

    printHeader("TEST 2: Invalid Form Grades");
    {
        try
        {
            std::cout << YELLOW << "Creating form with sign grade 0..." << RESET << std::endl;
            Form    invalid("Bad Sign", 0, 50);
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "Caught: " << e.what() << RESET << std::endl;
        }
        try
        {
            std::cout << YELLOW << "Creating form with exec grade 151..." << RESET << std::endl;
            Form    invalid("Bad Exec", 50, 151);
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "Caught: " << e.what() << RESET << std::endl;
        }
    }

    printHeader("TEST 3: Bureaucrat Signs a Form (Success)");
    {
        Bureaucrat    boss("Boss", 1);
        Form          form("Contract", 50, 25);

        std::cout << BLUE << form << RESET << std::endl;
        boss.signForm(form);
        std::cout << BLUE << form << RESET << std::endl;
    }

    printHeader("TEST 4: Bureaucrat Can't Sign (Grade Too Low)");
    {
        Bureaucrat    intern("Intern Bob", 140);
        Form          form("Contract", 50, 25);

        intern.signForm(form);
        std::cout << BLUE << "Form state after failed attempt: " << form << RESET << std::endl;
    }

    printHeader("TEST 5: Grade Boundaries in beSigned");
    {
        Bureaucrat    exact("Exactly Enough", 50);
        Bureaucrat    notEnough("One Short", 51);
        Form          form("Boundary Form", 50, 50);

        std::cout << MAGENTA << "--- Grade 50 signing a form requiring 50 (should work) ---" << RESET << std::endl;
        exact.signForm(form);
        std::cout << MAGENTA << "--- Grade 51 signing a form requiring 50 (should fail) ---" << RESET << std::endl;
        notEnough.signForm(form);
    }

    printHeader("TEST 6: Calling beSigned Directly");
    {
        Bureaucrat    low("Low Rank", 100);
        Form          form("Direct Form", 20, 20);

        try
        {
            low.signForm(form);
            form.beSigned(low); // Would not throw: already signed, still signs again
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "Caught: " << e.what() << RESET << std::endl;
        }
        std::cout << BLUE << form << RESET << std::endl;
    }

    printHeader("TEST 7: Orthodox Canonical Form (Both Classes)");
    {
        Bureaucrat    bOriginal("Original", 10);
        Bureaucrat    bCopy(bOriginal);
        Bureaucrat    bAssigned("Assigned", 100);
        bAssigned = bOriginal;

        Form    fOriginal("Form Original", 60, 60);
        Form    fCopy(fOriginal);
        Bureaucrat    signer("Signer", 1);
        signer.signForm(fOriginal);
        Form    fAssigned("Form Assigned", 100, 100);
        fAssigned = fOriginal; // Copies only the signed state

        std::cout << BLUE << bCopy << RESET << std::endl;
        std::cout << BLUE << bAssigned << RESET << std::endl;
        std::cout << BLUE << fCopy << RESET << " (copy keeps signed state)" << std::endl;
        std::cout << BLUE << fAssigned << RESET << " (name/grades are const, signed copied)" << std::endl;
    }

    std::cout << BOLD << GREEN << "\n========================================" << std::endl;
    std::cout << "END OF TESTS: All tests completed successfully!" << std::endl;
    std::cout << "========================================" << RESET << std::endl;

    return (0);
}
