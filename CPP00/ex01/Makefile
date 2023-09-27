# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:53:40 by siwolee           #+#    #+#              #
#    Updated: 2023/09/25 22:08:17 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 # -g3 #-fsanitize=address
RM = rm -f

SRCS = main.cpp phonebook.cpp Contact.cpp


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

