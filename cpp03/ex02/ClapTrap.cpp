/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:20:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/28 10:30:10 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("Default ClapTrap"),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	  _hitPoints(10),
	  _energyPoints(10),
	  _attackDamage(0)
{
	std::cout << "ClapTrap parameterized constructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

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
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
}

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
