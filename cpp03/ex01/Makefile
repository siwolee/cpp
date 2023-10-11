# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:53:40 by juhyulee          #+#    #+#              #
#    Updated: 2023/10/09 12:25:35 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scavtrap

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 #-fsanitize=address
RM = rm -f

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
INC = ClapTrap.hpp ScavTrap.hpp

all : 		$(NAME)

$(NAME) :	$(SRCS) $(INC)
			@echo $(SRCS) 
			@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
			@echo "🌹ALL compiled"
 
clean :	
			@rm -rf miniRT.dSYM
			@$(RM) $(NAME)
			@echo "💔cleaned everything"

re :		clean all

.PHONY : all clean re

