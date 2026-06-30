/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 09:30:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/30 11:26:57 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

/*
 * WrongCat - Derived class from WrongAnimal
 *
 * makeSound() is "overridden" but, since WrongAnimal::makeSound() is NOT
 * virtual, calling makeSound() through a WrongAnimal pointer will NOT
 * dispatch to WrongCat::makeSound() — it will call WrongAnimal::makeSound().
 *
 * However, when used directly as a WrongCat (not through a WrongAnimal
 * pointer), the override behaves as expected.
 */
class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const& src);
		WrongCat&	operator=(WrongCat const& rhs);
		~WrongCat(void);

		void	makeSound(void) const;
};

#endif