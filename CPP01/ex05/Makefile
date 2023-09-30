# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:53:40 by juhyulee          #+#    #+#              #
#    Updated: 2023/09/30 11:08:22 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 #-fsanitize=address
RM = rm -f

SRCS = main.cpp Harl.cpp

all : 		$(NAME)

$(NAME) :	$(SRCS) 
			@echo $(SRCS) 
			@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
			@echo "🌹ALL compiled"
 
fclean :	
			@rm -rf miniRT.dSYM
			@$(RM) $(NAME)
			@echo "💔cleaned everything"

re :		fclean all

.PHONY : all fclean re

