# include "Fixed.hpp"
# include <stdexcept>

// ==========================================================================
// CONSTRUCTORS AND DESTRUCTOR
// ==========================================================================

Fixed::Fixed(void) : _fixedPointValue(0)
{
}

Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue)
{
}

Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits)
{
}

Fixed::Fixed(const float value) 
	: _fixedPointValue(static_cast<int>(roundf(value * (1 << _fractionalBits))))
{
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

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->_fixedPointValue > other._fixedPointValue);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_fixedPointValue < other._fixedPointValue);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->_fixedPointValue >= other._fixedPointValue);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_fixedPointValue <= other._fixedPointValue);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_fixedPointValue == other._fixedPointValue);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_fixedPointValue != other._fixedPointValue);
}

// ==========================================================================
// ARITHMETIC OPERATORS
// ==========================================================================

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;
	result._fixedPointValue = this->_fixedPointValue + other._fixedPointValue;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;
	result._fixedPointValue = this->_fixedPointValue - other._fixedPointValue;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	long long	tmp;
	Fixed		result;
	
	tmp = static_cast<long long>(this->_fixedPointValue) 
		* static_cast<long long>(other._fixedPointValue);
	result._fixedPointValue = static_cast<int>(tmp >> _fractionalBits);
	
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	long long	tmp;
	Fixed		result;
	
	if (other._fixedPointValue == 0)
	{
		throw std::runtime_error("Division by zero in Fixed::operator/");
	}
	
	tmp = static_cast<long long>(this->_fixedPointValue) << _fractionalBits;
	result._fixedPointValue = static_cast<int>(tmp / other._fixedPointValue);
	
	return (result);
}

// ==========================================================================
// INCREMENT/DECREMENT OPERATORS
// ==========================================================================

Fixed&	Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->_fixedPointValue++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_fixedPointValue--;
	return (tmp);
}

// ==========================================================================
// STATIC MIN/MAX FUNCTIONS
// ==========================================================================

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

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
