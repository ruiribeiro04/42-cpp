#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

/*
 * Fixed Point Number Class - Full Operator Overloading
 * 
 * Exercise 02 adds comprehensive operator overloading:
 * - 6 comparison operators: >, <, >=, <=, ==, !=
 * - 4 arithmetic operators: +, -, *, /
 * - 4 increment/decrement operators: ++, -- (pre and post versions)
 * - 4 static min/max functions (const and non-const versions)
 * 
 * This makes Fixed objects behave like built-in numeric types!
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

		// *** Comparison Operators ***
		// These allow us to compare Fixed objects just like numbers
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		// *** Arithmetic Operators ***
		// These allow us to perform mathematical operations on Fixed objects
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		// *** Increment/Decrement Operators ***
		// Pre-increment: ++object (increments, then returns the incremented value)
		Fixed&	operator++(void);
		
		// Pre-decrement: --object (decrements, then returns the decremented value)
		Fixed&	operator--(void);
		
		// Post-increment: object++ (returns current value, then increments)
		// The int parameter is a dummy to distinguish from pre-increment
		Fixed	operator++(int);
		
		// Post-decrement: object-- (returns current value, then decrements)
		Fixed	operator--(int);

		// *** Static Min/Max Functions ***
		// These return references to the smallest or largest of two Fixed objects
		// Non-const versions (for modifiable objects)
		static Fixed&			min(Fixed& a, Fixed& b);
		static Fixed&			max(Fixed& a, Fixed& b);
		
		// Const versions (for const objects)
		static const Fixed&		min(const Fixed& a, const Fixed& b);
		static const Fixed&		max(const Fixed& a, const Fixed& b);
};

/*
 * Output Stream Operator (from Exercise 01)
 */
std::ostream&	operator<<(std::ostream& out, const Fixed& value);

#endif // FIXED_HPP
