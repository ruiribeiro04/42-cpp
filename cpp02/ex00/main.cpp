# include "Fixed.hpp"

/*
 * Main test function for Exercise 00
 * 
 * This program tests the Orthodox Canonical Form implementation:
 * - Default constructor
 * - Copy constructor
 * - Copy assignment operator
 * - Destructor
 * - getRawBits and setRawBits methods
 * 
 * Expected output demonstrates the order of constructor/destructor calls
 * and shows that all objects are properly initialized to 0.
 */
int	main(void)
{
	// Create a Fixed object 'a' using default constructor
	// This will print: "Default constructor called"
	Fixed	a;
	
	// Create a Fixed object 'b' as a copy of 'a'
	// This will print: "Copy constructor called"
	Fixed	b(a);
	
	// Create a Fixed object 'c' using default constructor
	// This will print: "Default constructor called"
	Fixed	c;
	
	// Use the copy assignment operator to assign 'b' to 'c'
	// This will print: "Copy assignment operator called"
	// Note: Some optimizations might skip this message
	c = b;
	
	// Print the raw values (all should be 0 since default constructor initializes to 0)
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	// When main() ends, destructors are called in reverse order of construction
	// This will print: "Destructor called" three times (c, b, a)
	return (0);
}
