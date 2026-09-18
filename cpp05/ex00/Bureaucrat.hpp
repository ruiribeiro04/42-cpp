/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/18 12:53:32 by ruiferna         ###   ########.fr       */
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
		static int const	_highestGrade = 1;
		static int const	_lowestGrade = 150;
		
		Bureaucrat(void);

	public:
		Bureaucrat(std::string const& name, int grade);
		Bureaucrat(Bureaucrat const& src);
		Bureaucrat&	operator=(Bureaucrat const& rhs);
		~Bureaucrat(void);

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

		static void	checkGrade(int grade);
		std::string const&	getName(void) const;
		int					getGrade(void) const;
		void	incrementGrade(void);
		void	decrementGrade(void);
};

std::ostream&	operator<<(std::ostream& o, Bureaucrat const& bureaucrat);

#endif
