# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:53:40 by juhyulee          #+#    #+#              #
#    Updated: 2023/10/05 19:52:47 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 #-fsanitize=address
RM = rm -f

SRCS = Animal.cpp Dog.cpp Cat.cpp
OBJS = $(SRCS:.cpp=.o) main.o
INC = $(SRCS:.cpp=.hpp)

all : 		$(NAME)

$(NAME) :	$(OBJS) $(INC)
			@echo $(SRCS) 
			@$(CXX) $(CXXFLAGS) main.o $(OBJS) -o $(NAME)
			@echo "🌹ALL compiled"

%.o : %.c $(INC)
			@$(CXX) $(CXXFLAGS) -c $< -o $@
 
clean :	
			@rm -rf miniRT.dSYM
			@$(RM) $(NAME)
			@echo "💔cleaned everything"

re :		clean all

.PHONY : all clean re

