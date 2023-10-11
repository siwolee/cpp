# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 17:53:40 by juhyulee          #+#    #+#              #
#    Updated: 2023/10/11 20:12:59 by siwolee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g3 #-fsanitize=address
RM = rm -f

SRCS = Cure.cpp Character.cpp AMateria.cpp Ice.cpp MateriaSource.cpp IMateriaSource.cpp
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

