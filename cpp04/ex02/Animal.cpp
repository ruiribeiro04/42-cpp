/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 09:30:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/30 19:08:01 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
        std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const& src)
{
        std::cout << "Animal copy constructor called" << std::endl;
        *this = src;
}

Animal& Animal::operator=(Animal const& rhs)
{
        std::cout << "Animal copy assignment operator called" << std::endl;
        if (this != &rhs)
        {
                this->type = rhs.type;
        }
        return (*this);
}

Animal::~Animal(void)
{
        std::cout << "Animal destructor called" << std::endl;
}

std::string const&      Animal::getType(void) const
{
        return (this->type);
}
