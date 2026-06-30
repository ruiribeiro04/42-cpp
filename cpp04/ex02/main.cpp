/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 09:30:00 by ruiferna          #+#    #+#             */
/*   Updated: 2026/06/30 19:07:54 by ruiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <sstream>

// ANSI Color Codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void    printHeader(std::string title)
{
        std::cout << BOLD << CYAN << "\n========================================" << std::endl;
        std::cout << title << std::endl;
        std::cout << "========================================" << RESET << std::endl;
}

// Subject's main test: just verify that creating and deleting Dog/Cat through
// Animal pointers doesn't leak (Brain must be freed by Dog/Cat destructor,
// which is reached because Animal's destructor is virtual).
int     subjectTest(void)
{
        const Animal*   j = new Dog();
        const Animal*   i = new Cat();

        delete j; // should not create a leak
        delete i;

        return (0);
}

int     main(void)
{
        printHeader("TEST 1: Subject Test - Dog and Cat with Brain (no leak)");
        {
                subjectTest();
        }

        printHeader("TEST 2: Subject Test - Array of Animals (half Dog, half Cat)");
        {
                const int               size = 6;
                const Animal*   animals[size];

                std::cout << BLUE << "\n--- Creating " << size << " animals (half Dog, half Cat) ---" << RESET << std::endl;
                for (int i = 0; i < size; i++)
                {
                        if (i < size / 2)
                                animals[i] = new Dog();
                        else
                                animals[i] = new Cat();
                }

                std::cout << BLUE << "\n--- Calling makeSound() on each ---" << RESET << std::endl;
                for (int i = 0; i < size; i++)
                {
                        std::cout << GREEN << "animals[" << i << "] (" << animals[i]->getType()
                                << "): " << RESET;
                        animals[i]->makeSound();
                }

                std::cout << BLUE << "\n--- Deleting every Animal as Animal (virtual destructor) ---" << RESET << std::endl;
                for (int i = 0; i < size; i++)
                        delete animals[i];
        }

        printHeader("TEST 3: Deep copy - Dog basic; { Dog tmp = basic; }");
        {
                std::cout << BLUE << "\n--- Creating basic Dog and setting an idea ---" << RESET << std::endl;
                Dog     basic;
                basic.getBrain().setIdea(0, "I want a bone");
                basic.getBrain().setIdea(1, "I want to chase the cat");

                std::cout << BLUE << "\n--- Inner scope: copying basic into tmp ---" << RESET << std::endl;
                {
                        Dog     tmp = basic;

                        std::cout << BLUE << "\n--- Modify tmp's Brain (should NOT affect basic) ---" << RESET << std::endl;
                        tmp.getBrain().setIdea(0, "I am the copy, I want a different bone");

                        std::cout << GREEN << "\nbasic.getIdea(0) = " << basic.getBrain().getIdea(0) << RESET << std::endl;
                        std::cout << GREEN << "tmp.getIdea(0)   = " << tmp.getBrain().getIdea(0) << RESET << std::endl;
                        std::cout << GREEN << "basic.getIdea(1) = " << basic.getBrain().getIdea(1) << RESET << std::endl;
                        std::cout << GREEN << "tmp.getIdea(1)   = " << tmp.getBrain().getIdea(1) << RESET << std::endl;

                        std::cout << BLUE << "\n--- tmp's address: " << &tmp << " | basic's address: " << &basic << " ---" << RESET << std::endl;
                        std::cout << BLUE << "--- tmp's Brain address: " << &tmp.getBrain()
                                << " | basic's Brain address: " << &basic.getBrain() << " ---" << RESET << std::endl;
                        std::cout << MAGENTA << "--- If the Brain addresses differ, the copy is DEEP ---" << RESET << std::endl;

                        std::cout << BLUE << "\n--- End of inner scope: tmp is destroyed (its Brain too) ---" << RESET << std::endl;
                }

                std::cout << BLUE << "\n--- After inner scope: basic's Brain must still be valid ---" << RESET << std::endl;
                std::cout << GREEN << "basic.getIdea(0) = " << basic.getBrain().getIdea(0) << RESET << std::endl;
                std::cout << GREEN << "basic.getIdea(1) = " << basic.getBrain().getIdea(1) << RESET << std::endl;
        }

        printHeader("TEST 4: Deep copy - copy assignment operator");
        {
                Dog     a;
                a.getBrain().setIdea(0, "A's first idea");

                Dog     b;
                b.getBrain().setIdea(0, "B's first idea");

                std::cout << BLUE << "\n--- Before assignment ---" << RESET << std::endl;
                std::cout << GREEN << "a.getIdea(0) = " << a.getBrain().getIdea(0) << RESET << std::endl;
                std::cout << GREEN << "b.getIdea(0) = " << b.getBrain().getIdea(0) << RESET << std::endl;

                std::cout << BLUE << "\n--- b = a; ---" << RESET << std::endl;
                b = a;

                std::cout << BLUE << "\n--- After assignment (b should have a's ideas) ---" << RESET << std::endl;
                std::cout << GREEN << "a.getIdea(0) = " << a.getBrain().getIdea(0) << RESET << std::endl;
                std::cout << GREEN << "b.getIdea(0) = " << b.getBrain().getIdea(0) << RESET << std::endl;

                std::cout << BLUE << "\n--- Modify b's Brain (should NOT affect a) ---" << RESET << std::endl;
                b.getBrain().setIdea(0, "B's NEW first idea");
                std::cout << GREEN << "a.getIdea(0) = " << a.getBrain().getIdea(0) << RESET << std::endl;
                std::cout << GREEN << "b.getIdea(0) = " << b.getBrain().getIdea(0) << RESET << std::endl;
        }

        printHeader("TEST 5: Deep copy - Cat");
        {
                Cat     original;
                original.getBrain().setIdea(0, "Knock something off the table");

                Cat     copy = original; // copy constructor

                std::cout << BLUE << "\n--- Modify copy's Brain (should NOT affect original) ---" << RESET << std::endl;
                copy.getBrain().setIdea(0, "Sleep all day");

                std::cout << GREEN << "original.getIdea(0) = " << original.getBrain().getIdea(0) << RESET << std::endl;
                std::cout << GREEN << "copy.getIdea(0)     = " << copy.getBrain().getIdea(0) << RESET << std::endl;
        }

        printHeader("TEST 6: Brain can hold 100 ideas");
        {
                Dog     dog;
                for (int i = 0; i < 100; i++)
                {
                        std::stringstream       ss;
                        ss << "Idea " << i;
                        dog.getBrain().setIdea(i, ss.str());
                }
                std::cout << GREEN << "dog.getIdea(0)   = " << dog.getBrain().getIdea(0) << RESET << std::endl;
                std::cout << GREEN << "dog.getIdea(50)  = " << dog.getBrain().getIdea(50) << RESET << std::endl;
                std::cout << GREEN << "dog.getIdea(99)  = " << dog.getBrain().getIdea(99) << RESET << std::endl;
                std::cout << YELLOW << "dog.getIdea(100) = (out of range)" << RESET << std::endl;
                dog.getBrain().getIdea(100);
        }

        printHeader("TEST 7: WrongAnimal / WrongCat (no virtual)");
        {
                const WrongAnimal*      meta = new WrongAnimal();
                const WrongAnimal*      i = new WrongCat();

                std::cout << i->getType() << " " << std::endl;
                i->makeSound(); // outputs the WrongAnimal sound (no virtual)
                meta->makeSound();

                delete meta;
                delete i;
        }

        printHeader("TEST 8: Construction / destruction order with Brain");
        {
                std::cout << BLUE << "\n--- Creating a Dog ---" << RESET << std::endl;
                Dog     dog;
                std::cout << BLUE << "\n--- Creating a Cat ---" << RESET << std::endl;
                Cat     cat;
                std::cout << MAGENTA << "\n--- End of scope: destructors in reverse order ---" << RESET << std::endl;
                std::cout << MAGENTA << "--- Order: Cat -> Brain -> Dog -> Brain ---" << RESET << std::endl;
        }

        printHeader("TEST 9: Polymorphism still works");
        {
                const Animal*   animals[4];
                animals[0] = new Dog();
                animals[1] = new Cat();
                animals[2] = new Dog();
                animals[3] = new Cat();

                for (int i = 0; i < 4; i++)
                {
                        std::cout << GREEN << "animals[" << i << "] (" << animals[i]->getType()
                                << "): " << RESET;
                        animals[i]->makeSound();
                }

                for (int i = 0; i < 4; i++)
                        delete animals[i];
        }

        printHeader("TEST 10: Animal is abstract (cannot be instantiated)");
        {
                std::cout << YELLOW << "\n--- Animal is now an abstract class ---" << RESET << std::endl;
                std::cout << YELLOW << "--- Uncomment the line below to verify it doesn't compile ---" << RESET << std::endl;
                // Animal animal;  // ERROR: cannot declare variable 'animal' to be of abstract type 'Animal'
                // const Animal* meta = new Animal();  // ERROR: invalid new-expression of abstract class type 'Animal'

                std::cout << GREEN << "\nDog and Cat (concrete derived classes) work as before:" << RESET << std::endl;
                Dog     dog;
                Cat     cat;
                std::cout << GREEN << "dog.getType() = " << dog.getType() << RESET << std::endl;
                std::cout << GREEN << "cat.getType() = " << cat.getType() << RESET << std::endl;
                dog.makeSound();
                cat.makeSound();
        }

        std::cout << BOLD << GREEN << "\n========================================" << std::endl;
        std::cout << "END OF TESTS: All tests completed successfully!" << std::endl;
        std::cout << "========================================" << RESET << std::endl;

        return (0);
}
