/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 10:37:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/30 11:26:49 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

#define BRAIN_IDEAS_COUNT 100

/*
 * Brain - Holds an array of 100 std::string ideas
 *
 * Used as a private member of Dog and Cat (Brain* attribute allocated on the
 * heap with `new Brain()`). Because the Brain is allocated on the heap, the
 * default shallow copy of a Dog or Cat would simply share the same pointer,
 * which would result in double-free bugs and unintended aliasing.
 *
 * To prevent this, Dog and Cat must implement deep copies in their copy
 * constructor and copy assignment operator, duplicating the Brain object
 * itself (not just the pointer).
 */
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