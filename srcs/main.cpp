#include <iostream>
#include "../include/DLLoader.hpp"
#include "../ArcadeInterfaces/IGfxLib.hpp"
#include "../include/Map.hpp"
#include "../games/snake/SnakeGame.hpp"

void showMap(arcade::SnakeGame const &game)
{
    for (size_t i = 0; i < game.getCurrentMap().getHeight(); ++i) {
        for (size_t j = 0; j < game.getCurrentMap().getWidth(); ++j) {
            std::cout << (int)(game.getCurrentMap()[0][i][j]->getType());
        }
        std::cout << std::endl;
    }
}

int main() {
    DLLoader<arcade::IGfxLib> loader("gfxLibs/lib/lib_arcade_sfml.so");

    arcade::IGfxLib *lib = loader.getInstance("getClone");
    lib->display();
    arcade::SnakeGame game;

    game.updatePlayerPos();
    showMap(game);
    game.clearPlayerPos();
    game.snake.move(game.getCurrentMap(), arcade::Unit::DOWN);
    game.updatePlayerPos();
    showMap(game);
    game.clearPlayerPos();
    game.snake.move(game.getCurrentMap(), arcade::Unit::DOWN);
    game.updatePlayerPos();
    showMap(game);
    game.clearPlayerPos();
    game.snake.move(game.getCurrentMap(), arcade::Unit::LEFT);
    game.updatePlayerPos();
    showMap(game);
    game.clearPlayerPos();
    game.snake.move(game.getCurrentMap(), arcade::Unit::UP);
    game.updatePlayerPos();
    showMap(game);
    game.clearPlayerPos();
    game.snake.move(game.getCurrentMap(), arcade::Unit::UP);
    game.updatePlayerPos();
    showMap(game);
    return 0;
}