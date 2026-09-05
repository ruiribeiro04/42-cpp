/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/05 12:00:00 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

// The known form names, matching the subject's examples exactly
std::string const	Intern::_formNames[3] =
{
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

Intern::Intern(void)
{
}

Intern::Intern(Intern const& src)
{
	(void)src; // Nothing to copy: an intern has no attributes
}

Intern&	Intern::operator=(Intern const& rhs)
{
	(void)rhs; // Nothing to assign: an intern has no attributes
	return (*this);
}

Intern::~Intern(void)
{
}

/*
 * The three creation functions
 * Each one simply builds its form with the requested target
 */
AForm*	Intern::makeShrubberyCreationForm(std::string const& target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomyRequestForm(std::string const& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePresidentialPardonForm(std::string const& target) const
{
	return (new PresidentialPardonForm(target));
}

/*
 * makeForm: dispatch table with pointers to MEMBER functions
 * The names array and the functions array are index-aligned,
 * so one loop finds the match and calls the right creator
 * No if/elseif/else chain anywhere
 */
AForm*	Intern::makeForm(std::string const& formName, std::string const& target)
{
	AForm* (Intern::*creators[3])(std::string const&) const =
	{
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == _formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*creators[i])(target));
		}
	}

	std::cout << "Error: the intern does not know how to create '"
			  << formName << "' (not a valid form name)" << std::endl;
	return (NULL);
}
