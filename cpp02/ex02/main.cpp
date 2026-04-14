# include "Fixed.hpp"

/*
 * Main test function for Exercise 02
 * 
 * This program tests all the operator overloading features:
 * - Pre and post increment/decrement operators
 * - Arithmetic operators (through the example)
 * - Static min/max functions
 * 
 * The expected output demonstrates:
 * - Default initialization (a starts at 0)
 * - Pre-increment returns incremented value
 * - Post-increment returns original value, then increments
 * - Multiplication and max operations work correctly
 */
int	main(void)
{
	// Create Fixed object 'a' with default value 0
	Fixed		a;
	
	// Create const Fixed object 'b' by multiplying 5.05f by 2
	// 5.05 * 2 = 10.1, which in fixed-point is approximately 10.1016
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	// Print initial value of a (should be 0)
	std::cout << a << std::endl;
	
	// Pre-increment a: increments a first, then returns the new value
	// a becomes 0.00390625 (1/256), and we print that
	std::cout << ++a << std::endl;
	
	// Print a again (should still be 0.00390625)
	std::cout << a << std::endl;
	
	// Post-increment a: returns current value (0.00390625), then increments
	// a becomes 0.0078125 (2/256)
	std::cout << a++ << std::endl;
	
	// Print a again (should now be 0.0078125)
	std::cout << a << std::endl;
	
	// Print b (should be approximately 10.1016)
	std::cout << b << std::endl;
	
	// Print the maximum of a and b (should be b, approximately 10.1016)
	std::cout << Fixed::max(a, b) << std::endl;
	
	// Test additional operators (not in subject but good for verification)
	std::cout << "\n--- Additional Tests ---" << std::endl;
	
	// Test arithmetic operators
	Fixed	x(10.5f);
	Fixed	y(2.5f);
	
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "x + y = " << (x + y) << std::endl;
	std::cout << "x - y = " << (x - y) << std::endl;
	std::cout << "x * y = " << (x * y) << std::endl;
	std::cout << "x / y = " << (x / y) << std::endl;
	
	// Test comparison operators
	std::cout << "\n--- Comparison Tests ---" << std::endl;
	std::cout << "x > y? " << (x > y ? "true" : "false") << std::endl;
	std::cout << "x < y? " << (x < y ? "true" : "false") << std::endl;
	std::cout << "x == y? " << (x == y ? "true" : "false") << std::endl;
	std::cout << "x != y? " << (x != y ? "true" : "false") << std::endl;
	
	// Test min/max
	std::cout << "\n--- Min/Max Tests ---" << std::endl;
	std::cout << "min(x, y) = " << Fixed::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << Fixed::max(x, y) << std::endl;
	
	// Test increment/decrement more thoroughly
	std::cout << "\n--- Increment/Decrement Tests ---" << std::endl;
	Fixed	counter(5.0f);
	
	std::cout << "Initial: " << counter << std::endl;
	std::cout << "Post-increment: " << counter++ << " (now " << counter << ")" << std::endl;
	std::cout << "Pre-increment: " << ++counter << " (now " << counter << ")" << std::endl;
	std::cout << "Post-decrement: " << counter-- << " (now " << counter << ")" << std::endl;
	std::cout << "Pre-decrement: " << --counter << " (now " << counter << ")" << std::endl;
	
	return (0);
}
