//
// Created by sauvau_m on 4/4/17.
//

#include <iostream>
#include <zconf.h>
#include "SolarFoxGame.hpp"

arcade::SolarFoxGame::~SolarFoxGame() {

}

arcade::SolarFoxGame::SolarFoxGame() : map(Map(MAP_WIDTH, MAP_HEIGHT, 2)),
                                       state(arcade::GameState::INGAME),
                                       player(Spaceship(MAP_WIDTH / 2, MAP_HEIGHT / 2, 1)),
                                       enemyLeft(SpaceshipEnemy(0, MAP_HEIGHT / 2, MAP_WIDTH - 1)),
                                       enemyRight(SpaceshipEnemy(MAP_WIDTH - 1, MAP_HEIGHT / 2, MAP_WIDTH - 1)),
                                       enemyUp(SpaceshipEnemy(MAP_WIDTH / 2, 0, MAP_HEIGHT - 1)),
                                       enemyDown(SpaceshipEnemy(MAP_WIDTH / 2, MAP_HEIGHT - 1, MAP_HEIGHT - 1)),
                                       sprites(std::vector<std::unique_ptr<Sprite>>()),
                                       netPacket(std::move(std::vector<NetworkPacket>(0))), accelerationRate(250) {

    enemyDown.setMovingDirection(arcade::Unit::Direction::LEFT);
    enemyUp.setMovingDirection(arcade::Unit::Direction::RIGHT);
    enemyLeft.setMovingDirection(arcade::Unit::Direction::UP);
    enemyRight.setMovingDirection(arcade::Unit::Direction::DOWN);
    for (size_t y = 0; y < map.getHeight(); ++y) {
        for (size_t x = 0; x < map.getWidth(); ++x) {
            if (level0[y][x] == 0) {
                map[0][y][x]->setType(TileType::EMPTY);
                map[0][y][x]->setTypeEv(TileTypeEvolution::EMPTY);
                map[0][y][x]->setColor(Color::Black);
            } else {
                map[0][y][x]->setType(TileType::POWERUP);
                map[0][y][x]->setTypeEv(TileTypeEvolution::POWERUP);
                map[0][y][x]->setColor(Color::White);
            }
            map[1][y][x]->setType(TileType::EMPTY);
            map[1][y][x]->setTypeEv(TileTypeEvolution::EMPTY);
            map[1][y][x]->setColor(Color::Transparent);
        }
    }
    inputs[KeyboardKey::KB_ARROW_UP] = Unit::Direction::UP;
    inputs[KeyboardKey::KB_ARROW_DOWN] = Unit::Direction::DOWN;
    inputs[KeyboardKey::KB_ARROW_LEFT] = Unit::Direction::LEFT;
    inputs[KeyboardKey::KB_ARROW_RIGHT] = Unit::Direction::RIGHT;
    timer.start();
    timerProjectile.start();
    totalTime.start();
}

arcade::GameState arcade::SolarFoxGame::getGameState() const {
    return state;
}

void arcade::SolarFoxGame::notifyEvent(std::vector<arcade::Event> &&events) {
    if (events.size() > 0) {
        if (inputs.find(events[0].kb_key) != inputs.end())
            player.setMovingDirection(inputs[events[0].kb_key]);
        else if (events[0].action == AT_PRESSED) {
            if (events[0].kb_key == KB_SPACE)
                player.shoot();
            else if (events[0].kb_key == KB_8)
                restart();
        }
    }
}

void arcade::SolarFoxGame::notifyNetwork(std::vector<arcade::NetworkPacket> &&events) {
    (void) events;
}

std::vector<arcade::NetworkPacket> &&arcade::SolarFoxGame::getNetworkToSend() {
    return std::move(netPacket);
}

bool arcade::SolarFoxGame::moveShipProjectiles(arcade::Spaceship &spaceship) {
    auto it = spaceship.getProjectiles().begin();
    for (int i = 0; it != spaceship.getProjectiles().end();) {
        if (!spaceship.getProjectiles()[i]->move(map, player)) {
            delete *it;
            it = spaceship.getProjectiles().erase(it);
        } else {
            ++it;
            ++i;
        }
    }
    return (true);
}

