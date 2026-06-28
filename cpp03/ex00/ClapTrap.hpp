/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:20:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/28 10:04:47 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		// Protected attributes - accessible by derived classes
		std::string		_name;			// Name of the ClapTrap
		unsigned int	_hitPoints;		// Health points (default: 10)
		unsigned int	_energyPoints;	// Energy for actions (default: 10)
		unsigned int	_attackDamage;	// Damage dealt by attacks (default: 0)

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& src);
		ClapTrap&	operator=(ClapTrap const& rhs);
		~ClapTrap(void);

		// Attack a target, consuming 1 energy point
		void		attack(std::string const& target);
		// Take damage, reducing hit points
		void		takeDamage(unsigned int amount);
		// Repair yourself, consuming 1 energy point to gain hit points
		void		beRepaired(unsigned int amount);

		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
};

#endif
