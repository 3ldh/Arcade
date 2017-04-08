//
// Created by sauvau_m on 4/4/17.
//

#include <iostream>
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
                                       sprites(std::vector<std::unique_ptr<Sprite>>()), accelerationRate(250) {

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
}

arcade::GameState arcade::SolarFoxGame::getGameState() const {
    return state;
}

void arcade::SolarFoxGame::notifyEvent(std::vector<arcade::Event> &&events) {
    if (events.size() > 0) {
        if (inputs.find(events[0].kb_key) != inputs.end())
            player.setMovingDirection(inputs[events[0].kb_key]);
        else if (events[0].kb_key == KB_SPACE && events[0].action == AT_PRESSED) {
            player.shoot();
        }
    }
}

void arcade::SolarFoxGame::notifyNetwork(std::vector<arcade::NetworkPacket> &&events) {
    (void) events;
}

std::vector<arcade::NetworkPacket> &&arcade::SolarFoxGame::getNetworkToSend() {
    return std::vector<arcade::NetworkPacket>();
}


void arcade::SolarFoxGame::moveShipProjectiles(arcade::Spaceship &spaceship) {
    auto it = spaceship.getProjectiles().begin();

    for (int i = 0; it != spaceship.getProjectiles().end();) {
        if (!spaceship.getProjectiles()[i]->move(map)) {
            delete *it;
            it = spaceship.getProjectiles().erase(it);
        } else {
            ++it;
            ++i;
        }
    }
}

void arcade::SolarFoxGame::processProjectile() {
    if (timerProjectile.isTimeOverMilliseconds(accelerationRate / 2)) {
        clearProjectilesPos();
        moveShipProjectiles(player);
        moveShipProjectiles(enemyDown);
        moveShipProjectiles(enemyUp);
        moveShipProjectiles(enemyLeft);
        moveShipProjectiles(enemyRight);
        if (enemyDown.doesProjectilesCollide(map, player) || enemyUp.doesProjectilesCollide(map, player) ||
        enemyLeft.doesProjectilesCollide(map, player) || enemyRight.doesProjectilesCollide(map, player)) {
            std::cerr << "BOOM YOU DEAD GAME OVER" << std::endl;
            player.setAlive(false);
        }
        if (player.doesProjectilesCollide(map, enemyDown.getProjectiles()) ||
                player.doesProjectilesCollide(map, enemyRight.getProjectiles()) ||
                player.doesProjectilesCollide(map, enemyLeft.getProjectiles()) ||
                player.doesProjectilesCollide(map, enemyUp.getProjectiles()))
            std::cerr << "CONGRATZ YOU KILLED A MISSILE" << std::endl;

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

extern "C" void Play() {

}

extern "C" arcade::IGame *getGame() {
    return new arcade::SolarFoxGame();
}