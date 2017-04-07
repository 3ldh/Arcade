//
// Created by sauvau_m on 4/4/17.
//

#include <iostream>
#include "SolarFoxGame.hpp"

arcade::SolarFoxGame::~SolarFoxGame() {

}

arcade::SolarFoxGame::SolarFoxGame():  map(Map(MAP_WIDTH, MAP_HEIGHT, 1)),
                                       state(arcade::GameState::INGAME), player(Spaceship(MAP_WIDTH / 2, MAP_HEIGHT / 2)),
                                       enemyLeft(Spaceship(0, MAP_HEIGHT / 2)),
                                       enemyRight(Spaceship(MAP_WIDTH - 1, MAP_HEIGHT / 2)),
                                       enemyUp(Spaceship(MAP_WIDTH / 2, 0)),
                                       enemyDown(Spaceship(MAP_WIDTH / 2, MAP_HEIGHT - 1)),
                                       sprites(std::vector<std::unique_ptr<Sprite>>()), accelerationRate(250) {

    enemyDown.setMovingDirection(arcade::Unit::Direction::LEFT);
    enemyUp.setMovingDirection(arcade::Unit::Direction::RIGHT);
    enemyLeft.setMovingDirection(arcade::Unit::Direction::UP);
    enemyRight.setMovingDirection(arcade::Unit::Direction::DOWN);
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
    if (events.size() > 0 && inputs.find(events[0].kb_key) != inputs.end()) {
        player.setMovingDirection(inputs[events[0].kb_key]);
    }
}

void arcade::SolarFoxGame::notifyNetwork(std::vector<arcade::NetworkPacket> &&events) {
    (void)events;
}

std::vector<arcade::NetworkPacket> &&arcade::SolarFoxGame::getNetworkToSend() {
    return std::vector<arcade::NetworkPacket>();
}

void arcade::SolarFoxGame::process() {
    if (timer.isTimeOverMilliseconds(accelerationRate)) {
        cleaPlayerPos();
        clearEnemyPos();
        enemyDown.chooseDirectionFromAxe(map, player);
        enemyUp.chooseDirectionFromAxe(map, player);
        enemyLeft.chooseDirectionFromAxe(map, player);
        enemyRight.chooseDirectionFromAxe(map, player);
        enemyDown.move(map);
        enemyUp.move(map);
        enemyLeft.move(map);
        enemyRight.move(map);
        if (!player.move(map)) {
            std::cout << "can't move" << std::endl;
        }

        updatePlayerPos();
        updateEnemyPos();
        timer.start();
    }
}

std::vector<std::unique_ptr<arcade::ISprite>> arcade::SolarFoxGame::getSpritesToLoad() const {
    std::vector<std::unique_ptr<arcade::ISprite>> copy;
    for (size_t i = 0; i < sprites.size(); ++i) {
        copy.push_back(std::unique_ptr<Sprite>(new Sprite(*sprites[i])));
    }
    return copy;
}

std::vector<std::pair<std::string, arcade::SoundType>> arcade::SolarFoxGame::getSoundsToLoad() const {
    return sounds;
}

std::vector<arcade::Sound> arcade::SolarFoxGame::getSoundsToPlay() {
    return std::vector<arcade::Sound>();
}

const arcade::IMap &arcade::SolarFoxGame::getCurrentMap() const {
    return map;
}

arcade::IGUI &arcade::SolarFoxGame::getGUI() {
    return gui;
}

void arcade::SolarFoxGame::clearPos(const arcade::Spaceship &ship) {
    map[0][ship.getPosition().second][ship.getPosition().first]->setType(TileType::EMPTY);
    map[0][ship.getPosition().second][ship.getPosition().first]->setTypeEv(TileTypeEvolution::EMPTY);
    map[0][ship.getPosition().second][ship.getPosition().first]->setColor(Color::Black);
}

void arcade::SolarFoxGame::updatePos(const arcade::Spaceship &ship, Color const &color) {
    map[0][ship.getPosition().second][ship.getPosition().first]->setType(TileType::OTHER);
    map[0][ship.getPosition().second][ship.getPosition().first]->setTypeEv(TileTypeEvolution::PLAYER);
    map[0][ship.getPosition().second][ship.getPosition().first]->setColor(color);
}

void arcade::SolarFoxGame::cleaPlayerPos() {
    clearPos(player);
}

void arcade::SolarFoxGame::updatePlayerPos() {
    updatePos(player, Color::Blue);
}

void arcade::SolarFoxGame::clearEnemyPos() {
    clearPos(enemyDown);
    clearPos(enemyUp);
    clearPos(enemyLeft);
    clearPos(enemyRight);
}

void arcade::SolarFoxGame::updateEnemyPos() {
    updatePos(enemyDown, Color::Red);
    updatePos(enemyUp, Color::Red);
    updatePos(enemyLeft, Color::Red);
    updatePos(enemyRight, Color::Red);
}

void arcade::SolarFoxGame::canMove() {

}

extern "C" void Play() {

}

extern "C" arcade::IGame *getGame() {
    return new arcade::SolarFoxGame();
}