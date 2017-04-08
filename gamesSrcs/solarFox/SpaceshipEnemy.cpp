//
// Created by sauvau_m on 4/7/17.
//

#include <iostream>
#include "SpaceshipEnemy.hpp"


arcade::SpaceshipEnemy::SpaceshipEnemy(size_t x, size_t y, int shootingRange) : Spaceship(x, y, shootingRange) {}

arcade::SpaceshipEnemy::~SpaceshipEnemy() {

}

bool arcade::SpaceshipEnemy::move(const arcade::Map &map) {
    std::pair<int, int> vector = convertDirection(movingDirection);

    if (!canMove(map))
        movingDirection = getOppositeDirection(movingDirection);
    if (canMove(map)) {
        setPosition(position.first + vector.first, position.second + vector.second);
        return true;
    }
    return false;
}

bool arcade::SpaceshipEnemy::canMove(const arcade::Map &map) {
    std::pair<int, int> vector = convertDirection(movingDirection);

    return (movingDirection == UP && position.second + vector.second > 0) ||
           (movingDirection == DOWN && position.second + vector.second < map.getHeight() - 1) ||
           (movingDirection == LEFT && position.first + vector.first > 0) ||
           (movingDirection == RIGHT && position.first + vector.first < map.getWidth() - 1);
}

std::pair<int, int> arcade::SpaceshipEnemy::posDiffWithPlayer(const arcade::Spaceship &player) {
    return std::make_pair(player.getPosition().first - position.first, player.getPosition().second - position.second);
}

void arcade::SpaceshipEnemy::chooseToShoot(Map const &map, const arcade::Spaceship &player) {
    std::pair<int, int> posDiff = posDiffWithPlayer(player);
    int r = rand() % 100;
    int chances = 10;
    if (abs(posDiff.first) <= 2 || abs(posDiff.second) <= 2)
        chances += 5;
    if (r < chances)
        shoot(map);
}

void arcade::SpaceshipEnemy::shoot(Map const &map) {
    Direction direction = FORWARD;
    std::pair<int, int> vector = std::make_pair<int, int>(0, 0);

    if (position.first == 0)
        direction = RIGHT;
    else if (position.first == map.getWidth() - 1)
        direction = LEFT;
    else if (position.second == 0)
        direction = DOWN;
    else if (position.second == map.getHeight() - 1)
        direction = UP;
    vector = convertDirection(direction);
    projectiles.push_back(
            new Projectile(position.first + vector.first, position.second + vector.second, direction, shootingRange));
}

void arcade::SpaceshipEnemy::updateMapForProjectile(arcade::Map &map) {
    for (size_t i = 0; i < projectiles.size(); ++i)
        map.updateMapTileForUnit(*projectiles[i], 1, Color::Green, TileType::EVIL_SHOOT, TileTypeEvolution::SHOT_ENEMY);
}

void arcade::SpaceshipEnemy::clearMapForProjectile(arcade::Map &map) {
    for (size_t i = 0; i < projectiles.size(); ++i) {
        map.updateMapTileForUnit(*projectiles[i], 1, Color::Transparent, TileType::EMPTY, TileTypeEvolution::EMPTY);
    }
}
