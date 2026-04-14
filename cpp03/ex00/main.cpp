/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruizenna <ruizenna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:20:00 by ruizenna          #+#    #+#             */
/*   Updated: 2025/04/11 15:20:00 by ruizenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/*
 * Helper function to print a section header
 * Makes the test output more readable
 */
void	printHeader(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << title << std::endl;
	std::cout << "========================================" << std::endl;
}

/*
 * Helper function to display ClapTrap stats
 * Shows current state of a ClapTrap instance
 */
void	printStats(std::string label, ClapTrap& clap)
{
	std::cout << label << ": "
			  << "Name=" << clap.getName()
			  << " HP=" << clap.getHitPoints()
			  << " EP=" << clap.getEnergyPoints()
			  << " DMG=" << clap.getAttackDamage()
			  << std::endl;
}

int	main(void)
{
	printHeader("TEST 1: Orthodox Canonical Form");
	{
		std::cout << "\n--- Creating ClapTraps using different constructors ---" << std::endl;
		ClapTrap	clap1;							// Default constructor
		ClapTrap	clap2("Named ClapTrap");		// Parameterized constructor
		ClapTrap	clap3(clap2);					// Copy constructor

		std::cout << "\n--- Using copy assignment operator ---" << std::endl;
		clap1 = clap2;							// Assignment operator

		std::cout << "\n--- ClapTraps will be destroyed when scope ends ---" << std::endl;
	}

	printHeader("TEST 2: Basic Attack Functionality");
	{
		ClapTrap	warrior("Warrior");

		printStats("Initial state", warrior);
		std::cout << "\nAttacking 3 times:" << std::endl;
		warrior.attack("Target 1");
		warrior.attack("Target 2");
		warrior.attack("Target 3");
		printStats("After 3 attacks", warrior);
	}

	printHeader("TEST 3: Taking Damage");
	{
		ClapTrap	tank("Tank");

		printStats("Initial state", tank);
		std::cout << "\nTaking 3 damage:" << std::endl;
		tank.takeDamage(3);
		printStats("After 3 damage", tank);

		std::cout << "\nTaking 5 more damage:" << std::endl;
		tank.takeDamage(5);
		printStats("After 5 more damage", tank);

		std::cout << "\nTaking 2 more damage (should have 0 HP):" << std::endl;
		tank.takeDamage(2);
		printStats("Final state", tank);
	}

	printHeader("TEST 4: Repair Functionality");
	{
		ClapTrap	medic("Medic");

		printStats("Initial state", medic);
		std::cout << "\nTaking 5 damage:" << std::endl;
		medic.takeDamage(5);
		printStats("After damage", medic);

		std::cout << "\nRepairing 3 points:" << std::endl;
		medic.beRepaired(3);
		printStats("After repair", medic);

		std::cout << "\nRepairing 10 more points:" << std::endl;
		medic.beRepaired(10);
		printStats("Final state", medic);
	}

	printHeader("TEST 5: Cannot Attack When Dead");
	{
		ClapTrap	dead("Dead ClapTrap");

		printStats("Initial state", dead);
		std::cout << "\nTaking 10 damage (lethal):" << std::endl;
		dead.takeDamage(10);
		printStats("After lethal damage", dead);

		std::cout << "\nTrying to attack while dead:" << std::endl;
		dead.attack("Anyone");
	}

	printHeader("TEST 6: Cannot Repair When Dead");
	{
		ClapTrap	dead("Dead ClapTrap");

		dead.takeDamage(10);
		std::cout << "\nTrying to repair while dead:" << std::endl;
		dead.beRepaired(5);
	}

	printHeader("TEST 7: Energy Depletion");
	{
		ClapTrap	runner("Runner");

		printStats("Initial state", runner);
		std::cout << "\nAttacking 10 times (should use all energy):" << std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << "Attack " << (i + 1) << ": ";
			runner.attack("Dummy");
		}
		printStats("After 10 attacks", runner);

		std::cout << "\nTrying to attack with no energy:" << std::endl;
		runner.attack("Anyone");

		std::cout << "\nTrying to repair with no energy:" << std::endl;
		runner.beRepaired(5);
	}

	printHeader("TEST 8: Cannot Actions When Out of Energy");
	{
		ClapTrap	exhausted("Exhausted");

		// Use all energy
		for (int i = 0; i < 10; i++)
			exhausted.attack("Dummy");

		std::cout << "\nTrying to attack with no energy:" << std::endl;
		exhausted.attack("Target");

		std::cout << "\nTrying to repair with no energy:" << std::endl;
		exhausted.beRepaired(5);
	}

	printHeader("TEST 9: Combat Scenario");
	{
		ClapTrap	hero("Hero");
		ClapTrap	villain("Villain");

		printStats("Hero initial", hero);
		printStats("Villain initial", villain);

		std::cout << "\n--- Combat Round 1 ---" << std::endl;
		hero.attack("Villain");
		villain.takeDamage(5);
		printStats("Hero after attack", hero);
		printStats("Villain after damage", villain);

		std::cout << "\n--- Combat Round 2 ---" << std::endl;
		villain.attack("Hero");
		hero.takeDamage(3);
		printStats("Villain after attack", villain);
		printStats("Hero after damage", hero);

		std::cout << "\n--- Combat Round 3 (Hero repairs) ---" << std::endl;
		hero.beRepaired(2);
		printStats("Hero after repair", hero);
	}

	printHeader("TEST 10: Overkill Damage");
	{
		ClapTrap	fragile("Fragile");

		printStats("Initial state", fragile);
		std::cout << "\nTaking 100 damage (massive overkill):" << std::endl;
		fragile.takeDamage(100);
		printStats("After overkill", fragile);

		std::cout << "\nTrying to attack after overkill:" << std::endl;
		fragile.attack("Ghost");
	}

	printHeader("TEST 11: Multiple Repairs");
	{
		ClapTrap	healer("Healer");

		healer.takeDamage(7);
		printStats("After damage", healer);

		std::cout << "\nRepairing 3 times:" << std::endl;
		healer.beRepaired(2);
		printStats("After repair 1", healer);

		healer.beRepaired(3);
		printStats("After repair 2", healer);

		healer.beRepaired(5);
		printStats("After repair 3", healer);
	}

	printHeader("END OF TESTS");
	std::cout << "\nAll tests completed successfully!" << std::endl;

	return (0);
}
