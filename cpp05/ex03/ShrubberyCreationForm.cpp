/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/05 12:00:00 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

/*
 * Default constructor: uses the standard class name,
 * the required grades (sign 145, exec 137) and a default target
 */
ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("shrubbery creation", 145, 137, "home")
{
}

/*
 * The only parameter the subject requires: the target
 * "home" => writes to home_shrubbery
 */
ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
	: AForm("shrubbery creation", 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src)
	: AForm(src)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
	if (this != &rhs)
		AForm::operator=(rhs); // Only copies the signed state
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

/*
 * executeAction: called by AForm::execute() AFTER the checks passed
 * Creates <target>_shrubbery and plants ASCII trees inside
 */
void	ShrubberyCreationForm::executeAction(void) const
{
	std::ofstream	file((this->getTarget() + "_shrubbery").c_str());

	if (!file.is_open())
	{
		std::cout << "Error: could not create file "
				  << this->getTarget() << "_shrubbery" << std::endl;
		return ;
	}

	file << "              /\\      " << std::endl;
	file << "             /  \\     " << std::endl;
	file << "            /\\  /\\    " << std::endl;
	file << "           /  \\/  \\   " << std::endl;
	file << "          /\\      /\\  " << std::endl;
	file << "         /  \\    /  \\ " << std::endl;
	file << "        /\\   /\\ /\\   /\\" << std::endl;
	file << "       /  \\ /  v  \\ /  \\" << std::endl;
	file << "          ||||||||||    " << std::endl;
	file << "          ||||||||||    " << std::endl;
	file << std::endl;
	file << "       &&&&&&&&&&&      " << std::endl;
	file << "      &&& trees  &&&    " << std::endl;
	file << "     &&&&&&&&&&&&&&&    " << std::endl;

	file.close();
}
