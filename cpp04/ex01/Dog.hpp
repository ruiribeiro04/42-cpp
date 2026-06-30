/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 09:30:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/30 11:26:51 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	_brain;

	public:
		Dog(void);
		Dog(Dog const& src);
		Dog&	operator=(Dog const& rhs);
		~Dog(void);

		void	makeSound(void) const;

		// Helper used to demonstrate that the deep copy really duplicated
		// the Brain and not just the pointer.
		Brain&		getBrain(void);
		Brain const&	getBrain(void) const;
};

#endif