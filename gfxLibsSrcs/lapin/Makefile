SRC         = $(wildcard ./src/*.cpp)

OBJ         = $(SRC:.cpp=.o)

CXXFLAGS    = -W -Wall -Wextra --std=c++11 -Iinclude/ -fPIC \

LIB         = -llapin -lsfml-graphics -lsfml-audio -lsfml-window \
              -lsfml-system -lstdc++ -lm -ldl -lpthread -L./LibLapin

INCLUDE     = -I./include/

NAME        = ../../lib/lib_arcade_lapin.so

all:        $(NAME)

lapin:
			@make -C LibLapin

$(NAME):    $(OBJ) lapin
			g++ -o $(NAME) $(OBJ) $(LIB) -shared

.cpp.o:
			g++ $(INCLUDE) $(CXXFLAGS) -c $< -o $@

clean:
			rm $(OBJ)

re:         clean all
