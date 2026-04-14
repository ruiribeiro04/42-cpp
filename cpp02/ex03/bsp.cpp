# include "Point.hpp"
# include <cmath>

/*
 * Binary Space Partitioning (BSP) - Point in Triangle Test
 * 
 * This function determines whether a given point is inside a triangle.
 * It uses the barycentric coordinate system approach.
 * 
 * ALGORITHM EXPLANATION:
 * =====================
 * 
 * A triangle has 3 vertices: a, b, c
 * We want to check if 'point' is inside this triangle.
 * 
 * The method:
 * 1. Calculate the areas of 3 sub-triangles:
 *    - Area of triangle (point, b, c)
 *    - Area of triangle (a, point, c)
 *    - Area of triangle (a, b, point)
 * 
 * 2. Calculate the area of the main triangle (a, b, c)
 * 
 * 3. If the sum of the 3 sub-triangle areas equals the main triangle area,
 *    then the point is inside the triangle.
 * 
 * 4. If the point is exactly on an edge or vertex, it returns FALSE
 *    (as per subject requirements)
 * 
 * AREA CALCULATION:
 * =================
 * 
 * We use the cross product method to calculate triangle area:
 * 
 * For triangle with vertices (x1,y1), (x2,y2), (x3,y3):
 * Area = 0.5 * |(x2-x1)(y3-y1) - (x3-x1)(y2-y1)|
 * 
 * This is equivalent to:
 * Area = 0.5 * |cross_product(vector(v1,v2), vector(v1,v3))|
 * 
 * The absolute value ensures we always get a positive area.
 * 
 * EDGE CASES:
 * ===========
 * 
 * - Point on vertex: One of the sub-triangles will have area 0
 * - Point on edge: One of the sub-triangles will have area 0
 * - Point outside: Sum of sub-areas > main area
 * - Point inside: Sum of sub-areas = main area
 * 
 * The subject requires returning FALSE for points on edges/vertices,
 * so we use strict equality check.
 * 
 * FLOATING POINT PRECISION:
 * =========================
 * 
 * Since we're using fixed-point numbers, we have limited precision.
 * The comparison uses a small epsilon for floating-point comparison.
 * However, for this exercise, exact equality should work fine
 * because we're using consistent Fixed arithmetic.
 */
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Helper lambda to calculate the area of a triangle
	// Uses the cross product formula: |(x2-x1)(y3-y1) - (x3-x1)(y2-y1)| / 2
	// We skip the division by 2 since it cancels out in the comparison
	struct AreaCalculator
	{
		static Fixed calculate(Point const p1, Point const p2, Point const p3)
		{
			// Extract coordinates
			Fixed x1 = p1.getX();
			Fixed y1 = p1.getY();
			Fixed x2 = p2.getX();
			Fixed y2 = p2.getY();
			Fixed x3 = p3.getX();
			Fixed y3 = p3.getY();
			
			// Calculate cross product: (x2-x1)(y3-y1) - (x3-x1)(y2-y1)
			Fixed cross = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
			
			// Return absolute value
			// Note: Fixed doesn't have unary minus, so we use 0 - cross
			if (cross < 0)
				return (Fixed(0) - cross);
			return (cross);
		}
	};
	
	// Calculate the main triangle area (a, b, c)
	Fixed	mainArea = AreaCalculator::calculate(a, b, c);
	
	// Calculate the 3 sub-triangle areas
	Fixed	area1 = AreaCalculator::calculate(point, b, c);	// Triangle (point, b, c)
	Fixed	area2 = AreaCalculator::calculate(a, point, c);	// Triangle (a, point, c)
	Fixed	area3 = AreaCalculator::calculate(a, b, point);	// Triangle (a, b, point)
	
	// Sum of sub-areas
	Fixed	sumAreas = area1 + area2 + area3;
	
	// Check if point is inside triangle
	// Point is inside if: sum of sub-areas equals main area
	// AND none of the sub-areas is zero (point not on edge/vertex)
	
	// If any sub-area is zero, point is on an edge or vertex
	if (area1 == 0 || area2 == 0 || area3 == 0)
		return (false);
	
	// Check if sum equals main area
	// Use == for Fixed comparison since they have the same scale
	if (sumAreas == mainArea)
		return (true);
	
	return (false);
}
