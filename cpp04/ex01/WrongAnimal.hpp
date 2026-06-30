/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 09:30:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/30 11:26:54 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

/*
 * WrongAnimal - Deliberately incorrect version of Animal
 *
 * The makeSound() member function is NOT declared virtual here.
 * This means that calling makeSound() through a WrongAnimal pointer
 * pointing to a WrongCat will resolve to WrongAnimal::makeSound(),
 * not WrongCat::makeSound().
 *
 * This class exists to demonstrate the importance of the `virtual`
 * keyword when implementing polymorphism.
 *
 * Orthodox Canonical Form is implemented.
 */
class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const& src);
		WrongAnimal&	operator=(WrongAnimal const& rhs);
		~WrongAnimal(void);

		std::string const&	getType(void) const;

		// NOTE: deliberately NOT virtual — this is the "wrong" behaviour.
		void	makeSound(void) const;
};

#endif