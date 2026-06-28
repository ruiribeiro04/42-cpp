/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:20:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/28 10:32:55 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
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
        std::cout << BLUE << "\n--- Creating a FragTrap ---" << RESET << std::endl;
        FragTrap    frag;
        std::cout << BLUE << "\n--- FragTrap will be destroyed when scope ends ---" << RESET << std::endl;
        std::cout << MAGENTA << "--- Watch the destruction order! ---" << RESET << std::endl;
    }

    printHeader("TEST 2: FragTrap with Custom Name");
    {
        FragTrap    frag("Fraggy");
        printStats("Initial state", frag);
        std::cout << MAGENTA << "\n--- Testing highFivesGuys() ---" << RESET << std::endl;
        frag.highFivesGuys();
    }

    printHeader("TEST 3: Comparing All Three Classes");
    {
        ClapTrap    clap("Basic Clap");
        FragTrap    frag("Fraggy");

        printStats("ClapTrap", clap);
        printStats("FragTrap", frag);

        std::cout << BLUE << "\n--- Notice the different default values ---" << RESET << std::endl;
        std::cout << GREEN << "ClapTrap: HP=" << clap.getHitPoints()
                  << ", EP=" << clap.getEnergyPoints()
                  << ", DMG=" << clap.getAttackDamage() << RESET << std::endl;
        std::cout << GREEN << "FragTrap: HP=" << frag.getHitPoints()
                  << ", EP=" << frag.getEnergyPoints()
                  << ", DMG=" << frag.getAttackDamage() << RESET << std::endl;
    }

    printHeader("TEST 4: FragTrap Special Ability");
    {
        FragTrap    frag("Friendly Frag");

        std::cout << MAGENTA << "\n--- Requesting high fives multiple times ---" << RESET << std::endl;
        frag.highFivesGuys();
        frag.highFivesGuys();
        frag.highFivesGuys();
    }

    printHeader("TEST 5: FragTrap in Combat");
    {
        FragTrap    warrior("Warrior Frag");

        printStats("Initial", warrior);
        std::cout << BLUE << "\n--- Combat sequence ---" << RESET << std::endl;

        warrior.attack("Enemy");
        std::cout << RED << "Takes 10 damage" << RESET << std::endl;
        warrior.takeDamage(10);
        printStats("After damage", warrior);

        warrior.attack("Enemy");
        warrior.highFivesGuys();
        printStats("After combat", warrior);
    }

    printHeader("TEST 6: FragTrap Orthodox Canonical Form");
    {
        FragTrap    original("Original Frag");
        original.attack("Target");

        std::cout << BLUE << "\n--- Using copy constructor ---" << RESET << std::endl;
        FragTrap    copy(original);

        std::cout << BLUE << "\n--- Using assignment operator ---" << RESET << std::endl;
        FragTrap    assigned("Assigned Frag");
        assigned = original;

        printStats("Original", original);
        printStats("Copy", copy);
        printStats("Assigned", assigned);
    }

    printHeader("TEST 7: FragTrap Energy Management");
    {
        FragTrap    frag("Energetic Frag");

        printStats("Initial", frag);
        std::cout << YELLOW << "\n--- Attacking until energy runs out (100 attacks) ---" << RESET << std::endl;

        for (int i = 0; i < 100; i++)
        {
            if (i % 20 == 0)
                std::cout << YELLOW << "Attack " << (i + 1) << RESET << std::endl;
            frag.attack("Dummy");
        }

        printStats("After 100 attacks", frag);
        std::cout << RED << "\nTrying to attack with no energy:" << RESET << std::endl;
        frag.attack("Anyone");
    }

    printHeader("TEST 8: FragTank - High Durability");
    {
        FragTrap    frag("Tank");

        printStats("Initial", frag);
        std::cout << BOLD << RED << "\n--- Taking lots of damage (90 damage) ---" << RESET << std::endl;
        frag.takeDamage(90);
        printStats("After damage", frag);

        std::cout << GREEN << "\n--- Still alive and kicking ---" << RESET << std::endl;
        frag.attack("Enemy");
        frag.highFivesGuys();
        printStats("After actions", frag);
    }

    printHeader("TEST 9: FragTrap Cannot High Five When Dead");
    {
        FragTrap    frag("Dead Frag");

        frag.takeDamage(100);
        std::cout << RED << "\nTrying to request high five while dead:" << RESET << std::endl;
        frag.highFivesGuys();
    }

    printHeader("TEST 10: FragTrap High Energy Pool");
    {
        FragTrap    frag("Marathon Runner");

        printStats("Initial", frag);
        std::cout << BLUE << "\n--- FragTrap has 100 energy points (10x ClapTrap!) ---" << RESET << std::endl;
        std::cout << BLUE << "--- Can perform many more actions than other classes ---" << RESET << std::endl;

        // Use 50 energy
        for (int i = 0; i < 50; i++)
            frag.attack("Dummy");

        printStats("After 50 attacks", frag);
        std::cout << GREEN << "\n--- Still has 50 energy left! ---" << RESET << std::endl;

        // Use 40 more energy
        for (int i = 0; i < 40; i++)
            frag.attack("Dummy");

        printStats("After 90 total attacks", frag);
        std::cout << GREEN << "\n--- Still has 10 energy! ---" << RESET << std::endl;
    }

    printHeader("TEST 11: FragTrap High Damage Output");
    {
        FragTrap    frag("Heavy Hitter");

        printStats("Initial", frag);
        std::cout << BLUE << "\n--- FragTrap deals 30 damage per attack (highest so far) ---" << RESET << std::endl;

        frag.attack("Boss");
        frag.attack("Boss");
        frag.attack("Boss");

        std::cout << MAGENTA << "\n--- 3 attacks = 90 total damage! ---" << RESET << std::endl;
        printStats("After 3 attacks", frag);
    }

    std::cout << BOLD << GREEN << "\n========================================" << std::endl;
    std::cout << "END OF TESTS: All tests completed successfully!" << std::endl;
    std::cout << "========================================" << RESET << std::endl;

    return (0);
}