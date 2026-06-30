/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 09:30:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/30 11:26:51 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const& src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	// Allocate a new Brain and copy the ideas from src.
	// This is what makes the copy DEEP — without this we would just
	// copy the pointer and end up sharing the same Brain.
	this->_brain = new Brain(*src._brain);
}

Dog&	Dog::operator=(Dog const& rhs)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		// Free the existing Brain before assigning a new one,
		// otherwise we leak the previously allocated Brain.
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof!" << std::endl;
}

Brain&	Dog::getBrain(void)
{
	return (*this->_brain);
}

Brain const&	Dog::getBrain(void) const
{
	return (*this->_brain);
}