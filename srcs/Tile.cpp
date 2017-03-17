//
// Created by sauvau_m on 3/17/17.
//

#include <iostream>
#include "../include/Tile.hpp"

arcade::TileType arcade::Tile::getType() const {
    return type;
}

void arcade::Tile::setType(arcade::TileType type) {
    Tile::type = type;
}

TileTypeEvolution arcade::Tile::getTypeEv() const {
    return typeEv;
}

void arcade::Tile::setTypeEv(TileTypeEvolution type) {
    Tile::typeEv = type;
}

arcade::Color arcade::Tile::getColor() const {
    return Color();
}

void arcade::Tile::setColor(arcade::Color color) {
    (void)color;
}

size_t arcade::Tile::getSpriteId() const {
    return 0;
}

size_t arcade::Tile::getSpritePos() const {
    return 0;
}

void arcade::Tile::nextSprite() {

}

void arcade::Tile::prevSprite() {

}

void arcade::Tile::setSpritePos(size_t pos) {
    (void)pos;
}

void arcade::Tile::setSprite(size_t id) {
    (void)id;
}

arcade::Tile::~Tile() {

}

arcade::Tile::Tile(TileTypeEvolution type) : typeEv(type) {
}
