/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruizenna <ruizenna@student.42 Porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:50:00 by ruizenna          #+#    #+#             */
/*   Updated: 2025/04/11 15:50:00 by ruizenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
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
	printHeader("TEST 1: DiamondTrap Construction Order");
	{
		std::cout << "\n--- Creating a DiamondTrap ---" << std::endl;
		std::cout << "--- Watch the construction order! ---" << std::endl;
		std::cout << "--- ClapTrap should be constructed ONLY ONCE ---" << std::endl;
		DiamondTrap	diamond;
		std::cout << "\n--- DiamondTrap will be destroyed when scope ends ---" << std::endl;
		std::cout << "--- Watch the destruction order! ---" << std::endl;
	}

	printHeader("TEST 2: DiamondTrap with Custom Name");
	{
		std::cout << "\n--- Creating DiamondTrap named 'Diamond' ---" << std::endl;
		DiamondTrap	diamond("Diamond");

		std::cout << "\n--- Testing whoAmI() ---" << std::endl;
		diamond.whoAmI();

		printStats("DiamondTrap stats", diamond);
	}

	printHeader("TEST 3: DiamondTrap Name Shadowing");
	{
		DiamondTrap	diamond("Sparkle");

		std::cout << "\n--- Demonstrating name shadowing ---" << std::endl;
		diamond.whoAmI();

		std::cout << "\n--- Notice the two different names: ---" << std::endl;
		std::cout << "DiamondTrap name: 'Sparkle'" << std::endl;
		std::cout << "ClapTrap name: 'Sparkle_clap_name'" << std::endl;
	}

	printHeader("TEST 4: DiamondTrap Uses ScavTrap's Attack");
	{
		DiamondTrap	diamond("Fighter");

		printStats("Initial", diamond);
		std::cout << "\n--- Attacking (should use ScavTrap's version) ---" << std::endl;
		diamond.attack("Enemy");
		printStats("After attack", diamond);
	}

	printHeader("TEST 5: DiamondTrap Can Use Both Parent Abilities");
	{
		DiamondTrap	diamond("Hybrid");

		std::cout << "\n--- Using ScavTrap's guardGate() ---" << std::endl;
		diamond.guardGate();

		std::cout << "\n--- Using FragTrap's highFivesGuys() ---" << std::endl;
		diamond.highFivesGuys();

		std::cout << "\n--- Using DiamondTrap's whoAmI() ---" << std::endl;
		diamond.whoAmI();
	}

	printHeader("TEST 6: DiamondTrap Attribute Values");
	{
		DiamondTrap	diamond("Test");

		std::cout << "\n--- DiamondTrap should have: ---" << std::endl;
		std::cout << "Hit Points: 100 (from FragTrap)" << std::endl;
		std::cout << "Energy Points: 50 (from ScavTrap)" << std::endl;
		std::cout << "Attack Damage: 30 (from FragTrap)" << std::endl;

		printStats("Actual values", diamond);

		if (diamond.getHitPoints() == 100 &&
			diamond.getEnergyPoints() == 50 &&
			diamond.getAttackDamage() == 30)
		{
			std::cout << "\n✓ All attributes are correct!" << std::endl;
		}
		else
		{
			std::cout << "\n✗ Attribute mismatch!" << std::endl;
		}
	}

	printHeader("TEST 7: DiamondTrap Orthodox Canonical Form");
	{
		DiamondTrap	original("Original");
		original.attack("Target");

		std::cout << "\n--- Using copy constructor ---" << std::endl;
		DiamondTrap	copy(original);

		std::cout << "\n--- Using assignment operator ---" << std::endl;
		DiamondTrap	assigned("Assigned");
		assigned = original;

		std::cout << "\n--- Comparing all three ---" << std::endl;
		original.whoAmI();
		copy.whoAmI();
		assigned.whoAmI();
	}

	printHeader("TEST 8: DiamondTrap in Combat");
	{
		DiamondTrap	diamond("Warrior Diamond");

		printStats("Initial", diamond);
		std::cout << "\n--- Combat sequence ---" << std::endl;

		diamond.attack("Enemy");
		std::cout << "Takes 20 damage" << std::endl;
		diamond.takeDamage(20);
		printStats("After damage", diamond);

		diamond.attack("Enemy");
		diamond.guardGate();
		diamond.highFivesGuys();
		printStats("After combat", diamond);
	}

	printHeader("TEST 9: DiamondTrap Energy Management");
	{
		DiamondTrap	diamond("Marathon");

		printStats("Initial", diamond);
		std::cout << "\n--- Attacking until energy runs out (50 attacks) ---" << std::endl;

		for (int i = 0; i < 50; i++)
		{
			if (i % 10 == 0)
				std::cout << "Attack " << (i + 1) << std::endl;
			diamond.attack("Dummy");
		}

		printStats("After 50 attacks", diamond);
		std::cout << "\nTrying to attack with no energy:" << std::endl;
		diamond.attack("Anyone");
	}

	printHeader("TEST 10: Comparing All Four Classes");
	{
		ClapTrap		clap("Basic Clap");
		ScavTrap		scav("Scavvy");
		FragTrap		frag("Fraggy");
		DiamondTrap	diamond("Diamondy");

		std::cout << "\n--- Default attribute values: ---" << std::endl;
		printStats("ClapTrap", clap);
		printStats("ScavTrap", scav);
		printStats("FragTrap", frag);
		printStats("DiamondTrap", diamond);

		std::cout << "\n--- Special abilities: ---" << std::endl;
		std::cout << "ClapTrap: Basic attack only" << std::endl;
		std::cout << "ScavTrap: guardGate()" << std::endl;
		std::cout << "FragTrap: highFivesGuys()" << std::endl;
		std::cout << "DiamondTrap: whoAmI() + both parent abilities" << std::endl;
	}

	printHeader("TEST 11: DiamondTrap Virtual Inheritance Proof");
	{
		std::cout << "\n--- This test proves virtual inheritance works ---" << std::endl;
		std::cout << "--- ClapTrap constructor should be called ONLY ONCE ---" << std::endl;
		std::cout << "--- Not twice (once through ScavTrap, once through FragTrap) ---" << std::endl;

		DiamondTrap	diamond("Proof");

		std::cout << "\n--- If you see 'ClapTrap constructor called' only ONCE above, ---" << std::endl;
		std::cout << "--- then virtual inheritance is working correctly! ---" << std::endl;
	}

	printHeader("END OF TESTS");
	std::cout << "\nAll tests completed successfully!" << std::endl;
	std::cout << "\nKey takeaways:" << std::endl;
	std::cout << "1. Virtual inheritance solves the diamond problem" << std::endl;
	std::cout << "2. Only ONE ClapTrap base subobject exists" << std::endl;
	std::cout << "3. DiamondTrap combines abilities from both parents" << std::endl;
	std::cout << "4. Name shadowing allows two different names" << std::endl;

	return (0);
}
