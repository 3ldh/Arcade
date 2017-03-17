//
// Created by sauvau_m on 3/17/17.
//

#include "../include/AUnits.hpp"

arcade::Units::~Units() {

}

arcade::Units::Units(const std::pair<int, int> &position) : position(position) {}

arcade::Units::Units(int x, int y) : position(std::make_pair(x, y)){

}

const std::pair<int, int> &arcade::Units::getPosition() const {
    return position;
}

void arcade::Units::setPosition(const std::pair<int, int> &position) {
    Units::position = position;
}

void arcade::Units::setPosition(int x, int y) {
    Units::position = std::make_pair(x, y);
}

arcade::Units::Direction arcade::Units::getNextMove() const {
    return nextMove;
}

void arcade::Units::setNextMove(arcade::Units::Direction nextMove) {
    Units::nextMove = nextMove;
}

void arcade::Units::move(arcade::Units::Direction direction) {
    switch (direction) {
        case UP:
            moveUp();
            break;
        case DOWN:
            moveDown();
            break;
        case LEFT:
            moveLeft();
            break;
        case RIGHT:
            moveRight();
            break;
    }
}

void arcade::Units::moveUp() {
    setPosition(position.first, position.second + 1);
}

void arcade::Units::moveDown() {

}

void arcade::Units::moveLeft() {

}

void arcade::Units::moveRight() {

}
