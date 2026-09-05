/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/05 12:00:00 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

		// Grade limits: 1 is the highest, 150 is the lowest
		static int const	_highestGrade = 1;
		static int const	_lowestGrade = 150;

		// Private default constructor: a bureaucrat is nothing without a name
		Bureaucrat(void);

	public:
		Bureaucrat(std::string const& name, int grade);
		Bureaucrat(Bureaucrat const& src);
		Bureaucrat&	operator=(Bureaucrat const& rhs);
		~Bureaucrat(void);

		/*
		 * Nested exception classes
		 * They inherit from std::exception so they are catchable
		 * with "catch (std::exception & e)"
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
		int					getGrade(void) const;

		// Increment the grade (3 -> 2, since 1 is the highest)
		void	incrementGrade(void);
		// Decrement the grade (3 -> 4, since 150 is the lowest)
		void	decrementGrade(void);
};

// Prints: <name>, bureaucrat grade <grade>.
std::ostream&	operator<<(std::ostream& o, Bureaucrat const& bureaucrat);

#endif
