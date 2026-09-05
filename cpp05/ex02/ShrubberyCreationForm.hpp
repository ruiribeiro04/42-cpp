/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:00:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/09/05 12:00:00 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

/*
 * ShrubberyCreationForm
 * Required grades: sign 145, execute 137
 * Action: creates a file <target>_shrubbery in the working
 * directory and writes ASCII trees inside it
 */
class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const& target);
		ShrubberyCreationForm(ShrubberyCreationForm const& src);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& rhs);
		~ShrubberyCreationForm(void);

		// Write the ASCII trees to <target>_shrubbery
		void	executeAction(void) const;
};

#endif
