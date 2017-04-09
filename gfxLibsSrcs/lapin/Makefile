SRC         =   $(wildcard ./src/*.cpp)  \
		$(wildcard ../../arcadeInterfaces/*.cpp)

OBJ         = $(SRC:.cpp=.o)

CXXFLAGS    = -g -W -Wall -Wextra --std=c++14 -Iinclude/ -fPIC \

LIB         = -llapin -lsfml-graphics -lsfml-audio -lsfml-window \
              -lsfml-system -lstdc++ -lm -ldl -lpthread -L./LibLapin

INCLUDE     = -I./include/ -I./

NAME        = ../../lib/lib_arcade_lapin.so

$(NAME):    $(OBJ)
			@mkdir -p ../../lib
			g++ -o $(NAME) $(OBJ) $(LIB) -shared

all:        $(NAME)


.cpp.o:
			g++ $(INCLUDE) $(CXXFLAGS) -c $< -o $@

clean:
			rm -rf $(OBJ)

fclean:			clean
			rm -rf $(NAME)

re:         clean all
