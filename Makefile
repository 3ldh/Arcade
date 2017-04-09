##
## Makefile for MAKEFILE in /home/bougon_p
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Wed Jan  4 12:28:45 2017 bougon_p
## Last update Sun Apr 09 17:23:21 2017 
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
		@make -j4 -C gfxLibsSrcs/ncurses || make re -C gfxLibsSrcs/ncurses

sfml        :
		@make -j4 -C gfxLibsSrcs/sfml || make re -C gfxLibsSrcs/sfml

lapin       :
		@make -j4 -C gfxLibsSrcs/lapin || make re -C gfxLibsSrcs/lapin

gfx         :
		@make -j4 -C gfxLibsSrcs || make re -C gfxLibsSrcs

snake       :
		@make -j4 -C gamesSrcs/snake || make re -C gamesSrcs/snake

solarfox    :
		@make -j4 -C gamesSrcs/solarFox || make re -C gamesSrcs/solarFox

games       : 
		@make -j4 -C gamesSrcs || make re -C gamesSrcs

42          : $(NAME) games gfx

42re	    : 42fclean 42

42fclean:
		@make fclean -C gamesSrcs
		@make fclean -C gfxLibsSrcs

all         : $(LIB)
		@make -j4 -s compile

clean       :
		@$(RM) $(OBJS)

fclean      : clean
		@$(RM) $(NAME)

re          : fclean all


.cpp.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "[$(GREEN)OK$(WHITE)] > $<\t \t "


.PHONY		:	all compile all clean fclean re
