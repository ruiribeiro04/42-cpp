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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

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
    // Seed the PRNG once so the robotomy is 50/50 on every run
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    printHeader("TEST 1: Form Grades and << Operator");
    {
        ShrubberyCreationForm    shrub("home");
        RobotomyRequestForm      robo("Bender");
        PresidentialPardonForm   pardon("Ford");

        std::cout << GREEN << shrub << RESET << std::endl;
        std::cout << GREEN << robo << RESET << std::endl;
        std::cout << GREEN << pardon << RESET << std::endl;
    }

    printHeader("TEST 2: AForm Is Abstract (compile-time by design)");
    {
        std::cout << BLUE << "AForm cannot be instantiated: executeAction() is pure virtual."
                  << RESET << std::endl;
        std::cout << BLUE << "Uncommenting the next line would fail compilation:" << RESET << std::endl;
        std::cout << BLUE << "// AForm    impossible(\"name\", 1, 1, \"target\");" << RESET << std::endl;
    }

    printHeader("TEST 3: Successful Shrubbery Creation");
    {
        Bureaucrat              gardener("Gardener", 130);
        ShrubberyCreationForm   shrub("garden");

        gardener.signForm(shrub);
        gardener.executeForm(shrub);
        std::cout << YELLOW << "Check: file 'garden_shrubbery' created in the working directory"
                  << RESET << std::endl;
    }

    printHeader("TEST 4: Execute Unsigned Form (Throws)");
    {
        Bureaucrat              boss("Boss", 1);
        ShrubberyCreationForm   shrub("park");

        boss.executeForm(shrub); // Not signed yet: must fail with an explicit error
    }

    printHeader("TEST 5: Grade Too Low to Sign / Execute");
    {
        Bureaucrat              unlucky("Unlucky", 146);
        ShrubberyCreationForm   shrub("forest");

        unlucky.signForm(shrub); // Needs 145, has 146: fails

        Bureaucrat    signer("Signer", 145);
        signer.signForm(shrub);  // Exactly enough: signs
        unlucky.executeForm(shrub); // Needs 137, has 146: fails
        signer.executeForm(shrub);  // Still too low to execute (145 > 137)
    }

    printHeader("TEST 6: Robotomy (50% Success, Multiple Attempts)");
    {
        Bureaucrat            doctor("Doctor", 1);
        RobotomyRequestForm   robo("Bender");

        doctor.signForm(robo);
        for (int i = 0; i < 6; i++)
        {
            std::cout << MAGENTA << "--- Attempt " << (i + 1) << " ---" << RESET << std::endl;
            doctor.executeForm(robo);
        }
    }

    printHeader("TEST 7: Presidential Pardon");
    {
        Bureaucrat              president("Zaphod", 1);
        PresidentialPardonForm   pardon("Arthur Dent");

        president.signForm(pardon);
        president.executeForm(pardon);
    }

    printHeader("TEST 8: Polymorphism Through AForm*");
    {
        Bureaucrat    boss("Boss", 1);
        AForm*        forms[3];

        forms[0] = new ShrubberyCreationForm("poly1");
        forms[1] = new RobotomyRequestForm("poly2");
        forms[2] = new PresidentialPardonForm("poly3");

        for (int i = 0; i < 3; i++)
        {
            boss.signForm(*forms[i]);
            boss.executeForm(*forms[i]);
            delete forms[i]; // Virtual destructor: correct derived destructor called
        }
    }

    printHeader("TEST 9: Orthodox Canonical Form (Derived Forms)");
    {
        PresidentialPardonForm   original("Original");
        Bureaucrat               signer("Signer", 1);

        signer.signForm(original);
        PresidentialPardonForm   copy(original); // Copy constructor
        PresidentialPardonForm   assigned("Assigned");
        assigned = original;                     // Copy assignment (signed state)

        std::cout << BLUE << copy << RESET << std::endl;
        std::cout << BLUE << assigned << RESET << std::endl;
    }

    std::cout << BOLD << GREEN << "\n========================================" << std::endl;
    std::cout << "END OF TESTS: All tests completed successfully!" << std::endl;
    std::cout << "========================================" << RESET << std::endl;

    return (0);
}
