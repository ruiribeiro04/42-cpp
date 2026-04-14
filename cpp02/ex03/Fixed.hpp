#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

/*
 * Fixed Point Number Class
 * 
 * This is the same fully-featured Fixed class from Exercise 02.
 * We reuse it for Exercise 03 to work with 2D points.
 */
class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		// Constructors and Destructor
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed(const int value);
		Fixed(const float value);
		Fixed&	operator=(const Fixed& other);
		~Fixed(void);

		// Conversion functions
		float	toFloat(void) const;
		int		toInt(void) const;

		// Getters and Setters
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		// Comparison Operators
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		// Arithmetic Operators
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		// Increment/Decrement Operators
		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		// Static Min/Max Functions
		static Fixed&			min(Fixed& a, Fixed& b);
		static Fixed&			max(Fixed& a, Fixed& b);
		static const Fixed&		min(const Fixed& a, const Fixed& b);
		static const Fixed&		max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& out, const Fixed& value);

#endif // FIXED_HPP
