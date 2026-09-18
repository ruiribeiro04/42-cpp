/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/18 13:40:04 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define DIM     "\033[2m"

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
              << "|  CPP05 — Exercise 00: Bureaucrat                                   \n"
              << "+====================================================================+"
              << RESET << std::endl;

    // ───────────────────────────────────────────────────────────────────
    chapter("1", "Valid Construction (boundaries 1 and 150)");
    action("Construct bureaucrats with grades 1, 75 and 150.");
    expect("All three should print via operator<<.");
    {
        Bureaucrat    highRank("Zaphod", 1);
        Bureaucrat    midRank("Trillian", 75);
        Bureaucrat    lowRank("Marvin", 150);

        std::cout << "    " << highRank << std::endl;
        std::cout << "    " << midRank << std::endl;
        std::cout << "    " << lowRank << std::endl;
    }
    result("Grades 1 and 150 are valid boundaries. Construction succeeds.");

    // ───────────────────────────────────────────────────────────────────
    chapter("2", "Invalid Construction — Grade Too High (0)");
    action("Construct Bureaucrat(\"TooGood\", 0).");
    expect("GradeTooHighException thrown from constructor.");
    {
        try
        {
            Bureaucrat    invalid("TooGood", 0);
            std::cout << invalid << std::endl;
            fail("Constructor should have thrown.");
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "    caught: " << e.what() << RESET << std::endl;
        }
    }
    result("Upper boundary is guarded.");

    // ───────────────────────────────────────────────────────────────────
    chapter("3", "Invalid Construction — Grade Too Low (151)");
    action("Construct Bureaucrat(\"TooBad\", 151).");
    expect("GradeTooLowException thrown from constructor.");
    {
        try
        {
            Bureaucrat    invalid("TooBad", 151);
            std::cout << invalid << std::endl;
            fail("Constructor should have thrown.");
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "    caught: " << e.what() << RESET << std::endl;
        }
    }
    result("Lower boundary is guarded.");

    // ───────────────────────────────────────────────────────────────────
    chapter("4", "Getters — getName() and getGrade()");
    action("Call getters on Bureaucrat(\"Ford\", 42).");
    expect("getName() → \"Ford\", getGrade() → 42.");
    {
        Bureaucrat    b("Ford", 42);

        std::cout << BLUE << "    getName()  → " << GREEN << b.getName() << RESET << std::endl;
        std::cout << BLUE << "    getGrade() → " << GREEN << b.getGrade() << RESET << std::endl;
    }
    result("Getters expose private fields safely.");

    // ───────────────────────────────────────────────────────────────────
    chapter("5", "Increment / Decrement");
    action("Start grade 3 → increment once → decrement twice.");
    expect("3 → 2 → 3 → 4.");
    {
        Bureaucrat    b("Arthur", 3);

        std::cout << BLUE << "    before:            " << b << RESET << std::endl;
        b.incrementGrade();
        std::cout << BLUE << "    after increment:   " << b << RESET << " (expect 2)" << std::endl;
        b.decrementGrade();
        b.decrementGrade();
        std::cout << BLUE << "    after 2 decrements:" << b << RESET << " (expect 4)" << std::endl;
    }
    result("Each call mutates grade by ±1.");

    // ───────────────────────────────────────────────────────────────────
    chapter("6", "Increment Past Limit (grade 1)");
    action("incrementGrade() on a grade 1 bureaucrat.");
    expect("GradeTooHighException thrown; grade unchanged.");
    {
        Bureaucrat    b("Perfect", 1);

        std::cout << BLUE << "    before: " << b << RESET << std::endl;
        try
        {
            b.incrementGrade();
            fail("Should have thrown.");
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "    caught: " << e.what() << RESET << std::endl;
        }
        std::cout << BLUE << "    after:  " << b << RESET << " (must still be 1)" << std::endl;
    }
    result("Strong exception guarantee — state preserved.");

    // ───────────────────────────────────────────────────────────────────
    chapter("7", "Decrement Past Limit (grade 150)");
    action("decrementGrade() on a grade 150 bureaucrat.");
    expect("GradeTooLowException thrown; grade unchanged.");
    {
        Bureaucrat    b("Hopeless", 150);

        std::cout << BLUE << "    before: " << b << RESET << std::endl;
        try
        {
            b.decrementGrade();
            fail("Should have thrown.");
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "    caught: " << e.what() << RESET << std::endl;
        }
        std::cout << BLUE << "    after:  " << b << RESET << " (must still be 150)" << std::endl;
    }
    result("Strong exception guarantee — state preserved.");

    // ───────────────────────────────────────────────────────────────────
    chapter("8", "Orthodox Canonical Form");
    action("Copy-construct from grade 10; copy-assign to a grade 100.");
    expect("Copy and assigned both have grade 10. Names may differ (const).");
    {
        Bureaucrat    original("Original", 10);
        Bureaucrat    copy(original);
        Bureaucrat    assigned("Assigned", 100);

        std::cout << BLUE << "    original: " << original << RESET << std::endl;
        std::cout << BLUE << "    copy:     " << copy << RESET << " (expect grade 10)" << std::endl;
        assigned = original;
        std::cout << BLUE << "    assigned: " << assigned << RESET << " (expect grade 10)" << std::endl;
    }
    result("Copy ctor and copy assignment operator work.");

    // ───────────────────────────────────────────────────────────────────
    chapter("9", "Exception Type Hierarchy");
    action("Throw GradeTooHighException (catch by type); "
            "throw GradeTooLowException (catch as std::exception).");
    expect("Both what() messages printed; second caught via base class.");
    {
        try
        {
            throw (Bureaucrat::GradeTooHighException());
        }
        catch (Bureaucrat::GradeTooHighException const& e)
        {
            std::cout << RED << "    GradeTooHighException: " << e.what() << RESET << std::endl;
        }
        try
        {
            throw (Bureaucrat::GradeTooLowException());
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "    caught as std::exception: " << e.what() << RESET << std::endl;
        }
    }
    result("Exceptions inherit from std::exception — polymorphic catch works.");

    return (0);
}