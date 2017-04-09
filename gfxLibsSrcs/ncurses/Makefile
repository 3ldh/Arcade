SRC         =   $(wildcard ./src/*.cpp)  \
				$(wildcard ../../arcadeInterfaces/*.cpp)

OBJ         = $(SRC:.cpp=.o)

CXXFLAGS    = -g -W -Wall -Wextra --std=c++14 -Iinclude/ -fPIC \

LIB         = -lncurses

INCLUDE     = -I./include/ -I./

NAME        = ../../lib/lib_arcade_ncurses.so

$(NAME):    $(OBJ)
			mkdir -p ../../lib
			g++ -o $(NAME) $(OBJ) $(LIB) -shared

all:        $(NAME)

.cpp.o:
			g++ $(INCLUDE) $(CXXFLAGS) -c $< -o $@

clean:
			rm -rf $(OBJ)

fclean:			clean
			rm -rf $(NAME)

re:         clean all
