#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/*
 * Fixed Point Number Class
 * 
 * This class implements a fixed-point number representation with 8 fractional bits.
 * Fixed-point numbers offer a balance between performance and precision, useful
 * in computer graphics, sound processing, and scientific programming.
 * 
 * The value is stored as an integer, but represents the actual value divided by 2^8 (256).
 * For example: raw value 256 = 1.0, raw value 512 = 2.0, raw value 128 = 0.5
 */
class Fixed
{
	private:
		int					_fixedPointValue;	// The raw fixed-point number value
		static const int	_fractionalBits = 8;	// Number of fractional bits (always 8)

	public:
		/*
		 * Default Constructor
		 * Initializes the fixed-point number value to 0.
		 */
		Fixed(void);

		/*
		 * Copy Constructor
		 * Creates a new Fixed object as a copy of an existing one.
		 * @param other: The Fixed object to copy from
		 */
		Fixed(const Fixed& other);

		/*
		 * Copy Assignment Operator
		 * Assigns the value of one Fixed object to another.
		 * @param other: The Fixed object to copy from
		 * @return: Reference to the assigned object (allows chaining like a = b = c)
		 */
		Fixed&	operator=(const Fixed& other);

		/*
		 * Destructor
		 * Cleans up resources when the object is destroyed.
		 */
		~Fixed(void);

		/*
		 * Get Raw Bits
		 * Returns the raw value of the fixed-point number.
		 * This is the actual integer stored, not the floating-point value.
		 * @return: The raw fixed-point value
		 */
		int		getRawBits(void) const;

		/*
		 * Set Raw Bits
		 * Sets the raw value of the fixed-point number.
		 * @param raw: The raw value to set
		 */
		void	setRawBits(int const raw);
};

#endif // FIXED_HPP
