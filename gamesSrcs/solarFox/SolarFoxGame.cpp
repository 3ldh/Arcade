//
// Created by sauvau_m on 4/4/17.
//

#include <iostream>
#include "SolarFoxGame.hpp"

arcade::SolarFoxGame::~SolarFoxGame() {

}

arcade::SolarFoxGame::SolarFoxGame():  map(Map(MAP_WIDTH, MAP_HEIGHT, 1)),
                                       state(arcade::GameState::INGAME),
                                       sprites(std::vector<std::unique_ptr<ISprite> >()), accelerationRate(1000) {

    for (size_t y = 0; y < map.getHeight(); ++y) {
        for (size_t x = 0; x < map.getWidth(); ++x) {
            if (level0[y][x] == 0) {
                map[0][y][x]->setType(TileType::EMPTY);
                map[0][y][x]->setTypeEv(TileTypeEvolution ::EMPTY);
                map[0][y][x]->setColor(Color::Black);
            } else {
                map[0][y][x]->setType(TileType::POWERUP);
                map[0][y][x]->setTypeEv(TileTypeEvolution ::POWERUP);
                map[0][y][x]->setColor(Color::White);
            }
        }
    }
    inputs[KeyboardKey::KB_ARROW_UP] = Unit::Direction::UP;
    inputs[KeyboardKey::KB_ARROW_DOWN] = Unit::Direction::DOWN;
    inputs[KeyboardKey::KB_ARROW_LEFT] = Unit::Direction::LEFT;
    inputs[KeyboardKey::KB_ARROW_RIGHT] = Unit::Direction::RIGHT;
    timer.start();
}

arcade::GameState arcade::SolarFoxGame::getGameState() const {
    return state;
}

void arcade::SolarFoxGame::notifyEvent(std::vector<arcade::Event> &&events) {
    (void)events;
}

void arcade::SolarFoxGame::notifyNetwork(std::vector<arcade::NetworkPacket> &&events) {
    (void)events;
}

std::vector<arcade::NetworkPacket> &&arcade::SolarFoxGame::getNetworkToSend() {
    return std::vector<arcade::NetworkPacket>();
}

void arcade::SolarFoxGame::process() {

}

std::vector<std::unique_ptr<arcade::ISprite>> &&arcade::SolarFoxGame::getSpritesToLoad() const {
    return std::move(sprites);
}

std::vector<std::pair<std::string, arcade::SoundType>> arcade::SolarFoxGame::getSoundsToLoad() const {
    return sounds;
}

std::vector<int> &&arcade::SolarFoxGame::getSoundsToPlay() {
    return std::vector<int>();
}

const arcade::IMap &arcade::SolarFoxGame::getCurrentMap() const {
    return map;
}

arcade::IGUI &arcade::SolarFoxGame::getGUI() {
    return gui;
}

extern "C" arcade::IGame *getGame() {
    return new arcade::SolarFoxGame();
}