/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/05 12:00:00 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

/*
 * AForm: abstract base class for all forms
 * The pure virtual executeAction() makes this class abstract,
 * so it can never be instantiated directly
 */
class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		std::string const	_target;

		// Grade limits, same rules as the Bureaucrat
		static int const	_highestGrade = 1;
		static int const	_lowestGrade = 150;

		// Private default constructor: every form needs real grades and a target
		AForm(void);

	public:
		AForm(std::string const& name, int gradeToSign, int gradeToExecute,
			  std::string const& target);
		AForm(AForm const& src);
		AForm&	operator=(AForm const& rhs);
		virtual	~AForm(void);

		/*
		 * Nested exception classes
		 * Grade rules are identical to the Bureaucrat's
		 */
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};

		// Thrown by execute() when the form has not been signed yet
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};

		// Validate a grade and throw the appropriate exception if out of range
		static void	checkGrade(int grade);

		std::string const&	getName(void) const;
		bool				isSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		std::string const&	getTarget(void) const;

		// Sign the form if the bureaucrat's grade is high enough
		void	beSigned(Bureaucrat const& bureaucrat);

		/*
		 * execute(): the elegant way — all requirement checks live HERE,
		 * in the base class, exactly once. If the form is signed and the
		 * executor's grade is high enough, it calls the concrete action.
		 */
		void	execute(Bureaucrat const& executor) const;

		// Pure virtual: each concrete form implements its own action
		virtual void	executeAction(void) const = 0;
};

// Prints all the form's information
std::ostream&	operator<<(std::ostream& o, AForm const& form);

#endif
