/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruizenna <ruizenna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:40:00 by ruizenna          #+#    #+#             */
/*   Updated: 2025/04/11 15:40:00 by ruizenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

/*
 * FragTrap - Another derived class that inherits from ClapTrap
 *
 * This class demonstrates:
 * - VIRTUAL public inheritance (crucial for DiamondTrap!)
 * - Different default attribute values
 * - A different special ability (highFivesGuys)
 *
 * Inheritance relationship:
 *        ClapTrap (base class)
 *           ^
 *           |
 *    virtual public
 *           |
 *        FragTrap (derived class)
 *
 * VIRTUAL INHERITANCE:
 * This ensures that when DiamondTrap inherits from both ScavTrap and FragTrap,
 * there will be only ONE ClapTrap base subobject, not two.
 * This solves the "diamond problem" in multiple inheritance.
 */
class FragTrap : virtual public ClapTrap
{
	public:
		/*
		 * Orthodox Canonical Form
		 * Same 4 special member functions
		 */

		// Default constructor
		FragTrap(void);

		// Parameterized constructor
		FragTrap(std::string name);

		// Copy constructor
		FragTrap(FragTrap const& src);

		// Copy assignment operator
		FragTrap&	operator=(FragTrap const& rhs);

		// Destructor
		virtual ~FragTrap(void);

		/*
		 * Special ability unique to FragTrap
		 * Requests a positive high-five from other robots
		 */
		virtual void	highFivesGuys(void);
};

#endif // FRAGTRAP_HPP
