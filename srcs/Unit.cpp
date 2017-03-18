//
// Created by sauvau_m on 3/17/17.
//

#include <iostream>
#include "../include/Unit.hpp"

arcade::Unit::~Unit() {

}

arcade::Unit::Unit(const std::pair<size_t , size_t > &position) : position(position) {}

arcade::Unit::Unit(size_t x, size_t y) : position(std::make_pair(x, y)) {

}

const std::pair<size_t , size_t> &arcade::Unit::getPosition() const {
    return position;
}

void arcade::Unit::setPosition(const std::pair<size_t, size_t> &position) {
    Unit::position = position;
}

void arcade::Unit::setPosition(size_t x, size_t y) {
    Unit::position = std::make_pair(x, y);
}

arcade::Unit::Direction arcade::Unit::getNextMove() const {
    return nextMove;
}

void arcade::Unit::setNextMove(arcade::Unit::Direction move) {
    nextMove = move;
}

bool arcade::Unit::move(IMap const &map, arcade::Unit::Direction direction) {
    switch (direction) {
        case UP:
            if (map.isWalkable(0, position.first, position.second - 1)) {
                moveUp();
                return true;
            }
            break;
        case DOWN:
            if (map.isWalkable(0, position.first, position.second + 1)) {
                moveDown();
                return true;
            }
            break;
        case LEFT:
            if (map.isWalkable(0, position.first - 1, position.second)) {
                moveLeft();
                return true;
            }
            break;
        case RIGHT:
            if (map.isWalkable(0, position.first + 1, position.second)) {
                moveRight();
                return true;
            }
            break;
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

