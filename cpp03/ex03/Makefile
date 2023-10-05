# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:53:40 by juhyulee          #+#    #+#              #
#    Updated: 2023/10/04 18:21:25 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamondTrap

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 #-fsanitize=address
RM = rm -f

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
INC = ClapTrap.hpp ScavTrap.hpp	FragTrap.hpp DiamondTrap.hpp

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

