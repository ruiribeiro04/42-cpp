# include "Fixed.hpp"

/*
 * Default Constructor
 * Initializes the fixed-point value to 0
 */
Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*
 * Copy Constructor
 * Creates a copy of another Fixed object
 */
Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

/*
 * Integer Constructor
 * Converts an integer to fixed-point representation.
 * 
 * How it works:
 * - We use bit shifting: value << 8 is equivalent to value * 256
 * - This makes room for 8 fractional bits
 * - Example: 5 << 8 = 1280 (which represents 5.0 in fixed-point)
 * 
 * Why bit shifting instead of multiplication?
 * - Bit shifting is faster and more explicit about our intent
 * - It clearly shows we're working with fixed-point representation
 */
Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

/*
 * Float Constructor
 * Converts a floating-point number to fixed-point representation.
 * 
 * How it works:
 * - We multiply by 256 (1 << 8) to convert to fixed-point
 * - We use roundf() to round to the nearest integer (not just truncate)
 * - Example: 42.42 * 256 = 10859.52 → rounds to 10860
 * 
 * Why round instead of truncate?
 * - Rounding gives us better precision
 * - 42.42f becomes 10860, which represents 42.421875 (very close!)
 */
Fixed::Fixed(const float value) : _fixedPointValue(static_cast<int>(roundf(value * (1 << _fractionalBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

/*
 * Copy Assignment Operator
 */
Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &other)
	{
		this->_fixedPointValue = other._fixedPointValue;
	}
	
	return (*this);
}

/*
 * Destructor
 */
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/*
 * Convert to Float
 * Converts the fixed-point value back to a floating-point number.
 * 
 * How it works:
 * - We divide the raw value by 256 to get the actual decimal value
 * - We cast to float to ensure floating-point division
 * - Example: 1280 / 256.0 = 5.0
 * 
 * The formula: raw_value / 2^8 = raw_value / 256 = actual_value
 */
float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits));
}

/*
 * Convert to Integer
 * Converts the fixed-point value to an integer.
 * 
 * How it works:
 * - We shift right by 8 bits, which divides by 256
 * - This discards the fractional part (like floor division)
 * - Example: 1280 >> 8 = 5, 1320 >> 8 = 5 (fractional part lost)
 * 
 * Why not just divide?
 * - Bit shifting is faster and more explicit
 * - It clearly shows we're extracting the integer part
 * - The fractional bits are simply discarded
 */
int	Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

/*
 * Get Raw Bits
 */
int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

/*
 * Set Raw Bits
 */
void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

/*
 * Output Stream Operator
 * Allows us to print Fixed objects directly
 * 
 * Example usage:
 *   Fixed a(5.5f);
 *   std::cout << a << std::endl;  // Prints: 5.5
 */
std::ostream&	operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return (out);
}
