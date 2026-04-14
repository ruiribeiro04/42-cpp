# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruizenna <ruizenna@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 15:30:00 by ruizenna          #+#    #+#              #
#    Updated: 2025/04/11 15:30:00 by ruizenna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	scavtrap

CC			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp

OBJS		=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)
			@echo "✓ Executable '$(NAME)' created successfully!"

%.o:		%.cpp
			$(CC) $(CXXFLAGS) -c $< -o $@

clean:
			@rm -f $(OBJS)
			@echo "✓ Object files cleaned!"

fclean:		clean
			@rm -f $(NAME)
			@echo "✓ Executable '$(NAME)' removed!"

re:			fclean all

.PHONY:		all clean fclean re
