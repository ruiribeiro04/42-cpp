# include "Point.hpp"

/*
 * Default Constructor
 * Initializes point to origin (0, 0)
 * 
 * Note: We use constructor initializer list to initialize const members.
 * This is required because const members MUST be initialized in the initializer list,
 * not in the constructor body.
 */
Point::Point(void) : _x(0), _y(0)
{
}

/*
 * Parameterized Constructor
 * Creates a point with the given coordinates.
 * 
 * Again, we use the initializer list because _x and _y are const.
 */
Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

/*
 * Copy Constructor
 * Creates a copy of another point.
 */
Point::Point(const Point& other) : _x(other._x), _y(other._y)
{
}

/*
 * Copy Assignment Operator
 * 
 * This is interesting! Since _x and _y are const, we can't modify them.
 * But we still need to provide this operator for the Orthodox Canonical Form.
 * 
 * The trick: We can't actually assign, but we can return *this.
 * In practice, this operator won't be very useful for const members,
 * but it satisfies the OCF requirement.
 * 
 * Note: Some compilers might warn about this, but it's technically correct.
 * The const members are already initialized in the constructor, and
 * we can't change them, which is fine - we just return the current object.
 */
Point&	Point::operator=(const Point& other)
{
	// We can't modify _x and _y because they're const
	// But we still need to return *this to satisfy the interface
	(void)other;	// Suppress unused parameter warning
	return (*this);
}

/*
 * Destructor
 */
Point::~Point(void)
{
}

/*
 * Get X Coordinate
 * Returns a copy of the x coordinate (the original is const)
 */
Fixed	Point::getX(void) const
{
	return (this->_x);
}

/*
 * Get Y Coordinate
 * Returns a copy of the y coordinate (the original is const)
 */
Fixed	Point::getY(void) const
{
	return (this->_y);
}
