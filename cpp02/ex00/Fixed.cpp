# include "Fixed.hpp"

/*
 * Default Constructor Implementation
 * Initializes the fixed-point value to 0 and prints a message for learning purposes.
 */
Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*
 * Copy Constructor Implementation
 * Creates a copy of another Fixed object.
 * We use the assignment operator to avoid code duplication.
 */
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/*
 * Copy Assignment Operator Implementation
 * Assigns the value from another Fixed object to this one.
 * Important: We check for self-assignment (a = a) to avoid unnecessary work.
 * We return a reference to allow chaining (a = b = c).
 */
Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	// Self-assignment check: if we're assigning to ourselves, do nothing
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}
	
	// Return reference to this object (allows chaining)
	return (*this);
}

/*
 * Destructor Implementation
 * Called automatically when the object goes out of scope or is deleted.
 */
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/*
 * Get Raw Bits Implementation
 * Simply returns the stored raw value.
 * The 'const' keyword means this method doesn't modify the object.
 */
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

/*
 * Set Raw Bits Implementation
 * Sets the internal raw value to the provided integer.
 * This directly modifies the stored value without any conversion.
 */
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}
