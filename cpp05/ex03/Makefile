# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruiferna <ruiferna@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/05 12:00:00 by ruiferna         #+#    #+#              #
#    Updated: 2026/09/05 12:00:00 by ruiferna        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# shellcheck disable=SC2283,SC2276,SC2068  # This is a Makefile, not a shell script; rules misparse Make syntax

NAME		=	intern

CC			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \
				Bureaucrat.cpp \
				AForm.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \
				Intern.cpp

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
			@rm -f *_shrubbery
			@echo "✓ Executable '$(NAME)' removed!"
			@echo "✓ Shrubbery files cleaned!"

re:			fclean all

.PHONY:		all clean fclean re
