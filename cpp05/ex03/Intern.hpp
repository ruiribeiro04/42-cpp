/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/05 12:00:00 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>

/*
 * Intern: no name, no grade, no personality
 * Only one ability: makeForm() creates the right form from its name
 */
class Intern
{
	private:
		// The three known form names, in the subject's lowercase format
		static std::string const	_formNames[3];

		// One private creation function per form type
		AForm*	makeShrubberyCreationForm(std::string const& target) const;
		AForm*	makeRobotomyRequestForm(std::string const& target) const;
		AForm*	makePresidentialPardonForm(std::string const& target) const;

	public:
		Intern(void);
		Intern(Intern const& src);
		Intern&	operator=(Intern const& rhs);
		~Intern(void);

		/*
		 * Factory method: returns a heap-allocated form matching
		 * formName with the given target, or NULL if the name is unknown
		 * Implemented with an array of pointers to member functions:
		 * no if/elseif/else chains allowed by the subject
		 */
		AForm*	makeForm(std::string const& formName, std::string const& target);
};

#endif
