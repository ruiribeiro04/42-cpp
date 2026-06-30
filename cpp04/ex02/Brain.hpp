/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 09:45:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/30 19:08:15 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

#define BRAIN_IDEAS_COUNT 100

class Brain
{
	private:
		std::string	ideas[BRAIN_IDEAS_COUNT];

	public:
		Brain(void);
		Brain(Brain const& src);
		Brain&	operator=(Brain const& rhs);
		~Brain(void);

		// Setter / getter for individual ideas (used to verify deep copy).
		void		setIdea(unsigned int idx, std::string const& idea);
		std::string	getIdea(unsigned int idx) const;
};

#endif
