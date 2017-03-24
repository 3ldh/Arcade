#include <iostream>
#include "../include/DLLoader.hpp"
#include "../ArcadeInterfaces/IGfxLib.hpp"
#include "../include/Map.hpp"
#include "../gamesSrcs/snake/SnakeGame.hpp"
#include "../include/Core.hpp"

void showMap(arcade::SnakeGame const &game)
{
    for (size_t i = 0; i < game.getCurrentMap().getHeight(); ++i) {
        for (size_t j = 0; j < game.getCurrentMap().getWidth(); ++j) {
            std::cout << (int)(game.getCurrentMap().at(0, i, j).getType());
        }
        std::cout << std::endl;
    }
}

int main(int ac, char **av) {
    if (!av[1]) {
        std::cerr << "Usage: ./arcade pathToLibrary.so" << std::endl;
        return (1);
    }
    arcade::Core(std::string(av[1]));
    
/*    DLLoader<arcade::IGfxLib> loader("lib/lib_arcade_sfml.so");

    arcade::IGfxLib *lib = loader.getInstance("getClone");
    lib->display();*/

    

    /*arcade::SnakeGame game;

    game.updatePlayerPos();
    showMap(game);
    game.clearPlayerPos();
    game.snake.move(game.getMap(), arcade::Unit::DOWN);
    game.updatePlayerPos();
    showMap(game);
    game.clearPlayerPos();
    game.snake.move(game.getMap(), arcade::Unit::DOWN);
    game.updatePlayerPos();
    showMap(game);
    game.clearPlayerPos();
    game.snake.move(game.getMap(), arcade::Unit::LEFT);
    game.updatePlayerPos();
    showMap(game);
    game.clearPlayerPos();
    game.snake.move(game.getMap(), arcade::Unit::UP);
    game.updatePlayerPos();
    showMap(game);
    game.clearPlayerPos();
    game.snake.move(game.getMap(), arcade::Unit::UP);
    game.updatePlayerPos();
    showMap(game);*/
    return 0;
}
