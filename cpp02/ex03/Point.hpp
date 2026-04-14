#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

/*
 * Point Class - 2D Point with Fixed-Point Coordinates
 * 
 * This class represents a 2D point using fixed-point numbers for coordinates.
 * It follows the Orthodox Canonical Form and has const x and y members.
 * 
 * Exercise 03 uses this class to implement Binary Space Partitioning (BSP)
 * to determine if a point is inside a triangle.
 */
class Point
{
	private:
		Fixed const	_x;	// X coordinate (constant - cannot be modified after construction)
		Fixed const	_y;	// Y coordinate (constant - cannot be modified after construction)

	public:
		/*
		 * Default Constructor
		 * Initializes both coordinates to (0, 0)
		 */
		Point(void);

		/*
		 * Parameterized Constructor
		 * Creates a point with the given x and y coordinates.
		 * 
		 * @param x: X coordinate as float
		 * @param y: Y coordinate as float
		 */
		Point(const float x, const float y);

		/*
		 * Copy Constructor
		 * Creates a new point as a copy of an existing one
		 */
		Point(const Point& other);

		/*
		 * Copy Assignment Operator
		 * Note: This is tricky because _x and _y are const!
		 * We can't modify them after construction.
		 * However, we still need to implement this for OCF.
		 */
		Point&	operator=(const Point& other);

		/*
		 * Destructor
		 */
		~Point(void);

		/*
		 * Get X Coordinate
		 * Returns the x coordinate (cannot modify it since it's const)
		 */
		Fixed	getX(void) const;

		/*
		 * Get Y Coordinate
		 * Returns the y coordinate (cannot modify it since it's const)
		 */
		Fixed	getY(void) const;
};

/*
 * Binary Space Partitioning Function
 * Determines whether a point is inside a triangle.
 * 
 * @param a: First vertex of the triangle
 * @param b: Second vertex of the triangle
 * @param c: Third vertex of the triangle
 * @param point: The point to check
 * @return: true if point is inside triangle, false otherwise
 *          (Returns false if point is on edge or vertex)
 */
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif // POINT_HPP
