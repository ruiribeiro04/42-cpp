# CPP02 - Ad-hoc Polymorphism, Operator Overloading and Orthodox Canonical Form

## Overview

This module implements a fixed-point number class in C++98, progressively adding features from basic Orthodox Canonical Form to full operator overloading and Binary Space Partitioning.

## Fixed-Point Numbers

Fixed-point numbers are a way to represent decimal values using integers. Instead of storing a value as a floating-point number, we store it as an integer with a fixed number of fractional bits.

**Why Fixed-Point?**
- More predictable than floating-point (no precision surprises)
- Faster on hardware without FPU (though less relevant today)
- Used in computer graphics, sound processing, and financial calculations

**How It Works:**
- We use 8 bits for the fractional part (2^8 = 256)
- To convert float to fixed: `value * 256` (and round)
- To convert fixed to float: `value / 256`
- Example: `5.5` becomes `5.5 * 256 = 1408`

## Directory Structure

```
cpp02/
├── ex00/  - Basic Orthodox Canonical Form
├── ex01/  - Constructors and conversions
├── ex02/  - Operator overloading
└── ex03/  - BSP (Binary Space Partitioning)
```

## Exercise 00: My First OCF Class

**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, `Makefile`

**Concepts:**
- Orthodox Canonical Form (4 required member functions)
- Private vs public members
- Static constant members
- Basic class structure

**Key Implementation:**
```cpp
class Fixed {
private:
    int _fixedPointValue;           // Raw fixed-point value
    static const int _fractionalBits = 8;  // Always 8 bits

public:
    Fixed();                        // Default constructor
    Fixed(const Fixed& other);      // Copy constructor
    Fixed& operator=(const Fixed& other);  // Assignment operator
    ~Fixed();                       // Destructor
    
    int getRawBits() const;         // Getter
    void setRawBits(int raw);       // Setter
};
```

**Testing:**
```bash
cd ex00
make
./fixed
```

## Exercise 01: Enhanced Fixed Class

**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, `Makefile`

**New Features:**
- Integer constructor: `Fixed(5)` → `5 << 8 = 1280`
- Float constructor: `Fixed(5.5f)` → `roundf(5.5 * 256) = 1408`
- `toFloat()`: Convert back to float
- `toInt()`: Extract integer part (shift right)
- `operator<<`: Output stream overload

**Conversion Examples:**
```cpp
Fixed a(10);        // Integer: 10 * 256 = 2560
Fixed b(42.42f);    // Float: 42.42 * 256 = 10860
std::cout << a;     // Prints: 10
std::cout << b;     // Prints: 42.4219 (precision limited by 8 bits)
std::cout << b.toInt();  // Prints: 42
```

**Testing:**
```bash
cd ex01
make
./fixed
```

## Exercise 02: Operator Overloading

**Files:** `Fixed.hpp`, `Fixed.cpp`, `main.cpp`, `Makefile`

**Operators Implemented:**

### Comparison Operators (6)
```cpp
bool operator>(const Fixed& other) const;
bool operator<(const Fixed& other) const;
bool operator>=(const Fixed& other) const;
bool operator<=(const Fixed& other) const;
bool operator==(const Fixed& other) const;
bool operator!=(const Fixed& other) const;
```

### Arithmetic Operators (4)
```cpp
Fixed operator+(const Fixed& other) const;  // Add raw values
Fixed operator-(const Fixed& other) const;  // Subtract raw values
Fixed operator*(const Fixed& other) const;  // Multiply (adjust scale)
Fixed operator/(const Fixed& other) const;  // Divide (adjust scale)
```

**Multiplication Trick:**
When multiplying fixed-point numbers, we need to adjust the scale:
```cpp
(a * 256) * (b * 256) = (a * b) * 65536
We want: (a * b) * 256
So: divide by 256 (shift right by 8)
```

### Increment/Decrement Operators (4)
```cpp
Fixed& operator++();    // Pre-increment: ++a
Fixed& operator--();    // Pre-decrement: --a
Fixed operator++(int);  // Post-increment: a++
Fixed operator--(int);  // Post-decrement: a--
```

**Epsilon (smallest increment):** `1/256 = 0.00390625`

