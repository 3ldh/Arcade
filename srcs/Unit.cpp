//
// Created by sauvau_m on 3/17/17.
//

#include <iostream>
#include "../include/Unit.hpp"

arcade::Unit::~Unit() {}

arcade::Unit::Unit(const std::pair<size_t , size_t > &position) : position(position) {}

arcade::Unit::Unit(size_t x, size_t y) : initialPos(std::make_pair(x, y)), position(std::make_pair(x, y)) {}

const std::pair<size_t , size_t> &arcade::Unit::getPosition() const {
    return position;
}

void arcade::Unit::setPosition(const std::pair<size_t, size_t> &position) {
    Unit::position = position;
}

void arcade::Unit::setPosition(size_t x, size_t y) {
    Unit::position = std::make_pair(x, y);
}

bool arcade::Unit::move(Map const &map, arcade::Unit::Direction direction) {
    std::pair<int, int> vector = convertDirection(direction);

    if (map.isWalkable(0, position.first + vector.first, position.second + vector.second)) {
        setPosition(position.first + vector.first, position.second + vector.second);
        return true;
    }
    return false;
}

bool arcade::Unit::move(Map const &map, arcade::Unit::Direction direction, size_t offsetMapBorder) {
    std::pair<int, int> vector = convertDirection(direction);

    if (map.isWalkableOffset(0, position.first + vector.first, position.second + vector.second, offsetMapBorder)) {
        setPosition(position.first + vector.first, position.second + vector.second);
        return true;
    }
    return false;
}

void arcade::Unit::moveUp() {
    setPosition(position.first, position.second - 1);
}

void arcade::Unit::moveDown() {
    setPosition(position.first, position.second + 1);
}

void arcade::Unit::moveLeft() {
    setPosition(position.first - 1, position.second);
}

void arcade::Unit::moveRight() {
    setPosition(position.first + 1, position.second);
}

std::pair<int, int> arcade::Unit::convertDirection(arcade::Unit::Direction direction) {
    switch (direction) {
        case UP:
            return std::make_pair(0, -1);
        case DOWN:
            return std::make_pair(0, 1);
        case LEFT:
            return std::make_pair(-1, 0);
        case RIGHT:
            return std::make_pair(1, 0);
        case FORWARD:
            return std::make_pair(0, 0);
    }
    return std::make_pair(0, 0);
}

const arcade::Sprite &arcade::Unit::getSprite() const {
    return sprite;
}

void arcade::Unit::setSprite(const arcade::Sprite &sprite) {
    Unit::sprite = sprite;
}

arcade::Unit::Direction arcade::Unit::getOppositeDirection(arcade::Unit::Direction direction) {
    switch (direction)
    {
        case UP:
            return DOWN;
        case DOWN:
            return UP;
        case LEFT:
            return RIGHT;
        case RIGHT:
            return LEFT;
        case FORWARD:
            return FORWARD;
    }
    return FORWARD;
}

bool arcade::Unit::cmpPos(const arcade::Unit &unit) {
    return position.first == unit.getPosition().first && position.second == unit.getPosition().second;
}


