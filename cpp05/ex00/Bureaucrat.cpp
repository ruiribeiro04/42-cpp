/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/18 12:51:29 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
 * Private default constructor
 * Defined here (not in the header) so it cannot be used from outside
 */
Bureaucrat::Bureaucrat(void) : _name("Unnamed"), _grade(_lowestGrade)
{
}

/*
 * Parameterized constructor
 * The name is const, so it must be initialized in the initializer list
 * The grade is validated before being assigned: if the constructor throws,
 * the object is never considered fully constructed
 */
Bureaucrat::Bureaucrat(std::string const& name, int grade) : _name(name), _grade(grade)
{
	checkGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) : _name(src._name), _grade(src._grade)
{
}

/*
 * Copy assignment operator
 * The name is const, so only the grade can be copied
 */
Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
}

/*
 * Centralized grade validation
 * Both the constructor and the increment/decrement functions use it,
 * so the grade rules live in exactly one place
 */
void	Bureaucrat::checkGrade(int grade)
{
	if (grade < _highestGrade)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > _lowestGrade)
		throw (Bureaucrat::GradeTooLowException());
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Exception: grade is too high!");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Exception: grade is too low!");
}

std::string const&	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

/*
 * Increment: grade 3 becomes grade 2 (1 is the highest)
 * Decrement: grade 3 becomes grade 4 (150 is the lowest)
 * Both throw the same exceptions as the constructor when out of range
 */
void	Bureaucrat::incrementGrade(void)
{
	checkGrade(this->_grade - 1);
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	checkGrade(this->_grade + 1);
	this->_grade++;
}

std::ostream&	operator<<(std::ostream& o, Bureaucrat const& bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (o);
}
