/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:20:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/28 10:37:46 by ruiferna         ###   ########.fr       */
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

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap parameterized constructor called for " << this->_name << std::endl;
}

FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap&	FragTrap::operator=(FragTrap const& rhs)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called for " << this->_name << std::endl;
}

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
