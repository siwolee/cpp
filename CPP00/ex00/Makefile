# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:53:40 by juhyulee          #+#    #+#              #
#    Updated: 2023/09/27 16:09:06 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 
RM = rm -f

SRCS = megaphone.cpp

OBJS = $(SRC:.cpp=.o)

# HEADER = -I./header

all : 		$(NAME)

$(NAME) :	$(SRCS) 
			@echo $(SRCS)
			@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
			@echo "🌹ALL compiled"
clean :
			@$(RM) $(NAME)
			@echo "💔nothing to be cleaned"

fclean :	
			@rm -rf miniRT.dSYM
			@$(RM) $(NAME)
			@echo "💔cleaned everything"

re :		fclean all

.PHONY : all clean fclean re 

