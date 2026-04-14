/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruizenna <ruizenna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:40:00 by ruizenna          #+#    #+#             */
/*   Updated: 2025/04/11 15:40:00 by ruizenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

void	printHeader(std::string title)
{
	std::cout << "\n========================================" << std::endl;
	std::cout << title << std::endl;
	std::cout << "========================================" << std::endl;
}

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
	printHeader("TEST 1: Construction and Destruction Order");
	{
		std::cout << "\n--- Creating a FragTrap ---" << std::endl;
		FragTrap	frag;
		std::cout << "\n--- FragTrap will be destroyed when scope ends ---" << std::endl;
		std::cout << "--- Watch the destruction order! ---" << std::endl;
	}

	printHeader("TEST 2: FragTrap with Custom Name");
	{
		FragTrap	frag("Fraggy");
		printStats("Initial state", frag);
		std::cout << "\n--- Testing highFivesGuys() ---" << std::endl;
		frag.highFivesGuys();
	}

	printHeader("TEST 3: Comparing All Three Classes");
	{
		ClapTrap	clap("Basic Clap");
		FragTrap	frag("Fraggy");

		printStats("ClapTrap", clap);
		printStats("FragTrap", frag);

		std::cout << "\n--- Notice the different default values ---" << std::endl;
		std::cout << "ClapTrap: HP=" << clap.getHitPoints()
				  << ", EP=" << clap.getEnergyPoints()
				  << ", DMG=" << clap.getAttackDamage() << std::endl;
		std::cout << "FragTrap: HP=" << frag.getHitPoints()
				  << ", EP=" << frag.getEnergyPoints()
				  << ", DMG=" << frag.getAttackDamage() << std::endl;
	}

	printHeader("TEST 4: FragTrap Special Ability");
	{
		FragTrap	frag("Friendly Frag");

		std::cout << "\n--- Requesting high fives multiple times ---" << std::endl;
		frag.highFivesGuys();
		frag.highFivesGuys();
		frag.highFivesGuys();
	}

	printHeader("TEST 5: FragTrap in Combat");
	{
		FragTrap	warrior("Warrior Frag");

		printStats("Initial", warrior);
		std::cout << "\n--- Combat sequence ---" << std::endl;

		warrior.attack("Enemy");
		std::cout << "Takes 10 damage" << std::endl;
		warrior.takeDamage(10);
		printStats("After damage", warrior);

		warrior.attack("Enemy");
		warrior.highFivesGuys();
		printStats("After combat", warrior);
	}

	printHeader("TEST 6: FragTrap Orthodox Canonical Form");
	{
		FragTrap	original("Original Frag");
		original.attack("Target");

		std::cout << "\n--- Using copy constructor ---" << std::endl;
		FragTrap	copy(original);

		std::cout << "\n--- Using assignment operator ---" << std::endl;
		FragTrap	assigned("Assigned Frag");
		assigned = original;

		printStats("Original", original);
		printStats("Copy", copy);
		printStats("Assigned", assigned);
	}

	printHeader("TEST 7: FragTrap Energy Management");
	{
		FragTrap	frag("Energetic Frag");

		printStats("Initial", frag);
		std::cout << "\n--- Attacking until energy runs out (100 attacks) ---" << std::endl;

		for (int i = 0; i < 100; i++)
		{
			if (i % 20 == 0)
				std::cout << "Attack " << (i + 1) << std::endl;
			frag.attack("Dummy");
		}

		printStats("After 100 attacks", frag);
		std::cout << "\nTrying to attack with no energy:" << std::endl;
		frag.attack("Anyone");
	}

	printHeader("TEST 8: FragTank - High Durability");
	{
		FragTrap	frag("Tank");

		printStats("Initial", frag);
		std::cout << "\n--- Taking lots of damage (90 damage) ---" << std::endl;
		frag.takeDamage(90);
		printStats("After damage", frag);

		std::cout << "\n--- Still alive and kicking ---" << std::endl;
		frag.attack("Enemy");
		frag.highFivesGuys();
		printStats("After actions", frag);
	}

	printHeader("TEST 9: FragTrap Cannot High Five When Dead");
	{
		FragTrap	frag("Dead Frag");

		frag.takeDamage(100);
		std::cout << "\nTrying to request high five while dead:" << std::endl;
		frag.highFivesGuys();
	}

	printHeader("TEST 10: FragTrap High Energy Pool");
	{
		FragTrap	frag("Marathon Runner");

		printStats("Initial", frag);
		std::cout << "\n--- FragTrap has 100 energy points (10x ClapTrap!) ---" << std::endl;
		std::cout << "--- Can perform many more actions than other classes ---" << std::endl;

		// Use 50 energy
		for (int i = 0; i < 50; i++)
			frag.attack("Dummy");

		printStats("After 50 attacks", frag);
		std::cout << "\n--- Still has 50 energy left! ---" << std::endl;

		// Use 40 more energy
		for (int i = 0; i < 40; i++)
			frag.attack("Dummy");

		printStats("After 90 total attacks", frag);
		std::cout << "\n--- Still has 10 energy! ---" << std::endl;
	}

	printHeader("TEST 11: FragTrap High Damage Output");
	{
		FragTrap	frag("Heavy Hitter");

		printStats("Initial", frag);
		std::cout << "\n--- FragTrap deals 30 damage per attack (highest so far) ---" << std::endl;

		frag.attack("Boss");
		frag.attack("Boss");
		frag.attack("Boss");

		std::cout << "\n--- 3 attacks = 90 total damage! ---" << std::endl;
		printStats("After 3 attacks", frag);
	}

	printHeader("END OF TESTS");
	std::cout << "\nAll tests completed successfully!" << std::endl;

	return (0);
}
