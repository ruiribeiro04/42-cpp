# include "Fixed.hpp"
# include <stdexcept>

// ==========================================================================
// CONSTRUCTORS AND DESTRUCTOR
// ==========================================================================

Fixed::Fixed(void) : _fixedPointValue(0)
{
	// Silent constructor for ex02 (no messages)
}

Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue)
{
	// Silent copy constructor
}

Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits)
{
	// Silent int constructor
}

Fixed::Fixed(const float value) 
	: _fixedPointValue(static_cast<int>(roundf(value * (1 << _fractionalBits))))
{
	// Silent float constructor
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->_fixedPointValue = other._fixedPointValue;
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	// Silent destructor
}

// ==========================================================================
// CONVERSION FUNCTIONS
// ==========================================================================

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

// ==========================================================================
// GETTERS AND SETTERS
// ==========================================================================

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

// ==========================================================================
// COMPARISON OPERATORS
// ==========================================================================

/*
 * Greater Than Operator (>)
 * Returns true if this Fixed object's value is greater than the other's
 * We simply compare the raw integer values since they have the same scale
 */
bool	Fixed::operator>(const Fixed& other) const
{
	return (this->_fixedPointValue > other._fixedPointValue);
}

/*
 * Less Than Operator (<)
 * Returns true if this Fixed object's value is less than the other's
 */
bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_fixedPointValue < other._fixedPointValue);
}

/*
 * Greater Than or Equal Operator (>=)
 * Returns true if this Fixed object's value is greater than or equal to the other's
 */
bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->_fixedPointValue >= other._fixedPointValue);
}

/*
 * Less Than or Equal Operator (<=)
 * Returns true if this Fixed object's value is less than or equal to the other's
 */
bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_fixedPointValue <= other._fixedPointValue);
}

/*
 * Equality Operator (==)
 * Returns true if both Fixed objects have the same value
 */
bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_fixedPointValue == other._fixedPointValue);
}

/*
 * Inequality Operator (!=)
 * Returns true if the Fixed objects have different values
 */
bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_fixedPointValue != other._fixedPointValue);
}

// ==========================================================================
// ARITHMETIC OPERATORS
// ==========================================================================

/*
 * Addition Operator (+)
 * Adds two Fixed objects and returns a new Fixed object with the result.
 * Since both have the same scale (8 fractional bits), we can add raw values directly.
 */
Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;
	
	result._fixedPointValue = this->_fixedPointValue + other._fixedPointValue;
	return (result);
}

/*
 * Subtraction Operator (-)
 * Subtracts the other Fixed object from this one.
 * Again, same scale allows direct subtraction of raw values.
 */
Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;
	
	result._fixedPointValue = this->_fixedPointValue - other._fixedPointValue;
	return (result);
}

/*
 * Multiplication Operator (*)
 * Multiplies two Fixed objects.
 * 
 * This is tricky! When we multiply two fixed-point numbers:
 * - (a * 256) * (b * 256) = (a * b) * 65536 = (a * b) * 256 * 256
 * - We need to divide by 256 to get back to our scale
 * 
 * We use long long to avoid overflow during multiplication.
 */
Fixed	Fixed::operator*(const Fixed& other) const
{
	long long	tmp;
	Fixed		result;
	
	// Multiply as long long to prevent overflow
	tmp = static_cast<long long>(this->_fixedPointValue) 
		* static_cast<long long>(other._fixedPointValue);
	
	// Scale back by dividing by 256 (shift right by 8)
	result._fixedPointValue = static_cast<int>(tmp >> _fractionalBits);
	
	return (result);
}

/*
 * Division Operator (/)
 * Divides this Fixed object by another.
 * 
 * Similar to multiplication, we need to adjust the scale:
 * - (a * 256) / (b * 256) = a / b
 * - We want the result in our scale: (a / b) * 256
 * - So we multiply by 256 before dividing
 * 
 * Note: Division by zero will crash the program (as per subject requirements)
 */
Fixed	Fixed::operator/(const Fixed& other) const
{
	long long	tmp;
	Fixed		result;
	
	// Check for division by zero (optional, but good practice)
	if (other._fixedPointValue == 0)
	{
		// According to the subject, crashing is acceptable for division by zero
		// But let's at least make it explicit
		throw std::runtime_error("Division by zero in Fixed::operator/");
	}
	
	// Scale up by multiplying by 256, then divide
	tmp = static_cast<long long>(this->_fixedPointValue) << _fractionalBits;
	result._fixedPointValue = static_cast<int>(tmp / other._fixedPointValue);
	
	return (result);
}

// ==========================================================================
// INCREMENT/DECREMENT OPERATORS
// ==========================================================================

/*
 * Pre-increment Operator (++object)
 * Increments the Fixed object by the smallest representable value (epsilon).
 * Epsilon for our 8-bit fractional system is 1/256 = 0.00390625
 * 
 * Returns a reference to the incremented object (so we can chain like ++++a).
 */
Fixed&	Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return (*this);
}

/*
 * Pre-decrement Operator (--object)
 * Decrements the Fixed object by epsilon.
 * Returns a reference to the decremented object.
 */
Fixed&	Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return (*this);
}

/*
 * Post-increment Operator (object++)
 * Increments the Fixed object but returns the original value.
 * The int parameter is just a dummy to distinguish from pre-increment.
 * 
 * This is the behavior you expect from: int a = b++;
 * (a gets the old value, b gets incremented)
 */
Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);	// Save current state
	
	this->_fixedPointValue++;	// Increment
	return (tmp);				// Return old value
}

/*
 * Post-decrement Operator (object--)
 * Decrements the Fixed object but returns the original value.
 */
Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);	// Save current state
	
	this->_fixedPointValue--;	// Decrement
	return (tmp);				// Return old value
}

// ==========================================================================
// STATIC MIN/MAX FUNCTIONS
// ==========================================================================

/*
 * Min Function (Non-const Version)
 * Returns a reference to the smaller of two Fixed objects.
 * This version can modify the objects through the returned reference.
 */
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

/*
 * Max Function (Non-const Version)
 * Returns a reference to the larger of two Fixed objects.
 */
Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

/*
 * Min Function (Const Version)
 * Returns a const reference to the smaller of two Fixed objects.
 * This version is used when the objects are const (cannot be modified).
 */
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

/*
 * Max Function (Const Version)
 * Returns a const reference to the larger of two Fixed objects.
 */
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

// ==========================================================================
// OUTPUT STREAM OPERATOR
// ==========================================================================

std::ostream&	operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return (out);
}
