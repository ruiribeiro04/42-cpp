/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/18 13:39:57 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

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
              << "|  CPP05 — Exercise 01: Form                                          \n"
              << "+====================================================================+"
              << RESET << std::endl;

    // ───────────────────────────────────────────────────────────────────
    chapter("1", "Valid Form Construction + operator<<");
    action("Construct forms with sign/exec grades (145,137) and (1,1).");
    expect("Both print via operator<<, isSigned = false.");
    {
        Form    easy("Easy Form", 145, 137);
        Form    hard("Hard Form", 1, 1);

        std::cout << "    " << easy << std::endl;
        std::cout << "    " << hard << std::endl;
    }
    result("Forms construct within valid range [1, 150].");

    // ───────────────────────────────────────────────────────────────────
    chapter("2", "Invalid Form Grades");
    action("Construct form with sign grade 0; construct form with exec grade 151.");
    expect("GradeTooHighException then GradeTooLowException thrown.");
    {
        try
        {
            Form    invalid("Bad Sign", 0, 50);
            std::cout << "    " << invalid << std::endl;
            fail("Constructor should have thrown.");
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "    caught: " << e.what() << RESET << std::endl;
        }
        try
        {
            Form    invalid("Bad Exec", 50, 151);
            std::cout << "    " << invalid << std::endl;
            fail("Constructor should have thrown.");
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "    caught: " << e.what() << RESET << std::endl;
        }
    }
    result("Both sign and exec grades are boundary-checked.");

    // ───────────────────────────────────────────────────────────────────
    chapter("3", "Bureaucrat Signs Form (Success)");
    action("Bureaucrat(\"Boss\", 1) signs Form(\"Contract\", 50, 25).");
    expect("Form goes from not signed → signed. No exception.");
    {
        Bureaucrat    boss("Boss", 1);
        Form          form("Contract", 50, 25);

        std::cout << BLUE << "    before: " << form << RESET << std::endl;
        boss.signForm(form);
        std::cout << BLUE << "    after:  " << form << RESET << std::endl;
    }
    result("signForm() succeeds when bureaucrat grade ≤ required sign grade.");

    // ───────────────────────────────────────────────────────────────────
    chapter("4", "Bureaucrat Can't Sign (Grade Too Low)");
    action("Bureaucrat(\"Intern\", 140) signs Form(\"Contract\", 50, 25).");
    expect("Error message printed; form remains unsigned; no crash.");
    {
        Bureaucrat    intern("Intern Bob", 140);
        Form          form("Contract", 50, 25);

        intern.signForm(form);
        std::cout << BLUE << "    after: " << form << RESET << " (must be unsigned)" << std::endl;
    }
    result("signForm() handles failure gracefully — prints reason, state unchanged.");

    // ───────────────────────────────────────────────────────────────────
    chapter("5", "Grade Boundaries in beSigned");
    action("Grade 50 signs form requiring 50 (exact); grade 51 signs same form.");
    expect("First succeeds (≤); second fails (>).");
    {
        Bureaucrat    exact("ExactlyEnough", 50);
        Bureaucrat    notEnough("OneShort", 51);
        Form          form("Boundary Form", 50, 50);

        std::cout << MAGENTA << "    --- grade 50 signing form requiring 50 ---" << RESET << std::endl;
        exact.signForm(form);
        std::cout << MAGENTA << "    --- grade 51 signing form requiring 50 ---" << RESET << std::endl;
        notEnough.signForm(form);
    }
    result("Boundary is inclusive: grade == required is enough.");

    // ───────────────────────────────────────────────────────────────────
    chapter("6", "beSigned() Direct Call");
    action("Call beSigned() directly: grade 1 on form requiring 20 (success); "
            "grade 100 on form requiring 20 (throws).");
    expect("First call succeeds; second throws GradeTooLowException.");
    {
        Bureaucrat    boss("Boss", 1);
        Bureaucrat    low("LowRank", 100);
        Form          form("Direct Form", 20, 20);

        try
        {
            form.beSigned(boss);
            std::cout << GREEN << "    beSigned(boss) succeeded" << RESET << std::endl;
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "    caught: " << e.what() << RESET << std::endl;
            fail("Should have succeeded.");
        }
        try
        {
            form.beSigned(low);
            fail("Should have thrown.");
        }
        catch (std::exception const& e)
        {
            std::cout << RED << "    caught: " << e.what() << RESET << std::endl;
        }
        std::cout << BLUE << "    final: " << form << RESET << " (signed=true)" << std::endl;
    }
    result("beSigned() throws directly; signForm() wraps it with output.");

    // ───────────────────────────────────────────────────────────────────
    chapter("7", "Orthodox Canonical Form (Both Classes)");
    action("Copy-construct and copy-assign both Bureaucrat and Form. "
            "Sign the original form, then copy it — signed state should copy.");
    expect("Bureaucrat copies grade; Form copies signed state (name/grades are const).");
    {
        Bureaucrat    bOriginal("Original", 10);
        Bureaucrat    bCopy(bOriginal);
        Bureaucrat    bAssigned("Assigned", 100);
        bAssigned = bOriginal;

        Form    fOriginal("FormOriginal", 60, 60);
        Form    fCopy(fOriginal);
        Bureaucrat    signer("Signer", 1);
        signer.signForm(fOriginal);
        Form    fAssigned("FormAssigned", 100, 100);
        fAssigned = fOriginal;

        std::cout << BLUE << "    bCopy:     " << bCopy << RESET << " (expect grade 10)" << std::endl;
        std::cout << BLUE << "    bAssigned: " << bAssigned << RESET << " (expect grade 10)" << std::endl;
        std::cout << BLUE << "    fCopy:     " << fCopy << RESET << " (unsigned — copied before signing)" << std::endl;
        std::cout << BLUE << "    fAssigned: " << fAssigned << RESET << " (signed — copied after signing)" << std::endl;
    }
    result("OCF works for both classes; Form copies signed state, const fields stay.");

    return (0);
}