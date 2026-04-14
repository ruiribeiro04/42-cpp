/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruizenna <ruizenna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:40:00 by ruizenna          #+#    #+#             */
/*   Updated: 2025/04/11 15:40:00 by ruizenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
 * Default Constructor
 * Creates a FragTrap with default name
 * Calls ClapTrap constructor first, then sets FragTrap-specific values
 *
 * FragTrap default values:
 * - Hit Points: 100 (more than ClapTrap's 10)
 * - Energy Points: 100 (much more than ClapTrap's 10)
 * - Attack Damage: 30 (more than both ClapTrap and ScavTrap)
 */
FragTrap::FragTrap(void) : ClapTrap("Default FragTrap")
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap default constructor called for " << this->_name << std::endl;
}

/*
 * Parameterized Constructor
 * Creates a FragTrap with a custom name
 */
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap parameterized constructor called for " << this->_name << std::endl;
}

/*
 * Copy Constructor
 * Creates a new FragTrap as a copy of an existing one
 */
FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

/*
 * Copy Assignment Operator
 * Copies values from another FragTrap
 */
FragTrap&	FragTrap::operator=(FragTrap const& rhs)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return (*this);
}

/*
 * Destructor
 * Called when FragTrap is destroyed
 * Destruction order: FragTrap destructor → ClapTrap destructor
 */
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called for " << this->_name << std::endl;
}

/*
 * High Fives Guys Function
 * Special ability unique to FragTrap
 * Displays a positive high-fives request
 *
 * This function demonstrates that each derived class can have
 * its own unique special abilities that don't exist in the base class
 */
void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "FragTrap " << this->_name
				  << " cannot request high fives. It has no hit points left!" << std::endl;
		return;
	}

	std::cout << "FragTrap " << this->_name
			  << " requests a positive high-five! ✋" << std::endl;
}
