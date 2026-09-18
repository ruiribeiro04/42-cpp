/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/18 13:51:53 by ruiferna         ###   ########.fr       */
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
              << "|  CPP05 — Exercise 03: Intern                                        \n"
              << "+====================================================================+"
              << RESET << std::endl;

    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // ───────────────────────────────────────────────────────────────────
    chapter("1", "Subject's Own Example");
    action("Intern makes \"robotomy request\" targeting \"Bender\".");
    expect("Non-NULL AForm* returned; form printed; no crash.");
    {
        Intern    someRandomIntern;
        AForm*    rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            std::cout << "    " << *rrf << std::endl;
            delete rrf;
        }
        else
            fail("makeForm returned NULL for a valid form name.");
    }
    result("Intern produces a valid RobotomyRequestForm as the subject requires.");

    // ───────────────────────────────────────────────────────────────────
    chapter("2", "All Three Form Types");
    action("Intern makes shrubbery creation, robotomy request, presidential pardon.");
    expect("Each returns a non-NULL AForm* of the correct derived type.");
    {
        Intern    intern;
        AForm*    form;

        form = intern.makeForm("shrubbery creation", "home");
        if (form) { std::cout << "    " << *form << RESET << std::endl; delete form; }
        else      fail("shrubbery creation returned NULL.");

        form = intern.makeForm("robotomy request", "Marvin");
        if (form) { std::cout << "    " << *form << RESET << std::endl; delete form; }
        else      fail("robotomy request returned NULL.");

        form = intern.makeForm("presidential pardon", "Trillian");
        if (form) { std::cout << "    " << *form << RESET << std::endl; delete form; }
        else      fail("presidential pardon returned NULL.");
    }
    result("Intern handles all three known form names; memory freed per call.");

    // ───────────────────────────────────────────────────────────────────
    chapter("3", "Unknown Form Name");
    action("Intern makes \"coffee request\" (does not exist).");
    expect("Returns NULL (or throws) — no valid form created.");
    {
        Intern    intern;
        AForm*    form = NULL;

        try
        {
            form = intern.makeForm("coffee request", "Zaphod");
            if (form == NULL)
                std::cout << YELLOW << "    returned NULL as expected" << RESET << std::endl;
            else
            {
                std::cout << "    " << *form << std::endl;
                fail("Unknown form name should not produce a form.");
                delete form;
            }
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "    caught: " << e.what() << RESET << std::endl;
        }
    }
    result("Unknown form name is rejected — either NULL or exception, no leak.");

    // ───────────────────────────────────────────────────────────────────
    chapter("4", "Full Pipeline: Intern → Bureaucrat → Execution");
    action("Intern makes forms; Bureaucrat(\"Boss\", 1) signs and executes each.");
    expect("Shrubbery file created; pardon message printed; no exceptions.");
    {
        Intern       intern;
        Bureaucrat   boss("Boss", 1);
        AForm*       form;

        std::cout << MAGENTA << "    --- shrubbery creation ---" << RESET << std::endl;
        form = intern.makeForm("shrubbery creation", "office");
        if (form)
        {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }

        std::cout << MAGENTA << "    --- presidential pardon ---" << RESET << std::endl;
        form = intern.makeForm("presidential pardon", "Arthur Dent");
        if (form)
        {
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }
    result("Intern-made forms integrate seamlessly with Bureaucrat sign/execute.");

    // ───────────────────────────────────────────────────────────────────
    chapter("5", "Intern-Made Forms Respect Grade Rules");
    action("Bureaucrat(\"Junior\", 140) signs shrubbery (needs 145) → succeeds; "
            "executes (needs 137) → fails.");
    expect("Sign succeeds (140 ≤ 145); execute fails (140 > 137); no crash.");
    {
        Intern       intern;
        Bureaucrat   junior("Junior", 140);
        AForm*       form;

        form = intern.makeForm("shrubbery creation", "garden");
        if (form)
        {
            junior.signForm(*form);
            junior.executeForm(*form);
            delete form;
        }
        else
            fail("makeForm returned NULL for a valid form name.");
    }
    result("Forms created by Intern enforce the same grade rules as manual construction.");

    // ───────────────────────────────────────────────────────────────────
    chapter("6", "Intern Orthodox Canonical Form");
    action("Copy-construct and copy-assign an Intern; use the copy to make a form.");
    expect("Copy and assignment compile and run; copied intern produces valid forms.");
    {
        Intern    original;
        Intern    copy(original);
        Intern    assigned;

        assigned = original;
        std::cout << GREEN << "    copy and assignment succeeded" << RESET << std::endl;

        AForm*    form = copy.makeForm("robotomy request", "CopyBot");
        if (form)
        {
            std::cout << "    " << *form << std::endl;
            delete form;
        }
        else
            fail("Copied intern failed to produce a form.");
    }
    result("Intern OCF works; copied/assigned interns remain fully functional.");

    return (0);
}
