/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruizenna <ruizenna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:50:00 by ruizenna          #+#    #+#             */
/*   Updated: 2025/04/11 15:50:00 by ruizenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

/*
 * DiamondTrap - The Diamond Problem Demonstration
 *
 * This class demonstrates:
 * - Multiple inheritance (inherits from BOTH FragTrap and ScavTrap)
 * - Virtual inheritance (solving the diamond problem)
 * - Name shadowing (DiamondTrap::name shadows ClapTrap::name)
 * - Complex constructor initialization
 *
 * THE DIAMOND PROBLEM:
 *
 *              ClapTrap
 *                 ^
 *        _________|_________
 *        |                 |
 *   ScavTrap          FragTrap
 *        |                 |
 *        |________    _____|
 *                 |  |
 *             DiamondTrap
 *
 * WITHOUT virtual inheritance:
 * - DiamondTrap would have TWO ClapTrap subobjects
 * - Ambiguity when accessing ClapTrap members
 * - Wasted memory
 *
 * WITH virtual inheritance (what we use):
 * - Only ONE ClapTrap subobject exists
 * - No ambiguity
 * - Efficient memory usage
 *
 * DiamondTrap characteristics:
 * - Name: from parameter
 * - ClapTrap::name: parameter + "_clap_name" suffix
 * - Hit Points: 100 (from FragTrap)
 * - Energy Points: 50 (from ScavTrap)
 * - Attack Damage: 30 (from FragTrap)
 * - attack(): uses ScavTrap's version
 */
class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		/*
		 * DiamondTrap's own name attribute
		 * This SHADOWS (hides) the _name inherited from ClapTrap
		 *
		 * So we have:
		 * - DiamondTrap::_name (DiamondTrap's own name)
		 * - ClapTrap::_name (inherited, but only ONE due to virtual inheritance)
		 *
		 * We can access both:
		 * - this->_name → DiamondTrap's name
		 * - ClapTrap::_name → ClapTrap's name
		 */
		std::string	_name;

	public:
		/*
		 * Orthodox Canonical Form
		 */

		// Default constructor
		DiamondTrap(void);

		// Parameterized constructor
		DiamondTrap(std::string name);

		// Copy constructor
		DiamondTrap(DiamondTrap const& src);

		// Copy assignment operator
		DiamondTrap&	operator=(DiamondTrap const& rhs);

		// Destructor
		~DiamondTrap(void);

		/*
		 * Member functions
		 */

		// Use ScavTrap's attack() function
		void		attack(std::string const& target);

		// Special ability unique to DiamondTrap
		// Displays both names to show the shadowing effect
		void		whoAmI(void);
};

#endif // DIAMONDTRAP_HPP
