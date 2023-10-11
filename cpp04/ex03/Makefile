# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:53:40 by juhyulee          #+#    #+#              #
#    Updated: 2023/10/10 21:32:57 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 #-fsanitize=address
RM = rm -f

SRCS = Cure.cpp Character.cpp AMateria.cpp Ice.cpp
OBJS = $(SRCS:.cpp=.o) main.o
INC = $(SRCS:.cpp=.hpp)

all : 		$(NAME)

$(NAME) :	$(OBJS) $(INC)
			@echo $(SRCS) 
			@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
			@echo "🌹ALL compiled"

%.o : %.cpp $(INC)
			@$(CXX) $(CXXFLAGS) -c $< -o $@
 
clean :	
			@rm -rf $(OBJS) miniRT.dSYM
			@echo "💔cleaned OBJS"

fclean :	clean
			@$(RM) $(NAME)
			@echo "💔cleaned everything"

re :		fclean all

.PHONY : all clean re fclean

