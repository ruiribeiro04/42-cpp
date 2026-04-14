# include "Point.hpp"

/*
 * Main test function for Exercise 03 - BSP (Binary Space Partitioning)
 * 
 * This program tests the bsp() function which determines whether a point
 * is inside a triangle.
 * 
 * We test various scenarios:
 * 1. Point clearly inside the triangle
 * 2. Point clearly outside the triangle
 * 3. Point on a vertex (should return false)
 * 4. Point on an edge (should return false)
 * 5. Points near edges
 */
int	main(void)
{
	std::cout << "=== BSP (Binary Space Partitioning) Tests ===" << std::endl;
	std::cout << std::endl;
	
	// Define a simple triangle: (0,0), (10,0), (5,10)
	// This is an isosceles triangle with base along the x-axis
	Point	const a(0.0f, 0.0f);
	Point	const b(10.0f, 0.0f);
	Point	const c(5.0f, 10.0f);
	
	std::cout << "Triangle vertices:" << std::endl;
	std::cout << "  A = (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "  B = (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "  C = (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	std::cout << std::endl;
	
	// Test 1: Point clearly inside the triangle (centroid area)
	// Centroid would be at (5, 3.33), let's use (5, 3)
	Point	const	inside(5.0f, 3.0f);
	std::cout << "Test 1: Point inside triangle" << std::endl;
	std::cout << "  Point = (" << inside.getX() << ", " << inside.getY() << ")" << std::endl;
	std::cout << "  Result: " << (bsp(a, b, c, inside) ? "INSIDE ✓" : "OUTSIDE ✗") << std::endl;
	std::cout << std::endl;
	
	// Test 2: Point clearly outside the triangle
	Point	const	outside(15.0f, 15.0f);
	std::cout << "Test 2: Point outside triangle" << std::endl;
	std::cout << "  Point = (" << outside.getX() << ", " << outside.getY() << ")" << std::endl;
	std::cout << "  Result: " << (bsp(a, b, c, outside) ? "INSIDE ✗" : "OUTSIDE ✓") << std::endl;
	std::cout << std::endl;
	
	// Test 3: Point on vertex A (should return false per subject)
	Point	const	onVertex(0.0f, 0.0f);
	std::cout << "Test 3: Point on vertex A" << std::endl;
	std::cout << "  Point = (" << onVertex.getX() << ", " << onVertex.getY() << ")" << std::endl;
	std::cout << "  Result: " << (bsp(a, b, c, onVertex) ? "INSIDE ✗" : "OUTSIDE ✓") << std::endl;
	std::cout << "  (Should be OUTSIDE - point on vertex returns false)" << std::endl;
	std::cout << std::endl;
	
	// Test 4: Point on edge AB (should return false per subject)
	Point	const	onEdge(5.0f, 0.0f);
	std::cout << "Test 4: Point on edge AB" << std::endl;
	std::cout << "  Point = (" << onEdge.getX() << ", " << onEdge.getY() << ")" << std::endl;
	std::cout << "  Result: " << (bsp(a, b, c, onEdge) ? "INSIDE ✗" : "OUTSIDE ✓") << std::endl;
	std::cout << "  (Should be OUTSIDE - point on edge returns false)" << std::endl;
	std::cout << std::endl;
	
	// Test 5: Another point inside
	Point	const	inside2(3.0f, 2.0f);
	std::cout << "Test 5: Another point inside triangle" << std::endl;
	std::cout << "  Point = (" << inside2.getX() << ", " << inside2.getY() << ")" << std::endl;
	std::cout << "  Result: " << (bsp(a, b, c, inside2) ? "INSIDE ✓" : "OUTSIDE ✗") << std::endl;
	std::cout << std::endl;
	
	// Test 6: Point outside but close to edge
	Point	const	outside2(5.0f, -0.1f);
	std::cout << "Test 6: Point outside (just below base)" << std::endl;
	std::cout << "  Point = (" << outside2.getX() << ", " << outside2.getY() << ")" << std::endl;
	std::cout << "  Result: " << (bsp(a, b, c, outside2) ? "INSIDE ✗" : "OUTSIDE ✓") << std::endl;
	std::cout << std::endl;
	
	// Test 7: Point at centroid (should be inside)
	Point	const	centroid(5.0f, 3.333333f);
	std::cout << "Test 7: Point at centroid (approximately)" << std::endl;
	std::cout << "  Point = (" << centroid.getX() << ", " << centroid.getY() << ")" << std::endl;
	std::cout << "  Result: " << (bsp(a, b, c, centroid) ? "INSIDE ✓" : "OUTSIDE ✗") << std::endl;
	std::cout << std::endl;
	
	std::cout << "=== All Tests Complete ===" << std::endl;
	
	return (0);
}
