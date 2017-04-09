##
## Makefile for MAKEFILE in /home/bougon_p
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Wed Jan  4 12:28:45 2017 bougon_p
## Last update Fri Apr 07 19:34:08 2017
##

# USEFUL VARIABLES

DEBUG   =   	NO

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e

# SOURCES VARIABLES

SRC		=	$(wildcard srcs/*.cpp) \
        	$(wildcard arcadeInterfaces/*.cpp)

OBJS    	=	$(SRC:.cpp=.o)


# PROJECT VARIABLES

NAME	    =   arcade

LDFLAGS     = -ldl

CXXFLAGS    =	-W -Wall -Wextra --std=c++14 \
                -Iinclude/ \

ifeq ($(DEBUG), YES)
CXXFLAGS	+= -g
endif


CC          =	g++ $(CXXFLAGS)


# PROJECT RULES

$(NAME)		: 	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

compile     	:       $(OBJS)
ifeq ($(DEBUG), YES)
		@$(CC) -DDEBUG -o $(NAME) $(OBJS) $(LDFLAGS)
else
		@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
endif

ncurse		:
		@make re -C gfxLibsSrcs/ncurses

sfml        :
		@make re -C gfxLibsSrcs/sfml

lapin       :
		@make re -C gfxLibsSrcs/lapin

gfx         : sfml lapin ncurse

snake       :
		@make re -C gamesSrcs/snake

solarfox    :
		@make re -C gamesSrcs/solarFox

games       : snake solarfox

42          : all games gfx

all         : $(LIB)
		@make -j 4 -s compile

clean       :
		@$(RM) $(OBJS)

fclean      : clean
		@$(RM) $(NAME)

re          : fclean all


.cpp.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "[$(GREEN)OK$(WHITE)] > $<\t \t "


.PHONY		:	all compile all clean fclean re
