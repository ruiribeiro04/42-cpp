/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruizenna <ruizenna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:30:00 by ruizenna          #+#    #+#             */
/*   Updated: 2025/04/11 15:30:00 by ruizenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
 * Default Constructor
 * Creates a ScavTrap with default name
 * Calls ClapTrap constructor first (constructor chaining)
 * Then overrides the default values with ScavTrap-specific values
 *
 * Construction order: ClapTrap constructor → ScavTrap constructor body
 */
ScavTrap::ScavTrap(void) : ClapTrap("Default ScavTrap")
{
	// Set ScavTrap-specific attribute values
	// These are different from ClapTrap's defaults
	this->_hitPoints = 100;		// ScavTrap has more health than ClapTrap (10)
	this->_energyPoints = 50;	// ScavTrap has less energy than ClapTrap (10)
	this->_attackDamage = 20;	// ScavTrap deals more damage than ClapTrap (0)

	std::cout << "ScavTrap default constructor called for " << this->getName() << std::endl;
}

/*
 * Parameterized Constructor
 * Creates a ScavTrap with a custom name
 * Also calls ClapTrap constructor first with the name
 */
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	// Set ScavTrap-specific attribute values
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << "ScavTrap parameterized constructor called for " << this->getName() << std::endl;
}

/*
 * Copy Constructor
 * Creates a new ScavTrap as a copy of an existing one
 * Calls ClapTrap copy constructor first
 */
ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src; // Reuse assignment operator
}

/*
 * Copy Assignment Operator
 * Copies values from another ScavTrap
 * Calls ClapTrap's assignment operator to copy base class members
 */
ScavTrap&	ScavTrap::operator=(ScavTrap const& rhs)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		// Call base class assignment operator to copy ClapTrap members
		ClapTrap::operator=(rhs);
	}
	return (*this);
}

/*
 * Destructor
 * Called when ScavTrap is destroyed
 * Destruction order: ScavTrap destructor → ClapTrap destructor (automatic)
 *
 * Note: We don't need to explicitly call ClapTrap's destructor.
 * C++ automatically calls base class destructors after derived class destructors.
 */
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called for " << this->getName() << std::endl;
}

/*
 * Attack Function (Overridden)
 * This overrides ClapTrap::attack() to display "ScavTrap" instead of "ClapTrap"
 * The logic is the same, but the messages are different to show individuality
 *
 * Now we can directly access the protected members from ClapTrap
 */
void	ScavTrap::attack(std::string const& target)
{
	// Check if ScavTrap is alive
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name
				  << " cannot attack. It has no hit points left!" << std::endl;
		return;
	}

	// Check if ScavTrap has energy
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name
				  << " cannot attack. It has no energy points left!" << std::endl;
		return;
	}

	// Perform the attack
	this->_energyPoints--; // Consume 1 energy point
	std::cout << "ScavTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

/*
 * Guard Gate Function
 * Special ability unique to ScavTrap
 * Displays a message about entering Gate keeper mode
 */
void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name
				  << " cannot guard gates. It has no hit points left!" << std::endl;
		return;
	}

	std::cout << "ScavTrap " << this->_name
			  << " is now in Gate keeper mode!" << std::endl;
}
