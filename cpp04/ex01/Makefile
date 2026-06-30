# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/30 09:30:00 by ruiferna          #+#    #+#              #
#    Updated: 2026/06/30 11:26:53 by ruiferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            =       brain

CC                      =       c++
CXXFLAGS        =       -Wall -Wextra -Werror -std=c++98

SRCS            =       main.cpp \
								Animal.cpp \
								Dog.cpp \
								Cat.cpp \
								WrongAnimal.cpp \
								WrongCat.cpp \
								Brain.cpp

OBJS            =       $(SRCS:.cpp=.o)

all:            $(NAME)

$(NAME):        $(OBJS)
						$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)
						@echo "✓ Executable '$(NAME)' created successfully!"

%.o:            %.cpp
						$(CC) $(CXXFLAGS) -c $< -o $@

clean:
						@rm -f $(OBJS)
						@echo "✓ Object files cleaned!"

fclean:         clean
						@rm -f $(NAME)
						@echo "✓ Executable '$(NAME)' removed!"

re:                     fclean all

.PHONY:         all clean fclean re