### Static Min/Max Functions (4)
```cpp
static Fixed& min(Fixed& a, Fixed& b);
static Fixed& max(Fixed& a, Fixed& b);
static const Fixed& min(const Fixed& a, const Fixed& b);
static const Fixed& max(const Fixed& a, const Fixed& b);
```

**Testing:**
```bash
cd ex02
make
./fixed
```

## Exercise 03: BSP (Binary Space Partitioning)

**Files:** `Fixed.hpp`, `Fixed.cpp`, `Point.hpp`, `Point.cpp`, `bsp.cpp`, `main.cpp`, `Makefile`

**Point Class:**
```cpp
class Point {
private:
    Fixed const _x;  // Constant X coordinate
    Fixed const _y;  // Constant Y coordinate

public:
    Point();                              // (0, 0)
    Point(float x, float y);              // (x, y)
    Point(const Point& other);            // Copy constructor
    Point& operator=(const Point& other);  // Assignment
    ~Point();                             // Destructor
    
    Fixed getX() const;
    Fixed getY() const;
};
```

**BSP Algorithm:**
Determines if a point is inside a triangle using area comparison:

1. Calculate area of main triangle (a, b, c)
2. Calculate areas of 3 sub-triangles:
   - (point, b, c)
   - (a, point, c)
   - (a, b, point)
3. Point is inside if: `area1 + area2 + area3 == mainArea`
4. Returns `false` if point is on edge or vertex (per subject)

**Area Calculation:**
```
Area = |(x2-x1)(y3-y1) - (x3-x1)(y2-y1)| / 2
We skip division by 2 since it cancels out in comparison
```

**Testing:**
```bash
cd ex03
make
./bsp
```

## Compilation

All exercises use the same compilation flags:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

**No C++11+ features allowed:**
- ❌ No `auto`
- ❌ No smart pointers
- ❌ No lambda expressions
- ❌ No range-based for loops
- ✅ C++98 only

## Key Learning Points

### Orthodox Canonical Form
Every class needs these 4 special member functions:
1. **Default constructor** - Initialize object to default state
2. **Copy constructor** - Create object from another of same type
3. **Copy assignment operator** - Assign one object to another
4. **Destructor** - Clean up resources

### Const Correctness
- `const` methods don't modify object: `int get() const`
- `const` references prevent modification: `const Fixed&`
- `const` members can only be initialized in constructor initializer list

### Operator Overloading
- Makes classes behave like built-in types
- Comparison operators return `bool`
- Arithmetic operators return new objects
- Increment/decrement have pre/post versions (distinguished by dummy `int` parameter)
- `operator<<` is implemented as non-member function

### Static Members
- `static const int` = class-wide constant (shared by all instances)
- Static methods don't need an object instance: `Fixed::min(a, b)`

## Common Pitfalls

1. **Self-assignment in operator=**
   ```cpp
   Fixed& operator=(const Fixed& other) {
       if (this != &other)  // Always check!
           this->_value = other._value;
       return *this;
   }
   ```

2. **Const members in assignment operator**
   - Can't modify const members after construction
   - Return `*this` anyway for interface compliance

3. **Fixed-point arithmetic overflow**
   - Use `long long` for intermediate calculations
   - Scale back after multiplication/division

4. **Floating-point comparison**
   - Direct `==` works for Fixed (same scale)
   - Be careful with float comparison in general

## Testing Each Exercise

```bash
# Exercise 00 - Basic OCF
cd ex00 && make && ./fixed

# Exercise 01 - Conversions
cd ex01 && make && ./fixed

# Exercise 02 - Operators
cd ex02 && make && ./fixed

# Exercise 03 - BSP
cd ex03 && make && ./bsp
```

## Clean Up

```bash
# Remove object files
make clean

# Remove object files and executable
make fclean

# Rebuild from scratch
make re
```

## Further Reading

- Fixed-point arithmetic in computer graphics
- Barycentric coordinate system
- Binary Space Partitioning algorithms
- C++98 vs C++11 differences

## Author Notes

This implementation emphasizes:
- ✅ Clear, verbose comments for learning
- ✅ Step-by-step explanations
- ✅ Educational code structure
- ✅ Comprehensive test cases
- ✅ Strict C++98 compliance

Perfect for junior developers learning C++ after C!
