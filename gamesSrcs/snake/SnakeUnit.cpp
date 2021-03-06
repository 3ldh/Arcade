//
// Created by sauvau_m on 3/18/17.
//

#include <iostream>
#include "SnakeUnit.hpp"

arcade::SnakeUnit::~SnakeUnit() {

}

arcade::SnakeUnit::SnakeUnit(size_t x, size_t y) : Unit(x, y), movingDirection(RIGHT) {
    for (int i = 0; i < NB_STARTING_PARTS; ++i) {
        parts.push_back(new Unit(x - i, y));
    }
}

bool arcade::SnakeUnit::move(const arcade::Map &map, arcade::Unit::Direction direction) {
    return moveAllParts(map, direction);
}

bool arcade::SnakeUnit::move(const arcade::Map &map) {
    return moveAllParts(map, movingDirection);
}

bool arcade::SnakeUnit::isBodyPart(size_t x, size_t y) {
    for (size_t i = 0; i < parts.size(); ++i) {
        if (parts[i]->getPosition().first == x && parts[i]->getPosition().second == y)
            return true;
    }
    return false;
}

bool arcade::SnakeUnit::grow(Map const &map) {
    size_t last_x = parts[parts.size() - 1]->getPosition().first;
    size_t last_y = parts[parts.size() - 1]->getPosition().second;

    for (int i = -1; i < 2; i += 2) {
        if (map.isWalkable(0, last_x + i, last_y) &&
            !isBodyPart(last_x + i, last_y)) {
            parts.push_back(new Unit(last_x + i, last_y));
            return true;
        } else if (map.isWalkable(0, last_x, last_y + i) &&
                   !isBodyPart(last_x, last_y + i)) {
            parts.push_back(new Unit(last_x, last_y + i));
            return true;
        }
    }
    return false;
}

arcade::Unit &arcade::SnakeUnit::operator[](size_t n) {
    return *parts[n];
}

arcade::Unit &arcade::SnakeUnit::operator[](size_t n) const {
    return *parts[n];
}

size_t arcade::SnakeUnit::getLength() const {
    return parts.size();
}

arcade::Unit::Direction arcade::SnakeUnit::getMovingDirection() const {
    return movingDirection;
}

void arcade::SnakeUnit::setMovingDirection(arcade::Unit::Direction movingDirection) {
    if (getOppositeDirection(SnakeUnit::movingDirection) != movingDirection)
        SnakeUnit::movingDirection = movingDirection;
}

bool arcade::SnakeUnit::moveAllParts(Map const &map, Direction direction) {
    std::pair<int, int> vector = convertDirection(direction);
    if (isBodyPart(parts[0]->getPosition().first + vector.first, parts[0]->getPosition().second + vector.second) ||
    !map.isWalkable(0, parts[0]->getPosition().first + vector.first, parts[0]->getPosition().second + vector.second))
        return false;
    for (size_t i = parts.size() - 1; i > 0; --i) {
        parts[i]->setPosition(parts[i - 1]->getPosition());
    }
    parts[0]->move(map, direction);
    return true;
}

void arcade::SnakeUnit::reset() {
    for (size_t i = 0; i < parts.size(); ++i) {
        delete parts[i];
    }
    parts.clear();
    for (int i = 0; i < NB_STARTING_PARTS; ++i) {
        parts.push_back(new Unit(initialPos.first - i, initialPos.second));
    }
    movingDirection = RIGHT;
}


