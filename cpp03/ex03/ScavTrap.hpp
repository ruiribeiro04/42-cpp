/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruizenna <ruizenna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:30:00 by ruizenna          #+#    #+#             */
/*   Updated: 2025/04/11 15:30:00 by ruizenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

/*
 * ScavTrap - A derived class that inherits from ClapTrap
 *
 * This class demonstrates:
 * - VIRTUAL public inheritance (crucial for DiamondTrap!)
 * - Constructor/destructor chaining
 * - Overriding inherited methods
 * - Adding new specialized abilities
 *
 * Inheritance relationship:
 *        ClapTrap (base class)
 *           ^
 *           |
 *    virtual public
 *           |
 *        ScavTrap (derived class)
 *
 * VIRTUAL INHERITANCE:
 * This ensures that when DiamondTrap inherits from both ScavTrap and FragTrap,
 * there will be only ONE ClapTrap base subobject, not two.
 * This solves the "diamond problem" in multiple inheritance.
 */
class ScavTrap : virtual public ClapTrap
{
	public:
		/*
		 * Orthodox Canonical Form
		 * Same 4 special member functions as ClapTrap
		 */

		// Default constructor - creates ScavTrap with default values
		ScavTrap(void);

		// Parameterized constructor - creates ScavTrap with custom name
		ScavTrap(std::string name);

		// Copy constructor - creates a new ScavTrap as a copy
		ScavTrap(ScavTrap const& src);

		// Copy assignment operator - copies from another ScavTrap
		ScavTrap&	operator=(ScavTrap const& rhs);

		// Destructor - called when ScavTrap is destroyed
		virtual ~ScavTrap(void);

		/*
		 * Overridden member function
		 * This overrides the attack() function from ClapTrap
		 * to display "ScavTrap" instead of "ClapTrap" in messages
		 */
		virtual void	attack(std::string const& target);

		/*
		 * Special ability unique to ScavTrap
		 * Not available in the base ClapTrap class
		 */
		void		guardGate(void);
};

#endif // SCAVTRAP_HPP
