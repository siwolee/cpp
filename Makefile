# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:53:40 by juhyulee          #+#    #+#              #
#    Updated: 2023/10/04 19:14:05 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 #-fsanitize=address
RM = rm -f

SRCS = 
OBJS = $(SRCS:.c=.o)
INC = $(SRCS:.c=.h)

all : 		$(NAME)

$(NAME) :	$(OBJS) $(INC)
			@echo $(SRCS) 
			@$(CXX) $(CXXFLAGS) main.cpp $(OBJS) -o $(NAME)
			@echo "🌹ALL compiled"

%.o : %.c $(INC)
			@$(CXX) $(CXXFLAGS) -c $< -o $@
 
clean :	
			@rm -rf miniRT.dSYM
			@$(RM) $(NAME)
			@echo "💔cleaned everything"

re :		clean all

.PHONY : all clean re

