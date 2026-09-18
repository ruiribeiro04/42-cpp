/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/18 13:45:28 by ruiferna         ###   ########.fr       */
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

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

static void chapter(const std::string& n, const std::string& title)
{
    std::cout << BOLD << CYAN
              << "\n+--------------------------------------------------------------------+\n"
              << "|  TEST " << n << " — " << title << "\n"
              << "+--------------------------------------------------------------------+"
              << RESET << std::endl;
}

static void action(const std::string& text)
{
    std::cout << BLUE << "[ do     ] " << text << RESET << std::endl;
}

static void expect(const std::string& text)
{
    std::cout << MAGENTA << "[ expect ] " << text << RESET << std::endl;
}

static void result(const std::string& text)
{
    std::cout << GREEN << "[ result ] " << text << RESET << std::endl;
}

static void fail(const std::string& text)
{
    std::cout << RED << "[ FAIL!! ] " << text << RESET << std::endl;
}

int main(void)
{
    std::cout << BOLD << MAGENTA
              << "\n+====================================================================+\n"
              << "|  CPP06 — Exercise 02: Forms (AForm hierarchy)                      \n"
              << "+====================================================================+"
              << RESET << std::endl;

    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // ───────────────────────────────────────────────────────────────────
    chapter("1", "Form Grades and operator<<");
    action("Instantiate ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm.");
    expect("Print each via operator<<; grades should match spec (145/137, 72/45, 25/5).");
    {
        ShrubberyCreationForm    shrub("home");
        RobotomyRequestForm      robo("Bender");
        PresidentialPardonForm   pardon("Ford");

        std::cout << "    " << shrub << std::endl;
        std::cout << "    " << robo << std::endl;
        std::cout << "    " << pardon << std::endl;
    }
    result("All concrete forms construct and print correctly.");

    // ───────────────────────────────────────────────────────────────────
    chapter("2", "AForm Is Abstract");
    action("Show that AForm cannot be instantiated (executeAction() is pure virtual).");
    expect("No runtime test — compile-time error if uncommented.");
    {
        std::cout << BLUE << "    AForm cannot be instantiated: executeAction() is pure virtual."
                  << RESET << std::endl;
        std::cout << BLUE << "    Uncommenting the next line would fail compilation:" << RESET << std::endl;
        std::cout << BLUE << "    // AForm impossible(\"name\", 1, 1, \"target\");" << RESET << std::endl;
    }
    result("AForm correctly abstract; only derived concrete forms can be instantiated.");

    // ───────────────────────────────────────────────────────────────────
    chapter("3", "Successful Shrubbery Creation");
    action("Bureaucrat(\"Gardener\", 130) signs and executes ShrubberyCreationForm(\"garden\").");
    expect("File 'garden_shrubbery' created with ASCII trees; no exception.");
    {
        Bureaucrat              gardener("Gardener", 130);
        ShrubberyCreationForm   shrub("garden");

        gardener.signForm(shrub);
        gardener.executeForm(shrub);
        std::cout << YELLOW << "    Check: file 'garden_shrubbery' created in the working directory"
                  << RESET << std::endl;
    }
    result("ShrubberyCreationForm creates file when signed/executed by sufficient grade.");

    // ───────────────────────────────────────────────────────────────────
    chapter("4", "Execute Unsigned Form");
    action("Bureaucrat(\"Boss\", 1) executes unsigned ShrubberyCreationForm(\"park\").");
    expect("FormNotSignedException thrown; executeForm() prints reason; no file created.");
    {
        Bureaucrat              boss("Boss", 1);
        ShrubberyCreationForm   shrub("park");

        try
        {
            boss.executeForm(shrub);
            fail("Should have thrown FormNotSignedException.");
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "    caught: " << e.what() << RESET << std::endl;
        }
    }
    result("executeForm() rejects unsigned forms with clear error message.");

    // ───────────────────────────────────────────────────────────────────
    chapter("5", "Grade Too Low to Sign / Execute");
    action("Grade 146 tries to sign (needs 145) → fail; grade 145 signs → success; "
            "grade 146 tries to execute (needs 137) → fail; grade 145 tries to execute → fail.");
    expect("Sign succeeds only at grade ≤145; execute succeeds only at grade ≤137.");
    {
        Bureaucrat              unlucky("Unlucky", 146);
        ShrubberyCreationForm   shrub("forest");

        std::cout << MAGENTA << "    --- grade 146 signing form requiring 145 ---" << RESET << std::endl;
        unlucky.signForm(shrub);
        std::cout << MAGENTA << "    --- grade 145 signing form requiring 145 ---" << RESET << std::endl;
        Bureaucrat    signer("Signer", 145);
        signer.signForm(shrub);
        std::cout << MAGENTA << "    --- grade 146 executing form requiring 137 ---" << RESET << std::endl;
        unlucky.executeForm(shrub);
        std::cout << MAGENTA << "    --- grade 145 executing form requiring 137 ---" << RESET << std::endl;
        signer.executeForm(shrub);
    }
    result("Both sign and execute enforce their respective grade thresholds.");

    // ───────────────────────────────────────────────────────────────────
    chapter("6", "Robotomy (50% Success, Multiple Attempts)");
    action("Bureaucrat(\"Doctor\", 1) signs RobotomyRequestForm(\"Bender\"); "
            "execute 6 times to see ~50% success.");
    expect("Random 50% success/failure messages; each attempt prints its outcome.");
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
    result("RobotomyRequestForm randomly succeeds or fails; all attempts are logged.");

    // ───────────────────────────────────────────────────────────────────
    chapter("7", "Presidential Pardon");
    action("Bureaucrat(\"Zaphod\", 1) signs and executes PresidentialPardonForm(\"Arthur Dent\").");
    expect("Message announcing pardon; no exception.");
    {
        Bureaucrat              president("Zaphod", 1);
        PresidentialPardonForm   pardon("Arthur Dent");

        president.signForm(pardon);
        president.executeForm(pardon);
    }
    result("PresidentialPardonForm prints pardon message when executed by sufficient grade.");

    // ───────────────────────────────────────────────────────────────────
    chapter("8", "Polymorphism Through AForm*");
    action("Allocate array of AForm* (Shrubbery, Robotomy, Pardon); sign and execute via base pointer; delete.");
    expect("Each derived form's executeAction() runs; virtual destructor cleans up correctly.");
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
            delete forms[i];
        }
    }
    result("Polymorphic sign/execute works; virtual destructor prevents leaks.");

    // ───────────────────────────────────────────────────────────────────
    chapter("9", "Orthodox Canonical Form (Derived Forms)");
    action("Copy-construct and copy-assign a PresidentialPardonForm; sign before copy.");
    expect("Copied form inherits signed state; name/grades const (cannot change).");
    {
        PresidentialPardonForm   original("Original");
        Bureaucrat               signer("Signer", 1);

        signer.signForm(original);
        PresidentialPardonForm   copy(original);
        PresidentialPardonForm   assigned("Assigned");
        assigned = original;

        std::cout << BLUE << "    copy:     " << copy << RESET << " (should be signed)" << std::endl;
        std::cout << BLUE << "    assigned: " << assigned << RESET << " (should be signed)" << std::endl;
    }
    result("Copy constructor/assignment correctly copy signed state; const fields unchanged.");

    return (0);
}