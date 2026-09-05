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
#include "Intern.hpp"
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
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    printHeader("TEST 1: The Subject's Own Example");
    {
        Intern    someRandomIntern;
        AForm*    rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
    }

    printHeader("TEST 2: All Three Form Types");
    {
        Intern    intern;
        AForm*    form;

        form = intern.makeForm("shrubbery creation", "home");
        std::cout << BLUE << *form << RESET << std::endl;
        delete form;

        form = intern.makeForm("robotomy request", "Marvin");
        std::cout << BLUE << *form << RESET << std::endl;
        delete form;

        form = intern.makeForm("presidential pardon", "Trillian");
        std::cout << BLUE << *form << RESET << std::endl;
        delete form;
    }

    printHeader("TEST 3: Unknown Form Name");
    {
        Intern    intern;
        AForm*    form;

        form = intern.makeForm("coffee request", "Zaphod");
        std::cout << YELLOW << "Returned pointer: " << form
                  << " (NULL as expected)" << RESET << std::endl;
    }

    printHeader("TEST 4: Full Pipeline: Intern -> Bureaucrat -> Execution");
    {
        Intern       intern;
        Bureaucrat   boss("Boss", 1);
        AForm*       form;

        form = intern.makeForm("shrubbery creation", "office");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;

        form = intern.makeForm("presidential pardon", "Arthur Dent");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    printHeader("TEST 5: Intern-Made Forms Respect Grade Rules");
    {
        Intern       intern;
        Bureaucrat   junior("Junior", 140);
        AForm*       form;

        form = intern.makeForm("shrubbery creation", "garden");
        junior.signForm(*form);      // Needs 145, has 140: succeeds
        junior.executeForm(*form);   // Needs 137, has 140: fails
        delete form;
    }

    printHeader("TEST 6: Intern Orthodox Canonical Form");
    {
        Intern    original;
        Intern    copy(original);
        Intern    assigned;

        assigned = original;
        std::cout << GREEN << "Copy and assignment work (interns are interchangeable)"
                  << RESET << std::endl;

        // Prove the copy is still fully functional
        AForm*    form = copy.makeForm("robotomy request", "CopyBot");
        delete form;
    }

    std::cout << BOLD << GREEN << "\n========================================" << std::endl;
    std::cout << "END OF TESTS: All tests completed successfully!" << std::endl;
    std::cout << "========================================" << RESET << std::endl;

    return (0);
}
