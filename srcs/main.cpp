#include <iostream>
#include "../include/DLLoader.hpp"
#include "../arcadeInterfaces/IGfxLib.hpp"
#include "../include/Map.hpp"
#include "../gamesSrcs/snake/SnakeGame.hpp"
#include "../include/Core.hpp"

int main(int ac, char **av) {

    srand(time(0));
    if (ac != 2) {
        std::cerr << "Usage: ./arcade pathToLibrary.so" << std::endl;
        return (1);
    }
    arcade::Core(std::string(av[1]));
    return 0;
}
