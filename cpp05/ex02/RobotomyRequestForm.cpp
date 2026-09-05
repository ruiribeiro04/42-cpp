/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/05 12:00:00 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/*
 * Default constructor: uses the standard class name,
 * the required grades (sign 72, exec 45) and a default target
 */
RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("robotomy request", 72, 45, "unknown")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
	: AForm("robotomy request", 72, 45, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
	: AForm(src)
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
	if (this != &rhs)
		AForm::operator=(rhs); // Only copies the signed state
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

/*
 * executeAction: called by AForm::execute() AFTER the checks passed
 * Makes some drilling noises, then succeeds 50% of the time
 * std::rand() % 2 gives 0 or 1 with (roughly) equal probability
 */
void	RobotomyRequestForm::executeAction(void) const
{
	std::cout << "* BZZZZZZ... DRRRRRR... VRRRRRRR... *" << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully!"
				  << std::endl;
	else
		std::cout << "The robotomy of " << this->getTarget() << " failed..."
				  << std::endl;
}
