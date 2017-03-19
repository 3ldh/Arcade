##
## Makefile for  in /home/sauvau_m/rendu/cpp_arcade/gfxLibsSrcs/sfml
##
## Made by Sauvau Mathieu
## Login   <mathieu.sauvau@epitech.eu>
##
## Started on  Fri Mar 17 15:12:36 2017 Sauvau Mathieu
## Last update Sun Mar 19 13:05:33 2017 Sauvau Mathieu
##

# USEFUL VARIABLES

DEBUG   =   	NO

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e

# SOURCES VARIABLES

SRC		=	$(wildcard ./*.cpp) \
            ../../srcs/Exception.cpp \
            ../../srcs/Unit.cpp \
            ../../srcs/Layer.cpp \
            ../../srcs/Map.cpp \
            ../../srcs/Tile.cpp \
            ../../srcs/GUI.cpp \


OBJS    	=	$(SRC:.cpp=.o)


# PROJECT VARIABLES

NAME	    =   ../../games/lib_arcade_snake.so

LDFLAGS     =	-shared \

CXXFLAGS    =	-W -Wall -Wextra --std=c++11 \
		-std=c++11 \
		-fPIC \
		-I../ArcadeInterfaces \
		-I../include \

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
