//
// Created by sauvau_m on 3/17/17.
//

#include <iostream>
#include <zconf.h>
#include "SnakeGame.hpp"

arcade::SnakeGame::~SnakeGame() {

}

arcade::SnakeGame::SnakeGame() : map(Map(MAP_WIDTH, MAP_HEIGHT, 1)),
                                 state(arcade::GameState::INGAME), sprites(std::vector<std::unique_ptr<Sprite>>()),
                                 netPacket(std::move(std::vector<NetworkPacket>(0))),
                                 snake(SnakeUnit(MAP_WIDTH / 2, MAP_HEIGHT / 2)), accelerationRate(250), apple(false),
                                 score(0) {

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
        else if (events[0].kb_key == KB_8 && events[0].action == AT_PRESSED) {
            restart();
        }
    }
}

void arcade::SnakeGame::notifyNetwork(std::vector<arcade::NetworkPacket> &&events) {
    (void) events;
}


std::vector<std::unique_ptr<arcade::ISprite>> arcade::SnakeGame::getSpritesToLoad() const {
    std::vector<std::unique_ptr<arcade::ISprite>> copy;
    for (size_t i = 0; i < sprites.size(); ++i) {
        copy.push_back(std::unique_ptr<Sprite>(new Sprite(*sprites[i])));
    }
    return std::move(copy);
}

std::vector<arcade::Sound> arcade::SnakeGame::getSoundsToPlay() {
    return std::vector<arcade::Sound>();
}

std::vector<std::pair<std::string, arcade::SoundType>> arcade::SnakeGame::getSoundsToLoad() const {
    return sounds;
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
        clearPlayerPos();
        if (!snake.move(map)) {
            //TODO GameOver
            std::cerr << "you scored " << score << std::endl;
            std::cerr << "GameOver : the Snake has lost his head" << std::endl;
            restart();
        }
        takeApple(snake[0].getPosition().first, snake[0].getPosition().second);
        updatePlayerPos();
        spawnApple();
        timer.start();
    }
}

void arcade::SnakeGame::spawnApple() {
    if (!apple) {
        appleTimer.start();
        std::vector<std::pair<size_t, size_t>> spawnablePos = getSpawnablePos();
        applePos = spawnablePos[rand() % spawnablePos.size()];
        apple = true;
        map[0][applePos.second][applePos.first]->setType(TileType::POWERUP);
        map[0][applePos.second][applePos.first]->setTypeEv(TileTypeEvolution::POWERUP);
        map[0][applePos.second][applePos.first]->setColor(Color::Red);
    }
}

void arcade::SnakeGame::takeApple(size_t x, size_t y) {
    if (x == applePos.first && y == applePos.second) {
        if (appleTimer.timeElapsedSeconds() != 0)
        score += 10 / appleTimer.timeElapsedSeconds();
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

arcade::SnakeUnit &arcade::SnakeGame::getSnake() {
    return snake;
}

void arcade::SnakeGame::setAccelerationRate(int accelerationRate) {
    SnakeGame::accelerationRate = accelerationRate;
}

void arcade::SnakeGame::restart() {

    clearPlayerPos();
    map[0][applePos.second][applePos.first]->setColor(Color::Black);
    map[0][applePos.second][applePos.first]->setTypeEv(TileTypeEvolution::EMPTY);
    map[0][applePos.second][applePos.first]->setType(TileType::EMPTY);
    apple = false;
    score = 0;
    snake.reset();
    timer.start();
}

bool arcade::SnakeGame::hasNetwork() const {
    return false;
}

std::vector<arcade::NetworkPacket> arcade::SnakeGame::getNetworkToSend() {
    return netPacket;
}

static void cmdWhereAmI(arcade::SnakeUnit const &snake) {
    arcade::WhereAmI *whereAmI;
    whereAmI = reinterpret_cast<struct arcade::WhereAmI *>(new char[sizeof(struct arcade::WhereAmI) +
                                                                    (sizeof(struct arcade::Position) *
                                                                     snake.getLength())]);
    whereAmI->type = arcade::CommandType::WHERE_AM_I;
    whereAmI->lenght = snake.getLength();

    for (size_t i = 0; i < snake.getLength(); ++i) {
        whereAmI->position[i].x = snake[i].getPosition().first;
        whereAmI->position[i].y = snake[i].getPosition().second;
    }
    write(1, whereAmI, sizeof(struct arcade::WhereAmI) + (sizeof(struct arcade::Position) * snake.getLength()));
    delete whereAmI;
}

static void cmdGetMap(arcade::Map const &map) {
    arcade::GetMap *cmdMap;
    cmdMap = reinterpret_cast<struct arcade::GetMap *>(new char[sizeof(struct arcade::GetMap) +
                                                                sizeof(arcade::TileType) *
                                                                (map.getWidth() * map.getHeight())]);
    cmdMap->type = arcade::CommandType::GET_MAP;
    cmdMap->width = map.getHeight();
    cmdMap->height = map.getHeight();
    for (size_t y = 0; y < map.getHeight(); y++) {
        for (size_t x = 0; x < map.getWidth(); x++) {
            cmdMap->tile[y * map.getHeight() + x] = map[0][y][x]->getType();
        }
    }
    write(1, cmdMap, sizeof(struct arcade::GetMap) + sizeof(arcade::TileType) * (map.getWidth() * map.getHeight()));
    delete cmdMap;
}

extern "C" void Play() {

    arcade::CommandType cmd;
    arcade::SnakeGame snakeGame;
    arcade::Unit::Direction direction = arcade::Unit::Direction::FORWARD;

    while (read(0, &cmd, sizeof(arcade::CommandType))) {
        switch (cmd) {
            case (arcade::CommandType::GET_MAP) :
                direction = arcade::Unit::Direction::FORWARD;
                cmdGetMap(snakeGame.getMap());
                break;
            case (arcade::CommandType::WHERE_AM_I) :
                direction = arcade::Unit::Direction::FORWARD;
                cmdWhereAmI(snakeGame.getSnake());
                break;
            case (arcade::CommandType::GO_UP) :
                direction = arcade::Unit::Direction::UP;
                break;
            case (arcade::CommandType::GO_DOWN) :
                direction = arcade::Unit::Direction::DOWN;
                break;
            case (arcade::CommandType::GO_LEFT) :
                direction = arcade::Unit::Direction::LEFT;
                break;
            case (arcade::CommandType::GO_RIGHT) :
                direction = arcade::Unit::Direction::RIGHT;
                break;
            case (arcade::CommandType::GO_FORWARD) :
                direction = arcade::Unit::Direction::FORWARD;
                break;
            case (arcade::CommandType::PLAY) :
                if (direction != arcade::Unit::Direction::FORWARD)
                    snakeGame.getSnake().setMovingDirection(direction);
                snakeGame.setAccelerationRate(0);
                snakeGame.process();
                break;
            case arcade::CommandType::SHOOT:
                break;
            case arcade::CommandType::ILLEGAL:
                break;
        }
    }
}

extern "C" arcade::IGame *getGame() {
    return new arcade::SnakeGame();
}