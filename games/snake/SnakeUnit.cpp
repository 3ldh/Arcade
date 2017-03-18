//
// Created by sauvau_m on 3/18/17.
//

#include <iostream>
#include "SnakeUnit.hpp"

arcade::SnakeUnit::~SnakeUnit() {

}

arcade::SnakeUnit::SnakeUnit(size_t x, size_t y) : Unit(x, y) {
    for (int i = 0; i < NB_STARTING_PARTS; ++i) {
        parts.push_back(new Unit(x - i, y));
        std::cout << "move part " << i << " x : " << parts[i]->getPosition().first << " y : "<<parts[i]->getPosition().second << std::endl;
    }
}

//TODO do we need to remove collisino check fro the snake
bool arcade::SnakeUnit::move(const arcade::IMap &map, arcade::Unit::Direction direction) {
    return moveAllParts(map, direction);
}

bool arcade::SnakeUnit::isBodyPart(size_t x, size_t y) {
    for (size_t i = 1; i < parts.size(); ++i) {
        if (parts[i]->getPosition().first == x && parts[i]->getPosition().second == y)
            return true;
    }
    return false;
}

void arcade::SnakeUnit::grow() {

}

arcade::Unit &arcade::SnakeUnit::operator[](size_t n) {
    return *parts[n];
}

size_t arcade::SnakeUnit::getLength() const {
    return parts.size();
}

bool arcade::SnakeUnit::moveAllParts(IMap const &map, Direction direction) {
        std::cout << "move head 0 x : " << parts[0]->getPosition().first << " y : " << parts[0]->getPosition().second << std::endl;
        for (size_t i = parts.size() - 1; i > 0; --i) {
//            std::cout << "direction " << parts[i]->getNextMove() << std::endl;
            parts[i]->setPosition(parts[i - 1]->getPosition());
            std::cout << "move part " << i << " x : " << parts[i]->getPosition().first << " y : "<<parts[i]->getPosition().second << std::endl;
//            std::cout << "next direction " << parts[i]->getNextMove() << std::endl;
        }
    parts[0]->move(map, direction);
    return true;
}