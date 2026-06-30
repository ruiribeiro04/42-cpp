/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 09:30:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/30 10:34:56 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

// ANSI Color Codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void	printHeader(std::string title)
{
	std::cout << BOLD << CYAN << "\n========================================" << std::endl;
	std::cout << title << std::endl;
	std::cout << "========================================" << RESET << std::endl;
}

// Subject's main test: polymorphism through Animal pointers.
int	subjectTest(void)
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	return (0);
}

// Subject's wrong test: without virtual, WrongCat behaves like a WrongAnimal
// when accessed through a WrongAnimal pointer.
int	wrongSubjectTest(void)
{
	const WrongAnimal*	meta = new WrongAnimal();
	const WrongAnimal*	i = new WrongCat();

	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the WrongAnimal sound (no virtual!)
	meta->makeSound();

	delete meta;
	delete i;

	return (0);
}

int	main(void)
{
	printHeader("TEST 1: Subject Test - Polymorphism");
	{
		subjectTest();
	}

	printHeader("TEST 2: Subject Test - WrongAnimal (no virtual)");
	{
		wrongSubjectTest();
	}

	printHeader("TEST 3: Construction & Destruction Order");
	{
		std::cout << BLUE << "\n--- Creating a Dog ---" << RESET << std::endl;
		Dog	dog;
		std::cout << BLUE << "\n--- Creating a Cat ---" << RESET << std::endl;
		Cat	cat;
		std::cout << BLUE << "\n--- Creating an Animal ---" << RESET << std::endl;
		Animal	animal;
		std::cout << MAGENTA << "\n--- End of scope: destructors called in reverse order ---" << RESET << std::endl;
	}

	printHeader("TEST 4: Stack-allocated objects calling makeSound directly");
	{
		Dog	dog;
		Cat	cat;
		Animal	animal;

		std::cout << BLUE << "\n--- Each animal should produce its own sound ---" << RESET << std::endl;
		std::cout << GREEN << "Dog says: " << RESET;
		dog.makeSound();
		std::cout << GREEN << "Cat says: " << RESET;
		cat.makeSound();
		std::cout << GREEN << "Animal says: " << RESET;
		animal.makeSound();
	}

	printHeader("TEST 5: Type attribute set correctly");
	{
		Dog	dog;
		Cat	cat;
		Animal	animal;

		std::cout << GREEN << "Dog type    = " << dog.getType() << RESET << std::endl;
		std::cout << GREEN << "Cat type    = " << cat.getType() << RESET << std::endl;
		std::cout << GREEN << "Animal type = " << animal.getType() << RESET << std::endl;
	}

	printHeader("TEST 6: WrongCat used directly (not through WrongAnimal pointer)");
	{
		WrongCat	wc;

		std::cout << GREEN << "WrongCat type = " << wc.getType() << RESET << std::endl;
		std::cout << GREEN << "WrongCat says: " << RESET;
		wc.makeSound(); // should print the WrongCat sound
	}

	printHeader("TEST 7: Orthodox Canonical Form - Dog");
	{
		std::cout << BLUE << "\n--- Copy constructor ---" << RESET << std::endl;
		Dog	original;
		Dog	copy(original);

		std::cout << BLUE << "\n--- Copy assignment operator ---" << RESET << std::endl;
		Dog	assigned;
		assigned = original;

		std::cout << GREEN << "\nOriginal type = " << original.getType() << RESET << std::endl;
		std::cout << GREEN << "Copy type     = " << copy.getType() << RESET << std::endl;
		std::cout << GREEN << "Assigned type = " << assigned.getType() << RESET << std::endl;
	}

	printHeader("TEST 8: Orthodox Canonical Form - Cat");
	{
		std::cout << BLUE << "\n--- Copy constructor ---" << RESET << std::endl;
		Cat	original;
		Cat	copy(original);

		std::cout << BLUE << "\n--- Copy assignment operator ---" << RESET << std::endl;
		Cat	assigned;
		assigned = original;

		std::cout << GREEN << "\nOriginal type = " << original.getType() << RESET << std::endl;
		std::cout << GREEN << "Copy type     = " << copy.getType() << RESET << std::endl;
		std::cout << GREEN << "Assigned type = " << assigned.getType() << RESET << std::endl;
	}

	printHeader("TEST 9: Array of Animal pointers (mixing Dog and Cat)");
	{
		const Animal*	animals[4];

		std::cout << BLUE << "\n--- Creating 2 Dogs and 2 Cats ---" << RESET << std::endl;
		animals[0] = new Dog();
		animals[1] = new Cat();
		animals[2] = new Dog();
		animals[3] = new Cat();

		std::cout << BLUE << "\n--- Calling makeSound() on each (polymorphism) ---" << RESET << std::endl;
		for (int i = 0; i < 4; i++)
		{
			std::cout << GREEN << "animals[" << i << "] (" << animals[i]->getType()
				<< "): " << RESET;
			animals[i]->makeSound();
		}

		std::cout << BLUE << "\n--- Deleting all animals ---" << RESET << std::endl;
		for (int i = 0; i < 4; i++)
			delete animals[i];
	}

	printHeader("TEST 10: Reference polymorphism");
	{
		Dog	dog;
		Cat	cat;
		Animal&	rDog = dog;
		Animal&	rCat = cat;

		std::cout << BLUE << "\n--- Calling makeSound() through Animal references ---" << RESET << std::endl;
		std::cout << GREEN << "Through Animal& to Dog: " << RESET;
		rDog.makeSound();
		std::cout << GREEN << "Through Animal& to Cat: " << RESET;
		rCat.makeSound();
	}

	std::cout << BOLD << GREEN << "\n========================================" << std::endl;
	std::cout << "END OF TESTS: All tests completed successfully!" << std::endl;
	std::cout << "========================================" << RESET << std::endl;

	return (0);
}