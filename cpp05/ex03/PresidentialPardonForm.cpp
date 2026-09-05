/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/05 12:00:00 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

/*
 * Default constructor: uses the standard class name,
 * the required grades (sign 25, exec 5) and a default target
 */
PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("presidential pardon", 25, 5, "unknown")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
	: AForm("presidential pardon", 25, 5, target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src)
	: AForm(src)
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
	if (this != &rhs)
		AForm::operator=(rhs); // Only copies the signed state
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

/*
 * executeAction: called by AForm::execute() AFTER the checks passed
 * Informs that the target has been pardoned by Zaphod Beeblebrox
 */
void	PresidentialPardonForm::executeAction(void) const
{
	std::cout << this->getTarget()
			  << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
