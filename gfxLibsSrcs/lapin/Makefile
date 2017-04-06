SRC         =   $(wildcard ./src/*.cpp)  \
				$(wildcard ../../ArcadeInterfaces/*.cpp)

OBJ         = $(SRC:.cpp=.o)

CXXFLAGS    = -g -W -Wall -Wextra --std=c++11 -Iinclude/ -fPIC \

LIB         = -llapin -lsfml-graphics -lsfml-audio -lsfml-window \
              -lsfml-system -lstdc++ -lm -ldl -lpthread -L./LibLapin

INCLUDE     = -I./include/ -I./

NAME        = ../../lib/lib_arcade_lapin.so

all:        $(NAME)

lapin:
			@make -C LibLapin

$(NAME):    $(OBJ) lapin
			mkdir -p ../../lib
			g++ -o $(NAME) $(OBJ) $(LIB) -shared

.cpp.o:
			g++ $(INCLUDE) $(CXXFLAGS) -c $< -o $@

clean:
			rm $(OBJ)

re:         clean all
