#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

/*
 * Fixed Point Number Class - Enhanced Version
 * 
 * This class implements a fixed-point number with 8 fractional bits.
 * Exercise 01 adds:
 * - Constructor from integer
 * - Constructor from float  
 * - Conversion to float (toFloat)
 * - Conversion to integer (toInt)
 * - Output stream operator (<<)
 * 
 * Fixed-point representation:
 * - We use 8 bits for the fractional part (2^8 = 256 possible values)
 * - To convert float to fixed: multiply by 256 and round
 * - To convert fixed to float: divide by 256
 * - To convert int to fixed: shift left by 8 bits (multiply by 256)
 * - To convert fixed to int: shift right by 8 bits (divide by 256)
 */
class Fixed
{
	private:
		int					_fixedPointValue;	// Raw fixed-point value
		static const int	_fractionalBits = 8;	// Always 8 fractional bits

	public:
		/*
		 * Default Constructor
		 * Initializes fixed-point value to 0
		 */
		Fixed(void);

		/*
		 * Copy Constructor
		 * Creates a copy of another Fixed object
		 */
		Fixed(const Fixed& other);

		/*
		 * Integer Constructor
		 * Converts an integer to fixed-point representation.
		 * We shift left by 8 bits to make room for fractional part.
		 * Example: 5 becomes 5 * 256 = 1280
		 * 
		 * @param value: Integer value to convert
		 */
		Fixed(const int value);

		/*
		 * Float Constructor
		 * Converts a floating-point number to fixed-point representation.
		 * We multiply by 256 and round to get the nearest fixed-point value.
		 * Example: 5.5 becomes 5.5 * 256 = 1408
		 * 
		 * @param value: Floating-point value to convert
		 */
		Fixed(const float value);

		/*
		 * Copy Assignment Operator
		 * Assigns value from another Fixed object
		 */
		Fixed&	operator=(const Fixed& other);

		/*
		 * Destructor
		 */
		~Fixed(void);

		/*
		 * Convert to Float
		 * Converts the fixed-point value to a floating-point number.
		 * We divide by 256 to get the actual decimal value.
		 * 
		 * @return: Float representation of the fixed-point value
		 */
		float	toFloat(void) const;

		/*
		 * Convert to Integer
		 * Converts the fixed-point value to an integer.
		 * We shift right by 8 bits, which discards the fractional part.
		 * 
		 * @return: Integer representation (fractional part is lost)
		 */
		int		toInt(void) const;

		/*
		 * Get Raw Bits
		 * Returns the raw stored integer value
		 */
		int		getRawBits(void) const;

		/*
		 * Set Raw Bits
		 * Sets the raw stored integer value
		 */
		void	setRawBits(int const raw);
};

/*
 * Output Stream Operator Overload
 * Allows us to print Fixed objects using std::cout
 * This is a non-member function (not part of the class) because the left operand
 * is std::ostream, not a Fixed object.
 * 
 * @param out: Output stream to write to
 * @param value: Fixed object to print
 * @return: Reference to the output stream (allows chaining: cout << a << b)
 */
std::ostream&	operator<<(std::ostream& out, const Fixed& value);

#endif // FIXED_HPP
