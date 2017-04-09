//
// Created by sauvau_m on 4/4/17.
//

#include <iostream>
#include "Spaceship.hpp"

arcade::Spaceship::~Spaceship() {

}

arcade::Spaceship::Spaceship(size_t x, size_t y, int shootingRange) : Unit(x, y), shootingRange(shootingRange),
                                                                      movingDirection(FORWARD) {

}

void arcade::Spaceship::shoot() {
    std::pair<int, int> vector = convertDirection(movingDirection);
    projectiles.push_back(
            new Projectile(position.first + vector.first, position.second + vector.second, movingDirection,
                           shootingRange));
}

void arcade::Spaceship::setMovingDirection(arcade::Unit::Direction movingDirection) {
    if (getOppositeDirection(Spaceship::movingDirection) != movingDirection)
        Spaceship::movingDirection = movingDirection;
}

arcade::Unit::Direction arcade::Spaceship::getMovingDirection() const {
    return movingDirection;
}

bool arcade::Spaceship::move(const arcade::Map &map, size_t offsetMapBorder) {
    return Unit::move(map, movingDirection, offsetMapBorder);
}

std::vector<arcade::Projectile *> &arcade::Spaceship::getProjectiles() {
    return projectiles;
}

void arcade::Spaceship::updateMapForProjectile(arcade::Map &map, Color color) {
    for (size_t i = 0; i < projectiles.size(); ++i) {
        {
            map.updateMapTileForUnit(*projectiles[i], 1, color, TileType::MY_SHOOT, TileTypeEvolution::SHOT_PLAYER,
                                     shootDirectionToSpriteId(true, projectiles[i]->getDirection()));
        }
    }
}

void arcade::Spaceship::clearMapForProjectile(arcade::Map &map) {
    for (size_t i = 0; i < projectiles.size(); ++i)
        if (!cmpPos(*projectiles[i]))
            map.updateMapTileForUnit(*projectiles[i], 1, Color::Transparent, TileType::EMPTY, TileTypeEvolution::EMPTY,
                                     0);
}

bool arcade::Spaceship::doesProjectilesCollide(Map &map, arcade::Unit &unit) {
    for (auto it = projectiles.begin(); it != projectiles.end();) {
        if ((*it)->doesCollide(unit)) {
            map.updateMapTileForUnit(*(*it), 1, Color::Transparent, TileType::EMPTY, TileTypeEvolution::EMPTY, 0);
            delete *it;
            it = projectiles.erase(it);
            return (true);
        } else
            ++it;
    }
    return (false);
}

bool arcade::Spaceship::doesProjectilesCollide(Map &map, std::vector<arcade::Projectile *> &otherProjectiles) {
    for (auto it = projectiles.begin(); it != projectiles.end(); ++it) {
        for (auto it2 = otherProjectiles.begin(); it2 != otherProjectiles.end(); ++it2) {
            if ((*it)->doesCollide(*(*it2))) {
                map.updateMapTileForUnit(*(*it), 1, Color::Transparent, TileType::EMPTY, TileTypeEvolution::EMPTY, 0);
                map.updateMapTileForUnit(*(*it2), 1, Color::Transparent, TileType::EMPTY, TileTypeEvolution::EMPTY, 0);
                delete *it;
                delete *it2;
                it = projectiles.erase(it);
                it2 = otherProjectiles.erase(it2);
                --it;
                --it2;
                return (true);
            }
        }
    }
    return (false);
}

int arcade::Spaceship::shootDirectionToSpriteId(bool player, arcade::Unit::Direction direction) {
    switch (direction) {
        case arcade::Unit::Direction::UP:
            return player ? 10 : 14;
        case arcade::Unit::Direction::DOWN:
            return player ? 12 : 16;
        case arcade::Unit::Direction::LEFT:
            return player ? 13 : 17;
        case arcade::Unit::Direction::RIGHT:
            return player ? 11 : 15;
        case arcade::Unit::Direction::FORWARD:
            return 0;
    }
    return player ? 10 : 15;
}

void arcade::Spaceship::reset() {
    for (size_t i = 0; i < projectiles.size(); ++i) {
        delete projectiles[i];
    }
    projectiles.clear();
    position = initialPos;
}

