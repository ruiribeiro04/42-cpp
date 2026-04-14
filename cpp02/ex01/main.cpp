# include "Fixed.hpp"

/*
 * Main test function for Exercise 01
 * 
 * This program tests the enhanced Fixed class with:
 * - Integer constructor
 * - Float constructor
 * - Conversion functions (toFloat, toInt)
 * - Output stream operator (<<)
 * 
 * Expected output demonstrates:
 * - Proper conversion from int and float to fixed-point
 * - Accurate conversion back to float and int
 * - Clean output using the << operator
 */
int	main(void)
{
	// Create Fixed object 'a' using default constructor (value = 0)
	Fixed		a;
	
	// Create Fixed object 'b' from integer 10
	// This uses the integer constructor: 10 << 8 = 2560
	Fixed const	b(10);
	
	// Create Fixed object 'c' from float 42.42
	// This uses the float constructor: 42.42 * 256 = 10859.52 → 10860
	// When converted back: 10860 / 256 = 42.421875
	Fixed const	c(42.42f);
	
	// Create Fixed object 'd' as a copy of 'b'
	Fixed const	d(b);
	
	// Assign a temporary Fixed object created from float 1234.4321f
	// The float constructor is called, then copy assignment operator
	// 1234.4321 * 256 = 316014.6176 → 316015
	// When converted back: 316015 / 256 = 1234.4296875
	a = Fixed(1234.4321f);
	
	// Print all objects as floats using the << operator
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	// Print all objects converted to integers
	// Note: toInt() truncates the fractional part
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	// When main() ends, destructors are called in reverse order
	return (0);
}