void arcade::SolarFoxGame::processProjectile() {
    if (player.doesProjectilesCollide(map, enemyDown.getProjectiles()) ||
        player.doesProjectilesCollide(map, enemyRight.getProjectiles()) ||
        player.doesProjectilesCollide(map, enemyLeft.getProjectiles()) ||
        player.doesProjectilesCollide(map, enemyUp.getProjectiles()))
        std::cerr << "CONGRATZ YOU KILLED A MISSILE" << std::endl;
    if (enemyDown.doesProjectilesCollide(map, player) || enemyUp.doesProjectilesCollide(map, player) ||
        enemyLeft.doesProjectilesCollide(map, player) || enemyRight.doesProjectilesCollide(map, player)) {
        std::cerr << "BOOM YOU DEAD GAME OVER" << std::endl;
        restart();
    }
    if (timerProjectile.isTimeOverMilliseconds(accelerationRate / 2)) {
        clearProjectilesPos();
        moveShipProjectiles(player);
        moveShipProjectiles(enemyDown);
        moveShipProjectiles(enemyUp);
        moveShipProjectiles(enemyLeft);
        moveShipProjectiles(enemyRight);
        updateProjectilesTile();
        timerProjectile.start();
    }
}

void arcade::SolarFoxGame::process() {
    processProjectile();
    if (timer.isTimeOverMilliseconds(accelerationRate)) {
        cleaPlayerPos();
        clearEnemyPos();
        enemyDown.move(map);
        enemyUp.move(map);
        enemyLeft.move(map);
        enemyRight.move(map);
        enemyDown.chooseToShoot(map, player);
        enemyUp.chooseToShoot(map, player);
        enemyLeft.chooseToShoot(map, player);
        enemyRight.chooseToShoot(map, player);
        if (!player.move(map, 1)) {
            std::cerr << "You crashed" << std::endl;
            restart();
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

void arcade::SolarFoxGame::cleaPlayerPos() {
    map.updateMapTileForUnit(player, 0, Color::Black, TileType::EMPTY, TileTypeEvolution::EMPTY);
}

void arcade::SolarFoxGame::updatePlayerPos() {
    map.updateMapTileForUnit(player, 0, Color::Blue, TileType::OTHER, TileTypeEvolution::PLAYER);
}

void arcade::SolarFoxGame::clearEnemyPos() {
    map.updateMapTileForUnit(enemyDown, 0, Color::Black, TileType::EMPTY, TileTypeEvolution::EMPTY);
    map.updateMapTileForUnit(enemyUp, 0, Color::Black, TileType::EMPTY, TileTypeEvolution::EMPTY);
    map.updateMapTileForUnit(enemyLeft, 0, Color::Black, TileType::EMPTY, TileTypeEvolution::EMPTY);
    map.updateMapTileForUnit(enemyRight, 0, Color::Black, TileType::EMPTY, TileTypeEvolution::EMPTY);
}

void arcade::SolarFoxGame::updateEnemyPos() {
    map.updateMapTileForUnit(enemyDown, 0, Color::Red, TileType::EVIL_DUDE, TileTypeEvolution::ENEMY);
    map.updateMapTileForUnit(enemyUp, 0, Color::Red, TileType::EVIL_DUDE, TileTypeEvolution::ENEMY);
    map.updateMapTileForUnit(enemyLeft, 0, Color::Red, TileType::EVIL_DUDE, TileTypeEvolution::ENEMY);
    map.updateMapTileForUnit(enemyRight, 0, Color::Red, TileType::EVIL_DUDE, TileTypeEvolution::ENEMY);
}

void arcade::SolarFoxGame::clearProjectilesPos() {
    player.clearMapForProjectile(map);
    enemyDown.clearMapForProjectile(map);
    enemyUp.clearMapForProjectile(map);
    enemyLeft.clearMapForProjectile(map);
    enemyRight.clearMapForProjectile(map);
}

void arcade::SolarFoxGame::updateProjectilesTile() {
    player.updateMapForProjectile(map, Color::Magenta);
    enemyDown.updateMapForProjectile(map);
    enemyUp.updateMapForProjectile(map);
    enemyLeft.updateMapForProjectile(map);
    enemyRight.updateMapForProjectile(map);
}

void arcade::SolarFoxGame::restart() {
    player.reset();
    enemyDown.reset();
    enemyUp.reset();
    enemyLeft.reset();
    enemyRight.reset();
    enemyDown.setMovingDirection(arcade::Unit::Direction::LEFT);
    enemyUp.setMovingDirection(arcade::Unit::Direction::RIGHT);
    enemyLeft.setMovingDirection(arcade::Unit::Direction::UP);
    enemyRight.setMovingDirection(arcade::Unit::Direction::DOWN);
    for (size_t y = 0; y < map.getHeight(); ++y) {
        for (size_t x = 0; x < map.getWidth(); ++x) {
            if (level0[y][x] == 0) {
                map[0][y][x]->setType(TileType::EMPTY);
                map[0][y][x]->setTypeEv(TileTypeEvolution::EMPTY);
                map[0][y][x]->setColor(Color::Black);
            } else {
                map[0][y][x]->setType(TileType::POWERUP);
                map[0][y][x]->setTypeEv(TileTypeEvolution::POWERUP);
                map[0][y][x]->setColor(Color::White);
            }
            map[1][y][x]->setType(TileType::EMPTY);
            map[1][y][x]->setTypeEv(TileTypeEvolution::EMPTY);
            map[1][y][x]->setColor(Color::Transparent);
        }
    }
    timer.start();
    timerProjectile.start();
    totalTime.start();
}

const arcade::Map &arcade::SolarFoxGame::getMap() const {
    return map;
}

arcade::Spaceship &arcade::SolarFoxGame::getPlayer() {
    return player;
}

void arcade::SolarFoxGame::setAccelerationRate(int accelerationRate) {
    SolarFoxGame::accelerationRate = accelerationRate;
}

static void cmdWhereAmI(arcade::Spaceship const &spaceship) {
    arcade::WhereAmI *whereAmI;
    whereAmI = reinterpret_cast<struct arcade::WhereAmI *>(new char[sizeof(struct arcade::WhereAmI) +
                                                                    (sizeof(struct arcade::Position))]);
    whereAmI->type = arcade::CommandType::WHERE_AM_I;
    whereAmI->lenght = 1;

    whereAmI->position[0].x = spaceship.getPosition().first;
    whereAmI->position[0].y = spaceship.getPosition().second;
    write(1, whereAmI, sizeof(struct arcade::WhereAmI) + (sizeof(struct arcade::Position)));
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
            if (map[1][y][x]->getType() == arcade::TileType::MY_SHOOT) {
                std::cerr << "SHOOT" << std::endl;
                cmdMap->tile[y * map.getHeight() + x] = map[1][y][x]->getType();
            }
        }
    }
    write(1, cmdMap, sizeof(struct arcade::GetMap) + sizeof(arcade::TileType) * (map.getWidth() * map.getHeight()));
    delete cmdMap;
}

extern "C" void Play() {
    arcade::CommandType cmd;
    arcade::SolarFoxGame game;
    arcade::Unit::Direction direction = arcade::Unit::Direction::FORWARD;

    game.setAccelerationRate(0);

    while (read(0, &cmd, sizeof(arcade::CommandType))) {
        switch (cmd) {
            case (arcade::CommandType::GET_MAP) :
                direction = arcade::Unit::Direction::FORWARD;
                cmdGetMap(game.getMap());
                break;
            case (arcade::CommandType::WHERE_AM_I) :
                direction = arcade::Unit::Direction::FORWARD;
                cmdWhereAmI(game.getPlayer());
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
                    game.getPlayer().setMovingDirection(direction);
                game.process();
                break;
            case arcade::CommandType::SHOOT:
                game.getPlayer().shoot();
                game.process();
                break;
            case arcade::CommandType::ILLEGAL:
                break;
        }
    }
}

extern "C" arcade::IGame *getGame() {
    return new arcade::SolarFoxGame();
}