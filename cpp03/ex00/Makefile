# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruizenna <ruizenna@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 15:20:00 by ruizenna          #+#    #+#              #
#    Updated: 2025/04/11 15:20:00 by ruizenna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME		=	claptrap

# Compiler
CC			=	c++

# Compiler flags
# -Wall: Enable all warnings
# -Wextra: Enable extra warnings
# -Werror: Turn warnings into errors
# -std=c++98: Use C++98 standard (required by 42 curriculum)
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

# Source files
SRCS		=	main.cpp \
				ClapTrap.cpp

# Object files (generated from SRCS)
OBJS		=	$(SRCS:.cpp=.o)

# Default target: build the executable
all:		$(NAME)

# Link object files to create executable
$(NAME):	$(OBJS)
			$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)
			@echo "✓ Executable '$(NAME)' created successfully!"

# Compile source files to object files
# This rule is implicit but shown here for clarity
%.o:		%.cpp
			$(CC) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
			@rm -f $(OBJS)
			@echo "✓ Object files cleaned!"

# Clean object files and executable
fclean:		clean
			@rm -f $(NAME)
			@echo "✓ Executable '$(NAME)' removed!"

# Rebuild everything from scratch
re:			fclean all

# Prevent Makefile from trying to delete these files
.PHONY:		all clean fclean re
