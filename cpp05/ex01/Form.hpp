/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/05 12:00:00 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;

		// Grade limits, same rules as the Bureaucrat
		static int const	_highestGrade = 1;
		static int const	_lowestGrade = 150;

		// Private default constructor: every form needs real grades
		Form(void);

	public:
		Form(std::string const& name, int gradeToSign, int gradeToExecute);
		Form(Form const& src);
		Form&	operator=(Form const& rhs);
		~Form(void);

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

		// Validate a grade and throw the appropriate exception if out of range
		static void	checkGrade(int grade);

		std::string const&	getName(void) const;
		bool				isSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		// Sign the form if the bureaucrat's grade is high enough
		void	beSigned(Bureaucrat const& bureaucrat);
};

// Prints all the form's information
std::ostream&	operator<<(std::ostream& o, Form const& form);

#endif
