##
## Makefile for  in /home/sauvau_m/rendu/cpp_arcade/gfxLibs/sfml
##
## Made by Sauvau Mathieu
## Login   <mathieu.sauvau@epitech.eu>
##
## Started on  Fri Mar 17 15:12:36 2017 Sauvau Mathieu
## Last update Fri Mar 17 15:26:20 2017 Sauvau Mathieu
##

# CXX		=	g++
# RM		=	rm -f


# # CXXFLAGS	+=	-I./deps/glew/include

# NAME		=	../lib/lib_arcade_sfml.so

# OBJS		=	$(SRCS:.cpp=.o)

# LDFLAGS		+=	-L./deps/glew/lib -lGLEW -lGLEWmx
# LDFLAGS		+=	-L./deps/SFML-2.2/lib -lsfml-audio
# LDFLAGS		+=	-lsfml-graphics -lsfml-window -lsfml-network -lsfml-system
# LDFLAGS		+=	-Wl,--rpath=./deps/glew/lib/
# LDFLAGS		+=	-Wl,--rpath=./deps/SFML-2.2/lib

# all:		$(NAME)

# $(NAME):	$(OBJS)
# 		$(CXX) -shared $(OBJS) -o $(NAME) $(LDFLAGS)

# re: 		fclean all

# clean:
# 		$(RM) $(OBJS)

# fclean: 	clean
# 		$(RM) $(NAME)

# USEFUL VARIABLES

DEBUG   =   	NO

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e

# SOURCES VARIABLES

SRC		=	$(wildcard ./*.cpp)

OBJS    	=	$(SRC:.cpp=.o)


# PROJECT VARIABLES

NAME	    =   ../lib/lib_arcade_sfml.so

LDFLAGS     =	-shared \
		-L./deps/SFML-2.2/lib -lsfml-audio \
		-lsfml-graphics -lsfml-window -lsfml-network -lsfml-system

CXXFLAGS    =	-W -Wall -Wextra --std=c++11 \
                -Iinclude/ \
		-std=c++11 \
		-fPIC \
		-I./SFML-2.4.2/include

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
