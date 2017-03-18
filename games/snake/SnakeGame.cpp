//
// Created by sauvau_m on 3/17/17.
//

#include <iostream>
#include "SnakeGame.hpp"
#include "../../include/GUI.hpp"

arcade::SnakeGame::~SnakeGame() {

}

arcade::SnakeGame::SnakeGame() : map(Map(MAP_WIDTH, MAP_HEIGHT, 1)),
                                 state(arcade::GameState::INGAME), snake(SnakeUnit(MAP_WIDTH / 2, MAP_HEIGHT / 2)) {

    for (size_t i = 0; i < map.getHeight(); ++i) {
        for (size_t j = 0; j < map.getWidth(); ++j) {
            if (i == 0 || i == map.getHeight() - 1 ||
                j == 0 || j == map.getWidth() - 1)
                map[0][i][j]->setType(arcade::TileType::BLOCK);
        }
    }
}

arcade::GameState arcade::SnakeGame::getGameState() const {
    return state;
}

void arcade::SnakeGame::notifyEvent(const std::vector<arcade::Event> &events) {
    (void) events;
}

void arcade::SnakeGame::notifyNetwork(const std::vector<arcade::NetworkPacket> &events) {
    (void) events;
}

std::vector<arcade::NetworkPacket> arcade::SnakeGame::getNetworkToSend() const {
    return std::vector<arcade::NetworkPacket>();
}

std::vector<std::string> arcade::SnakeGame::getSoundsToLoad() const {
    return std::vector<std::string>();
}

std::vector<int> arcade::SnakeGame::getSoundSToPlay() const {
    return std::vector<int>();
}

const arcade::IMap &arcade::SnakeGame::getCurrentMap() const {
    return map;
}

const arcade::IGUI &arcade::SnakeGame::getGUI() const {
    return *new GUI();
}

//TODO remove this function of test
void arcade::SnakeGame::updatePlayerPos() {
    for (size_t i = 0; i < snake.getLength(); ++i) {
        map[0][snake[i].getPosition().second][snake[i].getPosition().first]->setType(TileType::OTHER);
        map[0][snake[i].getPosition().second][snake[i].getPosition().first]->setTypeEv(TileTypeEvolution::PLAYER);
    }
}

void arcade::SnakeGame::clearPlayerPos() {
    for (size_t i = 0; i < snake.getLength(); ++i) {
        map[0][snake[i].getPosition().second][snake[i].getPosition().first]->setType(TileType::EMPTY);
        map[0][snake[i].getPosition().second][snake[i].getPosition().first]->setTypeEv(TileTypeEvolution::EMPTY);
    }
}