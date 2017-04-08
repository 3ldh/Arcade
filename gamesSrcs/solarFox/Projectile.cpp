//
// Created by sauvau_m on 4/7/17.
//

#include <iostream>
#include "Projectile.hpp"

arcade::Projectile::~Projectile() {

}

arcade::Projectile::Projectile(size_t x, size_t y, Direction direction, int maxRange) : Unit(x, y), initialPosition(
        std::make_pair(x, y)), direction(direction), maxRange(maxRange) {}

bool arcade::Projectile::move(const arcade::Map &map) {
    if (abs((int) (initialPosition.first - position.first)) > maxRange ||
        abs((int) (initialPosition.second - position.second)) > maxRange)
        return (false);
    return Unit::move(map, direction);
}

bool arcade::Projectile::doesCollide(const arcade::Unit &unit) const {
    return position.first == unit.getPosition().first && position.second == unit.getPosition().second;
}

