/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:20:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/28 10:07:13 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
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

void    printStats(std::string label, ClapTrap& clap)
{
    std::cout << BOLD << YELLOW << label << ": " << RESET << GREEN
              << "Name=" << clap.getName()
              << " HP=" << clap.getHitPoints()
              << " EP=" << clap.getEnergyPoints()
              << " DMG=" << clap.getAttackDamage()
              << RESET << std::endl;
}

int main(void)
{
    printHeader("TEST 1: Orthodox Canonical Form");
    {
        std::cout << BLUE << "\n--- Creating ClapTraps using different constructors ---" << RESET << std::endl;
        ClapTrap    clap1;                          // Default constructor
        ClapTrap    clap2("Named ClapTrap");        // Parameterized constructor
        ClapTrap    clap3(clap2);                   // Copy constructor

        std::cout << BLUE << "\n--- Using copy assignment operator ---" << RESET << std::endl;
        clap1 = clap2;                          // Assignment operator

        std::cout << BLUE << "\n--- ClapTraps will be destroyed when scope ends ---" << RESET << std::endl;
    }

    printHeader("TEST 2: Basic Attack Functionality");
    {
        ClapTrap    warrior("Warrior");

        printStats("Initial state", warrior);
        std::cout << YELLOW << "\nAttacking 3 times:" << RESET << std::endl;
        warrior.attack("Target 1");
        warrior.attack("Target 2");
        warrior.attack("Target 3");
        printStats("After 3 attacks", warrior);
    }

    printHeader("TEST 3: Taking Damage");
    {
        ClapTrap    tank("Tank");

        printStats("Initial state", tank);
        std::cout << RED << "\nTaking 3 damage:" << RESET << std::endl;
        tank.takeDamage(3);
        printStats("After 3 damage", tank);

        std::cout << RED << "\nTaking 5 more damage:" << RESET << std::endl;
        tank.takeDamage(5);
        printStats("After 5 more damage", tank);

        std::cout << RED << "\nTaking 2 more damage (should have 0 HP):" << RESET << std::endl;
        tank.takeDamage(2);
        printStats("Final state", tank);
    }

    printHeader("TEST 4: Repair Functionality");
    {
        ClapTrap    medic("Medic");

        printStats("Initial state", medic);
        std::cout << RED << "\nTaking 5 damage:" << RESET << std::endl;
        medic.takeDamage(5);
        printStats("After damage", medic);

        std::cout << MAGENTA << "\nRepairing 3 points:" << RESET << std::endl;
        medic.beRepaired(3);
        printStats("After repair", medic);

        std::cout << MAGENTA << "\nRepairing 10 more points:" << RESET << std::endl;
        medic.beRepaired(10);
        printStats("Final state", medic);
    }

    printHeader("TEST 5: Cannot Attack When Dead");
    {
        ClapTrap    dead("Dead ClapTrap");

        printStats("Initial state", dead);
        std::cout << BOLD << RED << "\nTaking 10 damage (lethal):" << RESET << std::endl;
        dead.takeDamage(10);
        printStats("After lethal damage", dead);

        std::cout << RED << "\nTrying to attack while dead:" << RESET << std::endl;
        dead.attack("Anyone");
    }

    printHeader("TEST 6: Cannot Repair When Dead");
    {
        ClapTrap    dead("Dead ClapTrap");

        dead.takeDamage(10);
        std::cout << RED << "\nTrying to repair while dead:" << RESET << std::endl;
        dead.beRepaired(5);
    }

    printHeader("TEST 7: Energy Depletion");
    {
        ClapTrap    runner("Runner");

        printStats("Initial state", runner);
        std::cout << YELLOW << "\nAttacking 10 times (should use all energy):" << RESET << std::endl;
        for (int i = 0; i < 10; i++)
        {
            std::cout << "Attack " << (i + 1) << ": ";
            runner.attack("Dummy");
        }
        printStats("After 10 attacks", runner);

        std::cout << RED << "\nTrying to attack with no energy:" << RESET << std::endl;
        runner.attack("Anyone");

        std::cout << RED << "\nTrying to repair with no energy:" << RESET << std::endl;
        runner.beRepaired(5);
    }

    printHeader("TEST 8: Cannot Actions When Out of Energy");
    {
        ClapTrap    exhausted("Exhausted");

        // Use all energy
        for (int i = 0; i < 10; i++)
            exhausted.attack("Dummy");

        std::cout << RED << "\nTrying to attack with no energy:" << RESET << std::endl;
        exhausted.attack("Target");

        std::cout << RED << "\nTrying to repair with no energy:" << RESET << std::endl;
        exhausted.beRepaired(5);
    }

    printHeader("TEST 9: Combat Scenario");
    {
        ClapTrap    hero("Hero");
        ClapTrap    villain("Villain");

        printStats("Hero initial", hero);
        printStats("Villain initial", villain);

        std::cout << BLUE << "\n--- Combat Round 1 ---" << RESET << std::endl;
        hero.attack("Villain");
        villain.takeDamage(5);
        printStats("Hero after attack", hero);
        printStats("Villain after damage", villain);

        std::cout << BLUE << "\n--- Combat Round 2 ---" << RESET << std::endl;
        villain.attack("Hero");
        hero.takeDamage(3);
        printStats("Villain after attack", villain);
        printStats("Hero after damage", hero);

        std::cout << BLUE << "\n--- Combat Round 3 (Hero repairs) ---" << RESET << std::endl;
        hero.beRepaired(2);
        printStats("Hero after repair", hero);
    }

    printHeader("TEST 10: Overkill Damage");
    {
        ClapTrap    fragile("Fragile");

        printStats("Initial state", fragile);
        std::cout << BOLD << RED << "\nTaking 100 damage (massive overkill):" << RESET << std::endl;
        fragile.takeDamage(100);
        printStats("After overkill", fragile);

        std::cout << RED << "\nTrying to attack after overkill:" << RESET << std::endl;
        fragile.attack("Ghost");
    }

    printHeader("TEST 11: Multiple Repairs");
    {
        ClapTrap    healer("Healer");

        healer.takeDamage(7);
        printStats("After damage", healer);

        std::cout << MAGENTA << "\nRepairing 3 times:" << RESET << std::endl;
        healer.beRepaired(2);
        printStats("After repair 1", healer);

        healer.beRepaired(3);
        printStats("After repair 2", healer);

        healer.beRepaired(5);
        printStats("After repair 3", healer);
    }

    std::cout << BOLD << GREEN << "\n========================================" << std::endl;
    std::cout << "END OF TESTS: All tests completed successfully!" << std::endl;
    std::cout << "========================================" << RESET << std::endl;

    return (0);
}