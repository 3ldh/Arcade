//
// Created by sauvau_m on 4/4/17.
//

#include "Spaceship.hpp"

arcade::Spaceship::~Spaceship() {

}

arcade::Spaceship::Spaceship(size_t x, size_t y) : Unit(x, y), projectile(Unit(0, 0)) {

}

void arcade::Spaceship::shoot() {
    std::pair<size_t, size_t> vector = convertDirection(movingDirection);
    projectile.setPosition(position.first + vector.first, position.second + vector.second);
}

void arcade::Spaceship::setMovingDirection(arcade::Unit::Direction movingDirection) {
    if (getOppositeDirection(Spaceship::movingDirection) != movingDirection)
        Spaceship::movingDirection = movingDirection;
}

arcade::Unit::Direction arcade::Spaceship::getMovingDirection() const {
    return movingDirection;
}

bool arcade::Spaceship::move(const arcade::Map &map) {
    return Unit::move(map, movingDirection);
}

void arcade::Spaceship::chooseDirectionFromAxe(const arcade::Map &map, Spaceship const &player) {

    int r = rand() % 100;
    movingDirection = r < 80
                      ? movingDirection : getOppositeDirection(movingDirection);
}

