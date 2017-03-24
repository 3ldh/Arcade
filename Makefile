##
## Makefile for MAKEFILE in /home/bougon_p
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Wed Jan  4 12:28:45 2017 bougon_p
## Last update Fri Mar 17 15:22:32 2017 Sauvau Mathieu
##

# USEFUL VARIABLES

DEBUG   =   	NO

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e

# SOURCES VARIABLES

SRC		=	$(wildcard srcs/*.cpp) \
        	$(wildcard gamesSrcs/snake/*.cpp) \
        	$(wildcard ArcadeInterfaces/*.cpp)

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
		make -C gfxLibsSrcs
		make -C gamesSrcs
		@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

compile     	:       $(OBJS)
ifeq ($(DEBUG), YES)
		@$(CC) -DDEBUG -o $(NAME) $(OBJS) $(LDFLAGS)
else
		@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
endif

all         	:       $(LIB)
		@make -j 4 -s compile

clean		:
		@$(RM) $(OBJS)

fclean		: 	clean
		@$(RM) $(NAME)

re  		:	fclean all


.cpp.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "[$(GREEN)OK$(WHITE)] > $<\t \t "


.PHONY		:	all compile all clean fclean re
