/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 09:30:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/30 19:08:46 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

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

#endif // WRONGANIMAL_HPP
