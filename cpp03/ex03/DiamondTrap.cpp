/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruizenna <ruizenna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:50:00 by ruizenna          #+#    #+#             */
/*   Updated: 2025/04/11 15:50:00 by ruizenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
 * Default Constructor
 *
 * CRITICAL: With virtual inheritance, we must explicitly call ClapTrap constructor!
 *
 * Constructor initialization order with virtual inheritance:
 * 1. ClapTrap (virtual base class - constructed only once)
 * 2. ScavTrap
 * 3. FragTrap
 * 4. DiamondTrap
 *
 * Note: Even though ScavTrap and FragTrap normally call ClapTrap constructors,
 * with virtual inheritance, DiamondTrap is responsible for constructing
 * the virtual base class (ClapTrap) directly.
 */
DiamondTrap::DiamondTrap(void)
	: ClapTrap("Default_clap_name"),  // Explicitly construct virtual base
	  ScavTrap(),                      // ScavTrap won't call ClapTrap due to virtual
	  FragTrap(),                      // FragTrap won't call ClapTrap due to virtual
	  _name("Default")                 // DiamondTrap's own name
{
	// Set attributes according to the subject:
	// - Hit Points: 100 (from FragTrap)
	// - Energy Points: 50 (from ScavTrap)
	// - Attack Damage: 30 (from FragTrap)
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;

	std::cout << "DiamondTrap default constructor called for " << this->_name << std::endl;
}

/*
 * Parameterized Constructor
 *
 * Same pattern as default constructor, but with custom name
 *
 * Important details:
 * - ClapTrap::name = name + "_clap_name" (per subject requirements)
 * - DiamondTrap::_name = name (DiamondTrap's own name)
 */
DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"),  // ClapTrap gets name with suffix
	  ScavTrap(name),                   // Pass name to ScavTrap (won't call ClapTrap)
	  FragTrap(name),                   // Pass name to FragTrap (won't call ClapTrap)
	  _name(name)                       // DiamondTrap's own name
{
	// Set the correct attribute values
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;

	std::cout << "DiamondTrap parameterized constructor called for " << this->_name << std::endl;
}

/*
 * Copy Constructor
 *
 * With virtual inheritance, we must explicitly construct all virtual base classes
 * and then copy the values from the source object.
 */
DiamondTrap::DiamondTrap(DiamondTrap const& src)
	: ClapTrap(src),    // Construct virtual base
	  ScavTrap(src),    // Construct ScavTrap part
	  FragTrap(src),    // Construct FragTrap part
	  _name(src._name)  // Copy DiamondTrap's name
{
	// Copy the attributes (they're already set by the constructors above,
	// but we ensure they match the source)
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;

	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

/*
 * Copy Assignment Operator
 *
 * With virtual inheritance, we need to be careful about which base class
 * assignment operator we call.
 */
DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& rhs)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		// Call ScavTrap's assignment operator (which will call ClapTrap's)
		// We don't need to call FragTrap's separately because both use the same
		// ClapTrap base due to virtual inheritance
		ScavTrap::operator=(rhs);

		// Copy DiamondTrap's own name
		this->_name = rhs._name;

		// Copy attributes explicitly
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

/*
 * Destructor
 *
 * Destruction order with virtual inheritance:
 * 1. DiamondTrap destructor
 * 2. FragTrap destructor
 * 3. ScavTrap destructor
 * 4. ClapTrap destructor (only ONCE, thanks to virtual inheritance)
 */
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called for " << this->_name << std::endl;
}

/*
 * Attack Function
 *
 * Uses ScavTrap's attack() function as specified in the subject.
 * This demonstrates that DiamondTrap can use functions from both parent classes.
 */
void	DiamondTrap::attack(std::string const& target)
{
	// Explicitly call ScavTrap's version of attack
	ScavTrap::attack(target);
}

/*
 * Who Am I Function
 *
 * Special ability that demonstrates name shadowing.
 * Shows both:
 * - DiamondTrap's own name (_name)
 * - ClapTrap's name (ClapTrap::_name)
 *
 * This is the KEY demonstration of the diamond problem solution!
 */
void	DiamondTrap::whoAmI(void)
{
	std::cout << "\n*** Who Am I? ***" << std::endl;
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
	std::cout << "*******************" << std::endl;
}
