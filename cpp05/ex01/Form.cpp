/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/05 12:00:00 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
 * Private default constructor
 * Defined here (not in the header) so it cannot be used from outside
 */
Form::Form(void)
	: _name("Unnamed"), _signed(false), _gradeToSign(_lowestGrade), _gradeToExecute(_lowestGrade)
{
}

/*
 * Parameterized constructor
 * The name and both grades are const, so they must be set
 * in the initializer list; both grades are validated right after
 */
Form::Form(std::string const& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

Form::Form(Form const& src)
	: _name(src._name), _signed(src._signed),
	  _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

/*
 * Copy assignment operator
 * The name and the grades are const, so only the signature status
 * can be copied; a fresh unsigned form stays unsigned if the source is
 */
Form&	Form::operator=(Form const& rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

Form::~Form(void)
{
}

/*
 * Centralized grade validation (same limits as the Bureaucrat)
 */
void	Form::checkGrade(int grade)
{
	if (grade < _highestGrade)
		throw (Form::GradeTooHighException());
	if (grade > _lowestGrade)
		throw (Form::GradeTooLowException());
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Exception: grade is too high!");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Exception: grade is too low!");
}

std::string const&	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::isSigned(void) const
{
	return (this->_signed);
}

int	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

/*
 * beSigned: the actual signing logic
 * Remember that grade 1 is HIGHER than grade 2, so the bureaucrat
 * must have a grade number smaller than or equal to the required one
 * Otherwise it throws Form::GradeTooLowException
 */
void	Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw (Form::GradeTooLowException());
	this->_signed = true;
}

std::ostream&	operator<<(std::ostream& o, Form const& form)
{
	o << form.getName()
	  << " [sign status: " << (form.isSigned() ? "signed" : "not signed")
	  << ", grade to sign: " << form.getGradeToSign()
	  << ", grade to execute: " << form.getGradeToExecute()
	  << "]";
	return (o);
}
