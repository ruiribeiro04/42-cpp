/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruizenna <ruizenna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:20:00 by ruizenna          #+#    #+#             */
/*   Updated: 2025/04/11 15:20:00 by ruizenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

/*
 * ClapTrap - A basic robot class that demonstrates Orthodox Canonical Form
 *
 * This class serves as the base for all robot types in this module.
 * It demonstrates:
 * - Orthodox Canonical Form (4 special member functions)
 * - Basic member functions with validation
 * - Protected attributes for inheritance (derived classes can access them)
 */
class ClapTrap
{
	protected:
		// Protected attributes - accessible by derived classes
		// This allows ScavTrap, FragTrap, etc. to modify these values
		std::string		_name;			// Name of the ClapTrap
		unsigned int	_hitPoints;		// Health points (default: 10)
		unsigned int	_energyPoints;	// Energy for actions (default: 10)
		unsigned int	_attackDamage;	// Damage dealt by attacks (default: 0)

	public:
		/*
		 * Orthodox Canonical Form - 4 special member functions
		 * These are required for all classes from Module 02 onwards
		 */

		// 1. Default constructor - creates ClapTrap with default values
		ClapTrap(void);

		// 2. Parameterized constructor - creates ClapTrap with a custom name
		ClapTrap(std::string name);

		// 3. Copy constructor - creates a new ClapTrap as a copy of another
		ClapTrap(ClapTrap const& src);

		// 4. Copy assignment operator - copies values from another ClapTrap
		ClapTrap&	operator=(ClapTrap const& rhs);

		// Destructor - called when object is destroyed
		~ClapTrap(void);

		/*
		 * Action member functions
		 * These demonstrate the robot's behavior
		 */

		// Attack a target, consuming 1 energy point
		void		attack(std::string const& target);

		// Take damage, reducing hit points
		void		takeDamage(unsigned int amount);

		// Repair yourself, consuming 1 energy point to gain hit points
		void		beRepaired(unsigned int amount);

		/*
		 * Getter functions
		 * Allow read-only access to private attributes
		 */
		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
};

#endif // CLAPTRAP_HPP
