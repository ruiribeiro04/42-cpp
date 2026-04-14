# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruiferma <ruiferma@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 10:00:00 by ruiferma          #+#    #+#              #
#    Updated: 2025/04/11 10:00:00 by ruiferma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME = megaphone

# Compiler and flags
# -Wall: Enable all warnings
# -Wextra: Enable extra warnings
# -Werror: Treat warnings as errors
# -std=c++98: Use C++98 standard (required by 42)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRC = megaphone.cpp

# Object files (automatically generated from .cpp files)
OBJ = $(SRC:.cpp=.o)

# Default target: build the program
all: $(NAME)

# Link object files to create the executable
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJ)

# Remove object files and executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

# Declare these as phony targets (not actual files)
.PHONY: all clean fclean re
