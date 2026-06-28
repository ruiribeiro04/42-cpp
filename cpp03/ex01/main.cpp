/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:20:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/28 10:11:10 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
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
    printHeader("TEST 1: Construction and Destruction Order");
    {
        std::cout << BLUE << "\n--- Creating a ScavTrap ---" << RESET << std::endl;
        ScavTrap    scav;
        std::cout << BLUE << "\n--- ScavTrap will be destroyed when scope ends ---" << RESET << std::endl;
        std::cout << MAGENTA << "--- Watch the destruction order! ---" << RESET << std::endl;
    }

    printHeader("TEST 2: ScavTrap with Custom Name");
    {
        ScavTrap    scav("Scavy");
        printStats("Initial state", scav);
        std::cout << MAGENTA << "\n--- Testing guardGate() ---" << RESET << std::endl;
        scav.guardGate();
    }

    printHeader("TEST 3: ScavTrap Attack (Overridden Function)");
    {
        ScavTrap    scav("Hunter");
        printStats("Initial state", scav);

        std::cout << YELLOW << "\nAttacking 3 times:" << RESET << std::endl;
        scav.attack("Target 1");
        scav.attack("Target 2");
        scav.attack("Target 3");
        printStats("After 3 attacks", scav);
    }

    printHeader("TEST 4: Comparing ClapTrap vs ScavTrap");
    {
        ClapTrap    clap("Basic Clap");
        ScavTrap    scav("Super Scav");

        printStats("ClapTrap", clap);
        printStats("ScavTrap", scav);

        std::cout << BLUE << "\n--- Both attack ---" << RESET << std::endl;
        clap.attack("Enemy");
        scav.attack("Enemy");

        std::cout << BLUE << "\n--- Notice the different default values ---" << RESET << std::endl;
        std::cout << GREEN << "ClapTrap has: HP=" << clap.getHitPoints()
                  << ", EP=" << clap.getEnergyPoints()
                  << ", DMG=" << clap.getAttackDamage() << RESET << std::endl;
        std::cout << GREEN << "ScavTrap has: HP=" << scav.getHitPoints()
                  << ", EP=" << scav.getEnergyPoints()
                  << ", DMG=" << scav.getAttackDamage() << RESET << std::endl;
    }

    printHeader("TEST 5: ScavTrap Special Abilities");
    {
        ScavTrap    scav("Gatekeeper");

        std::cout << MAGENTA << "\n--- Using guardGate() multiple times ---" << RESET << std::endl;
        scav.guardGate();
        scav.guardGate();
        scav.guardGate();
    }

    printHeader("TEST 6: ScavTrap In Combat");
    {
        ScavTrap    warrior("Warrior Scav");

        printStats("Initial", warrior);
        std::cout << BLUE << "\n--- Combat sequence ---" << RESET << std::endl;

        warrior.attack("Enemy");
        std::cout << RED << "Takes 5 damage" << RESET << std::endl;
        warrior.takeDamage(5);
        printStats("After damage", warrior);

        warrior.attack("Enemy");
        warrior.guardGate();
        printStats("After combat", warrior);
    }

    printHeader("TEST 7: ScavTrap Orthodox Canonical Form");
    {
        ScavTrap    original("Original Scav");
        original.attack("Target");

        std::cout << BLUE << "\n--- Using copy constructor ---" << RESET << std::endl;
        ScavTrap    copy(original);

        std::cout << BLUE << "\n--- Using assignment operator ---" << RESET << std::endl;
        ScavTrap    assigned("Assigned Scav");
        assigned = original;

        printStats("Original", original);
        printStats("Copy", copy);
        printStats("Assigned", assigned);
    }

    printHeader("TEST 8: ScavTrap Energy Management");
    {
        ScavTrap    scav("Energetic");

        printStats("Initial", scav);
        std::cout << YELLOW << "\n--- Attacking until energy runs out (50 attacks) ---" << RESET << std::endl;

        for (int i = 0; i < 50; i++)
        {
            if (i % 10 == 0)
                std::cout << YELLOW << "Attack " << (i + 1) << RESET << std::endl;
            scav.attack("Dummy");
        }

        printStats("After 50 attacks", scav);
        std::cout << RED << "\nTrying to attack with no energy:" << RESET << std::endl;
        scav.attack("Anyone");
    }

    printHeader("TEST 9: ScavTrap Cannot Guard Gates When Dead");
    {
        ScavTrap    scav("Dead Guard");

        scav.takeDamage(100);
        std::cout << RED << "\nTrying to guard gates while dead:" << RESET << std::endl;
        scav.guardGate();
    }

    printHeader("TEST 10: ScavTrap Durability");
    {
        ScavTrap    scav("Tank");

        printStats("Initial", scav);
        std::cout << BOLD << RED << "\n--- Taking massive damage (95 damage) ---" << RESET << std::endl;
        scav.takeDamage(95);
        printStats("After damage", scav);

        std::cout << GREEN << "\n--- Can still act if alive ---" << RESET << std::endl;
        scav.attack("Enemy");
        scav.guardGate();
    }

    std::cout << BOLD << GREEN << "\n========================================" << std::endl;
    std::cout << "END OF TESTS: All tests completed successfully!" << std::endl;
    std::cout << "========================================" << RESET << std::endl;

    return (0);
}