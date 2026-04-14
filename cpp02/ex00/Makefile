# *****************************************************************************
# Makefile for CPP02 Exercise 00 - Fixed Point Number Class
#
# This Makefile compiles the Fixed class implementation with proper C++98 flags
# *****************************************************************************

# Name of the executable output
NAME		=	fixed

# Compiler and flags
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

# Source files
SRCS		=	main.cpp Fixed.cpp

# Object files (generated from .cpp files)
OBJS		=	$(SRCS:.cpp=.o)

# Default target: build the executable
all:		$(NAME)

# Link object files to create the executable
$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compile source files to object files
%.o:		%.cpp Fixed.hpp
			$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files
clean:
			rm -f $(OBJS)

# Clean up object files and executable
fclean:		clean
			rm -f $(NAME)

# Rebuild everything from scratch
re:			fclean all

# Declare these as phony targets (they don't represent actual files)
.PHONY:		all clean fclean re
