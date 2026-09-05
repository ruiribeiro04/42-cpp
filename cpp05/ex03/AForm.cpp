/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/05 12:00:00 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*
 * Private default constructor
 * Defined here (not in the header) so it cannot be used from outside
 */
AForm::AForm(void)
	: _name("Unnamed"), _signed(false), _gradeToSign(_lowestGrade),
	  _gradeToExecute(_lowestGrade), _target("nowhere")
{
}

/*
 * Parameterized constructor
 * All attributes except the signed flag are const,
 * so they must be set in the initializer list
 */
AForm::AForm(std::string const& name, int gradeToSign, int gradeToExecute,
			 std::string const& target)
	: _name(name), _signed(false), _gradeToSign(gradeToSign),
	  _gradeToExecute(gradeToExecute), _target(target)
{
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

AForm::AForm(AForm const& src)
	: _name(src._name), _signed(src._signed),
	  _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute),
	  _target(src._target)
{
}

/*
 * Copy assignment operator
 * The name, grades and target are const, so only the
 * signature status can be copied
 */
AForm&	AForm::operator=(AForm const& rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

/*
 * Virtual destructor: mandatory in a polymorphic base class
 * so that deleting through an AForm* calls the derived destructor
 */
AForm::~AForm(void)
{
}

/*
 * Centralized grade validation (same limits as the Bureaucrat)
 */
void	AForm::checkGrade(int grade)
{
	if (grade < _highestGrade)
		throw (AForm::GradeTooHighException());
	if (grade > _lowestGrade)
		throw (AForm::GradeTooLowException());
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Exception: grade is too high!");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Exception: grade is too low!");
}

const char*	AForm::FormNotSignedException::what(void) const throw()
{
	return ("Exception: form is not signed!");
}

std::string const&	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::isSigned(void) const
{
	return (this->_signed);
}

int	AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

std::string const&	AForm::getTarget(void) const
{
	return (this->_target);
}

/*
 * beSigned: the actual signing logic
 * Grade 1 is HIGHER than grade 2, so the bureaucrat must have
 * a grade number smaller than or equal to the required one
 */
void	AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw (AForm::GradeTooLowException());
	this->_signed = true;
}

/*
 * execute(): requirement checks centralized in the base class
 * 1. The form must be signed
 * 2. The executor's grade must be high enough
 * Only then is the concrete action performed
 * This way no concrete form can forget the checks
 */
void	AForm::execute(Bureaucrat const& executor) const
{
	if (!this->_signed)
		throw (AForm::FormNotSignedException());
	if (executor.getGrade() > this->_gradeToExecute)
		throw (AForm::GradeTooLowException());
	this->executeAction();
}

std::ostream&	operator<<(std::ostream& o, AForm const& form)
{
	o << form.getName() << " [target: " << form.getTarget()
	  << ", sign status: " << (form.isSigned() ? "signed" : "not signed")
	  << ", grade to sign: " << form.getGradeToSign()
	  << ", grade to execute: " << form.getGradeToExecute()
	  << "]";
	return (o);
}
