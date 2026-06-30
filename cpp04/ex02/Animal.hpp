/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 09:30:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/30 19:08:07 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
        protected:
                std::string     type;

        public:
                Animal(void);
                Animal(Animal const& src);
                Animal&         operator=(Animal const& rhs);
                virtual ~Animal(void);

                std::string const&      getType(void) const;

                // Pure virtual: makes Animal an abstract class (cannot be instantiated).
                // Derived classes MUST provide their own implementation.
                virtual void    makeSound(void) const = 0;
};

#endif
