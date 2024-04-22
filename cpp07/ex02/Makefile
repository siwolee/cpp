NAME		= ex

FILES		= main
SRCSDIR		= ./
SRCS		= $(FILES:%=$(SRCSDIR)%.cpp)

OBJSDIR		= ./.obj/
OBJS		= $(FILES:%=$(OBJSDIR)%.o)

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -I./
DBFLAGS		=

RM			= rm -rf

ifdef DEBUG
	DBFLAGS	+= -fsanitize=address -g3
	# NAME	= $(addsuffix _debug, $(NAME))
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(DBFLAGS) -o $@ $^

$(OBJS): $(OBJSDIR)%.o : $(SRCSDIR)%.cpp
	@mkdir -p $(OBJSDIR)
	$(CXX) $(CXXFLAGS) $(DBFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJSDIR)

fclean: clean
	$(RM) $(NAME)

debug:
	@$(MAKE) DEBUG=1 all

rebug: clean
	@$(MAKE) DEBUG=1 all

re: fclean all

.PHONY: all clean fclean debug rebug re