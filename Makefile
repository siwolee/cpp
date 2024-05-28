# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 09:06:28 by siwolee           #+#    #+#              #
#    Updated: 2024/04/15 11:46:31 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ex

FILE	=   main
SRCDIR = 
SRC		=   $(addprefix $(FILE), .cpp)
SRCS	=	$(addprefix $(SRCDIR), $(SRC))

OBJDIR	=	.obj/
OBJ		=	$(addprefix $(FILE), .o)
OBJS	=	$(addprefix $(OBJDIR), $(OBJ))

CXX		=	c++
CXXFLAGS=   -Wall -Wextra -Werror -std=c++98
DBFLAGS =
RM		=	rm -rf

ifdef	DEBUG
		DBFLAGS		+=	-fsanitize=address -g3
		NAME		=	$(addsuffix _debug, $(NAME))
endif

all	:	$(OBJDIR) $(NAME)

$(OBJDIR)	:
	@mkdir $(OBJDIR)

$(NAME)		:	$(OBJS)
			$(CXX) $(CXXFLAGS) $(DBFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)%.o	:	$(SRCSDIR)%.cpp
			$(CXX) $(CXXFLAGS) $(DBFLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJDIR) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

debug	:
			@make DEBUG=1 all

rebug	:	clean
			@make DEBUG=1 all

re	:	fclean all

.PHONY	:	all clean fclean debug rebug re
