//
// Created by sauvau_m on 3/17/17.
//

#include <iostream>
#include "SnakeGame.hpp"
#include "../../include/GUI.hpp"

arcade::SnakeGame::~SnakeGame() {

}

arcade::SnakeGame::SnakeGame() : map(Map(MAP_WIDTH, MAP_HEIGHT, 1)),
                                 state(arcade::GameState::INGAME), snake(SnakeUnit(MAP_WIDTH / 2, MAP_HEIGHT / 2)),
                                 sprites(std::vector<std::unique_ptr<ISprite> >()),
                                 accelerationRate(1000), apple(false) {

    for (size_t i = 0; i < map.getHeight(); ++i) {
        for (size_t j = 0; j < map.getWidth(); ++j) {
            if (i == 0 || i == map.getHeight() - 1 ||
                j == 0 || j == map.getWidth() - 1) {
                map[0][i][j]->setType(arcade::TileType::BLOCK);
                map[0][i][j]->setTypeEv(arcade::TileTypeEvolution::BLOCK);
                map[0][i][j]->setColor(Color::White);
            } else
                map[0][i][j]->setColor(Color::Black);
        }
    }
    inputs[KeyboardKey::KB_ARROW_UP] = Unit::Direction::UP;
    inputs[KeyboardKey::KB_ARROW_DOWN] = Unit::Direction::DOWN;
    inputs[KeyboardKey::KB_ARROW_LEFT] = Unit::Direction::LEFT;
    inputs[KeyboardKey::KB_ARROW_RIGHT] = Unit::Direction::RIGHT;
    timer.start();
}

arcade::GameState arcade::SnakeGame::getGameState() const {
    return state;
}

void arcade::SnakeGame::notifyEvent(std::vector<arcade::Event> &&events) {
    if (events.size() > 0) {
        auto it = inputs.find(events[0].kb_key);
        if (it != inputs.end())
            snake.setMovingDirection((*it).second);
//        std::cout << snake.getMovingDirection() << std::endl;
    }
}

void arcade::SnakeGame::notifyNetwork(std::vector<arcade::NetworkPacket> &&events) {
    (void) events;
}

std::vector<arcade::NetworkPacket> &&arcade::SnakeGame::getNetworkToSend() {
    return std::vector<arcade::NetworkPacket>();
}

std::vector<int> &&arcade::SnakeGame::getSoundsToPlay() {
    return std::vector<int>();
}

std::vector<std::pair<std::string, arcade::SoundType>> arcade::SnakeGame::getSoundsToLoad() const {
    return sounds;
}

std::vector<std::unique_ptr<arcade::ISprite>> &&arcade::SnakeGame::getSpritesToLoad() const {
    return std::move(sprites);
}

arcade::IGUI &arcade::SnakeGame::getGUI() {
    return gui;
}

const arcade::IMap &arcade::SnakeGame::getCurrentMap() const {
    return map;
}

const arcade::Map &arcade::SnakeGame::getMap() const {
    return map;
}

void arcade::SnakeGame::updatePlayerPos() {
    for (size_t i = 0; i < snake.getLength(); ++i) {
        map[0][snake[i].getPosition().second][snake[i].getPosition().first]->setType(TileType::OTHER);
        map[0][snake[i].getPosition().second][snake[i].getPosition().first]->setTypeEv(TileTypeEvolution::PLAYER);
        if (i != 0)
            map[0][snake[i].getPosition().second][snake[i].getPosition().first]->setColor(Color::Green);
        else
            map[0][snake[i].getPosition().second][snake[i].getPosition().first]->setColor(Color::Yellow);
    }
}

void arcade::SnakeGame::clearPlayerPos() {
    for (size_t i = 0; i < snake.getLength(); ++i) {
        map[0][snake[i].getPosition().second][snake[i].getPosition().first]->setType(TileType::EMPTY);
        map[0][snake[i].getPosition().second][snake[i].getPosition().first]->setTypeEv(TileTypeEvolution::EMPTY);
        map[0][snake[i].getPosition().second][snake[i].getPosition().first]->setColor(Color::Black);
    }
}

void arcade::SnakeGame::process() {
    if (timer.isTimeOverMilliseconds(accelerationRate)) {
        spawnApple();
        clearPlayerPos();
        if (!snake.move(map)) {
            //TODO GameOver
            std::cerr << "GameOver : the Snake has lost his head" << std::endl;
        }
        takeApple(snake[0].getPosition().first, snake[0].getPosition().second);
        updatePlayerPos();
        timer.start();
    }
}

void arcade::SnakeGame::spawnApple() {
    if (!apple) {
        std::vector<std::pair<size_t , size_t>> spawnablePos = getSpawnablePos();
        applePos = spawnablePos[rand() % spawnablePos.size()];
        apple = true;
        map[0][applePos.second][applePos.first]->setType(TileType::POWERUP);
        map[0][applePos.second][applePos.first]->setTypeEv(TileTypeEvolution::POWERUP);
        map[0][applePos.second][applePos.first]->setColor(Color::Red);
    }
}

void arcade::SnakeGame::takeApple(size_t x, size_t y) {
    if (x == applePos.first && y == applePos.second) {
        apple = false;
        if (!snake.grow(map))
            std::cerr << "GameOver : the Snake can't grow" << std::endl;
    }
}

std::vector<std::pair<size_t, size_t>> arcade::SnakeGame::getSpawnablePos() {
    std::vector<std::pair<size_t, size_t>> pos;

    for (size_t y = 1; y < map.getHeight() - 1; ++y) {
        for (size_t x = 1; x < map.getWidth() - 1; ++x) {
            if (map[0][y][x]->getTypeEv() == TileTypeEvolution::EMPTY) {
                pos.push_back(std::make_pair(x, y));
            }
        }
    }
    return pos;
}

extern "C" void Play() {
/*    arcade::CommandType cmd;
    arcade::Unit::Direction direction;
    arcade::SnakeGame snakeGame;*/
}

extern "C" arcade::IGame *getGame() {
    return new arcade::SnakeGame();
}