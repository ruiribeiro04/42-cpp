/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruizenna <ruizenna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:20:00 by ruizenna          #+#    #+#             */
/*   Updated: 2025/04/11 15:20:00 by ruizenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
 * Default Constructor
 * Initializes ClapTrap with default name and values
 * Uses initialization list for efficiency (best practice in C++)
 */
ClapTrap::ClapTrap(void)
	: _name("Default ClapTrap"),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called for " << this->_name << std::endl;
}

/*
 * Parameterized Constructor
 * Creates a ClapTrap with a custom name
 * Still uses default values for hit points, energy, and damage
 */
ClapTrap::ClapTrap(std::string name)
	: _name(name),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap parameterized constructor called for " << this->_name << std::endl;
}

/*
 * Copy Constructor
 * Creates a new ClapTrap as a copy of an existing one
 * This is called when: ClapTrap copy(original);
 */
ClapTrap::ClapTrap(ClapTrap const& src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src; // Reuse the assignment operator to avoid code duplication
}

/*
 * Copy Assignment Operator
 * Copies values from another ClapTrap to this one
 * This is called when: copy = original;
 *
 * Important: We check for self-assignment (this != &rhs)
 * to prevent problems when someone does: object = object;
 */
ClapTrap&	ClapTrap::operator=(ClapTrap const& rhs)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this); // Return *this to allow chaining: a = b = c;
}

/*
 * Destructor
 * Called automatically when the object goes out of scope or is deleted
 * Always prints a message to show the destruction order
 */
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
}

/*
 * Attack Function
 * ClapTrap attacks a target, causing damage equal to _attackDamage
 * Costs 1 energy point
 *
 * Validation checks:
 * - Must have hit points > 0 (alive)
 * - Must have energy points > 0 (can perform actions)
 */
void	ClapTrap::attack(std::string const& target)
{
	// Check if ClapTrap is alive (has hit points)
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " cannot attack. It has no hit points left!" << std::endl;
		return;
	}

	// Check if ClapTrap has energy to perform the action
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " cannot attack. It has no energy points left!" << std::endl;
		return;
	}

	// Perform the attack
	this->_energyPoints--; // Consume 1 energy point
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!"
			  << std::endl;
}

/*
 * Take Damage Function
 * Reduces hit points by the specified amount
 * Hit points cannot go below 0 (we check for underflow)
 */
void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes "
			  << amount << " points of damage!" << std::endl;

	// Prevent underflow: if damage >= current HP, set to 0
	if (this->_hitPoints >= amount)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;

	// Inform if ClapTrap has been destroyed
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " has been destroyed!" << std::endl;
	}
}

/*
 * Be Repaired Function
 * Restores hit points by the specified amount
 * Costs 1 energy point
 *
 * Validation checks:
 * - Must have hit points > 0 (alive)
 * - Must have energy points > 0 (can perform actions)
 */
void	ClapTrap::beRepaired(unsigned int amount)
{
	// Check if ClapTrap is alive
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " cannot repair. It has no hit points left!" << std::endl;
		return;
	}

	// Check if ClapTrap has energy
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " cannot repair. It has no energy points left!" << std::endl;
		return;
	}

	// Perform the repair
	this->_energyPoints--; // Consume 1 energy point
	this->_hitPoints += amount; // Restore hit points
	std::cout << "ClapTrap " << this->_name << " repairs itself, gaining "
			  << amount << " hit points!" << std::endl;
}

/*
 * Getter Functions
 * Provide read-only access to private attributes
 * These are marked 'const' because they don't modify the object
 */

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}
