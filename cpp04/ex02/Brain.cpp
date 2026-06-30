/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 09:45:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/30 19:07:59 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < BRAIN_IDEAS_COUNT; i++)
		this->ideas[i] = "";
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const& src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain&	Brain::operator=(Brain const& rhs)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < BRAIN_IDEAS_COUNT; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(unsigned int idx, std::string const& idea)
{
	if (idx < BRAIN_IDEAS_COUNT)
		this->ideas[idx] = idea;
	else
		std::cout << "Brain: index out of range (" << idx << ")" << std::endl;
}

std::string	Brain::getIdea(unsigned int idx) const
{
	if (idx < BRAIN_IDEAS_COUNT)
		return (this->ideas[idx]);
	std::cout << "Brain: index out of range (" << idx << ")" << std::endl;
	return ("");
}
