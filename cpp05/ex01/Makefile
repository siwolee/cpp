# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 09:06:28 by siwolee           #+#    #+#              #
#    Updated: 2023/11/20 21:29:27 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ex

FILE	=	main \
			Bureaucrat \
			Form \
			
SRCSDIR = ./
SRC		=  	$(addsuffix .cpp, $(FILE))
SRCS	=	$(addprefix $(SRCDIR), $(SRC))

OBJSDIR	=	obj/
OBJ		=	$(addsuffix .o, $(FILE))
OBJS	=	$(addprefix $(OBJSDIR), $(OBJ))

CXX		=	c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
DBFLAGS =
RM		=	rm -rf

ifdef	DEBUG
		DBFLAGS		+=	-fsanitize=address -g3
		# NAME		=	$(addsuffix _debug, $(NAME))
endif

all	:	$(OBJSDIR) $(NAME)

$(OBJSDIR)	:
	@mkdir $(OBJSDIR)
	@echo $(FILE)
	@echo $(SRCS) 
	@echo $(OBJS)

$(NAME)		:	$(OBJS)
			$(CXX) $(CXXFLAGS) $(DBFLAGS) -o $(NAME) $(OBJS)

$(OBJSDIR)%.o	:	$(SRCSDIR)%.cpp
			$(CXX) $(CXXFLAGS) $(DBFLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJSDIR) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

debug	:
			@make DEBUG=1 all

rebug	:	fclean
			@make DEBUG=1 all

re	:	fclean all

.PHONY	:	all clean fclean debug rebug re
