/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruizenna <ruizenna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:30:00 by ruizenna          #+#    #+#             */
/*   Updated: 2025/04/11 15:30:00 by ruizenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
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
		std::cout << "\n--- Creating a ScavTrap ---" << std::endl;
		ScavTrap	scav;
		std::cout << "\n--- ScavTrap will be destroyed when scope ends ---" << std::endl;
		std::cout << "--- Watch the destruction order! ---" << std::endl;
	}

	printHeader("TEST 2: ScavTrap with Custom Name");
	{
		ScavTrap	scav("Scavy");
		printStats("Initial state", scav);
		std::cout << "\n--- Testing guardGate() ---" << std::endl;
		scav.guardGate();
	}

	printHeader("TEST 3: ScavTrap Attack (Overridden Function)");
	{
		ScavTrap	scav("Hunter");
		printStats("Initial state", scav);

		std::cout << "\nAttacking 3 times:" << std::endl;
		scav.attack("Target 1");
		scav.attack("Target 2");
		scav.attack("Target 3");
		printStats("After 3 attacks", scav);
	}

	printHeader("TEST 4: Comparing ClapTrap vs ScavTrap");
	{
		ClapTrap	clap("Basic Clap");
		ScavTrap	scav("Super Scav");

		printStats("ClapTrap", clap);
		printStats("ScavTrap", scav);

		std::cout << "\n--- Both attack ---" << std::endl;
		clap.attack("Enemy");
		scav.attack("Enemy");

		std::cout << "\n--- Notice the different default values ---" << std::endl;
		std::cout << "ClapTrap has: HP=" << clap.getHitPoints()
				  << ", EP=" << clap.getEnergyPoints()
				  << ", DMG=" << clap.getAttackDamage() << std::endl;
		std::cout << "ScavTrap has: HP=" << scav.getHitPoints()
				  << ", EP=" << scav.getEnergyPoints()
				  << ", DMG=" << scav.getAttackDamage() << std::endl;
	}

	printHeader("TEST 5: ScavTrap Special Abilities");
	{
		ScavTrap	scav("Gatekeeper");

		std::cout << "\n--- Using guardGate() multiple times ---" << std::endl;
		scav.guardGate();
		scav.guardGate();
		scav.guardGate();
	}

	printHeader("TEST 6: ScavTrap In Combat");
	{
		ScavTrap	warrior("Warrior Scav");

		printStats("Initial", warrior);
		std::cout << "\n--- Combat sequence ---" << std::endl;

		warrior.attack("Enemy");
		std::cout << "Takes 5 damage" << std::endl;
		warrior.takeDamage(5);
		printStats("After damage", warrior);

		warrior.attack("Enemy");
		warrior.guardGate();
		printStats("After combat", warrior);
	}

	printHeader("TEST 7: ScavTrap Orthodox Canonical Form");
	{
		ScavTrap	original("Original Scav");
		original.attack("Target");

		std::cout << "\n--- Using copy constructor ---" << std::endl;
		ScavTrap	copy(original);

		std::cout << "\n--- Using assignment operator ---" << std::endl;
		ScavTrap	assigned("Assigned Scav");
		assigned = original;

		printStats("Original", original);
		printStats("Copy", copy);
		printStats("Assigned", assigned);
	}

	printHeader("TEST 8: ScavTrap Energy Management");
	{
		ScavTrap	scav("Energetic");

		printStats("Initial", scav);
		std::cout << "\n--- Attacking until energy runs out (50 attacks) ---" << std::endl;

		for (int i = 0; i < 50; i++)
		{
			if (i % 10 == 0)
				std::cout << "Attack " << (i + 1) << std::endl;
			scav.attack("Dummy");
		}

		printStats("After 50 attacks", scav);
		std::cout << "\nTrying to attack with no energy:" << std::endl;
		scav.attack("Anyone");
	}

	printHeader("TEST 9: ScavTrap Cannot Guard Gates When Dead");
	{
		ScavTrap	scav("Dead Guard");

		scav.takeDamage(100);
		std::cout << "\nTrying to guard gates while dead:" << std::endl;
		scav.guardGate();
	}

	printHeader("TEST 10: ScavTrap Durability");
	{
		ScavTrap	scav("Tank");

		printStats("Initial", scav);
		std::cout << "\n--- Taking massive damage (95 damage) ---" << std::endl;
		scav.takeDamage(95);
		printStats("After damage", scav);

		std::cout << "\n--- Can still act if alive ---" << std::endl;
		scav.attack("Enemy");
		scav.guardGate();
	}

	printHeader("END OF TESTS");
	std::cout << "\nAll tests completed successfully!" << std::endl;

	return (0);
}
